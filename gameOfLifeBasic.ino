//written by henry lindbo 2017
/*Any live cell with fewer than two live neighbours dies
  Any live cell with two or three live neighbours lives on to the next generation.
  Any live cell with more than three live neighbours dies
  Any dead cell with exactly three live neighbours becomes a live cell
 */




#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <Time.h>

Adafruit_8x16matrix matrix = Adafruit_8x16matrix();//if using 8x16 matrix
//Adafruit_8x8matrix matrix = Adafruit_8x8matrix();//if using 8x8 matrix

const int rows = 16;// associated with i
const int cols = 8;// associated with j

int Old[rows][cols]/*=
{ {0,0,0,0,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,1,1,1,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0} }*/;
int New[rows][cols];

unsigned long times = 0;//times reset



void setup() {//sets stuff up
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
  matrix.setBrightness(0);
  matrix.setRotation(1);
  reset();
}

void loop() {//loops
  
  matrix.clear();
  draw();
  matrix.writeDisplay();
  nextState();
  int i,j;
  for(i=0;i<rows;i++){
    for(j=0;j<cols;j++){
      Old[i][j]=New[i][j];//copy new into old
    }
  }
  if (chkResetNeeded()){
    reset();
  }
  delay(100);
}

int chkResetNeeded(){//checks if any cell is too old or if all cells are dead
  int numDead=0;
  int oldest=0;
  int i,j;
  for(i=0;i<rows;i++){
    for(j=0;j<cols;j++){
      if(New[i][j]>oldest)
        oldest = New[i][j];
      if(New[i][j]==0)
        numDead++;
    }
  }
  Serial.println((rows*cols)-numDead);
  if((oldest>50)){
    return 1;
  }else if(numDead>=(rows*cols)){
    matrix.clear();
    matrix.writeDisplay();
    delay(1000);//display the blank board for a little bit
  }else{
    return 0;
  }
}

void reset(){//resets board to new psuedo random state
  randomSeed(analogRead(0)+times);//analog read of pin 0 is somewhat random, times increments
  times+=10;
  int i,j;
  for(i=0;i<rows;i++){
    for(j=0;j<cols;j++){
      Old[i][j]=random()%2;
    }
  }
}

void draw(){//draws all the new cells to the board
  int i,j;
  for(i=0;i<rows;i++){
    for(j=0;j<cols;j++){
      if(New[i][j]>=1)
        matrix.drawPixel(i,j,LED_ON);
      else
        matrix.drawPixel(i,j,LED_OFF);
    }
  }
}

void nextState(){//calculates the next state
  int i,j;
  for(i=0;i<rows;i++){
    for(j=0;j<cols;j++){
      int neighbors = countNeighbors(i,j);
      switch(neighbors){
        case 0: if(Old[i][j]>=1)
                  New[i][j]=0;
                else if(Old[i][j]==0)
                  New[i][j]=0;
                break;
        case 1: if(Old[i][j]>=1)
                  New[i][j]=0;
                else if(Old[i][j]==0)
                  New[i][j]=0;
                break;
        case 2: if(Old[i][j]>=1)
                  New[i][j]++;
                else if(Old[i][j]==0)
                  New[i][j]=0;
                break;
        case 3: if(Old[i][j]>=1)
                  New[i][j]++;
                else if(Old[i][j]==0)
                  New[i][j]++;
                break;
        case 4: if(Old[i][j]>=1)
                  New[i][j]=0;
                else if(Old[i][j]==0)
                  New[i][j]=0;
                break;
        default: New[i][j]=0;
                 break;
      }
    }
  }
}

int rmod(int x){//returns to mod of a number, useful to implement overlap
  return (x+rows)%rows;
}

int cmod(int x){//returns to mod of a number, useful to implement overlap
  return (x+cols)%cols;
}

int countNeighbors(int i,int j){//counts the number of neighbors for a given cell
  int neighbors=0;
  if(Old[rmod(i+1)][cmod(j)]>=1)
    neighbors++;
  if(Old[rmod(i-1)][cmod(j)]>=1)
    neighbors++;
  if(Old[rmod(i)][cmod(j+1)]>=1)
    neighbors++;
  if(Old[rmod(i)][cmod(j-1)]>=1)
    neighbors++;
  if(Old[rmod(i+1)][cmod(j+1)]>=1)
    neighbors++;
  if(Old[rmod(i-1)][cmod(j-1)]>=1)
    neighbors++;
  if(Old[rmod(i-1)][cmod(j+1)]>=1)
    neighbors++;
  if(Old[rmod(i+1)][cmod(j-1)]>=1)
    neighbors++;
  return neighbors;
}

