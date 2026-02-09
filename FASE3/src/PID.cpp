//
// Created by Vikky on 09/02/2026.
//
#include "PID.hpp"

static float forgjeAvik = 0;
static float integral = 0;

static const float K_P = 3.75;
static const float K_I = 0;
static const float K_D = 0.002;

float PID2(float avik) {
    integral += avik;
    float derivative = avik - forgjeAvik;

    float output = K_P * avik + K_I * integral + K_D * derivative;
    forgjeAvik = avik;

    if (output > 250) {
        output = 249;
        integral -= avik;
    }
    else if (output < -250) {
        output = -249;
        integral += avik;
    }
    return output;
}
