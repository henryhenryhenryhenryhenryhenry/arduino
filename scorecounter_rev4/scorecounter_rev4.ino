 /*
 * -This code was written mostly by Henry Lindbo, but tons of other code was lifted from various Arduino tutorials
 * -This is the code to run a pinball machine made for an ncsu fedd project
 * -The author makes no copyright claims to this code as a decent amount was written by other people
 * -last updated: Nov 22 2016
 */


/* Play Melody
 * -----------
 *
 * Program to play melodies stored in an array, it requires to know
 * about timing issues and about how to play tones.
 *
 * The calculation of the tones is made following the mathematical
 * operation:
 *
 *       timeHigh = 1/(2 * toneFrequency) = period / 2
 *
 * where the different tones are described as in the table:
 *
 * note         frequency       period  PW (timeHigh)   
 * c            261 Hz          3830    1915    
 * d            294 Hz          3400    1700    
 * e            329 Hz          3038    1519    
 * f            349 Hz          2864    1432    
 * g            392 Hz          2550    1275    
 * a            440 Hz          2272    1136    
 * b            493 Hz          2028    1014    
 * C            523 Hz          1912    956
 *
 * (cleft) 2005 D. Cuartielles for K3
 */



/*
 * 1/16  note -- 1
 * 1/8   note -- 2
 * 1/4   note -- 4
 * 1/2   note -- 8
 * whole note -- 16
 */

int ledPin = 13;
int speakerOut = 9;               
byte names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'};  //f in this case is actually an f sharp
int tones[] = {1047, 1175, 1319, 1480, 1568, 1760, 1976, 2093}; //again, f is actually an f sharp, the frequency for a normal f is 1397
//byte melody[] = "2d2a1f2c2d2a2d2c2f2d2a2c2d2a1f2c2d2a2a2g2p8p8p8p";
byte default_melody[] = "1e1e1f1g1d1f1e1e1a1a1g1g1f1g1f1e1e1a1a1g1g1f1f1f1f1d1e1f1g1g1f1e1f1g1g1a1a1b1b1b1b1b1a1g1e1f1d1e1e1b1a1g1d1e1e";
// count length:         1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0
//                                         10                  20                  30                  40                  50
byte  losing_melody[] = "4f4g2b2g2b2f4a4g8e";
// count length:         1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0
//                                         10                  20                  30                  40                  50
int count = 0;
int count2 = 0;
int count3 = 0;
int default_max_count = 55;
int losing_max_count = 9;
int statePin = LOW;

int randcount = 0;
int scorepersecond = 10;


//set up lcd
#include <LiquidCrystal.h> // include the library code
//constants for the number of rows and columns in the LCD
const int numRows = 2;
const int numCols = 16;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//set up game vars
long score = 0;
long highscore = 0;





void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); // if DEBUG is 1 it might try to show multiple things on the serial moniter which may or may not be bad
  // make the pushbutton's pin an input:
  pinMode(7, INPUT);
  // pin 7 is input for score increasing button, can have multiple it parallel
  pinMode(8, INPUT);
  // pin 8 is input for losing button
  
  lcd.begin(numCols, numRows);
  lcd.print("SCORE:"); // Print a message to the LCD.
  lcd.setCursor(0,1);
  lcd.print("HIGH:"); 
  playmusic( default_melody, default_max_count );
}



void playmusic(byte melody[], int max_count){
 analogWrite(speakerOut, 0);     
  for (count = 0; count < max_count; count++) {
    statePin = !statePin;
    digitalWrite(ledPin, statePin);
    for (count3 = 0; count3 <= (melody[count*2] - 48) * 30; count3++) {
      for (count2=0;count2<8;count2++) {
        if (names[count2] == melody[count*2 + 1]) {       
          analogWrite(speakerOut,255);
          delayMicroseconds(tones[count2]);
          analogWrite(speakerOut, 0);
          delayMicroseconds(tones[count2]);
        } 
        if (melody[count*2 + 1] == 'p') {
          // make a pause of a certain size
          analogWrite(speakerOut, 0);
          delayMicroseconds(500);
        }
      }
    }
  }
}

void playmusicAndRunGame(byte melody[], int max_count){
 analogWrite(speakerOut, 0);     
  for (count = 0; count < max_count; count++) {
    checkForScoring();
    checkForLosers();
    statePin = !statePin;
    digitalWrite(ledPin, statePin);
    for (count3 = 0; count3 <= (melody[count*2] - 48) * 30; count3++) {
      for (count2=0;count2<8;count2++) {
        if (names[count2] == melody[count*2 + 1]) {       
          analogWrite(speakerOut,255);
          delayMicroseconds(tones[count2]);
          analogWrite(speakerOut, 0);
          delayMicroseconds(tones[count2]);
        } 
        if (melody[count*2 + 1] == 'p') {
          // make a pause of a certain size
          analogWrite(speakerOut, 0);
          delayMicroseconds(500);
        }
      }
    }
  }
}


void loop(){ //this is where the game is actually run
  playmusicAndRunGame( default_melody, default_max_count );
}

void checkForScoring(){
  if(randcount == 0){
  score += 1;
  delay(1);
  }
  randcount++;
  if(randcount > scorepersecond){
  randcount = 0;
  }
  // read the input pin:
  int buttonStateA = digitalRead(7);
  delay(1);        // delay in between reads for stability
  int buttonStateB = digitalRead(8);

  if(buttonStateA == 0){
    score += 500;
    delay(1);
  }
  if(buttonStateB == 0){
    score += 500;
    delay(1);
  }
  
}

void checkForLosers(){
    // read the input pin:
  int buttonStateC = digitalRead(10);
  delay(1);        // delay in between reads for stability
  if(buttonStateC == 0){
    if(score>highscore){
       highscore = score;
    }
    score = 0;
    lcd.clear();
      for(int i = 2; i<6; i++){
        for(int j = 0; j<2; j++){
         for( int k = 0; k<50; k++){
          analogWrite(speakerOut,255);
           delayMicroseconds(50);
           analogWrite(speakerOut, 0);
           delayMicroseconds(50);
           }
          lcd.clear();
          lcd.setCursor(i, j);
          lcd.print("YOU LOSE!");
          delay(150);
        }
      }
    playmusic( losing_melody, losing_max_count );
    delay(1000);
    lcd.clear();
    lcd.print("SCORE:");
    lcd.setCursor(0,1);
    lcd.print("HIGH:");
    lcd.setCursor(7,1);
    lcd.print(highscore);
  }
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(7, 0);
  lcd.print(score);
}

/*
 _                A Banana.
//\
V  \
 \  \_
  \,'.`-.
   |\ `. `.       
   ( \  `. `-.                        _,.-:\
    \ \   `.  `-._             __..--' ,-';/
     \ `.   `-.   `-..___..---'   _.--' ,'/
      `. `.    `-._        __..--'    ,' /
        `. `-_     ``--..''       _.-' ,'
          `-_ `-.___        __,--'   ,'
             `-.__  `----"""    __.-'
hh                `--..____..--'
                  Because why not?
*/




