#include "M.h"

MotorController motorController(7, 5, 8, 6);

void setup() {
  // nothing here
}

void loop() {
  // Call the desired function to control the motors
  motorController.Forward();
  delay(2000);
  motorController.Backward();
  delay(2000);
  motorController.Stop();
  delay(2000);
  motorController.Left();
  delay(2000);
  motorController.Right();
  delay(2000);
  motorController.LeftForward();
  delay(2000);
  motorController.LeftBackward();
  delay(2000);
  motorController.RightForward();
  delay(2000);
  motorController.RightBackward();
  delay(2000);
}
