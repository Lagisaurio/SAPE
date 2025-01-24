#include <WiFi.h>

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
}
