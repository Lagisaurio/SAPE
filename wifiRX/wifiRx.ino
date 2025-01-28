/*#include <WiFi.h>

const char* ssid = "SAPE.net";
const char* password = "SAPE_2024";

const int puertoTCP = 1000;

WiFiServer servidor(puertoTCP);
const int ledPin = 13;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Punto de accesso iniciado. IP: ");
  Serial.println(IP);

  servidor.begin();
  Serial.println("Servidor TCP iniciado. Esperando conexiones...");
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient cliente = servidor.available();
  if (cliente){
    Serial.println("Cliente conectado");
    while (cliente.connected()){
      if(cliente.available()){
        String comando = cliente.readStringUntil('/n');
        comando.trim();
        Serial.println("Comando recibido: " + comando);

        if(comando == "ENCENDER") {
          digitalWrite(ledPin, HIGH);
          Serial.println("LED encendido");
          } else if (comando == "APAGAR") {
            digitalWrite(ledPin, LOW);
            Serial.println("LED Apagado");
          } else {
            Serial.println("Comando no reconocido");
          }
        }
      }
    
    Serial.println("Cliente desconectado");
  }
}*/

// Emisor

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
//byte almacenarUID[EEPROM_SIZE] = {};               // UID almacenado en memoria
//byte masterUID[EEPROM_SIZE] = {0x5D, 0x2E, 0xDE, 0x89}; // UID maestro

WiFiClient cliente;

// Estado del LED
bool ledEncendido = false; // Inicialmente apagado
bool ledEncendido2  =false;


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
    if (uid == UID_VALIDO) {
      if (cliente && cliente.connected()) {
        if (ledEncendido) {
          cliente.println("APAGAR"); // Comando para apagar el LED
          Serial.println("Comando enviado: APAGAR");
          ledEncendido = false; // Cambiar estado
        } else {
          cliente.println("ENCENDER"); // Comando para encender el LED
          Serial.println("Comando enviado: ENCENDER");
          ledEncendido = true; // Cambiar estado
        }
      }
    }
    else if (uid = UID_VALIDO2){
      if (cliente && cliente.connected()) {
        if (ledEncendido2) {
          cliente.println("APAGAR2"); // Comando para apagar el LED
          Serial.println("Comando enviado: APAGAR 2");
          ledEncendido2 = false; // Cambiar estado
        } else {
          cliente.println("ENCENDER2"); // Comando para encender el LED
          Serial.println("Comando enviado: ENCENDER 2");
          ledEncendido2 = true; // Cambiar estado
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

