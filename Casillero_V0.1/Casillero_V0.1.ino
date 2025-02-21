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

/* ------------ DEFINICIÓN DE PINES ------------ */
  //Infrarrojo
#define IR_PIN                2   // Pin del ESP32 para la lectura de la señal del sensor infrarrojo

  //Ultrasonico
#define TRIGGER_PIN           23  // Pin del ESP32 conectado al pin de disparo del sensor ultrasónico
#define ECHO_PIN              22  // Pin del ESP32 conectado al pin de eco del sensor ultrasónico
#define LED_ULTRASONICO       32  // Pin del ESP32 conectado a un LED para verificar el funcionamiento del sensor ultrasonico 
#define DISTANCIA_MINIMA      7  // Distancia mínima para que el sensor ultrasonico verifique la existencia de un objeto (en centímetros)
  
  //GALGA
#define DT_GALGA              19  // Pin del ESP32 conectado al pin del controlador HX711 que refiere a la salida
#define SCK_GALGA             18  // Pin del ESP32 conectado al pin del controlador HX711 que refiere a reloje serial
#define LED_GALGA             21  // Pin del ESP32 conectado a un LED para verificar el funcionamiento de la galga

  //Indicadores visuales
#define LED_DISPONIBLE        12  // Pin del LED que indica que el casillero está disponible
#define LED_OCUPADO           13  // Pin del LED que indica que el casillero está ocupado
#define LED_ALARMA            14  // Pin del LED que funje como alarma
#define LED_SENSADO           25  // Pin del LED que indica la existencia de un objeto dentro del casillero
//#define LED_ERROR             26  // Pin del LED que indica que la tarjeta es erronea
//#define ALARMA_PIN            27  // Pin del buzzer que funje como alarma
  
  //Control de cerradura
#define CERRADURA_VCC         26  // Pin que alimenta el modulo analógico para abrir la cerradura
#define CERRADURA_CTRL        27  // Pin que indica el estado de la cerradura.


/*  //Pruebas
#define TESTBUTTON_PIN        2   // Pin para prueba del sistema
#define TESTALARMA_PIN        4   // Pint para probar la alarma
#define GALGA_TEST_PIN        19  // Pin de simulación de galga*/

/* ------------ DEFINICIÓN DE VARIABLES ------------ */
float peso_umbral          = 20.0;
float factor_calibracion   = 2280.0;

bool deteccionUltrasonico  = false;    // Variable que almacena TRUE si el ultrasonico detecto algun objeto
bool deteccionIR           = false;    // Variable que almacena TRUE si el infrarrojo detecta algun objeto
bool deteccionGalga        = false;    // Variable que almacena TRUE si la galga detecta algun objeto
bool estadoCerradura       = false;    // Variable que indica si la cerradura esta abierta (TRUE) o cerrada (FALSE)
bool estadoSensado         = false;    // Variable que indica si todos los sensores detectaron el objeto(TRUE) o si no (FALSE)
bool solicitudOcupacion    = false;    // Variable que indica si se solicita el uso de un casillero (TRUE) o si se solicita el desuso (FALSE)

HX711 scale(DT_GALGA, SCK_GALGA);      // Objeto de tipo HX711 que prepara el funcionamiento de la celda de carga

const char* ssid           = "SAPE.net";
const char* password       = "SAPE_2024";
const char* servidorIP     = "192.167.4.1";
const int puertoTCP        = 1000;

WiFiClient cliente;

/* ------------ DEFINICIÓN DE FUNCIONES ------------ */

// 1. Función de medición de distancia.
long medir_distancia(int triggerPin, int echoPin) {
  
  digitalWrite(triggerPin, HIGH);                            
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  long duracion = pulseIn(echoPin, HIGH);                    //

  if(duracion == 0 ) {                                       //
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

    int irAux = digitalRead(IR_PIN);
    
    if (!irAux) {
      Serial.println("IR NO SENSANDO");
      deteccionIR = true;

    } else {
      Serial.println("IR SENSANDO");
      deteccionIR = false;
      
    }
}

// 4. Función de detección de peso por medio de celda de carga
void galga() {

  float lectura = scale.get_units(10);
  
  Serial.print("Peso: ");
  Serial.print(lectura);
  Serial.print(" KG   ||   ");

  if (lectura >= peso_umbral) {
    digitalWrite(LED_SENSADO, HIGH);
    deteccionGalga = true;

  } else {

    digitalWrite(LED_SENSADO, LOW);
    deteccionGalga = false;

  }
}

// 5. Función de ocupación del casillero (LEDS)
void casillero_Ocupado(int ledOcupado, int ledLibre) {

  digitalWrite(ledOcupado, HIGH);
  digitalWrite(ledLibre, LOW);
}

// 6. Función de liberación del casillero (LEDS)
void casillero_Liberado(int ledOcupado, int ledLibre) {
  
  digitalWrite(ledOcupado, LOW);
  digitalWrite(ledLibre, HIGH);
}

// 7. Función para abrir el casillero
void abrir_casillero() {
  digitalWrite(CERRADURA_VCC, HIGH);
  delay(10000);
  digitalWrite(CERRADURA_VCC, LOW);
}

// X. Función de alarma del casillero
void alarma(int pinAlarma, int conteo) {
  for (int i = 0; i < conteo; i++) {
    digitalWrite(pinAlarma, HIGH);
    delay(500);
    digitalWrite(pinAlarma, LOW);
    delay(500);
  }  
}

void setup() {
  Serial.begin(115200);

  //Entradas
  pinMode(IR_PIN, INPUT);
  pinMode(ECHO_PIN, INPUT);

  //Salidas
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(LED_SENSADO, OUTPUT);
  pinMode(LED_OCUPADO, OUTPUT);
  pinMode(LED_DISPONIBLE, OUTPUT);
  pinMode(LED_ALARMA, OUTPUT);
  pinMode(CERRADURA_PIN, OUTPUT);

  pinMode(LED_GALGA, OUTPUT);
  pinMode(LED_ULTRASONICO, OUTPUT);

  // Valores iniciales
  digitalWrite(LED_OCUPADO, LOW);
  digitalWrite(LED_DISPONIBLE, HIGH);
  digitalWrite(LED_ALARMA, LOW);
  digitalWrite(LED_SENSADO, LOW);
  digitalWrite(LED_GALGA, LOW);
  //digitalWrite(LED_ERROR, LOW);

  // Inicializa el sensor ultrasónico
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  // Inicializa la celda de carga
  scale.set_scale(factor_calibracion);
  scale.tare();

  // Inicializa conexión WIFI
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConexión establecida con Access Point.");

  if(cliente.connect(servidorIP, puertoTCP)) {
    Serial.println("Conexión TCP establecida con el servidor.");
  } else {
    Serial.println("No se logro conectar al servidor. Verifica la IP y el puerto");
  }

}

void loop() { 

  if (!cliente.connected()) {
    Serial.println("Conexión TCP perdida. Intentando reconectar...");
    cliente.connect(servidorIP, puertoTCP);
    delay(1000);
    return;
  }

  ultrasonico();
  galga();
  infrarrojo();

  

  if(cliente.available()) {
    String comando = cliente.readStringUntil('\n');
    comando.trim();
    Serial.println("Comando recibido " + comando);

    if (comando == "OCUPANDO") {

      estadoCerradura = true;
      solicitudOcupacion = true;
      abrir_casillero();
      Serial.println("Casillero ocupado");

    } else if (comando == "LIBERANDO") {

      estadoCerradura = true;
      solicitudOcupación = false;
      abrir_casillero();
      Serial.println("Casillero liberado");

    } else if (comando == "ALARMA"){

      alarma(LED_ALARMA, 5);

    }
  }

  if(deteccionGalga && deteccionUltrasonico && deteccionIR) {
    digitalWrite(LED_SENSADO, HIGH);
    estadoSensado = true;
  } else {
    digitalWrite(LED_SENSADO, LOW);
    estadoSensado = false;
  }
  
  if (solicitudOcupacion && !estadoCerradura) {
    if (estadoSensado) {
      casillero_Ocupado(LED_OCUPADO, LED_DISPONIBLE);
      Serial.println ("Ocupado");
    }
  } else if(!solicitudOcupacion && !estadoCerradura) {
    if (estadoSensado) {
      casillero_Liberado(LED_OCUPADO, LED_DISPONIBLE);
      Serial.println("Liberado");
    }
  } else if(!solicitudOcupacion && estadoSensando) {
    alarma(LED_ALARMA, 5 );
    Serial.print("ERROR EN EL SISTEMA !!!");
  }

  casillero_Ocupado(LED_OCUPADO, LED_DISPONIBLE);
  casillero_Liberado(LED_OCUPADO, LED_DISPONIBLE);
}

