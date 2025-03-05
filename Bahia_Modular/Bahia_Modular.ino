/*
  Fecha de edición: 30/01/25
  Código: Bahía - SAPE
  Editor: Luis Fuentes
  
  Descripción:
    Este programa controla el funcionamiento del modulo RFID-RC-522 para la identificación de tarjertas d radiofrecuencia (13.5 Mhz).
    El programa crea una red de nombre SAPE, espera conexciones a esta misma red y una vez exista algun dispositivo conectado inicializa la lectura del RFID.
    Al reconocer una tarjeta valida, se envia un comando "ENCENDER" (por el momento) al cliente conectado, una vez encendido, se espera que se reconozca la misma tarjeta
    y para enviar un comando "APAGAR" (Por el momento) al cliente, en caso de que sea otra tarjeta la que se reconoce,se enviará un comando "ALARMA" que encenderá un led 
    y un buzzer que indicaran que la tarjeta es erronea.
    
  

*/

/* -------------------- L I B R E R Í A S -------------------- */
#include <WiFi.h>
#include <SPI.h>
#include <MFRC522.h>
#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/* ------------ DEFINICIÓN DE PINES ------------ */
  //Lector RFID
#define SS_PIN 21                                           // Conexión del SS del modulo RC522
#define RST_PIN 22                                          // Conexión del RESET del modulo RC522

  //WiFi
#define LED_CONEXION 2

  //Indicadores
#define BUZZER 33

  //Control LCD
#define SDA_LCD 25
#define SCL_LCD 26

/* ------------ DEFINICIÓN DE VARIABLES ------------ */

  //Comunicación WiFi
const char* ssid = "SAPE.net";                              // Nombre de la red creada
const char* password = "SAPE_2025";                         // Contraseña de acceso a la red
const int puertoTCP = 1000;                                 // Puerto del servidor TCP

WiFiServer servidor(puertoTCP);                             // Objeto tipo WiFiServer que indica el puerto en que se asentará el servidor
WiFiClient casillero1, casillero2;                          // Objetos de tipo WiFiClient que permite vincular las esp32 de los casilleros

  //RFID
MFRC522 rfid(SS_PIN, RST_PIN);                              // Objeto de tipo MFRC522 que vincula ambos pines con el modulo

 //LCD
LiquidCrystal_I2C lcd(0x27, 20, 4);                         // Objeto de tipo LiquidCrystal que configura el LCD

 //Lista de UIDs válidos
const String UID_VALIDO  = "63D2EB95";
const String UID_VALIDO2 = "1B11E623";
const String UID_VALIDO3 = "5D2EDE89";

  //Almacenamiento de datos
String almacenamientoTarjeta1 = "";                         // Variables auxiliares de para el almacenamiento y reconocimiento de las tarjetas
String almacenamientoTarjeta2 = "";

  //Detección y estados
bool casilleroOcupado1 = false;                           // Variable auxiliar que indica si un casillero esta disponible o no.
bool casilleroOcupado2 = false;

//byte almacenarUID[EEPROM_SIZE] = {};               // UID almacenado en memoria
//byte masterUID[EEPROM_SIZE] = {0x5D, 0x2E, 0xDE, 0x89}; // UID maestro


/* ------------ DEFINICIÓN DE FUNCIONES ------------ */

// 1. Función para imprimir el dato de las tarjetas (Puede ignorarse)
void imprime_dato_tarjeta(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
  Serial.println();
}

// 2. Función para imprimir msj en el LCD
void msjLCD(String linea1, String linea2, String linea3, String linea4) {
  lcd.clear();
  lcd.setCursor(0, 0);      // Coloca el cursor del LCD
  lcd.print(linea1);        // Imprime en el LCD
  lcd.setCursor(0, 1);
  lcd.print(linea2);
  lcd.setCursor(0, 2);
  lcd.print(linea3);  
  lcd.setCursor(0, 3);
  lcd.print(linea4);
  
}

// 3. Función para sonido de buzzer
void buzzer(int pinBuzzer, int conteo) {
  for (int i = 0; i < conteo; i++) {
    digitalWrite(pinBuzzer, HIGH);
    delay(500);
    digitalWrite(pinBuzzer, LOW);
    delay(500);
  }  
}

void setup() {
  Serial.begin(115200); 

  //Entradas

  //Salidas
  pinMode(LED_CONEXION, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  //Valores iniciales
  digitalWrite(LED_CONEXION, HIGH);

  SPI.begin();                                              // Inicializa comunicación SPI
  rfid.PCD_Init();                                          // Inicializa 

  Wire.begin (SDA_LCD, SCL_LCD);                                      // Inicializa comunicación por I2C
  lcd.init();                                               // Inicializa configuración de la pantalla LCD
  lcd.backlight();                                          // Permite encender fondo LED de la pantalla LCD
  msjLCD("Inicializando... :D","","","");
  Serial.println("Lector RFID inicializado.");

  WiFi.softAP(ssid, password);                              // Configurar ESP32 como Access Point

  IPAddress IP = WiFi.softAPIP();                           // Objeto tipo IPAddress que obtiene la IP del AP
  Serial.print("Punto de acceso iniciado. IP: ");
  Serial.println(IP);
  //msjLCD("","","IP: " + String(IP.toString()),"");
  servidor.begin();                                         // Inicialización del servidor TCP
  Serial.println("Servidor TCP iniciado. Esperando conexiones...");
  msjLCD("","","","Servidor Iniciado");

}

void loop() {

  WiFiClient nuevoCasillero = servidor.available();
  // Aceptar cliente entrante

  if(nuevoCasillero) {
    if(!casillero1) {
      casillero1 = nuevoCasillero;
      Serial.println("Casillero 1 conectado");
      msjLCD("Casillero 1 conectado","","","");
    } else if (!casillero2) {
      casillero2 = nuevoCasillero;
      Serial.println("Casillero 2 conectado");
      msjLCD("Casillero2 conectado","","","");
    } else {
      Serial.println("Casillero rechazado, maximo alcanzado");
      nuevoCasillero.stop();
    }
  }

  if(casillero1 && casillero1.connected()) {
    while(casillero1.available()) {
      String comando = casillero1.readStringUntil('\n');
      comando.trim();
      Serial.println("Casillero 1: " + comando);
      msjLCD("","","C1 dice: "+ comando, "");
      if(comando == "DESOCUPADO") {
        Serial.println("Se desocupo el casillero correctamente");
        casilleroOcupado1 = false;
        almacenamientoTarjeta1 ="";
      }
    }
  }

  if(casillero2 && casillero2.connected()) {
    while(casillero2.available()) {
      String comando = casillero2.readStringUntil('\n');
      comando.trim();
      Serial.println("Casillero 2: " + comando);
      msjLCD("","","C2 dice: "+ comando, "");
      if(comando == "DESOCUPADO") {
        Serial.println("Se desocupo el casillero correctamente");
        casilleroOcupado2 = false;
        almacenamientoTarjeta2 ="";
      }
    }
  }

  msjLCD("Bienvenido, presente","su tarjeta en el lector","Por favor :D","|-/");
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
    buzzer(BUZZER, 3);
    msjLCD("Tarjeta detectada","","|-/","");

    // Verificar UID y alternar estado del LED
    if (uid == UID_VALIDO || uid == UID_VALIDO2 || uid == UID_VALIDO3) {
      if (casillero1 && casillero1.connected() && casilleroOcupado1 && almacenamientoTarjeta2 != uid) {  
        
        casillero1.println("OCUPANDO"); // Comando para apagar el LED
        Serial.println("Comando enviado a casillero 1: OCUPANDO");
        msjLCD("","","Casillero 1 Asignado","Pase por favor :D");
        casilleroOcupado1 = true; // Cambiar estado
        almacenamientoTarjeta1 = uid;
        delay(2000);

      }  else if (casillero2 && casillero2.connected() && casilleroOcupado2 && almacenamientoTarjeta1 != uid) {
        
        casillero2.println("OCUPANDO"); // Comando para apagar el LED
        Serial.println("Comando enviado a casillero 2: OCUPANDO");
        msjLCD("","","Casillero 2 Asignado","Pase por favor :D");
        casilleroOcupado2 = true; // Cambiar estado
        almacenamientoTarjeta2 = uid;
        delay(2000);

      } else if (casillero1 && casillero1.connected() && !casilleroOcupado1 && almacenamientoTarjeta1 == uid) {
        
        casillero1.print("LIBERANDO");
        Serial.println("Comando enviado a casillero 1: LIBERANDO");
        msjLCD("","","Casillero 1 Liberado","Pase por favor :D");
        casilleroOcupado1 = true;
        almacenamientoTarjeta1 = "";
        delay(2000);

      } else if (casillero2 && casillero1.connected() && !casilleroOcupado2 && almacenamientoTarjeta2 == uid) {
        
        casillero2.print("LIBERANDO");
        Serial.println("Comando enviado a casillero 2: LIBERANDO");
        msjLCD("","","Casillero 2 Liberado","Pase por favor :D");
        casilleroOcupado2 = true;
        almacenamientoTarjeta2 = "";
        delay(2000);

      } else {
        
        Serial.println("No hay casilleros disponibles");
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


