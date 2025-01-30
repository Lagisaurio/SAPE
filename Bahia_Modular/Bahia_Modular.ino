/*
  Fecha de edición: 30/01/25
  Código: Bahía - SAPE
  Editor: Luis Fuentes
  
  Descripción:
  

*/
#include <WiFi.h>
#include <SPI.h>
#include <MFRC522.h>
#include <EEPROM.h>

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
  Serial.println("Lector RFID inicializado.");

  // Configurar ESP32 como Access Point
  WiFi.softAP(ssid, password);

  // Obtener la IP del AP
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Punto de acceso iniciado. IP: ");
  Serial.println(IP);

  // Iniciar el servidor TCP
  servidor.begin();
  Serial.println("Servidor TCP iniciado. Esperando conexiones...");
}

void loop() {
  // Aceptar cliente entrante
  if (!cliente || !cliente.connected()) {
    cliente = servidor.available();
    if (cliente) {
      Serial.println("Cliente conectado.");
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

    // Verificar UID y alternar estado del LED
    if (uid == UID_VALIDO || uid == UID_VALIDO2 || uid == UID_VALIDO3) {
      if (cliente && cliente.connected()) {
        if (ledEncendido && tarjetaActiva == uid) {
          cliente.println("APAGAR"); // Comando para apagar el LED
          Serial.println("Comando enviado: APAGAR");
          ledEncendido = false; // Cambiar estado
          tarjetaActiva = "";
        } else if (ledEncendido && tarjetaActiva != uid) {
          cliente.println("ALARMA");
          Serial.println("Comando enviado: ALARMA");
        } else {
          tarjetaActiva = uid;
          cliente.println("ENCENDER"); // Comando para encender el LED
          Serial.println("Comando enviado: ENCENDER");
          ledEncendido = true; // Cambiar estado
        }
      }
    }
     else {
      Serial.println("UID no reconocido.");
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