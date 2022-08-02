#pragma once
#include <Arduino.h>
#include <sstream>
#include "resevoir.h"
#include "screen.h"

namespace resevoir {
    void initialize(int powerPin) {
        pinMode(powerPin,INPUT_PULLUP);
        delay(100);
    }

    bool hasWater(int powerPin) {
        int pinOutput = digitalRead(powerPin);
        if (pinOutput == HIGH) {
            return false;
        }

        return true;
    }
}

