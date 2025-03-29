#include "HX711.h"

#define DT    19
#define SCK   18
#define LED   2

int peso_conocido = 20; //gramos

HX711 celda;

void setup() {

  Serial.begin(115000);
  celda.begin(DT, SCK);
  Serial.println("Obbtener factor de escala:");

  celda.set_scale();
  celda.tare();
  Serial.println("Colocar un peso conocido");
  digitalWrite(LED, HIGH);
  delay(10000);
  digitalWrite(LED, LOW);
  float factScale = celda.get_units(10);
  Serial.println(factScale);
  Serial.println("Dividir el valor mostrado entre el peso del objeto medido");
  
  Serial.println(factScale/peso_conocido);

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
