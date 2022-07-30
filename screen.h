#pragma once

#include <vector>
#include <string>

namespace screen {
	void initialize(int powerPin);
	void update(std::string message);
	void reset();
	void addLine(std::string message, int lineNumber, bool center = true, int fontScale = 1);
	void render();
}
