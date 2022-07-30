#pragma once

namespace soil {
    enum MoistureLevel {
        Dry = 0,
        MostlyDry,
        Wet,
        VeryWet,
        Unknown,
    };

	void initialize(int powerPin);
	MoistureLevel GetSensorMoistureLevel(int analogPin, int pinAirReading, int pinWaterReading, int& rawDataOutput);
	bool IsDry(int analogPins[], int pinAirReadings[], int pinWaterReadings[], int arrayLength);
}



