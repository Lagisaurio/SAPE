/*
  Software para microcontroladr ESP32 - CASILLERO
  Autor: Luis Fuentes

  Este programa controla el sistema "esclavo" de los casilleros del proyecto.
  

  Mediante un sensor ultrasónico (HC-SRD04), un transmisor y receptor infrarrojo,
  y una celda de carga con controlador HX711, se envia la señal a la ESP32 la cual enciende un led (LED_SENSADO).
  A su vez el sistema cuenta con 3 led más: ocupado, libre y error. Estos encieden por medio de una señal externa proveniente del sistema de bahía.
  También se cuenta con el sistema de la cerradura electrica, que  de manera similar se activa con una señal externa provenieit del sistema de bahía.
  Finalmente, se tiene un sistema de alarmas, un buzzer y un led.   
*/

/* ------------      LIBRERÍAS      ------------ */
#include <WiFi.h>
#include <HX711.h>
#include <LiquidCrystal_I2C.h>


/* ------------ DEFINICIÓN DE PINES ------------ */
  
  //Infrarrojo
#define IR_PIN                34                // Pin del ESP32 conectado a la salida sensor infrarrojo.

  //Ultrasonico
#define TRIGGER_PIN           23                // Pin del ESP32 conectado al pin TRIGGER del sensor ultrasónico.
#define ECHO_PIN              22                // Pin del ESP32 conectado al pin ECHO sensor ultrasónico.
#define LED_ULTRASONICO       32                // Pin del ESP32 conectado a un LED para verificar el funcionamiento del sensor ultrasonico .
#define DISTANCIA_MINIMA      7                 // Distancia mínima configurada a la que el sensor ultrasonico verifica la existencia de un objeto (en centímetros).
  
  //Celda de carga
#define DT_GALGA              19                // Pin del ESP32 conectado al pin DT del controlador HX711.
#define SCK_GALGA             18                // Pin del ESP32 conectado al pin SCK del controlador HX711.
#define LED_GALGA             21                // Pin del ESP32 conectado a un LED para verificar el funcionamiento de la celda d carga.

  //Indicadores visuales
#define LED_G                 12                // Pin del LED que indica que el casillero está disponible
#define LED_R                 13                // Pin del LED que indica que el casillero está ocupado
#define LED_B                 14                // Pin del LED que funje como alarma
#define LED_SENSADO           4                 // Pin del LED que indica la existencia de un objeto dentro del casillero
#define LED_CONEXION          2                 // Pin del buzzer que funje como alarma

  //Indicadores 
#define BUZZER                27                // Pin del buzzer que emitirá sonido cuando la puerta se encuentre abierta
  
  //Control de cerradura
#define CERRADURA_VCC         26                // Pin que alimenta el modulo analógico para abrir la cerradura
#define CERRADURA_CTRL        35                // Pin que indica el estado de la cerradura.

  //Control LCD
#define SDA_LCD               15                // Pin de SDA para el funcionamiento de la LCD
#define SCL_LCD               5                 // Pin de SCL para el funcionamiento de la LCD

  //Control Tiempo

/*  //Pruebas
#define TESTBUTTON_PIN        2   // Pin para prueba del sistema.
#define TESTALARMA_PIN        4   // Pint para probar la alarma.
#define GALGA_TEST_PIN        19  // Pin de simulación de galga.*/

/* ------------ DEFINICIÓN DE VARIABLES ------------ */

 //"Calibración"
const int umbralIR         = 1000;
const int umbralCerradura  = 1000;
float peso_umbral          = 7.0;
float factor_calibracion   = 2280.0;

 //Millis
unsigned long tCerradura = 0;
unsigned long tEsperaColocacion = 0;
unsigned long tMsjLCD = 0;

const int duracionEsperaColocacion  = 10000;
const int duracionCerradura = 10000;
const int duracionMsjLCD = 5000;

 //Detección y estados
bool deteccionUltrasonico  = false;             // Variable que indica si el ultrasonico detecto algun objeto (TRUE).
bool deteccionIR           = false;             // Variable que indica si el infrarrojo detecta algun objeto (TRUE).
bool deteccionGalga        = false;             // Variable que indica si la galga detecta algun objeto (TRUE).
bool deteccionScooter      = deteccionUltrasonico && deteccionIR && deteccionGalga;
bool esperandoScooter      = false;             // Variable que indica un estado de espera para la colocación de un Scooter (TRUE)
bool cerraduraAbierta      = false;             // Variable que indica si la cerradura esta abierta (TRUE) o cerrada (FALSE).
bool iniciarTiempoCerradura     = false;
bool estadoSensado         = false;             // Variable que indica si todos los sensores detectaron el objeto(TRUE) o si no (FALSE).
bool solicitudOcupacion    = false;             // Variable que indica si se solicita el uso de un casillero (TRUE) o si se solicita el desuso (FALSE).
bool solicitudLiberar      = false;             // Variable que indica si se ha desocupado un casillero (TRUE) o si sigue en uso (FALSE).
bool msjLCD                = false;

 //Comunicación WiFi
const char* ssid           = "SAPE.net";        // Nombre de la red a la que se conectará la tarjeta.
const char* password       = "SAPE_2025";       // Contraseña para de acceso a la red.
const char* servidorIP     = "192.168.4.1";     // IP del servidor.
const int puertoTCP        = 1000;              // Puerto del servidor.

HX711 scale(DT_GALGA, SCK_GALGA);               // Objeto de tipo HX711 que prepara el funcionamiento de la celda de carga.
LiquidCrystal_I2C lcd(0x27, 16, 2);             // Objeto de tipo LiquidCrystal_I2C que permite el funcionamiento de las pantalla LCD
WiFiClient bahiaMod;                             // Objeto tipo WiFiCliente para comunicarse con el servidor provisto por el modulo de bahía.

/* ------------ DEFINICIÓN DE FUNCIONES ------------ */

// 1. Función de medición de distancia.
long medir_distancia(int triggerPin, int echoPin) {
  
  digitalWrite(triggerPin, HIGH);                            
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  long duracion = pulseIn(echoPin, HIGH);                    

  // Si la duración es igual a cero, indica error al detectar echo
  if(duracion == 0 ) {                                       
    Serial.println("¡¡¡¡ ERROR: ECHO NO DETECTADO !!!!");
    return -1;
  }

  return duracion/58;

} 

// 2. Función de medición del ultrasonico
void ultrasonico() {

  // Lectura de ultrasonico
  long distancia = medir_distancia(TRIGGER_PIN, ECHO_PIN);
  Serial.println("-----------------------------------------------------");
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm   ||   ");

  // Si la distancia es menor que la distancia mínima, enciende el LED y cambia el valor de detección
  if (DISTANCIA_MINIMA > distancia) {
    deteccionUltrasonico = true;
    digitalWrite(LED_ULTRASONICO, HIGH);

  } else {
    deteccionUltrasonico = false;
    digitalWrite(LED_ULTRASONICO, LOW);
  
  }
  
  delay(100);
}

// 3. Función de detección de interrupción de infrarrojo
void infrarrojo(){

    int irAux = analogRead(IR_PIN);
    
    // Si no hay lectura del infrarrojo, deteccionIR es falso, sí sí hay lectura, pasa a true
    if (irAux < umbralIR) {
      Serial.println("IR NO SENSANDO");
      Serial.println("-----------------------------------------------------");
      deteccionIR = false;

    } else {
      Serial.println("IR SENSANDO");
      Serial.println("-----------------------------------------------------");
      deteccionIR = true;
      
    }
}

// 4. Función de detección de peso por medio de celda de carga
void galga() {

  // Escala la lectura a 10
  float lectura = scale.get_units(10);
  
  Serial.print("Peso: ");
  Serial.print(lectura);
  Serial.print(" KG   ||   ");

  // Si la lectura es mayor o igual al peso configurado, enciende el led y cambia detecciónGalga a TRUE.
  if (lectura >= peso_umbral) {
    digitalWrite(LED_GALGA, HIGH);
    deteccionGalga = true;

  } else {

    digitalWrite(LED_GALGA, LOW);
    deteccionGalga = false;

  }
}

// 5. Función para abrir el casillero. Envia un pulso positivo durante 10s al circuito de la cerradura.
void abrir_casillero() {
  cerraduraAbierta = true;
  iniciarTiempoCerradura = true;
  tCerradura = millis();
  digitalWrite(CERRADURA_VCC, HIGH);
  msjLCD("Abriendo  . .", "Casillero  U");
}

// 6. Función para conocer el estado del casillero.
void detectar_cerradura() {
  int cerraduraAux = analogRead(CERRADURA_CTRL);

  if (cerraduraAux > umbralCerradura){
    Serial.println("Cerradura cerrada");
    cerraduraAbierta = false;
  } else {
    Serial.println("Cerradura abierta");
    buzzer(BUZZER, 3);
  }
}

// 7. Función de encendido de leds indicando ocupación del casillero.
void casillero_Ocupado(int ledR, int ledG, int ledB) {

  digitalWrite(ledR, HIGH);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, LOW);
}

// 8. Función de encendido de leds indicando liberación del casillero.
void casillero_Liberado(int ledR, int ledG, int ledB) {
  
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledB, LOW);
}

// 9. Función de encendido de leds indicando un Error en el Sistema
void error_Sistema(int ledR, int ledG, int ledB){

  digitalWrite(ledR, HIGH);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, HIGH);
}

// 10. Función para la escritura en la LCD.
void msjLCD(String linea1, String linea2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(linea1);
  lcd.setCursor(0, 1);
  lcd.print(linea2);
  tMsjLCD = millis();
  msjLCD = true;
}

// 11. Función de control del buzzer
void buzzer(int pinBuzzer, int conteo) {
  for (int i = 0; i < conteo; i++) {
    digitalWrite(pinBuzzer, HIGH);
    delay(500);
    digitalWrite(pinBuzzer, LOW);
    delay(500);
  }  
}

// 12. Función de control de tiempo abrir cerradura
void ctrl_Tiempo_Cerradura() {
  if (iniciarTiempoCerradura && millis() - tCerradura >= duracionCerradura) {
    digitalWrite(CERRADURA_VCC, LOW);
    Serial.println("-----------------------------------------------------");
    iniciarTiempoCerradura = false;
    if (solicitudOcupacion){
      tEsperaColocacion = millis();
      esperandoScooter = true;
    }
  }
}

void ctrl_Tiempo_msjLCD(){
  if(msjLCD && millis() - tMsjLCD >= duracionMsjLCD){
    lcd.clear()
    msjLCD("Prueba de texto", "estatico");
    msjLCD = false;
  }
}
void setup() {
  Serial.begin(115200);

  //Entradas
  pinMode(IR_PIN, INPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(CERRADURA_CTRL, INPUT);

  //Salidas
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_SENSADO, OUTPUT);
  pinMode(LED_CONEXION, OUTPUT);
  pinMode(LED_GALGA, OUTPUT);
  pinMode(LED_ULTRASONICO, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(CERRADURA_VCC, OUTPUT);

  // Valores iniciales
  digitalWrite(LED_G, HIGH);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_B, LOW);
  digitalWrite(BUZZER, LOW);
  digitalWrite(LED_SENSADO, LOW);
  digitalWrite(LED_GALGA, LOW);
  digitalWrite(LED_ULTRASONICO, LOW);
  digitalWrite(LED_CONEXION, LOW);
  digitalWrite(CERRADURA_VCC, LOW);

  // Inicializa el sensor ultrasónico
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  // Inicializa la celda de carga
  scale.set_scale(factor_calibracion);
  scale.tare();

  //Inicialización de LCD
  Wire.begin(SDA_LCD, SCL_LCD);
  lcd.init();
  lcd.backlight();
  msjLCD("Inicializando..."," \(O U O)/ ");

  // Inicializa conexión WIFI
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConexión establecida con Access Point.");

  // Si el cliente se conecta al servidor y puertos designados, muestra el mesaje de "Conexión TCP..."
  if(bahiaMod.connect(servidorIP, puertoTCP)) {
    Serial.println("Conexión TCP establecida con el servidor.");
    digitalWrite(LED_CONEXION, HIGH);
    msjLCD("Conectado :D", "");
  } else {
    Serial.println("No se logro conectar al servidor. Verifica la IP y el puerto");
  }

}

void loop() { 

 /* Serial.print("< Cerradura Abierta: ");
  Serial.print(cerraduraAbierta);
  Serial.print(" > - < Sensado Estatus: ");
  Serial.print(estadoSensado);
  Serial.print(" > - < Solicitar Casillero: ");
  Serial.print(solicitudOcupacion);
  Serial.print(" > - < Liberado: ");
  Serial.print(solicitudLiberar);
  Serial.println(" >");*/

  // Si el bahiaMod no se encuentra conectado al servior, muestra el mensaje "Conexión TCP perdida..."
  if (!bahiaMod.connected()) {
    msjLCD("Conexion Perdida", "... (._.')");
    Serial.println("Conexión TCP perdida. Intentando reconectar...");
    digitalWrite(LED_CONEXION, LOW);
    while (!bahiaMod.connect(servidorIP, puertoTCP)) {
      Serial.print(".");
      delay(500);
    }
    msjLCD("Conexion", "Restablecida ^_^");
    Serial.println("\n Conexión restablecida");
    digitalWrite(LED_CONEXION, HIGH);
    return;
  }

  ctrl_Tiempo_msjLCD();

  // Inicia el conteo para que abra la cerradura (10s)
  ctrl_Tiempo_Cerradura();

  // Detecta si la cerradura está abierta o cerrada
  detectar_cerradura();

  // Se hace el sensado del objeto constantemente.
  ultrasonico();
  galga();
  infrarrojo();

  // Si el cliente esta disponible para recibir instrucciones, se envia un comando desde el modulo de bahía.
  if(bahiaMod.available()) {
    String comando = bahiaMod.readStringUntil('\n');
    comando.trim();
    Serial.println("Comando recibido " + comando);

    // Si se recibe el comando "OCUPANDO", se abre la cerradura y cambian los valores de cerraduraAbierta y solicitudOcupacion a TRUE
    if (comando == "OCUPANDO") {
      solicitudOcupacion = true;
      abrir_casillero();
      bahiaMod.println("Solicitud para ocupar casillero recibida");

      /*if(estadoSensado){
        msjLCD("Patin colocado", "Correctamente :D");
      } else if (!estadoSensado){
        msjLCD("Patin mal", "Colocado >:(");
      }*/

    // Si el comando recibido es "LIBERANDO", se abre la cerradura, y cambian los valores de cerraduraAbierta y solicitudOcupacion a TRUE y FALSE respectivamente
    } else if (comando == "LIBERANDO") {
      solicitudOcupacion = false;
      solicitudLiberar = true;
      abrir_casillero();
      Serial.println("Casillero desocupado");
      bahiaMod.println("Solicitud para desocupar casillero recibida");

    } 
  }



  // Si todos los sensores detectan un objeto, se enciende el led de sensado y cambia el valor de estadoSensado a TRUE
  if(deteccionUltrasonico && deteccionIR && deteccionGalga) {
    digitalWrite(LED_SENSADO, HIGH);
    estadoSensado = true;
  } else {
    digitalWrite(LED_SENSADO, LOW);
    estadoSensado = false;
  }
  
  // Si hay una solicitud de ocupación y la cerradura está cerrada y no se ha excedido el tiempo, llama a la función de ocupación del casillero
  if (esperandoScooter && !cerraduraAbierta) {
    if (estadoSensado) {
      casillero_Ocupado(LED_R, LED_G, LED_B);
      Serial.println ("Ocupado");
      msjLCD("Ocupado","Puede retirarse");
      bahiaMod.println("Casillero OCUPADO");
      delay(2000);
      msjLCD("Ocupado", "Vuelva pronto :(");
      esperandoScooter = false;
      
    } else if ( millis() - tEsperaColocacion >= duracionEsperaColocacion){
      solicitudOcupacion = false;
      esperandoScooter = false;
      Serial.println("No se ocupo el casillero");
      msjLCD("No se ocupo","el casillero");
      bahiaMod.println("NO OCUPADO");
    }
  } else if(!solicitudOcupacion && !cerraduraAbierta && solicitudLiberar) {
    if (!estadoSensado) {
      solicitudLiberar = false;
      casillero_Liberado(LED_R, LED_G, LED_B);
      Serial.println("Liberado");
      msjLCD("Casillero", "Dispoible :D");
      bahiaMod.println("Casillero LIBERADO");
    } else if(estadoSensado){
      abrir_casillero();
      delay (1000);
      msjLCD("Retira el patin", "ERROR 404");

    }
  } else if(!solicitudOcupacion && estadoSensado) {
    error_Sistema(LED_R, LED_G, LED_B);
    Serial.print("ERROR EN EL SISTEMA !!!");
    
  }

}


/*
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
      
    

    } else if (millis() - tiempoEspera >= duracionEspera) {
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

}*/