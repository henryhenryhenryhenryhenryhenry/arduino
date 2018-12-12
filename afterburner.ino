
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include <Time.h>


#define PIN 6 // output to leds
#define PIN2 7 // pwm input from throttle
#define PIXELS 8
#define MAX 255
#define MIN 000
#define MED 127
#define DELAY 50
#define OFFSET 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

unsigned long rawThrottle;

int throttle = 0; //throttle position
                  // 0 - off  - very dull red
                  // 1 - low  - dull red
                  // 2 - med  - dull orange
                  // 3 - med  - yellow
                  // 4 - high - white
                  // 5 - max  - bright blue/white
int R_offset;
int G_offset;
int B_offset;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}


//loop through all leds and set each one to be a color 
//  based on the throttle input (+- some random offset)
//  red - orange - yellow - white - blue

void loop() {
  /*
  rawThrottle = pulseIn(PIN2, HIGH);
  if(rawThrottle < 500){
    throttle = 0;
  }else if(rawThrottle < 750){
    throttle = 1;
  }else if(rawThrottle < 1000){
    throttle = 2;
  }else if(rawThrottle < 1250){
    throttle = 3;
  }else if(rawThrottle < 1500){
    throttle = 4;
  }else if(rawThrottle < 2000){
    throttle = 5;
  }
  */
  
  for(int i=0;i<PIXELS;i++){
    R_offset = random(0,OFFSET);
    G_offset = random(0,OFFSET);
    B_offset = random(0,OFFSET);
    switch(throttle){
      case 0: 
        strip.setPixelColor(i, strip.Color(R_offset, 000, 000)); 
        break;//very dull red
      case 1: 
        strip.setPixelColor(i, strip.Color(127 + R_offset, 000, 000)); 
        break;//dull red
      case 2: 
        strip.setPixelColor(i, strip.Color(127 + R_offset, G_offset, 000)); 
        break;//dull orange
      case 3: 
        strip.setPixelColor(i, strip.Color(127 + R_offset, 64 + G_offset, 000)); 
        break;//yellow
      case 4: 
        strip.setPixelColor(i, strip.Color(127 + R_offset, 127 + G_offset, B_offset)); 
        break;//white
      case 5: 
        strip.setPixelColor(i, strip.Color(127 + R_offset, 127 + G_offset, 127 + G_offset)); 
        break;//bright blue/white
    }
    strip.show();
  }
  delay(DELAY);

}
