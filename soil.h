#pragma once

namespace soil {
    enum MoistureLevel {
        Dry = 0,
        Wet
    };

	void initialize(int powerPin);
	MoistureLevel GetSensorMoistureLevel(int analogPin, int& rawDataOutput);
	bool IsDry(int analogPins[], int arrayLength);
}



