/*
  Codigo de servidor ESP32

*/

#include <WiFi.h>
//#include <WebServer.h>
/*#include <WiFiAP.h>*/

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

 
