

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

    if (!unit::readyToWake(ShortSleepTimeInSeconds, ActualSleepTimeInMinutes)) {
        Serial.println("Not ready to wake");
        unit::sleep(ShortSleepTimeInSeconds);
        return;
    }
  
    screen::update("Checking water.");
    if(!resevoir::hasWater(WaterLevelPowerPin))
    {
        screen::update("Out of water!");
        delay(15000);
        unit::sleep(ShortSleepTimeInSeconds);
        return;
    }

    int attempts = 0;
    while (
        soil::IsDry(SoilSensorAnalogPins, SoilSensorAnalogPinArrayLength) && 
        resevoir::hasWater(WaterLevelPowerPin))
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
    unit::sleep(ShortSleepTimeInSeconds);
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
