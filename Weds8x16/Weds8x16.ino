//displays what day of the week it is 1/7 of the time

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16matrix matrix = Adafruit_8x16matrix();

void setup() {
  matrix.begin(0x70);
  matrix.setBrightness(0);
}

static const uint8_t PROGMEM
  pWog_bmp[] =
  { B00000000,
    B00111100,
    B01111111,
    B01111111,
    B10101111,
    B11111110,
    B10001000,
    B00011000 };

void loop() {
  matrix.clear();
  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  matrix.setRotation(1);
  for (int8_t x=7; x>=-25; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("It is");
    matrix.writeDisplay();
    delay(30);
  }
  for (int8_t x=7; x>=-40; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("Wednesday");
    matrix.writeDisplay();
    delay(25);
  }
  for (int8_t x=7; x>=-40; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("my Dudes");
    matrix.writeDisplay();
    delay(30);
  }

  matrix.clear();
  matrix.drawBitmap(0, 0, pWog_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);
  
  matrix.clear();
  matrix.drawBitmap(8, 0, pWog_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);
  
  matrix.clear();
  matrix.drawBitmap(4, 0, pWog_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

}
