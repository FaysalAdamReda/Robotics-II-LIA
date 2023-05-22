#include "PS4Controller.h"

PS4CarController* PS4CarController::instance = nullptr;

PS4CarController::PS4CarController()
  : lastTimeStamp(0), x_center(CENTER_X), y_center(CENTER_Y), deadzone(DEADZONE) {
  instance = this;
}

void PS4CarController::init() {
  PS4.attach(PS4CarController::staticNotify);
  PS4.attachOnConnect(PS4CarController::staticOnConnect);
  PS4.attachOnDisconnect(PS4CarController::staticOnDisConnect);
  PS4.begin();
  Serial.println("Ready.");
}

void PS4CarController::update() {
  int JoystickAngle = 0;
  int x = map(PS4.LStickX(), -128, 127, -255, 255);
  int y = map(PS4.LStickY(), -128, 127, -255, 255);

  JoystickAngle = atan2(y - y_center, x - x_center) * 180 / PI;
  if (JoystickAngle < 0) {
    JoystickAngle = 360 + JoystickAngle;
  }

  byte mappedAngle = map(JoystickAngle, 0, 360, 0, 255);
  Serial.print(mappedAngle);
  sendValuesOverI2C(mappedAngle);
}

void PS4CarController::notify() {
  char messageString[200];
  sprintf(messageString, "%4d,%4d,%4d,%4d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d",
          PS4.LStickX(),
          PS4.LStickY(),
          PS4.RStickX(),
          PS4.RStickY(),
          PS4.Left(),
          PS4.Down(),
          PS4.Right(),
          PS4.Up(),
          PS4.Square(),
          PS4.Cross(),
          PS4.Circle(),
          PS4.Triangle(),
          PS4.L1(),
          PS4.R1(),
          PS4.L2(),
          PS4.R2(),
          PS4.Share(),
          PS4.Options(),
          PS4.PSButton(),
          PS4.Touchpad(),
          PS4.Charging(),
          PS4.Audio(),
          PS4.Mic(),
          PS4.Battery());

  //Only needed to print the message properly on serial monitor. Else we dont need it.
  if (millis() - lastTimeStamp > 50) {
    Serial.println(messageString);
    lastTimeStamp = millis();
  }
}

void PS4CarController::onConnect() {
  Serial.println("Connected!.");
}

void PS4CarController::onDisConnect() {
  Serial.println("Disconnected!.");
}

void PS4CarController::sendValuesOverI2C(byte mappedAngle) {
  Wire.beginTransmission(8);
  Wire.write(PS4.R2());
  Wire.write(PS4.L2());
  Wire.write(PS4.Up());
  Wire.write(PS4.Down());
  Wire.write(PS4.Triangle());
  Wire.write(mappedAngle);
  Wire.endTransmission();
}

void PS4CarController::staticNotify() {
  instance->notify();
}

void PS4CarController::staticOnConnect() {
  instance->onConnect();
}

void PS4CarController::staticOnDisConnect() {
  instance->onDisConnect();
}
