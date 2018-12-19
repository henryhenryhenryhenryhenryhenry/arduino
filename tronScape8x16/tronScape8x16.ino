//draws a crappy pixelated road and background

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16matrix matrix = Adafruit_8x16matrix();

int valset[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int valset2[] = {1,1,1,1};
int speeed = 50;

void setup() {
  matrix.setBrightness(0);
  matrix.begin(0x70);
  matrix.setBrightness(0);
  matrix.setRotation(1);
  matrix.clear();
}

void loop() {
  
  matrix.clear();
  updateRoad();
  drawRoad();
  updateBackground();
  drawBackground();
  matrix.writeDisplay();
  delay(speeed);

  matrix.clear();
  updateRoad();
  drawRoad();
  drawBackground();
  matrix.writeDisplay();
  delay(speeed);
  
  matrix.clear();
  updateRoad();
  drawRoad();
  drawBackground();
  matrix.writeDisplay();
  delay(speeed);
}

void drawRoad(){
  matrix.fillRect(0,4, 16,7, LED_ON);
  
  //draw road
  if(valset2[3]){
    matrix.drawLine(7,4, 8,4, LED_OFF);
  }
  if(valset2[2]){
    matrix.drawLine(5,5, 10,5, LED_OFF);
  }
  if(valset2[1]){
    matrix.drawLine(3,6, 12,6, LED_OFF);
  }
  if(valset2[0]){
    matrix.drawLine(1,7, 14,7, LED_OFF);
  }
}

void updateRoad(){
  
  //matrix.drawLine(7,4, 0,8, LED_ON);
  //matrix.drawLine(8,4, 15,8, LED_ON);

  for(int x=0;x<4;x++){//update road
    valset2[x] = valset2[x+1];
  }

  valset2[3] = random(2)-1;//new road value
}

void drawBackground(){
  matrix.fillRect(0,0, 16,4, LED_ON);
  
  for(int x=0; x<16; x++){
    matrix.drawLine(x,(2-valset[x]), x,0 , LED_OFF);//draw background
  }
}

void updateBackground(){
  
  for(int x=0;x<=6;x++){//update left side of background
    valset[x]=valset[x+1];
  }
  
  for(int x=15;x>=9;x--){//update right side of background
    valset[x]=valset[x-1];
  }

  valset[7] = random(5)-1;//set left side middle to new value
  valset[8] = random(5)-1;//set right side middle to new value
}

