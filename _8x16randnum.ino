// this code uses a 8x16 led grid to draw an autoscrolling bar display
// right now there is no input, so it just uses rand numbers for values

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16matrix matrix = Adafruit_8x16matrix();

int value = 3;
int ValSet[]= {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};

void setup() {
  Serial.begin(9600);
  Serial.println("16x8 LED Matrix Begin");
  
  matrix.begin(0x70);  // pass in the address

  matrix.setBrightness(0);// (0-15)
  matrix.blinkRate(0);// (0-3)
  matrix.setRotation(1);
  
}



void loop() {
  matrix.clear();
  
  for(int x=16; x>-1; x--){
    ValSet[x+1] = ValSet[x];
  }
  ValSet[0] = random(9);
  Serial.println((ValSet[0]));
  for(int x=0; x<16; x++){
    matrix.drawLine(x,8, x,(8-ValSet[x]) , LED_ON);
    delay(5);
  }
  matrix.writeDisplay();
}
