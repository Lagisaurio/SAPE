

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

String tarjetaActiva ="";
//byte almacenarUID[EEPROM_SIZE] = {};               // UID almacenado en memoria
//byte masterUID[EEPROM_SIZE] = {0x5D, 0x2E, 0xDE, 0x89}; // UID maestro

WiFiClient cliente;

// Estado del LED
bool ledEncendido = false; // Inicialmente apagado


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
  // Aceptar cliente entrante
  if (!cliente || !cliente.connected()) {
    cliente = servidor.available();
    if (cliente) {
      Serial.println("Cliente conectado.");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Cliente conectado");
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
      if (cliente && cliente.connected()) {
        if (ledEncendido && tarjetaActiva == uid) {
          cliente.println("APAGAR"); // Comando para apagar el LED
          Serial.println("Comando enviado: APAGAR");
          lcd.setCursor(0, 2);
          lcd.print("Comando: APAGAR");
          ledEncendido = false; // Cambiar estado
          tarjetaActiva = "";
        } else if (ledEncendido && tarjetaActiva != uid) {
          cliente.println("ALARMA");
          Serial.println("Comando enviado: ALARMA");
          lcd.setCursor(0, 2);
          lcd.print("Comando: ALARMA");
        } else {
          tarjetaActiva = uid;
          cliente.println("ENCENDER"); // Comando para encender el LED
          Serial.println("Comando enviado: ENCENDER");
          lcd.setCursor(0, 2);
          lcd.print("Comando: ENCENDER");
          ledEncendido = true; // Cambiar estado
        }
      }
    }
     else {
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

/*


#include <WiFi.h>
#include <SPI.h>
#include <MFRC522.h>
#include <EEPROM.h>


// Configuración del LCD (Dirección I2C, Columnas, Filas)
LiquidCrystal_I2C lcd(0x27, 20, 4); // Asegúrate de que 0x27 sea la dirección correcta

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

WiFiClient cliente;

// Estado del LED
bool ledEncendido = false; 
bool ledEncendido2 = false;

void setup() {
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();

  // Inicializar LCD
  Wire.begin(25,26);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");

  Serial.println("Lector RFID inicializado.");
  lcd.setCursor(0, 1);
  lcd.print("RFID listo");

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
  Serial.println("Servidor TCP iniciado.");
  lcd.setCursor(0, 3);
  lcd.print("Servidor iniciado");
}

void loop() {
  // Aceptar cliente entrante
  if (!cliente || !cliente.connected()) {
    cliente = servidor.available();
    if (cliente) {
      Serial.println("Cliente conectado.");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Cliente conectado");
    }
  }

  // Detectar tarjeta RFID
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
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
    if (uid == UID_VALIDO) {
      if (cliente && cliente.connected()) {
        if (ledEncendido) {
          cliente.println("APAGAR");
          Serial.println("Comando enviado: APAGAR");
          lcd.setCursor(0, 2);
          lcd.print("Comando: APAGAR");
          ledEncendido = false;
        } else {
          cliente.println("ENCENDER");
          Serial.println("Comando enviado: ENCENDER");
          lcd.setCursor(0, 2);
          lcd.print("Comando: ENCENDER");
          ledEncendido = true;
        }
      }
    } else if (uid == UID_VALIDO2) {
      if (cliente && cliente.connected()) {
        if (ledEncendido2) {
          cliente.println("APAGAR2");
          Serial.println("Comando enviado: APAGAR 2");
          lcd.setCursor(0, 2);
          lcd.print("Comando: APAGAR 2");
          ledEncendido2 = false;
        } else {
          cliente.println("ENCENDER2");
          Serial.println("Comando enviado: ENCENDER 2");
          lcd.setCursor(0, 2);
          lcd.print("Comando: ENCENDER 2");
          ledEncendido2 = true;
        }
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
}*/



