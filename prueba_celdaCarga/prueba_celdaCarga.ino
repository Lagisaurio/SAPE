
#include "HX711.h"

#define DT 19  // GPIO del ESP32 conectado a DT del HX711
#define SCK 18 // GPIO del ESP32 conectado a SCK del HX711
#define LED 2  // GPIO del ESP32 donde está el LED (puedes cambiarlo)

HX711 celda(DT, SCK);

float factor_escala = -555.85;
float peso_umbral = 7.0;

void setup(){
  Serial.begin(115200);
  Serial.println("Celda de carga");
  celda.begin(DT, SCK);

  celda.set_scale(factor_escala);
  celda.tare();
}

void loop(){
  int promedio = celda.get_units(10);

  Serial.print("Valor en gramos: ");
  Serial.println(promedio);

  if (promedio >= peso_umbral) {
      digitalWrite(LED, HIGH); // Enciende el LED
  } else {
      digitalWrite(LED, LOW); // Apaga el LED
  }

}

/*
// ------------------------------------- Prueba 1 ---------------------------------------------


float peso_umbral = 50000.0; // Umbral en kg para encender el LED

void setup() {
    Serial.begin(115200); // Mejor velocidad para ESP32
    pinMode(LED, OUTPUT);
    
    scale.begin(DT, SCK);
    scale.set_scale();  // Sin factor de escala, solo lecturas crudas
    scale.tare();       // Ajustar la celda de carga a cero
    
    Serial.println("Listo. Coloca peso en la celda.");
}

void loop() {
    if (scale.is_ready()) { // Verifica si el HX711 está listo
        float lectura = scale.get_units(); // Obtener el valor de la celda de carga
        
        Serial.print("Peso: ");
        Serial.print(lectura);
        Serial.println(" kg");

        if (lectura >= peso_umbral) {
            digitalWrite(LED, HIGH); // Enciende el LED
        } else {
            digitalWrite(LED, LOW); // Apaga el LED
        }
    } else {
        Serial.println("Esperando HX711...");
    }

    delay(500); // Esperar medio segundo para evitar lecturas rápidas
}*/
/*
// ------------------------------------------ PRUEBA 2 -----------------------------------------------------


float peso_umbral = 20.0;   // Umbral en kg para encender el LED
float calibration_factor = 2280.0; // Ajusta este valor según la calibración

void setup() {
    Serial.begin(115200);  // ESP32 soporta velocidades más altas
    pinMode(LED, OUTPUT);
    
    scale.set_scale(calibration_factor);  // Configura el factor de escala (ajustar manualmente)
    scale.tare();  // Ajusta la celda de carga a cero
    
    Serial.println("Listo. Coloca peso en la celda.");
}

void loop() {
    float lectura = scale.get_units(10); // Obtiene el promedio de 10 mediciones para reducir ruido
    
    Serial.print("Peso: ");
    Serial.print(lectura);
    Serial.println(" kg");

    if (lectura >= peso_umbral) {
        digitalWrite(LED, HIGH); // Enciende el LED
    } else {
        digitalWrite(LED, LOW); // Apaga el LED
    }

    delay(10); // Pequeña pausa para estabilidad
}*/