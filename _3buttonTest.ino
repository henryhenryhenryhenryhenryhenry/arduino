#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16matrix matrix = Adafruit_8x16matrix();

const int butt1 = 4;// 
const int butt2 = 3;// 
const int butt3 = 2;// 

int butt1state;
int butt2state;
int butt3state;

int value = 3;
int ValSet[]= {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};

const int rotation = 1;
int brightness = 0;

int whatToDo = 1;

void processCommand();
void displayMenu();
void displayGraph();
int getValue();
void getButton();
void printToDisp(char* str, int strln, int x, int delval);

void setup() {
  pinMode(butt1,OUTPUT);
  pinMode(butt2,OUTPUT);
  pinMode(butt3,OUTPUT);

  Serial.begin(9600);
  Serial.println("Begin: 3ButtonTest");

  matrix.begin(0x70);
  
  matrix.setBrightness(brightness);// (0-15)
  matrix.blinkRate(0);// (0-3)
  matrix.setRotation(rotation);
}

void loop(){
  matrix.setRotation(rotation);
  switch (whatToDo){
    case 0: processCommand(); break;
    case 1: displayGraph(); break;
    case 2: displayMenu(); break;
    case 3: displayValue(); break;
    case 4: break;
  }  
  delay(100);
}

void displayValue(){
  matrix.setRotation(1);
  matrix.clear();
  matrix.setTextSize(1);
  matrix.setTextColor(LED_ON);
  matrix.setCursor(2,0);
  matrix.print(getValue());
  matrix.writeDisplay();
  processCommand();
  matrix.setRotation(rotation);
}

void processCommand(){
  getButton();
  if(whatToDo != 2 && butt1state == 1){
    whatToDo = 2;
    return;
  }else if(whatToDo == 2 && butt1state == 1){
    whatToDo = 1;
    return;
  }else if(whatToDo == 2 && butt3state == 1){
    brightness++;
    if(brightness>15) brightness=0;
    matrix.setBrightness(brightness);
    return;
  }else if(whatToDo != 2 && butt2state == 1 && whatToDo != 3){
    whatToDo = 3;
    return;
  }else if(whatToDo != 2 && butt2state == 1 && whatToDo == 3){
    whatToDo = 1;
    return;
  }
}

void displayMenu(){
  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  matrix.setRotation(1);
  for (int8_t x=7; x>=-80; x--) {
    printToDisp("Menu: 1:return ",0,x,100);
    if(whatToDo != 2)return;
  }
  for (int8_t x=7; x>=-80; x--) {
    printToDisp("2:do something ",0,x,100);
    if(whatToDo != 2)return;
  }
  for (int8_t x=7; x>=-75; x--) {
    printToDisp("3:brigtness+",0,x,100);
    if(whatToDo != 2)return;
  }
  whatToDo = 1;
}

void printToDisp(char* str, int strln, int x, int delval){
  matrix.clear();
  matrix.setCursor(x,0);
  matrix.print(str);
  matrix.writeDisplay();
  delay(delval);
  processCommand();
  if(whatToDo != 2)
      return;
}

void displayGraph(){
  matrix.clear();
  
  for(int x=16; x>-1; x--){
    ValSet[x+1] = ValSet[x];
  }
  ValSet[0] = getValue();
  Serial.print("value: ");
  Serial.println((ValSet[0]));
  for(int x=0; x<16; x++){
    matrix.drawLine(x,8, x,(8-ValSet[x]) , LED_ON);
  }
  matrix.writeDisplay();
  processCommand();
  //delay(100);
}

int getValue(){
  return random(9);
}

void getButton(){
  butt1state = digitalRead(butt1);
  butt2state = digitalRead(butt2);
  butt3state = digitalRead(butt3);

  Serial.print("button1: ");
  Serial.print(butt1state);
  Serial.print(" button2: ");
  Serial.print(butt2state);
  Serial.print(" button3: ");
  Serial.println(butt3state);

  //delay(100);
}


