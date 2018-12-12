#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"



Adafruit_24bargraph bar = Adafruit_24bargraph();

int i=0;
int j=40;

void setup() {
  Serial.begin(9600);
  Serial.println("HT16K33 Bi-Color Bargraph");
  
  bar.begin(0x70);  // pass in the address
  //for(i=0;i<24;i++){
    bar.clear();
  //}
  bar.writeDisplay();
}


void loop() {

    j+=random(9)-4;
    //Serial.print("value is: ");
    Serial.println(j);
    dispval(j);
    delay(50);//delay
    chkVal(); 
}

void chkVal(){
  if(j<-10){
    j=0;
    //Serial.println("RESET UP");
  }else if(j>80){
    j=72;
    //Serial.println("RESET DOWN");
  }

  
}

void dispval(int val){
  bar.clear();
  if(val>=1&&val<=24){
    for(i=0;i<val;i++){
      bar.setBar(i,LED_GREEN);
    }
    bar.writeDisplay();
  }else if(val>=25&&val<=48){
    for(i=0;i<24;i++){
      bar.setBar(i,LED_GREEN);
    }
    for(i=24;i<val;i++){
      bar.setBar(i-24,LED_YELLOW);
    }
    bar.writeDisplay();
  }else if(val>=49&&val<=72){
    for(i=0;i<24;i++){
      bar.setBar(i,LED_YELLOW);
    }
    for(i=48;i<val;i++){
      bar.setBar(i-48,LED_RED);
    }
    bar.writeDisplay();
  }else if(val<0){
    for(i=0;i<24;i+=2){
      bar.setBar(i,LED_GREEN);
    }
    bar.writeDisplay();
  }else if(val>72){
    for(i=0;i<24;i+=2){
      bar.setBar(i,LED_RED);
    }
    bar.writeDisplay();
  }else if(val==0){
    bar.clear();
  } 
}

