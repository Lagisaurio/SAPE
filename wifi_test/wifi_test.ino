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


// Sensores
#define INFRARROJO 15
#define TRIGGER    23
#define ECHO       22
#define GALGA      19

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
const int irPin = 33;

const int salidaPin = 4;

volatile bool irInterrupt = false;
bool salidaGalga = false;
bool ultrasonicoDetecta = false;

void galga_test(){
  int galgaAux = digitalRead(GALGA);
  if (galgaAux){
    Serial.println("---- SENSADO DE LA GALGA ----");
    salidaGalga = true;
    digitalWrite(galgaPin, HIGH);
  } else {
    salidaGalga = false;
    digitalWrite(galgaPin,LOW);
  }
}

void IRAM_ATTR handleIRInterrupt() {
  irInterrupt = true;
}

void infrarrojo_test(){
  if(irInterrupt){
    digitalWrite(irPin, HIGH);
    Serial.println("**** Infrarrojo Sensado ****");
    delay(500);
    irInterrupt = false;
  } else {
    Serial.println("¡¡¡ INFRARROJO DEJO DE SENSAR !!!");
    digitalWrite(irPin, LOW);
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

  delay(1000);
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
  pinMode(irPin, OUTPUT);
  digitalWrite(irPin,LOW);
  pinMode(INFRARROJO, INPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);


  attachInterrupt(digitalPinToInterrupt(INFRARROJO), handleIRInterrupt, CHANGE);

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

  if(salidaGalga && ultrasonicoDetecta){
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
