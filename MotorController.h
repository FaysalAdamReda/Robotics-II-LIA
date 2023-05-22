

#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <Arduino.h>

class MotorController {
public:
    MotorController(int AIN1, int PWMA, int BIN1, int PWMB);
    void forward();
    void stop();
    void backward();
    void left();
    void right();
    void leftForward();
    void leftBackward();
    void rightForward();
    void rightBackward();
private:
    int _AIN1;
    int _PWMA;
    int _BIN1;
    int _PWMB;
};

#endif
