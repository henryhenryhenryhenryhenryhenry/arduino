#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  for(int i = 0; i<8; i++){
    int j = random(1,7);
    switch (j){
      case 1: strip.setPixelColor(i, strip.Color(000, 000, 127));break;
      case 2: strip.setPixelColor(i, strip.Color(000, 127, 000));break;
      case 3: strip.setPixelColor(i, strip.Color(127, 000, 000));break;
      case 4: strip.setPixelColor(i, strip.Color(000, 127, 127));break;
      case 5: strip.setPixelColor(i, strip.Color(127, 000, 127));break;
      case 6: strip.setPixelColor(i, strip.Color(127, 127, 000));break;
      case 7: strip.setPixelColor(i, strip.Color(127, 127, 127));break;
    }
  }
  strip.show();
  delay(50);
}
