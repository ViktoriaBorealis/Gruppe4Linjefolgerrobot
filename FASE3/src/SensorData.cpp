//
// Created by Vikky on 09/02/2026.
#include "SensorData.hpp"

SensorData::SensorData() {
    qtr.setTypeRC();
    qtr.setSensorPins(
        (const uint8_t[]){A0,A0,A0,A0,A0,A0,A0,A0,A0,A0,A0,A0,A0},
        size
    );

    for (uint8_t i = 0; i < 250; i++) {
        qtr.calibrate();
        delay(20);
    }
}

float SensorData::seData() {
    float avik = 0;
    allWhite = true;

    for (int v : mostRecentData) {
        if (v != 0) allWhite = false;
        avik += v;
    }
    return avik;
}

void SensorData::update() {
    /*
    digitalWrite(D2,HIGH);
    digitalWrite(D4,HIGH);
    digitalWrite(D7,HIGH);
    digitalWrite(D8,HIGH);
    digitalWrite(D9,HIGH);
    digitalWrite(D5,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D3,HIGH);
    digitalWrite(PC15,HIGH);
    digitalWrite(A0,HIGH);
    digitalWrite(A5,HIGH);
*/
    uint16_t sensors[size];
    qtr.readLineBlack(sensors);

    int threshold = 400;
    int zeroCount = 0;
    int weightedSum = 0;

    for (int i = 0; i < size; i++) {
        mostRecentData[i] = (sensors[i] < threshold) ? 1 : 0;
        if (mostRecentData[i] == 0) zeroCount++;

        mostRecentData[i] *= numberthingy[i];
        weightedSum += mostRecentData[i];
    }

    if (zeroCount < 6) {
        if (weightedSum > 0) flagFloat = 1;
        else if (weightedSum < 0) flagFloat = -1;
    }

    allWhite = (weightedSum == 0);
}

bool SensorData::checkForAllWhite() {
    return allWhite;
}

float SensorData::getFlag() {
    return flagFloat;
}
