#pragma once

namespace unit {
	bool readyToWake(int shortSleepTimeInSeconds, int actualSleepTimeInMinutes);
	void print_wakeup_reason();
	void sleep(int timeInSeconds);
}