#include "Car.h"

Car car;

void Car::init() {
  for (int i = 6; i < 9; i++) {
    pinMode(i, OUTPUT);
  }
}

void Car::controlMotor() {
  switch (rt) {
    case 1:
      switch (joystickAngle) {
        case 0 ... 19:
        case 342 ... 361:
          moveMotor(1, 25, 1, MOTOR_SPEED);
          break;
        case 20 ... 45:
          moveMotor(1, 40, 1, MOTOR_SPEED);
          break;
        case 46 ... 71:
          moveMotor(1, 60, 1, MOTOR_SPEED);
          break;
        case 72 ... 112:
          moveMotor(1, MOTOR_SPEED, 1, MOTOR_SPEED);
          break;
        case 113 ... 138:
          moveMotor(1, MOTOR_SPEED, 1, 60);
          break;
        case 139 ... 164:
          moveMotor(1, MOTOR_SPEED, 1, 40);
          break;
        case 165 ... 205:
          moveMotor(1, MOTOR_SPEED, 1, 25);
          break;
      }
      break;
    default:
      moveMotor(1, 0, 1, 0);
      break;
  }

  switch (lt) {
    case 1:
      moveMotor(0, MOTOR_SPEED, 0, MOTOR_SPEED);
      break;
  }

  Serial.print("RT: ");
  Serial.print(rt);
  Serial.print("\t");
  Serial.print("LT: ");
  Serial.print(lt);
  Serial.print("\t");
  Serial.print("UP: ");
  Serial.print(up);
  Serial.print("\t");
  Serial.print("DOWN: ");
  Serial.print(down);
  Serial.print("\t");
  Serial.print("TRIANGLE: ");
  Serial.print(triangle);
  Serial.print("\t");
  Serial.print("\tAngle: ");
  Serial.println(joystickAngle);
  Serial.println();
  digitalWrite(7, rt);
}

void Car::updateControllerState(int rt, int lt, int up, int down, int triangle, uint8_t mappedAngle) {
  this->rt = rt;
  this->lt = lt;
  this->up = up;
  this->down = down;
  this->triangle = triangle;
  this->joystickAngle = map(mappedAngle, 0, 255, 0, 360);
}

void Car::moveMotor(bool a, int b, bool c, int d) {
  digitalWrite(MOTOR_PIN_A1, a);
  digitalWrite(MOTOR_PIN_A2, c);

  analogWrite(MOTOR_PIN_B1, b);
  analogWrite(MOTOR_PIN_B2, d);
}
