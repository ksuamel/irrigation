

#include <Wire.h>
#include <splash.h>

#include "constants.h"
#include "screen.h"
#include "wifi.h"
#include "resevoir.h"
#include "soil.h"
#include "pump.h"
#include "unit.h"

void app(){
    unit::print_wakeup_reason();
    // connectToWifi(Ssid, Password);
  
    screen::update("Checking water.");
    if(resevoir::isEmpty(WaterLevelPowerPin))
    {
        screen::update("Out of water!");
        delay(5000);
        unit::sleep(SleepTimeInSeconds);
        return;
    }

    int attempts = 0;
    while (
        soil::IsDry(SoilSensorAnalogPins, SoilSensorAirReadings, SoilSensorWaterReadings, SoilSensorAnalogPinArrayLength) && 
        !resevoir::isEmpty(WaterLevelPowerPin))
    {
        attempts++;
        if (attempts > MaxPumpRetries) {
            break;
        }
        screen::update("Pumping water..");
        pump::run(PumpPowerPin, PumpTimeInSeconds);
        
    }

    screen::update("Going to sleep..");
    delay(2000);
    unit::sleep(SleepTimeInSeconds);
}
 
void setup() {
    Serial.begin(9600);
    while (!Serial) { delay(500); }

    resevoir::initialize(WaterLevelPowerPin);
    pump::initialize(PumpPowerPin);
    soil::initialize(SoilSensorPowerPin);
    screen::initialize(ScreenPowerPin);
    app();
}

void loop() {        
}
