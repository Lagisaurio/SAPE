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
#define DURACION_ESPERA_COLOCACION 1000;
#define DURACION_CERRADURA 1000;
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
      deteccionIR = false;

    } else {
      Serial.println("IR SENSANDO");
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
    digitalWrite(LED_SENSADO, HIGH);
    deteccionGalga = true;

  } else {

    digitalWrite(LED_SENSADO, LOW);
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
  digitalWrite(ledG, HIGH);
  digitalWrite(ledB, LOW);
}

// 10. Función para la escritura en la LCD.
void msjLCD(String linea1, String linea2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(linea1);
  lcd.setCursor(0, 1);
  lcd.print(linea2);
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
void ctrl_Tiempo_Cerradura(){
  if (iniciarTiempoCerradura && millis() - tCerradura >= DURACION_CERRADURA){
    digitalWrite(CERRADURA_VCC, LOW);
    iniciarTiempoCerradura = false;
    if (solicitudOcupacion){
      tEsperaColocacion = millis();
      esperandoScooter = true;
    }
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
  digitalWrite(LED_GALGA, LOW);
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
    msjLCD("Connectado... :D", "");
  } else {
    Serial.println("No se logro conectar al servidor. Verifica la IP y el puerto");
  }

}

void loop() { 

  Serial.print("< Cerradura Abierta: ");
  Serial.print(cerraduraAbierta);
  Serial.print(" > - < Sensado Estatus: ");
  Serial.print(estadoSensado);
  Serial.print(" > - < Solicitar Casillero: ");
  Serial.print(solicitudOcupacion);
  Serial.print(" > - < Liberado: ");
  Serial.print(solicitudLiberar);
  Serial.println(" >");

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

  // Detecta si la cerradura está abierta o cerrada
  detectar_cerradura();

  // Inicia el conteo para que abra la cerradura (10s)
  ctrl_Tiempo_Cerradura();

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
  if(deteccionScooter) {
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
      msjLCD("OCUPADO","Puede retirarse");
      bahiaMod.println("Casillero OCUPADO");
      delay(2000);
      msjLCD("No disponible", "Vuelva pronto :(");
      
    } else if (millis() - tEsperaColocacion => DURACION_ESPERA_COLOCACION){
      solicitudOcupacion = false;
      esperandoScooter = false;
      Serial.println("No se ocupo el casillero");
      msjLCD("No se ocupo el casillero","");
      bahiaMod.println("NO OCUPADO");
    }
  } else if(!solicitudOcupacion && !cerraduraAbierta && solicitudLiberar) {
    if (!estadoSensado) {
      solicitudLiberar = false;
      casillero_Liberado(LED_R, LED_G, LED_B);
      Serial.println("Liberado");
      msjLCD("Casillero", "Dispoible 8D");
      bahiaMod.println("Casillero LIBERADO");
    }
  } else if(!solicitudOcupacion && estadoSensado) {
    error_Sistema(LED_R, LED_G, LED_B);
    Serial.print("ERROR EN EL SISTEMA !!!");
  }

}

