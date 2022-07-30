#pragma once
#include <Arduino.h>
#include <sstream>
#include "resevoir.h"
#include "screen.h"

namespace resevoir {
    void initialize(int powerPin) {
        //pinMode(powerPin, OUTPUT);
        //digitalWrite(powerPin, HIGH);
        delay(100);
    }

    bool isEmpty(int powerPin) {
        delay(1000);
        return false;
    }
}

