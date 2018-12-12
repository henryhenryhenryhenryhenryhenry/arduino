#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  fasttest();
}

void loop(){
  
}

void fasttest(){
  colorWipe( strip.Color(127, 127, 127), 1);
  delay(500);
  colorWipe( strip.Color(0, 0, 0), 1);
}

void colorTest(int del){
  colorWipe( strip.Color(127, 127, 127), del);
  colorWipe( strip.Color(000, 127, 127), del);
  colorWipe( strip.Color(127, 000, 127), del);
  colorWipe( strip.Color(127, 127, 000), del);
  colorWipe( strip.Color(000, 000, 127), del);
  colorWipe( strip.Color(000, 127, 000), del);
  colorWipe( strip.Color(127, 000, 000), del);
  colorWipe( strip.Color(000, 000, 000), del);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
