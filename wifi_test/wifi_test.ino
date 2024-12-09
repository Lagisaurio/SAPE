/*
  Codigo de servidor ESP32

*/

#include <WiFi.h>
//#include <WebServer.h>
#include <WiFiAP.h>

#define LED_BUILTIN 13

// Se crea la red de Access Point (AP)
const char* ssid = "SAPE.net";
const char* password = "SAPE_2024";

bool led_on = false;
//WebServer server(80);

void setup() {
  //Puertos
  pinMode(LED_BUILTIN, OUTPUT);

  //
  Serial.begin(115200);
  Serial.println();
  Serial.println("Configurando Access Point :D");
    
  // put your setup code here, to run once:
  WiFi.softAP(ssid, password);                      // Configura la red con el nombre y contraseña previamente declarados (ln 12)
  IPAddress AP_IP = WiFi.softAPIP();                // Obtiene la IP del dispositivo Servidor 
  Serial.print("Esta es la IP: ");                  
  Serial.println(AP_IP);                            // Muestra la IP de la red

}

void loop() {
  // put your main code here, to run repeatedly:
  // Print the number of conections
    Serial.print("Dispositivos conectados: ");
    Serial.println(WiFi.softAPgetStationNum());
    // Blink led
    if (led_on == false) {
        digitalWrite(LED_BUILTIN, HIGH);
    }
    else {
        digitalWrite(LED_BUILTIN, LOW);
    }
    led_on = !led_on;
    delay(500);

}
