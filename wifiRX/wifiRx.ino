#include <WiFi.h>
#include <SPI.h>
#include <MFRC522.h>
#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

// Configuración del Access Point
const char* ssid = "SAPE.net";
const char* password = "SAPE_2024";

const int puertoTCP = 1000; // Puerto del servidor TCP
WiFiServer servidor(puertoTCP);

// Configuración del lector RFID
#define SS_PIN 21
#define RST_PIN 22
MFRC522 rfid(SS_PIN, RST_PIN);
const int LED = 2;
const int buzzer = 33;
// Lista de UIDs válidos

const String UID_VALIDO = "63D2EB95";
const String UID_VALIDO2 = "1B11E623";
const String UID_VALIDO3 = "5D2EDE89";

String tarjetaActiva1 = "";
String tarjetaActiva2 = "";
//byte almacenarUID[EEPROM_SIZE] = {};               // UID almacenado en memoria
//byte masterUID[EEPROM_SIZE] = {0x5D, 0x2E, 0xDE, 0x89}; // UID maestro

WiFiClient cliente1, cliente2;

// Estado del LED
bool disponible1 = false; // Inicialmente apagado
bool disponible2 = false;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void msjLCD(String linea1, String linea2, String linea3, String linea4) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(linea1);
  lcd.setCursor(0, 1);
  lcd.print(linea2);
  lcd.setCursor(0, 2);
  lcd.print(linea3);  
  lcd.setCursor(0, 3);
  lcd.print(linea4);
  
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(buzzer,OUTPUT);

  Wire.begin(25,26);
  lcd.init();
  lcd.backlight();
  msjLCD("Inicializando... :D","","","");
  Serial.println("Lector RFID inicializado.");

  // Configurar ESP32 como Access Point
  WiFi.softAP(ssid, password);

  // Obtener la IP del AP
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Punto de acceso iniciado. IP: ");
  Serial.println(IP);
  msjLCD("","","IP: " + String(IP.toString()),"");
  servidor.begin();
  Serial.println("Servidor TCP iniciado. Esperando conexiones...");
    
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);

}

void loop() {
  WiFiClient nuevoCliente = servidor.available();
  if (nuevoCliente) {
    if (!cliente1) {
      cliente1 = nuevoCliente;
      msjLCD("Casillero1 conectado","","","");
      Serial.println("Casillero 1 conectado.");
      delay(2000);
      lcd.clear();
    } else if (!cliente2) {
      cliente2 = nuevoCliente;
      Serial.println("Casillero 2 conectado.");
      msjLCD("","Casillero2 conectado","","");
      delay(2000);
      lcd.clear();
    } else {
      Serial.println("Cliente rechazado (máximo alcanzado)");
      nuevoCliente.stop();
    }
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (cliente1 && cliente1.connected()) {
  while (cliente1.available()) {
    String mensaje = cliente1.readStringUntil('\n');
    mensaje.trim();
    Serial.println("Mensaje de Casillero 1: " + mensaje);
    msjLCD("","","C1 dice:" + mensaje,"");
  
    if(mensaje == "DESOCUPADO"){
      Serial.println("SE DESOCUPO EL CASILLERO CORRECTAMENTE");
      disponible1 = false; // Cambiar estado
      tarjetaActiva1 = "";
    }
  }
}

if (cliente2 && cliente2.connected()) {
  while (cliente2.available()) {
    String mensaje = cliente2.readStringUntil('\n');
    Serial.println("Mensaje de Casillero 2: " + mensaje);
    msjLCD("","","","C2 dice:" + mensaje);

    if(mensaje =="DESOCUPADO"){
      tarjetaActiva2 = "";
      disponible2 = false;
    }
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  msjLCD("Hola Bienvenidos","Pasa tu tarjeta","Por javor :D","|-/");
  delay(2000);

  // Detectar tarjeta RFID
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Leer UID de la tarjeta
    String uid = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      uid += String(rfid.uid.uidByte[i], HEX);
    }
    uid.toUpperCase();
    Serial.println("UID leído: " + uid);
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    delay(500);
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    delay(500);
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    delay(500);

    msjLCD("Tarjeta detectada","Hola Bienvenido","|-/","");
  
    
    // Verificar UID y alternar estado del LED
    if (uid == UID_VALIDO || uid == UID_VALIDO2 || uid == UID_VALIDO3) {
      if (cliente1 && cliente1.connected() && !disponible1 && tarjetaActiva2 != uid) {
        tarjetaActiva1 = uid;
        cliente1.println("OCUPANDO"); 
        Serial.println("Comando enviado a Cliente 1: OCUPANDO");
        msjLCD("","","Casillero 1 Asignado","Pase por favor :D");
        delay(2000);
      
        disponible1 = true; 

      } else if (cliente2 && cliente2.connected() && !disponible2 && tarjetaActiva1 != uid) {
        tarjetaActiva2 = uid;
        cliente2.println("OCUPANDO"); 
        Serial.println("Comando enviado a Cliente 2: OCUPANDO");
        msjLCD("","","Casillero 2 Asignado","Pase por favor :D");
        delay(2000);
        disponible2 = true; 

      } else if (cliente2 && cliente2.connected() && disponible2 && tarjetaActiva2 == uid) {
        cliente2.println("LIBERANDO"); // Comando para apagar el LED
        Serial.println("Comando enviado a cliente 2: LIBERANDO");
        msjLCD("","","Casillero 2 Liberado","Pase por favor :D");
        delay(2000);
        disponible2 = false; // Cambiar estado
        tarjetaActiva2 = "";

      } 
        else if(cliente1 && cliente1.connected() && disponible1 && tarjetaActiva1 == uid) {
        cliente1.println("LIBERANDO"); // Comando para apagar el LED
        Serial.println("Comando enviado a cliente 1: LIBERANDO");
        
        delay(2000);
        disponible1 = false; // Cambiar estado
        tarjetaActiva1 = "";

      } else {
        Serial.println("Todos los casilleros ocupados");
        msjLCD("","","Todos Ocupados","Vuelva mas tarde :'(");
        delay(2000);
        }
    } else {
      Serial.println("UID no reconocido.");
      msjLCD("","","No reconocido","");
    }

    // Detener comunicación con la tarjeta
    rfid.PICC_HaltA();
    delay(1000);
  }
}

void imprime_dato_tarjeta(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
  Serial.println();
}