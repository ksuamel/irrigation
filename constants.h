#pragma once

//Soil
int SoilSensorAnalogPins[3] = { 36, 34, 32 };
int SoilSensorAnalogPinArrayLength = sizeof(SoilSensorAnalogPins) / sizeof(SoilSensorAnalogPins[0]);
int SoilSensorPowerPin = 33;

//Pump
const int PumpPowerPin = 15;
const int PumpTimeInSeconds = 180; //Water Flow = 1.5~3L/min;
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