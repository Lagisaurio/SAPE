/*
  Software para microcontroladr ESP32 - CASILLERO
  Autor: Luis Fuentes

  Este programa controla el sistema "esclavo" de los casilleros del proyecto. Mediante un sensor ultrasónico (HC-SRD04), un transmisor y receptor infrarrojo,
  y una celda de carga, se envia la señal a la ESP32 la cual enciende un led (LED_SENSADO).
  A su vez el sistema cuenta con 3 led más: ocupado, libre y error. Estos encieden por medio de una señal externa proveniente del sistema de bahía.
  También se cuenta con el sistema de la cerradura electrica, que  de manera similar se activa con una señal externa provenieit del sistema de bahía.
  Finalmente, se tiene un sistema de alarmas, un buzzer y un led.   
*/

/* ------------ DEFINICIÓN DE PINES ------------ */
  //Infrarrojo
#define IR_PIN                15  // Pin del sensor infrarrojo
  //Ultrasonico
#define TRIGGER_PIN           23  // Pin del ESP32 conectado al pin de disparo del sensor ultrasónico
#define ECHO_PIN              22  // Pin del ESP32 conectado al pin de eco del sensor ultrasónico
  //Indicadores
#define LED_SENSADO           25   // Pin del LED que indica que hay algo en el casillero
#define LED_DISPONIBLE        13  // Pin del LED que indica que el casillero está disponible
#define LED_OCUPADO           12  // Pin del LED que indica que el casillero está ocupado
#define LED_ERROR             14  // Pin del LED que indica que la tarjeta es erronea
#define LED_ALARMA            26  // Pin del LED que funje como alarma
#define ALARMA_PIN            27  // Pin del buzzer que funje como alarma
  //Control de cerradura
#define CERRADURA_PIN         32  // Pin que alimenta el modulo analógico para abrir la cerradura
  //Pruebas
#define TESTBUTTON_PIN        2   // Pin para prueba del sistema
#define TESTALARMA_PIN        4   // Pint para probar la alarma
#define GALGA_TEST_PIN        19  // Pin de simulación de galga

/* ------------ DEFINICIÓN DE CONSTANTES NUMERICAS ------------ */
#define DISTANCIA_MINIMA      10 // Distancia mínima para encender el LED (en centímetros)

/* ------------ DEFINICIÓN DE VARIABLES ------------ */
volatile bool irInterrupt = false;
bool ultrasonicoDetecta = false;
bool infrarrojoDetecta = false;

/* ------------ DEFINICIÓN DE FUNCIONES ------------ */

// 1. Función de interrupción del infrarrojo.
void IRAM_ATTR handleIRInterrupt() {
  irInterrupt = true;
}

// 2. Función de medición de distancia.
long medirDistancia() {
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Mide el tiempo que tarda en llegar el eco
  long duracion = pulseIn(ECHO_PIN, HIGH);

  //
  if (duracion == 0) {
  Serial.println("Error: No se detectó eco.");
  return -1; // O algún valor especial para indicar error.
  }

  // Convierte el tiempo en distancia (en centímetros)
  return duracion / 58;
}

// 3. Función de medición del ultrasonico
void ultrasonico(){
    // Lectura de ultrasonico
    long distancia = medirDistancia();
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    // Si la distancia es menor que la distancia mínima, enciende el LED
    if (distancia < DISTANCIA_MINIMA) {
      ultrasonicoDetecta = true;
      Serial.println("Ultrasonico Sensando");
    }

}

//4. Función de detección de interrupción de infrarrojo
void infrarrojo(){
    // Lectura de infrarrojo
    if (irInterrupt) {
      Serial.println("Infrarrojo Sensando");
      infrarrojoDetecta = true;
      delay(500);
      irInterrupt = false; // Reinicia la bandera de interrupción
    }
}

// 5. Función de control de los leds
void controlLeds(bool ocupado, bool disponible, bool alarma, bool sensado) {
  digitalWrite(LED_OCUPADO, ocupado ? HIGH : LOW);
  digitalWrite(LED_DISPONIBLE, disponible ? HIGH : LOW);
  digitalWrite(LED_ALARMA, alarma ? HIGH : LOW);
  digitalWrite(LED_SENSADO, sensado ? HIGH : LOW);
}

/*/ 5. Función de simulación de galga con un boton.
void galga_test() {
  auxTGalga = digitalRead(GALGA_TEST_PIN);
  if (auxTGalga == HIGH){
    Serial.println("Galga Sensando");
    digitalWrite(LED_SENSADO, HIGH);
  } else {
    digitalWrite(LED_SENSADO, LOW);
  }
}       <= Esta ya no sirve aqui    */

void setup() {
  Serial.begin(115200);

  //Entradas
  pinMode(IR_PIN, INPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GALGA_TEST_PIN, INPUT);
  pinMode(TESTBUTTON_PIN, INPUT);
  pinMode(TESTALARMA_PIN, INPUT);

  //Salidas
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(LED_SENSADO, OUTPUT);
  pinMode(LED_OCUPADO, OUTPUT);
  pinMode(LED_DISPONIBLE, OUTPUT);
  pinMode(LED_ERROR, OUTPUT);
  pinMode(LED_ALARMA, OUTPUT);
  pinMode(ALARMA_PIN, OUTPUT);
  pinMode(CERRADURA_PIN, OUTPUT);
  

  attachInterrupt(digitalPinToInterrupt(IR_PIN), handleIRInterrupt, CHANGE);
  
  // Inicializa el sensor ultrasónico
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

}

void loop() {

  
  if  (digitalRead(TESTBUTTON_PIN)==HIGH){
    Serial.println("Ocupado");
    controlLeds(true, false, false, false);

    digitalWrite(CERRADURA_PIN, HIGH);
    delay(2000);
    digitalWrite(CERRADURA_PIN, LOW);

    ultrasonico();
    infrarrojo();
    if(ultrasonicoDetecta || infrarrojoDetecta){
      digitalWrite(LED_SENSADO, HIGH);
    } else{
      digitalWrite(LED_SENSADO, LOW);
    }
    //galga_test();      <= Se utilizará como modulo aparte. 
  }
  else if(digitalRead(TESTALARMA_PIN) == HIGH){
    Serial.println("Error/Alarma");
    controlLeds(false, false, true, true);
    digitalWrite(ALARMA_PIN, HIGH);

  }
  else if(digitalRead(TESTALARMA_PIN) ==LOW && digitalRead(TESTBUTTON_PIN)==LOW) { 
    Serial.println("Disponible");
    controlLeds(false, true, false, false);
    digitalWrite(ALARMA_PIN, LOW);
  }
  delay(500);         // Espera un tiempo antes de la próxima medición

}

