#ifndef CAR_H
#define CAR_H

#include <Wire.h>
#include <arduino.h>

#define MOTOR_PIN_A1 7
#define MOTOR_PIN_B1 5
#define MOTOR_PIN_A2 8
#define MOTOR_PIN_B2 6
#define MOTOR_SPEED 120

class Car {
public:
  bool rt, lt, up, down, triangle;
  int joystickAngle;

  Car() : rt(false), lt(false), up(false), down(false), triangle(false), joystickAngle(0) {}

  void init();
  void controlMotor();
  void updateControllerState(int rt, int lt, int up, int down, int triangle, uint8_t mappedAngle);

private:
  void moveMotor(bool a, int b, bool c, int d);
};

extern Car car;

#endif
