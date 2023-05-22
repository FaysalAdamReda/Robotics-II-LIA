#include "Car.h"

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(115200);
  car.init();
  digitalWrite(3, OUTPUT);
  pinMode(3, 1);
}

void loop() {
  car.controlMotor();
}

void receiveEvent(int bytes) {
  if (bytes == 6) {
    car.updateControllerState(Wire.read(), Wire.read(), Wire.read(), Wire.read(), Wire.read(), Wire.read());
  }
}
