//
// Created by Vikky on 09/02/2026.
//

#ifndef FASE3_MOTOR_HPP
#define FASE3_MOTOR_HPP
#include <Arduino.h>

class Motor {
public:
    Motor(int stby, int pwm, int dir1, int dir2);

    void drive(int power);
    void panikkSnu(bool framover);

    int directionalMultiplier = 1;
    bool forward = true;

private:
    int stby;
    int pwm;
    int dir1;
    int dir2;

    float drivingVariable = 255;
};
#endif //FASE3_MOTOR_HPP