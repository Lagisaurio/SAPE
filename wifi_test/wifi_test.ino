/*
  Codigo de servidor ESP32

*/
/*
#include <WiFi.h>
//#include <WebServer.h>
/*#include <WiFiAP.h>

#define BOTON 27

// Se crea la red de Access Point (AP)
const char* ssid = "SAPE.net";
const char* password = "SAPE_2024";

// Configuración TCP
const char* servidorIP = "192.168.4.1";
const int puertoTCP = 1000;

WiFiClient cliente;

bool lastState = LOW;


void setup() {
  Serial.begin(115200);
  
  //Puertos
  pinMode(BOTON, INPUT_PULLUP);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay (500);
    Serial.print(".");
  }

  Serial.println("Conexión establcia con el punto de acceso...");

  if(cliente.connect(servidorIP, puertoTCP)){
    Serial.println("Conexión TCP establecida con el servidor.");
  } else {
    Serial.println("No se logro conectar con el servidor");
  }
}

void loop() {
  
  if (!cliente.connected()){
    Serial.println("Conexión perdida... Reconectado...");
    cliente.connect(servidorIP, puertoTCP);
    delay(1000);
    return;
  }

  bool actualState = digitalRead(BOTON) == LOW;
  if(actualState != lastState){
    lastState = actualState;

    if(actualState){
      cliente.println("ENCENDER");
      Serial.println("Commado enviado: ENCENDER");
    } else {
      cliente.println("APAGAR");
      Serial.println("Comando enviado: APAGAR");
    }
  }
}
*/

//Receptor

#include <WiFi.h>
#include "HX711.h"


// Sensores
#define INFRARROJO 2
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
  Serial.println(" KG");

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

    //Serial.println("**** INFRARROJO NO ESTA SESANDO ****");
    irDetecta = false;
  } else {
    irDetecta = true;
    //Serial.println("¡¡¡¡ INFRARROJO SENSANDO !!!!");
    
  }
}

void ultrasonico_test(){
  long distancia = medir_distancia(TRIGGER, ECHO);
  Serial.print("++++ Distancia Detectada:");
  Serial.print(distancia);
  Serial.println(" cm ++++");

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


  ultrasonico_test();
  galga_test();
  infrarrojo_test();

  if(salidaGalga && ultrasonicoDetecta && irDetecta ){
    digitalWrite(salidaPin, HIGH);
  } else {
    digitalWrite(salidaPin, LOW);
  }

    // Verificar si el cliente sigue conectado
  if (!cliente.connected()) {
    Serial.println("Conexión TCP perdida. Intentando reconectar...");
    cliente.connect(servidorIP, puertoTCP);
    delay(1000);
    return;
  }

  // Leer datos del servidor
  if (cliente.available()) {
    String comando = cliente.readStringUntil('\n');
    comando.trim(); // Eliminar caracteres extra
    Serial.println("Comando recibido: " + comando);

    // Controlar el LED según el comando
    if (comando == "ENCENDER") {
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin12, LOW);
      Serial.println("LED encendido.");
    } else if (comando == "APAGAR") {
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin12, HIGH);
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
}
