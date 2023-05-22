

#include "MotorController.h"

MotorController::MotorController(int AIN1, int PWMA, int BIN1, int PWMB) {
    _AIN1 = AIN1;
    _PWMA = PWMA;
    _BIN1 = BIN1;
    _PWMB = PWMB;

    for (int i = 3; i < 9; i++) {
        pinMode(i, OUTPUT);
    }

    digitalWrite(3, 1);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
}

void MotorController::forward() {
    digitalWrite(_AIN1, 1);
    digitalWrite(_BIN1, 1);
    analogWrite(_PWMA, 255);
    analogWrite(_PWMB, 255);
}

void MotorController::stop() {
    digitalWrite(_AIN1, 1);
    digitalWrite(_BIN1, 1);
    analogWrite(_PWMA, 0);
    analogWrite(_PWMB, 0);
}

void MotorController::backward() {
    digitalWrite(_AIN1, 0);
    digitalWrite(_BIN1, 0);
    analogWrite(_PWMA, 255);
    analogWrite(_PWMB, 255);
}

void MotorController::left() {
    digitalWrite(_AIN1, 1);
    digitalWrite(_BIN1, 0);
    analogWrite(_PWMA, 255);
    analogWrite(_PWMB, 255);
}

void MotorController::right() {
    digitalWrite(_AIN1, 0);
    digitalWrite(_BIN1, 1);
    analogWrite(_PWMA, 255);
    analogWrite(_PWMB, 255);
}

void MotorController::leftForward() {
    digitalWrite(_AIN1, 1);
    digitalWrite(_BIN1, 1);
    analogWrite(_PWMA, 255);
    analogWrite(_PWMB, 126);
}

void MotorController::leftBackward() {
    digitalWrite(_AIN1, 0);
    digitalWrite(_BIN1, 0);
    analogWrite(_PWMA, 255);
    analogWrite(_PWMB, 126);
}

void MotorController::rightForward() {
    digitalWrite(_AIN1, 1);
    digitalWrite(_BIN1, 1);
    analogWrite(_PWMA, 126);
    analogWrite(_PWMB, 255);
}

void MotorController::rightBackward() {
    digitalWrite(_AIN1, 0);
    digitalWrite(_BIN1, 0);
    analogWrite(_PWMA, 126);
    analogWrite(_PWMB, 255);
}
