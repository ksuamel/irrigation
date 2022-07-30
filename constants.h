#pragma once

//Soil
int SoilSensorAnalogPins[3] = { 36, 34, 32 };
int SoilSensorAirReadings[3] = { 3900, 3850, 3900};
int SoilSensorWaterReadings[3] = { 575, 500, 535};
int SoilSensorAnalogPinArrayLength = sizeof(SoilSensorAnalogPins) / sizeof(SoilSensorAnalogPins[0]);
int SoilSensorPowerPin = 26;

//Pump
const int PumpPowerPin = 15;
const int PumpTimeInSeconds = 5; //TODO: Fine tune this number; Perhaps use the datasheet of the pump to understand water flow and account for a buffer where water may need to populate the line.
const int MaxPumpRetries = 3;

//Resevoir
//int WaterLevelSensorAnalogPin = 36; //TODO: Make sure the sensor is physically placed high enough to support at least 1 watering.
int WaterLevelPowerPin = 9;

//Wifi
char* Ssid = "REPLACE_WITH_YOUR_SSID";
char* Password = "REPLACE_WITH_YOUR_PASSWORD";

//Unit
const int SleepTimeInSeconds = 20;

//Screen
const int ScreenPowerPin = 23;