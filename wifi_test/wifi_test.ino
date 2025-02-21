/*
  Codigo de servidor ESP32

*/
/*
//Receptor

#include <WiFi.h>
#include "HX711.h"


// Sensores
#define INFRARROJO 15
#define TRIGGER    23
#define ECHO       22
#define GALGA_DT   19
#define GALGA_SCK  18

// Constantes de medición
#define DISTANCIA_MIN   10

// Configuración del Access Point
const char* ssid = "SAPE.net";
const char* password = "SAPE_2024";

// Configuración TCP
const char* servidorIP = "192.168.4.1"; // IP del servidor (AP)
const int puertoTCP = 1000;

WiFiClient cliente;

const int ledPin = 13;    //OCUPACIÓN
const int ledPin12 = 12;  // !OCUPACIÓN
const int ledPin2 = 14;   //ALARMA
const int galgaPin = 21;
const int ultrasonicoPin = 32;
const int errorSistema = 26;

float peso_umbral = 20.0;
float factor_calibracion = 2280.0;

HX711 scale(GALGA_DT,GALGA_SCK);
const int salidaPin = 4;

//volatile bool irInterrupt = false;
bool salidaGalga = false;
bool ultrasonicoDetecta = false;
bool irDetecta = false;

void galga_test(){       // Si da lecturas erroneas, reiniciar ESP32
  
  float lectura = scale.get_units(10);

  Serial.print("Peso: ");
  Serial.print(lectura);
  Serial.print(" KG || ");

  if (lectura >= peso_umbral){
    //Serial.println("---- SENSADO DE LA GALGA ----");
    salidaGalga = true;
    digitalWrite(galgaPin, HIGH);
  } else {
    salidaGalga = false;
    digitalWrite(galgaPin,LOW);
  }
  delay(100);
  
}

void infrarrojo_test(){
  int irAux = digitalRead(INFRARROJO);
  if(!irAux){

    Serial.println("INTERRUPCIÓN IR");
    irDetecta = false;
  } else {
    irDetecta = true;
    //Serial.println("¡¡¡¡ INFRARROJO SENSANDO !!!!");
    
  }
}

void ultrasonico_test(){
  long distancia = medir_distancia(TRIGGER, ECHO);
  Serial.print("Distancia:");
  Serial.print(distancia);
  Serial.print(" cm");

  if (DISTANCIA_MIN > distancia ){
    ultrasonicoDetecta = true;
    digitalWrite(ultrasonicoPin, HIGH);
  } else{
    ultrasonicoDetecta = false;
    digitalWrite(ultrasonicoPin, LOW);
  }

  delay(100);
}

long medir_distancia(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duracion = pulseIn(echoPin, HIGH);

  if(duracion == 0 ){
    Serial.println("¡¡¡¡ ERROR: ECHO NO DETECTADO !!!!");
    return -1;
  }

  return duracion/58;
} 


void setup() {
  Serial.begin(115200);

  scale.set_scale(factor_calibracion);  // Sin factor de escala, solo lecturas crudas
  scale.tare();       // Ajustar la celda de carga a cero

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin2,LOW);
  pinMode(ledPin12, OUTPUT);
  digitalWrite(ledPin12,LOW);

  pinMode(salidaPin, OUTPUT);
  digitalWrite(salidaPin, LOW);

  pinMode(galgaPin, OUTPUT);
  digitalWrite(galgaPin,LOW);
  pinMode(ultrasonicoPin, OUTPUT);
  digitalWrite(ultrasonicoPin,LOW);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);

  // Conectar al Access Point
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConexión establecida con el Access Point.");

  // Intentar conectarse al servidor TCP
  if (cliente.connect(servidorIP, puertoTCP)) {
    Serial.println("Conexión TCP establecida con el servidor.");
  } else {
    Serial.println("No se pudo conectar al servidor. Verifica la IP y el puerto.");
  }
}

void loop() {

  // Verificar si el cliente sigue conectado
  if (!cliente.connected()) {
    Serial.println("Conexión TCP perdida. Intentando reconectar...");
    cliente.connect(servidorIP, puertoTCP);
    delay(1000);
    return;
  }
 // Serial.println("ESPERANDO TARJETA PLS..");

  ultrasonico_test();
  galga_test();
  infrarrojo_test();

  // Leer datos del servidor
  if (cliente.available()) {
    String comando = cliente.readStringUntil('\n');
    comando.trim(); // Eliminar caracteres extra
    Serial.println("Comando recibido: " + comando);

    // Controlar el LED según el comando
    if (comando == "ENCENDER" ) {

      // Se abre casillero al mandar señal al pin 26

      if(salidaGalga && ultrasonicoDetecta && irDetecta ){
        digitalWrite(salidaPin, HIGH);
        digitalWrite(ledPin, HIGH);
        digitalWrite(ledPin12, LOW);
        Serial.println("Casillero OCUPADO");
      } /*else {
        digitalWrite(salidaPin, LOW);
        digitalWrite(ledPin, LOW);
        digitalWrite(ledPin12, HIGH);
        Serial.println("Casillero NO OCUPADO");
      }*//*

    } else if (comando == "APAGAR") {

      // Se abre casillero dando pulso al pin 26

      if (!salidaGalga && !ultrasonicoDetecta && !irDetecta) {
      digitalWrite(salidaPin, LOW);
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin12, HIGH);
      Serial.println("Casillero LIBERADO");
      } /*else {
        digitalWrite(salidaPin, HIGH);
        digitalWrite(ledPin, HIGH);
        digitalWrite(ledPin12, LOW);
        Serial.println("Casillero NO LIBERADO");
      }*//*

    } else if (comando == "ALARMA"){ // Cambiar por fución blink
      digitalWrite(ledPin2, HIGH);
      delay(500);
      digitalWrite(ledPin2, LOW);
      delay(500);
      digitalWrite(ledPin2, HIGH);
      delay(500);
      digitalWrite(ledPin2, LOW);
      delay(500);
      digitalWrite(ledPin2, HIGH);
      delay(500);
      digitalWrite(ledPin2, LOW);
      delay(500);
      Serial.println("Alarma");
    
    
    } else if (salidaPin == HIGH && ledPin == LOW){
      digitalWrite(errorSistema, HIGH);
      delay(5000);
      digitalWrite(errorSistema, LOW);
    }

  }
}*/

#include <WiFi.h>
#include "HX711.h"


// Sensores
#define INFRARROJO 2
#define TRIGGER    23
#define ECHO       22
#define GALGA_DT   19
#define GALGA_SCK  18
#define CERRADURA_VCC  26
#define CERRADURA_SGL  27

// Constantes de medición
#define DISTANCIA_MIN   7

// Configuración del Access Point
const char* ssid = "SAPE.net";
const char* password = "SAPE_2024";

// Configuración TCP
const char* servidorIP = "192.168.4.1"; // IP del servidor (AP)
const int puertoTCP = 1000;

WiFiClient cliente;

const int ledPin = 13;    //OCUPACIÓN
const int ledPin12 = 12;  // !OCUPACIÓN
const int ledPin2 = 14;   //ALARMA
const int galgaPin = 21;
const int ultrasonicoPin = 32;

float peso_umbral = 20.0;
float factor_calibracion = 2280.0;

HX711 scale(GALGA_DT,GALGA_SCK);
const int salidaPin = 4;

//volatile bool irInterrupt = false;
bool salidaGalga = false;
bool ultrasonicoDetecta = false;
bool irDetecta = false;

bool cerraduraAbierta = false;
bool sensadoStatus = false;
bool solicitudCasillero = false;

void galga_test(){       // Si da lecturas erroneas, reiniciar ESP32
  
  float lectura = scale.get_units(10);

  Serial.print("Peso: ");
  Serial.print(lectura);
  Serial.print(" KG   ||   ");

  if (lectura >= peso_umbral){
    //Serial.println("---- SENSADO DE LA GALGA ----");
    salidaGalga = true;
    digitalWrite(galgaPin, HIGH);
  } else {
    salidaGalga = false;
    digitalWrite(galgaPin,LOW);
  }
  delay(100);
  
}

void infrarrojo_test(){
  int irAux = digitalRead(INFRARROJO);
  if(!irAux){

    Serial.println("INFRARROJO NO ESTA SESANDO");
    irDetecta = false;
  } else {
    irDetecta = true;
    Serial.println("INFRARROJO SENSANDO");
    
  }
}

void ultrasonico_test(){
  long distancia = medir_distancia(TRIGGER, ECHO);
  Serial.print("Distancia:");
  Serial.print(distancia);
  Serial.print(" cm   ||   ");

  if (DISTANCIA_MIN > distancia ){
    ultrasonicoDetecta = true;
    digitalWrite(ultrasonicoPin, HIGH);
  } else{
    ultrasonicoDetecta = false;
    digitalWrite(ultrasonicoPin, LOW);
  }

  delay(100);
}

long medir_distancia(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duracion = pulseIn(echoPin, HIGH);

  if(duracion == 0 ){
    Serial.println("¡¡¡¡ ERROR: ECHO NO DETECTADO !!!!");
    return -1;
  }

  return duracion/58;
} 


void setup() {
  Serial.begin(115200);

  scale.set_scale(factor_calibracion);  // Sin factor de escala, solo lecturas crudas
  scale.tare();       // Ajustar la celda de carga a cero

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin2,LOW);
  pinMode(ledPin12, OUTPUT);
  digitalWrite(ledPin12,LOW);

  pinMode(salidaPin, OUTPUT);
  digitalWrite(salidaPin, LOW);

  pinMode(galgaPin, OUTPUT);
  digitalWrite(galgaPin,LOW);
  pinMode(ultrasonicoPin, OUTPUT);
  digitalWrite(ultrasonicoPin,LOW);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(CERRADURA_VCC, OUTPUT);
  digitalWrite(CERRADURA_VCC, LOW);
  pinMode(CERRADURA_SGL, INPUT);


  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);

  // Conectar al Access Point
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConexión establecida con el Access Point.");

  // Intentar conectarse al servidor TCP
  if (cliente.connect(servidorIP, puertoTCP)) {
    Serial.println("Conexión TCP establecida con el servidor.");
  } else {
    Serial.println("No se pudo conectar al servidor. Verifica la IP y el puerto.");
  }
}

void loop() {
  int cerraduraStatus = digitalRead(CERRADURA_SGL);

    // Verificar si el cliente sigue conectado
  if (!cliente.connected()) {
    Serial.println("Conexión TCP perdida. Intentando reconectar...");
    cliente.connect(servidorIP, puertoTCP);
    delay(1000);
    return;
  }

  ultrasonico_test();
  galga_test();
  infrarrojo_test();

  if(salidaGalga && ultrasonicoDetecta && irDetecta ){
    digitalWrite(salidaPin, HIGH);
    Serial.println("Objeto reconocido");
    sensadoStatus = true;
  } else {
    digitalWrite(salidaPin, LOW);
    Serial.println("No se encuentra objeto");
    sensadoStatus = false;
  }

  // Leer datos del servidor
  if (cliente.available()) {
    String comando = cliente.readStringUntil('\n');
    comando.trim(); // Eliminar caracteres extra
    Serial.println("Comando recibido: " + comando);

    // Controlar el LED según el comando
    if (comando == "ENCENDER") {
      cerraduraAbierta = true;
      solicitudCasillero = true;
      digitalWrite(ledPin12, LOW);
      digitalWrite(CERRADURA_VCC, HIGH);
      delay(10000);
      digitalWrite(CERRADURA_VCC, LOW);
      Serial.println("LED encendido.");
    } else if (comando == "APAGAR") {
      digitalWrite(CERRADURA_VCC, HIGH);
      delay(10000);
      digitalWrite(CERRADURA_VCC, LOW);
      cerraduraAbierta = true;
      solicitudCasillero = false;
      Serial.println("LED apagado.");
    } else if (comando == "ALARMA"){ // Cambiar por fución blink
      digitalWrite(ledPin2, HIGH);
      delay(500);
      digitalWrite(ledPin2, LOW);
      delay(500);
      digitalWrite(ledPin2, HIGH);
      delay(500);
      digitalWrite(ledPin2, LOW);
      delay(500);
      digitalWrite(ledPin2, HIGH);
      delay(500);
      digitalWrite(ledPin2, LOW);
      delay(500);
      Serial.println("Alarma");
    }
  }
  if(cerraduraStatus) {
    Serial.println("Cerrado");
    cerraduraAbierta = false;

  } else{
    Serial.println("Abierto");
    cerraduraAbierta = true;
    
  }

  if(solicitudCasillero  && !cerraduraAbierta) {
    //delay(15000);
    if(sensadoStatus) {
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin12, LOW);
      Serial.print("Ocupado");
    } /*else {
      Serial.println("No se ocupo el casillero");

    }*/
    
  } else if(!solicitudCasillero && !cerraduraAbierta){
    if(!sensadoStatus) {
      digitalWrite(ledPin, LOW);  
      digitalWrite(ledPin12, HIGH);
      Serial.println("Liberado");
    }
  } /*else{
    digitalWrite(ledPin2, HIGH);
  }*/


}
