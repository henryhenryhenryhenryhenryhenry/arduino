/*
* Tone sketch
*
* Plays tones through a speaker on digital pin 9
* frequency determined by values read from analog port
*/
const int speakerPin = 9; // connect speaker to pin 9
const int pitchPin = 0; // pot that will determine the frequency of the tone
const int A = 5000;
const int B = 4000;
const int C = 3000;
const int D = 1000;

int button1 = 2;
int button2 = 3;
int button3 = 4;
int button4 = 5;
void setup()
{  
pinMode(button1, INPUT);
pinMode(button2, INPUT);
pinMode(button3, INPUT);
pinMode(button4, INPUT);
}
void loop()
{
  //frequency must be between 100 and 5000
if(button1 == 1){
  tone(speakerPin, A, 100);
}
delay(1);
if(button2 == 1){
  tone(speakerPin, B, 100);
}
delay(1);
if(button3 == 1){
  tone(speakerPin, C, 100);
}
delay(1);
if(button4 == 1){
  tone(speakerPin, D, 100);
}
delay(1);






/*  
int sensor0Reading = analogRead(pitchPin); // read input to set frequency
// map the analog readings to a meaningful range
int frequency = map(sensor0Reading, 0, 1023, 100,5000); //100Hz to 5kHz
int duration = 100; // how long the tone lasts
tone(speakerPin, frequency, duration); // play the tone
delay(500); //pause one second
*/
}
