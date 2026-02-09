//
// Created by Vikky on 09/02/2026.
//

#ifndef FASE3_SENSORDATA_HPP
#define FASE3_SENSORDATA_HPP
#include <Arduino.h>
#include <QTRSensors.h>

class SensorData {
public:
    SensorData();

    void update();
    float seData();
    bool checkForAllWhite();
    float getFlag();

private:
    static const int size = 13;

    QTRSensors qtr;
    int mostRecentData[size];
    int numberthingy[size] = {50,30,25,15,8,2,0,-2,-8,-15,-25,-30,-50};

    bool allWhite = false;
    float flagFloat = 0;
};
#endif //FASE3_SENSORDATA_HPP