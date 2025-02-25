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

void setup() {
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();

  Wire.begin(25,26);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
  Serial.println("Lector RFID inicializado.");

  // Configurar ESP32 como Access Point
  WiFi.softAP(ssid, password);

  // Obtener la IP del AP
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Punto de acceso iniciado. IP: ");
  Serial.println(IP);

  lcd.setCursor(0, 2);
  lcd.print("IP: " + String(IP.toString()));

  // Iniciar el servidor TCP
  servidor.begin();
  Serial.println("Servidor TCP iniciado. Esperando conexiones...");
  lcd.setCursor(0, 3);
  lcd.print("Servidor iniciado");

}

void loop() {
  WiFiClient nuevoCliente = servidor.available();
  if (nuevoCliente) {
    if (!cliente1) {
      cliente1 = nuevoCliente;
      Serial.println("Casillero 1 conectado.");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Casillero1 conectado");
    } else if (!cliente2) {
      cliente2 = nuevoCliente;
      Serial.println("Casillero 2 conectado.");
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("Casillero2 conectado");
    } else {
      Serial.println("Cliente rechazado (máximo alcanzado)");
      nuevoCliente.stop();
    }
  }

  // Detectar tarjeta RFID
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Leer UID de la tarjeta
    String uid = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      uid += String(rfid.uid.uidByte[i], HEX);
    }
    uid.toUpperCase();
    Serial.println("UID leído: " + uid);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("UID leido:");
    lcd.setCursor(0, 1);
    lcd.print(uid);

    // Verificar UID y alternar estado del LED
    if (uid == UID_VALIDO || uid == UID_VALIDO2 || uid == UID_VALIDO3) {
      if (cliente1 && cliente1.connected() && !disponible1 && tarjetaActiva2 != uid) {
        tarjetaActiva1 = uid;
        cliente1.println("ENCENDER"); 
        Serial.println("Comando enviado a Cliente 1: ENCENDER");
        lcd.setCursor(0, 2);
        lcd.print("Casillero 1 Asignado");
        disponible1 = true; 

      } else if (cliente2 && cliente2.connected() && !disponible2 && tarjetaActiva1 != uid) {
        tarjetaActiva2 = uid;
        cliente2.println("ENCENDER"); 
        Serial.println("Comando enviado a Cliente 2: ENCENDER");
        lcd.setCursor(0, 2);
        lcd.print("Casillero 2 Asignado");
        disponible2 = true; 

      } else if (cliente2 && cliente2.connected() && disponible2 && tarjetaActiva2 == uid) {
        cliente2.println("APAGAR"); // Comando para apagar el LED
        Serial.println("Comando enviado a cliente 2: APAGAR");
        lcd.setCursor(0, 2);
        lcd.print("Casillero 2 Liberado");
        disponible2 = false; // Cambiar estado
        tarjetaActiva2 = "";

      } 
        else if(cliente1 && cliente1.connected() && disponible1 && tarjetaActiva1 == uid) {
        cliente1.println("APAGAR"); // Comando para apagar el LED
        Serial.println("Comando enviado a cliente 1: APAGAR");
        lcd.setCursor(0, 2);
        lcd.print("Casillero 1 Liberado");
        disponible1 = false; // Cambiar estado
        tarjetaActiva1 = "";

      } else {
        Serial.println("Todos los casilleros ocupados");
        lcd.setCursor(0, 2);
        lcd.print("Todos ocupados");
        }
    } else {
      Serial.println("UID no reconocido.");
      lcd.setCursor(0, 2);
      lcd.print("No reconocido");
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

/*   -------------------------------------------- PRUEBAS --------------------------------------------   */