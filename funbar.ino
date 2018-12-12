#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_24bargraph bar = Adafruit_24bargraph();

int i=0;
int j=0;

void setup() {
  Serial.begin(9600);
  Serial.println("HT16K33 Bi-Color Bargraph test");
  
  bar.begin(0x70);  // pass in the address

  for(i=0;i<24;i++){
    bar.setBar(i,LED_YELLOW);
  }
  
  bar.writeDisplay();
  delay(2000);
}


void loop() {
    for(i=23;i>=0;i--){
      j=random(3);
      switch (j){
      case 0:bar.setBar(i,LED_GREEN); break;
      case 1:bar.setBar(i,LED_YELLOW); break;
      case 2:bar.setBar(i,LED_RED); break;
      }
    
    bar.writeDisplay();
    delay(5);
  }
  for(i=0;i<24;i++){
   j=random(3);
      switch (j){
      case 0:bar.setBar(i,LED_GREEN); break;
      case 1:bar.setBar(i,LED_YELLOW); break;
      case 2:bar.setBar(i,LED_RED); break;
      }
    
    bar.writeDisplay();
    delay(5);
  }

  
}
