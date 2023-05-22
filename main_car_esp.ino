#include "PS4Controller.h"

PS4CarController controller;

void setup() {
  Serial.begin(115200);
  controller.init();
  Wire.begin(SDA_PIN, SCL_PIN);   
}

void loop() {
  controller.update();
  delay(50);
}
