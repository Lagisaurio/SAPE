/Librerias
#include <EEPROM.h>
#include <SPI.h>
#include <MFRC522.h>

//Declaración de Pines ESP32
//Modulos
#define SS_PIN 5             // Pin del esclavo seleccionado (SDA)
#define RST_PIN 22           // Pin de reset del MFRC522, configurado para el ESP32

//Constantes
#define EEPROM_SIZE 4        // Tamaño de la memoria EEPROM para almacenar la UID de la tarjeta
#define MIN_DISTANCE 20      // Distancia minima del sensor ultrasonicoo para activar led

enum Estado{
  IGUAL,
  DIFERENTE,
};

Estado memoria;

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Crea el objeto MFRC522

byte almacenarUID[EEPROM_SIZE] = {}; // Inicializa la memoria almacenada
byte masterUID[EEPROM_SIZE] = {0x5D, 0x2E, 0xDE, 0x89}; //5D 2E DE 89

void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
  delayMicroseconds(2);
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Muestra la UID de la tarjeta
    Serial.print("UID de la tarjeta: ");
    imprime_dato_tarjeta(mfrc522.uid.uidByte, mfrc522.uid.size);
    
    // Compara la UID leída con la almacenada en la memoria y con el masterUID
    bool sameUID = comparar_uid(mfrc522.uid.uidByte, mfrc522.uid.size, almacenarUID, EEPROM_SIZE);
    bool masterUIDBool = comparar_uid(mfrc522.uid.uidByte, mfrc522.uid.size, masterUID, EEPROM_SIZE);
    Serial.println("------------------------------\nDetección de tarjeta\n------------------------------");



