/*
I recently got one of those 8x8 LED matrices  and I was playing with some Game of Life patterns when I found this pretty repeating pattern. I found it by starting with some random patterns. If you look closely you can see the pattern becoming a mirrored version of itself halfway through. Apparently the pattern doesn't repeat like this on an infinite grid but on this wrapping 8x8 grid it does ;-) 

FYI, the LED matrix is a bicolor one (green/red) and has an I2C interface (http://www.adafruit.com/products/902). I'm using the colors as follows:
 - newly created cells are green
 - cells that are at least 10 generations old are red
 - other living cells are yellow (simultaneously green+red)

It's hookup up to my Arduino Uno r3.

here's a video: http://www.youtube.com/watch?v=Ee2hOaQ2RDI

*/
//some edits made by henry lindbo


#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

boolean cells[8][8];

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

// game of life
int next[8][8];

void setup() {
  Serial.begin(9600);
  Serial.write("test");

  randomSeed(analogRead(0));
  for (int r=0 ; r<8 ; r++) {
    for (int c=0 ; c<8 ; c++) {    
      if (random(2) >0)
        next[r][c] = 1;
    }
 } 
 
  matrix.begin(0x70);  // pass in the address
  matrix.setBrightness(15);
}

void loop() {

  game_of_life();
}

int current[8][8] =
{ {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,1,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0} };
  
int mod(int a) { return (a+8)%8; }

void game_of_life() {
  
  matrix.clear();
  
  // draw
  for (int r=0 ; r<8 ; r++) {
    for (int c=0 ; c<8 ; c++) {
      int color;
      if (next[r][c] == 0)
        color = 0;
      else if (next[r][c] == 1) 
        color = LED_GREEN;
      else if (next[r][c] > 10)
        color = LED_RED;
      else
        color = LED_YELLOW;
      matrix.drawPixel(c,r,color);
    }
  }
  matrix.writeDisplay();
  if (checkIfDead()>=64){
    matrix.clear();
    matrix.writeDisplay();
    delay(1000);
    reset();
  }else if(checkOldest()>50){
    matrix.clear();
    matrix.writeDisplay();
    delay(1000);
    reset();
  }else{
    // calc next state
    for (int r=0 ; r<8 ; r++) {
      for (int c=0 ; c<8 ; c++) {    
        // count alive neighbors
        int alive = 0;
        alive += current[mod(r+1)][mod(c)  ] != 0;
        alive += current[mod(r)  ][mod(c+1)] != 0;
        alive += current[mod(r-1)][mod(c)  ] != 0;
        alive += current[mod(r)  ][mod(c-1)] != 0;
        alive += current[mod(r+1)][mod(c+1)] != 0;
        alive += current[mod(r-1)][mod(c-1)] != 0;
        alive += current[mod(r+1)][mod(c-1)] != 0;
        alive += current[mod(r-1)][mod(c+1)] != 0;
        if (current[r][c])
          if (alive < 2 || alive > 3)
            next[r][c] = 0;
          else
            next[r][c] = current[r][c] + 1;
        else
          if (alive == 3)
            next[r][c] = 1;
      }
    }    
  }
  for (int r=0 ; r<8 ; r++) {
    for (int c=0 ; c<8 ; c++) {    
      current[r][c] = next[r][c];
    }
  }  
  delay(100);
  

}

void reset(){
  for (int r=0 ; r<8 ; r++) {
    for (int c=0 ; c<8 ; c++) {    
      if (random(2) >0)
        next[r][c] = 1;
    }
 }
}

int checkOldest(){
  int oldest=0;
  int i,j;
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      if(current[i][j]>oldest){
        oldest = next[i][j];
      }
    }
  }
  return oldest;
}



int checkIfDead(){
  int deadCount = 0;
  int i,j;
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      if(next[i][j]==0){
        deadCount++;
      }
    }
  }
  return deadCount;
}

