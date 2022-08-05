#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <Arduino.h>

#include "soil.h"
#include "screen.h"


namespace soil {
    
    const int ReadingsToTakePerSensor = 5;
    const MoistureLevel ThresholdLevelToWaterAt = MoistureLevel::Dry;
    std::vector<std::string> sensorValues;

    void initialize(int powerPin) {
        pinMode(powerPin, OUTPUT);
        digitalWrite(powerPin, HIGH);
        delay(100);
    }

    uint16_t GetAnalogAverageValue(int analogPin, int readingsToTake) {
        uint16_t sumValue = 0;
        for (int i = 0; i < readingsToTake; i++) {
            sumValue += analogRead(analogPin);
            delay(25);
        }

        if (sumValue == 0) {
            return 0;
        }

        return sumValue / readingsToTake;
    }

    MoistureLevel GetSensorMoistureLevel(int analogPin, int& rawDataOutput) {
        uint16_t avgValue = soil::GetAnalogAverageValue(analogPin, ReadingsToTakePerSensor);
        rawDataOutput = avgValue;
        if (avgValue > 1725) {
            return MoistureLevel::Dry;
        }

        return MoistureLevel::Wet;
    }

    bool IsDry(int analogPins[], int arrayLength) {
        sensorValues.clear();
        MoistureLevel moistureLevel;
        int rawData = 0;
        std::ostringstream ss;
        bool sensorIsDry = false;

        screen::reset();

        for (int i = 0; i < arrayLength; i++) {

            moistureLevel = GetSensorMoistureLevel(analogPins[i], rawData);
            ss << "Sensor " << i << ": " << rawData;
            screen::addLine(ss.str(), i, false);

            ss.str("");
            ss.clear();

            if (moistureLevel == ThresholdLevelToWaterAt) {
                sensorIsDry = true;
            }
        }
        screen::render();
        delay(2500);
        

        return sensorIsDry;
    }

   
    
}



