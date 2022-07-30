#pragma once
#include <Arduino.h>

#include "pump.h"
#include "screen.h"

namespace pump {
	void initialize(int powerPin) {
		pinMode(powerPin, OUTPUT);
		delay(100);
	}

	void run(int powerPin, int runtimeInSeconds) {
		digitalWrite(powerPin, HIGH);
		delay(runtimeInSeconds * 1000);
		digitalWrite(powerPin, LOW);
	}
}
