/*
 * example sketch to draw stuff on adafruit 96x128 oled display
 * 
 * valid function calls:
 * tft.drawPixel(int x, int y, uint16_t color)
 * tft.fillRect(int, int, int, int, uint16_t color)
 * tft.invert(true) or tft.invert(false)
 * tft.fillScreen(uint16_t color)
 * tft.drawLine(int x, int y, int x, int y, uint16_t color)
 * tft.setCursor(int x, int y)
 * tft.setTextColor(uint16_t color)
 * tft.setTextSize(int size)
 * tft.print(char* text)
 * tft.print(int x)
 * tft.print(double x, int length);
 * tft.print(int x, HEX)
 * tft.println(char* text)
 * tft.drawFastHLine(int x, int y, int x, uint16_t color)
 * tft.drawFastVLine(int x, int y, int y, uint16_t color)
 * tft.drawRect(int x, int y, int x, int x, uint16_t color)
 * tft.fillRect(int x, int y, int x, int x, uint16_t color)
 * tft.fillCircle(int x, int y, int radius, uint16_t color)
 * tft.drawCircle(int x, int y, intradius, uint16_t color)
 * tft.drawRoundRect(int x, int y, int w, int h, int r, uint16_t color)
 * 
 * tft.height()
 * tft.width()
 * 
 */
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF
#define LIGHTGREY       0xC618
#define DARKGREY        0x7BEF

#define sclk 2
#define mosi 3
#define dc   4
#define cs   5
#define rst  6

Adafruit_SSD1351 tft = Adafruit_SSD1351(cs, dc, mosi, sclk, rst);

void setup() {
  tft.begin();
  tft.fillScreen(BLACK);
  testPattern();
}

void loop() {
  
}

void testPattern(){
  tft.fillRect( 0, 0, 20, 72, WHITE);
  tft.fillRect( 20, 0, 20, 72, YELLOW);
  tft.fillRect( 38, 0, 20, 72, CYAN);
  tft.fillRect( 56, 0, 20, 72, GREEN);
  tft.fillRect( 75, 0, 20, 72, MAGENTA);
  tft.fillRect( 93, 0, 20, 72, RED);
  tft.fillRect( 111, 0, 20, 72, BLUE);

  tft.fillRect( 0, 72, 20, 24, 0x1082);
  tft.fillRect( 20, 72, 20, 24, 0x2104);
  tft.fillRect( 38, 72, 20, 24, 0x630C);
  tft.fillRect( 56, 72, 20, 24, 0x7BEF);
  tft.fillRect( 75, 72, 20, 24, 0xC618);
  tft.fillRect( 93, 72, 20, 24, 0xE71C);
  tft.fillRect( 111, 72, 20, 24, 0xFFFF);

  tft.setCursor(0,0);
  tft.setTextSize(1);
  tft.setTextColor(BLACK);
  tft.println("\n128x96 OLED display\n\n\n initializing...\n\n please stand by");
  
  tft.invert(true);
  delay(100);
  tft.invert(false);
  delay(100);
  tft.invert(true);
  delay(100);
  tft.invert(false);
}

void testAllPixels(){
  tft.fillScreen(BLACK);
  delay(100);
  tft.fillScreen(BLUE);
  delay(100);
  tft.fillScreen(RED);
  delay(100);
  tft.fillScreen(GREEN);
  delay(100);
  tft.fillScreen(CYAN);
  delay(100);
  tft.fillScreen(MAGENTA);
  delay(100);
  tft.fillScreen(YELLOW);
  delay(100);
  tft.fillScreen(WHITE);
  delay(100);
}

void testText(){
  drawText("text text text", WHITE, 1);
  delay(500);
  tft.fillScreen(BLACK);
  drawText("text text text", WHITE, 2);
  delay(500);
  tft.fillScreen(BLACK);
  drawText("text text text", WHITE, 3);
  delay(500);
  tft.fillScreen(BLACK);
  drawText("text text text", WHITE, 4);
  delay(500);
  tft.fillScreen(BLACK);
}

void drawText(char *text, uint16_t color, int txtsize) {
  tft.setCursor(0,0);
  tft.setTextColor(color);
  tft.print(text);
  tft.setTextSize(txtsize);
}

