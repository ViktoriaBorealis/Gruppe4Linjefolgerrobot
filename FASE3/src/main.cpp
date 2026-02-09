#include <Arduino.h>
//#include "SensorData.hpp"
//#include "Motor.hpp"
//#include "PID.hpp"

//Motor motor1(A0, A0, A0, A0);
//Motor motor2(A0, A0, A0, A0);
//SensorData sensor;

//int mengdepanikk = 0;

void setup() {
    //motor1.directionalMultiplier = -1;
    Serial.begin(9600);
}

void loop() {
    /*
    sensor.update();

    if (sensor.checkForAllWhite()) {
        mengdepanikk++;

        if (mengdepanikk > 3) {
            float vei = sensor.getFlag();
            motor1.panikkSnu(vei > 0);
            motor2.panikkSnu(vei < 0);
            mengdepanikk = 0;
        }
    } else {
        float avik = sensor.seData();
        float response = PID2(-avik);

        motor1.drive(response);
        motor2.drive(response);

        mengdepanikk = 0;
    }
    */
    Serial.println("Hello World");
}
