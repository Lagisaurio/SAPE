
#include <WiFi.h>
#include "HX711.h"
#include <LiquidCrystal_I2C.h>


// Sensores
#define INFRARROJO 34
#define TRIGGER    23
#define ECHO       22
#define GALGA_DT   19
#define GALGA_SCK  18
#define CERRADURA_VCC  26
#define CERRADURA_SGL  35

#define LED_CONEXION  2

// Constantes de medición
#define DISTANCIA_MIN   7

// Configuración del Access Point
const char* ssid = "SAPE.net";
const char* password = "SAPE_2024";

// Configuración TCP
const char* servidorIP = "192.168.4.1"; // IP del servidor (AP)
const int puertoTCP = 1000;

WiFiClient cliente;

const int led_R = 13;    //OCUPACIÓN
const int led_G = 12;  // !OCUPACIÓN
const int led_B = 14;   //ALARMA
const int galgaPin = 21;
const int buzzerPin = 27;
const int ultrasonicoPin = 32;

const int umbralIR = 1000;
const int umbralCerradura = 1000;
float peso_umbral = 7.0;
float factor_calibracion = 2280.0;

HX711 scale(GALGA_DT,GALGA_SCK);
const int salidaPin = 4;

LiquidCrystal_I2C lcd(0x27, 16, 2);

//volatile bool irInterrupt = false;
bool salidaGalga = false;
bool ultrasonicoDetecta = false;
bool irDetecta = false;

bool cerraduraAbierta = false;
bool sensadoStatus = false;
bool solicitudCasillero = false;
bool liberar = false;

// CODIGOS MILIS
unsigned long tiempoAperturaCerradura = 0;
bool cerraduraActivada = false;
const long duracionApertura = 10000;
const long duracionEspera = 10000;
unsigned long tiempoEspera = 0;
unsigned long auxiliar = 0;
bool esperandoScooter = false;

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
  int irAux = analogRead(INFRARROJO);

  if(irAux < umbralIR){

    Serial.print("INFRARROJO NO ESTA SESANDO    ||   ");
    irDetecta = false;
  } else {
    irDetecta = true;
    Serial.print("INFRARROJO SENSANDO    ||   ");
    
  }
}

void ultrasonico_test(){
  long distancia = medir_distancia(TRIGGER, ECHO);
  Serial.print("Distancia:");
  Serial.print(distancia);
  Serial.println(" cm");

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

void led_Ocupado(){
  digitalWrite(led_R, HIGH);
  digitalWrite(led_G, LOW);
  digitalWrite(led_B, LOW);
}

void led_Libre(){
  digitalWrite(led_R, LOW);
  digitalWrite(led_G, HIGH);
  digitalWrite(led_B, LOW);
}

void led_ErrorSistema (){
  digitalWrite(led_R, HIGH);
  digitalWrite(led_G, HIGH);
  digitalWrite(led_B, LOW);
}


void setup() {
  Serial.begin(115200);

  scale.set_scale(factor_calibracion);  // Sin factor de escala, solo lecturas crudas
  scale.tare();       // Ajustar la celda de carga a cero

  pinMode(led_R, OUTPUT);
  digitalWrite(led_R, LOW);
  pinMode(led_B, OUTPUT);
  digitalWrite(led_B,LOW);
  pinMode(led_G, OUTPUT);
  digitalWrite(led_G,LOW);
  pinMode(LED_CONEXION, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  pinMode(salidaPin, OUTPUT);
  digitalWrite(salidaPin, LOW);
  

  pinMode(galgaPin, OUTPUT);
  digitalWrite(galgaPin,LOW);
  pinMode(ultrasonicoPin, OUTPUT);
  digitalWrite(ultrasonicoPin,LOW);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(INFRARROJO, INPUT);
  pinMode(CERRADURA_VCC, OUTPUT);
  digitalWrite(CERRADURA_VCC, LOW);
  pinMode(CERRADURA_SGL, INPUT);

  Wire.begin(15,5);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");


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
    digitalWrite(LED_CONEXION, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Conectado...  :D"); 
    led_Libre();
  } else {
    Serial.println("No se pudo conectar al servidor. Verifica la IP y el puerto.");
  }
}

void loop() {
  int cerraduraStatus = analogRead(CERRADURA_SGL);

  Serial.print("< Cerradura Abierta: ");
  Serial.print(cerraduraAbierta);
  Serial.print("> - < Sensado Estatus: ");
  Serial.print(sensadoStatus);
  Serial.print("> - < Solicitar Casillero: ");
  Serial.print(solicitudCasillero);
  Serial.print("> - < Liberado: ");
  Serial.print(sensadoStatus);
  Serial.println(">");

    // Verificar si el cliente sigue conectado
  if (!cliente.connected()) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Conexion Perdida");
    lcd.setCursor(0,1);
    lcd.print("... (._.')");
    digitalWrite(LED_CONEXION, LOW);
    Serial.println("Conexión TCP perdida. Intentando reconectar...");
    cliente.connect(servidorIP, puertoTCP);
    digitalWrite(LED_CONEXION, HIGH);
    delay(1000);
    return;
  }

  if (cerraduraActivada && millis() - tiempoAperturaCerradura >= duracionApertura) {
  digitalWrite(CERRADURA_VCC, LOW);
  cerraduraActivada = false;
  if (solicitudCasillero){
    tiempoEspera = millis();
    esperandoScooter = true;
  }
}

  // Leer datos del servidor
  if (cliente.available()) {
    String comando = cliente.readStringUntil('\n');
    comando.trim(); // Eliminar caracteres extra
    Serial.println("Comando recibido: " + comando);

    // Controlar el LED según el comando
    if (comando == "OCUPANDO") {
      cerraduraAbierta = true;
      solicitudCasillero = true;
      digitalWrite(CERRADURA_VCC, HIGH);
      cerraduraActivada = true;
      tiempoAperturaCerradura = millis();
      Serial.println("----------------- LED encendido. ------------------------------");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Abriendo  . .");
      lcd.setCursor(0,1);
      lcd.print("Casillero  U");
      cliente.println("Led ENCENDIDO --- --- ");
      
      
    } else if (comando == "LIBERANDO") {
      digitalWrite(CERRADURA_VCC, HIGH);
      cerraduraActivada = true;
      tiempoAperturaCerradura = millis();
      cerraduraAbierta = true;
      solicitudCasillero = false;
      liberar = true;
      Serial.println("---------------------------- LED apagado.--------------------------------");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Abriendo  . .");
      lcd.setCursor(0,1);
      lcd.print("Casillero  U");
      cliente.println("LED APAGADO --- ---");
    }
  }
  if(cerraduraStatus > umbralCerradura) {
    Serial.println("Cerrado");
    cerraduraAbierta = false;
  } else{
    Serial.println("Abierto");
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);

    cerraduraAbierta = true;
  }

  galga_test();
  infrarrojo_test();
  ultrasonico_test();

  if(salidaGalga && ultrasonicoDetecta && irDetecta ){
    digitalWrite(salidaPin, HIGH);
    Serial.println("Objeto reconocido");
    sensadoStatus = true;
  
  } else {
    digitalWrite(salidaPin, LOW);
    Serial.println("No se encuentra objeto");
    sensadoStatus = false;
  }

  if(esperandoScooter  && !cerraduraAbierta) {
    Serial.print("--------------- T I E M P O S: ");
    Serial.print(tiempoEspera);
    Serial.print(" --- ");
    auxiliar = millis()- tiempoEspera;
    Serial.print(auxiliar);
    Serial.print(" ------------------");

    if(sensadoStatus) {
      led_Ocupado();
      Serial.print("Ocupado");

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Patin Colocado");
      lcd.setCursor(0,1);
      lcd.print("Correctamente :D");
      delay(500);
      cliente.println("CASILLERO OCUPADO");

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Ocupado");
      lcd.setCursor(0,1);
      lcd.print("Puede retirarse");
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("No disponible");
      lcd.setCursor(0,1);
      lcd.print("Vuelva pronto :(");

      esperandoScooter = false;
      solicitudCasillero = false;

    } /*else if(!sensadoStatus){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Patin mal");
      lcd.setCursor(0,1);
      lcd.print("Colocado >:L");
      
    

    } */else if (millis() - tiempoEspera >= duracionEspera) {
      Serial.println("No se ocupo el casillero");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("No se Ocupo casillero");
      solicitudCasillero = false;
      esperandoScooter = false;
      cliente.println("DESOCUPADO");


    }
    
  } else if(!solicitudCasillero && !cerraduraAbierta && liberar){
    if(!sensadoStatus) {
      led_Libre();
      //led_ErrorSistema();
      Serial.print("Liberado");
      Serial.println(liberar);
      cliente.println("CASILLERO LIBERADO");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Casillero");
      lcd.setCursor(0,1);
      lcd.print("Disponible 8D");
      liberar = false;
    }
  } else if(!solicitudCasillero && sensadoStatus) {
    led_ErrorSistema();
    Serial.println("Error en el Sistema");
  }

}



