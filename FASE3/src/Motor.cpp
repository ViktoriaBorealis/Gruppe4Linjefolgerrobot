//
// Created by Vikky on 09/02/2026.
//
#include "Motor.hpp"

Motor::Motor(int stby, int pwm, int dir1, int dir2)
    : stby(stby), pwm(pwm), dir1(dir1), dir2(dir2) {

    pinMode(dir1, OUTPUT);
    pinMode(dir2, OUTPUT);
    pinMode(stby, OUTPUT);
    pinMode(pwm, OUTPUT);
}

void Motor::panikkSnu(bool framover) {
    digitalWrite(dir1, framover ? HIGH : LOW);
    digitalWrite(dir2, framover ? LOW : HIGH);
    analogWrite(pwm, 255);
}

void Motor::drive(int power) {
    power *= directionalMultiplier;
    digitalWrite(stby, HIGH);

    digitalWrite(dir1, forward ? HIGH : LOW);
    digitalWrite(dir2, forward ? LOW : HIGH);

    int out = constrain(power + drivingVariable, 0, 255);
    analogWrite(pwm, out * 0.7);
}
