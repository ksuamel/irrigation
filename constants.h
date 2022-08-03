#pragma once

//Soil
int SoilSensorAnalogPins[3] = { 36, 34, 32 };
int SoilSensorAirReadings[3] = { 3900, 3850, 3900};
int SoilSensorWaterReadings[3] = { 575, 500, 535};
int SoilSensorAnalogPinArrayLength = sizeof(SoilSensorAnalogPins) / sizeof(SoilSensorAnalogPins[0]);
int SoilSensorPowerPin = 33;

//Pump
const int PumpPowerPin = 15;
const int PumpTimeInSeconds = 240; //Water Flow = 1.5~3L/min; Water for 5min (3 * 60 = 300) + prime time (60 seconds)
const int MaxPumpRetries = 3;

//Resevoir
int WaterLevelPowerPin = 13;

//Wifi
char* Ssid = "REPLACE_WITH_YOUR_SSID";
char* Password = "REPLACE_WITH_YOUR_PASSWORD";

//Unit
const int ShortSleepTimeInSeconds = 60;
const int ActualSleepTimeInMinutes = 360;

//Screen
const int ScreenPowerPin = 23;