/*
 * This code was written mostly bu Henry Lindbo, but tons of other code was lifted from various Arduino tutorials
 * This is the code to run a pinball machine made for an ncsu fedd project
 * The author makes no copyright claims to this code
 */
#include <LiquidCrystal.h> // include the library code
//constants for the number of rows and columns in the LCD
const int numRows = 2;
const int numCols = 16;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int score = 0;
int highscore = 0;

void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(7, INPUT);
  // pin 7 is input for score increasing button
  pinMode(8, INPUT);
  // pin 8 is input for score losing button
  
  lcd.begin(numCols, numRows);
  lcd.print("SCORE:"); // Print a message to the LCD.
  lcd.setCursor(0,1);
  lcd.print("HIGH:");
}
void loop()
{

  // read the input pin:
  int buttonStateA = digitalRead(7);
  delay(1);        // delay in between reads for stability
  int buttonStateB = digitalRead(8);

  if(buttonStateA == 0){
    score += 100;
    delay(100);
  }

  if(buttonStateB == 0){
    if(score>highscore){
       highscore = score;
    }
    score = 0;
    lcd.clear();
      for(int i = 0; i<8; i++){
        for(int j = 0; j<2; j++){
          lcd.setCursor(i, j);
          lcd.print("YOU LOSE!");
          delay(250);
          lcd.clear();
        }
      }
    lcd.print("SCORE:");
    lcd.setCursor(0,1);
    lcd.print("HIGH:");
    lcd.setCursor(6,1);
    lcd.print(highscore);
  }
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(7, 0);
  lcd.print(score);
}

