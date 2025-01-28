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



// Configuración del Access Point
const char* ssid = "SAPE.net";
const char* password = "SAPE_2024";

// Configuración TCP
const char* servidorIP = "192.168.4.1"; // IP del servidor (AP)
const int puertoTCP = 1000;

WiFiClient cliente;

const int ledPin = 13;
const int ledPin2 = 32;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin,LOW);

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

  // Leer datos del servidor
  if (cliente.available()) {
    String comando = cliente.readStringUntil('\n');
    comando.trim(); // Eliminar caracteres extra
    Serial.println("Comando recibido: " + comando);

    // Controlar el LED según el comando
    if (comando == "ENCENDER") {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED encendido.");
    } else if (comando == "APAGAR") {
      digitalWrite(ledPin, LOW);
      Serial.println("LED apagado.");
    }
    if (comando == "ENCENDER2"){
      digitalWrite(ledPin2, HIGH);
      Serial.println("LED encendido.");
    } else if (comando == "APAGAR2") {
      digitalWrite(ledPin2, LOW);
      Serial.println("LED apagado.");
    }
  }
}

 
