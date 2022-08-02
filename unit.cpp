#pragma once
#include <Esp.h>
#include "unit.h"
#include "screen.h"

namespace unit {
	RTC_DATA_ATTR int bootCount = 9999;

	bool readyToWake(int shortSleepTimeInSeconds, int actualSleepTimeInMinutes) {
		bootCount++;

		int actualSleepTimeInSeconds = actualSleepTimeInMinutes * 60;
		int bootCountThreshold = actualSleepTimeInSeconds / shortSleepTimeInSeconds;

		if (bootCount >= bootCountThreshold) {
			bootCount = 0;
			return true;
		}

		return false;
	}

	void print_wakeup_reason() {
		esp_sleep_wakeup_cause_t wakeup_reason;

		wakeup_reason = esp_sleep_get_wakeup_cause();

		switch (wakeup_reason)
		{
			case ESP_SLEEP_WAKEUP_EXT0: Serial.println("Wakeup caused by external signal using RTC_IO"); break;
			case ESP_SLEEP_WAKEUP_EXT1: Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
			case ESP_SLEEP_WAKEUP_TIMER: Serial.println("Wakeup caused by timer"); break;
			case ESP_SLEEP_WAKEUP_TOUCHPAD: Serial.println("Wakeup caused by touchpad"); break;
			case ESP_SLEEP_WAKEUP_ULP: Serial.println("Wakeup caused by ULP program"); break;
			default: Serial.printf("Wakeup was not caused by deep sleep: %d\n", wakeup_reason); break;
		}
	}

	void sleep(int timeInSeconds) {
		double timeInMicroSeconds = timeInSeconds * 1000000;
		esp_sleep_enable_timer_wakeup(timeInMicroSeconds);

		esp_deep_sleep_start();
	}
}

