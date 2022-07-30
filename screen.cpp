#pragma once

#include <Adafruit_SSD1306.h>
#include <gfxfont.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_GFX.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Wire.h>
#include <vector>
#include <string>
#include <HardwareSerial.h>
#include "screen.h"
#include <stdexcept>

#define OLED_ADDR   0x3C

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

namespace screen {

    const int LinePadding = 10;
    const double PtToPixelRatio = 1.3;
    const int FontHeight = (9 * PtToPixelRatio) + LinePadding;
    const int FontWidth = (7 * 1.3);
    const int ScreenWidth = 128;
    const int ScreenHeight = 64;

    Adafruit_SSD1306 display(ScreenWidth, ScreenHeight, &Wire, -1);

    void initialize(int powerPin) {
        pinMode(powerPin, OUTPUT);
        digitalWrite(powerPin, HIGH);
        delay(500);

        if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
            Serial.println(F("SSD1306 allocation failed"));
            for (;;); // Don't proceed, loop forever
        }
    }

    void reset() {
        display.clearDisplay();
        display.display();
        display.setFont(&FreeSans9pt7b);
        display.setTextSize(0);
        display.setTextColor(WHITE);
    }

    int getPositionX(std::string message, int screenMiddlePosX) {
        if (message.length() * FontWidth > ScreenWidth) {
            return 0;
        }

        int messageMiddle = message.length() * FontWidth / 2;
        return screenMiddlePosX - messageMiddle;
    }

    void update(std::string message) {
        
        reset();

        int xPos = getPositionX(message, ScreenWidth / 2);
        display.setCursor(xPos, ScreenHeight / 2);
        display.print(message.c_str());
        Serial.println(message.c_str());

        display.display();
    }

    void addLine(std::string message, int lineNumber, bool center, int fontScale) {
        int lineHeight = (FontHeight * fontScale);
        display.setTextSize(fontScale);

        int yPos = (lineNumber + 1) * lineHeight;
        int xPos = center ? getPositionX(message, ScreenWidth / 2) : 0;
        display.setCursor(xPos, yPos);
        display.print(message.c_str());
    }
    void render() {
        display.display();
    }
}

