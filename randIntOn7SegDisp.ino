// bits representing segments A through G (and decimal point) for numerals 0-9
const byte numeral[10] = {
//ABCDEFG /dp
B11111100, // 0
B01100000, // 1
B11011010, // 2
B11110010, // 3
B01100110, // 4
B10110110, // 5
B00111110, // 6
B11100000, // 7
B11111110, // 8
B11100110, // 9
};
// every pin needs a 220 ohm resistor
// pins for decimal point and each segment
// dp,G,F,E,D,C,B,A
const int segmentPins[8] = { 5,9,8,7,6,4,3,2};
void setup()
{
for(int i=0; i < 8; i++)
{
pinMode(segmentPins[i], OUTPUT); // set segment and DP pins to output
}
}


void loop()
{
  int inumber = random(0, 9);
  writeNum(inumber);
  delay(500);
  /*
  for(int number = 0; number<10; number++){
    writeNum(number);
    delay(500);
  }
  */
}





void writeNum(int num){
if(num == 0){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
}
else if(num == 1){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
}
else if(num == 2){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
}
else if(num == 3){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
}
else if(num == 4){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
else if(num == 5){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
else if(num == 6){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
else if(num == 7){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
}
else if(num == 8){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
else if(num == 9){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
}
/*




void loop()
{
for(int i=0; i <= 10; i++)
{
showDigit(i);
delay(1000);
}
// the last value if i is 10 and this will turn the display off
delay(2000); // pause two seconds with the display off
}





// Displays a number from 0 through 9 on a 7-segment display
// any value not within the range of 0-9 turns the display off
void showDigit( int number)
{
boolean isBitSet;
for(int segment = 1; segment < 8; segment++)
{
if( number < 0 || number > 9){
isBitSet = 0; // turn off all segments
}
else{
  // isBitSet will be true if given bit is 1
isBitSet = bitRead(numeral[number], segment);
}
isBitSet = ! isBitSet; // remove this line if common cathode display
digitalWrite( segmentPins[segment], isBitSet);
}
}
*/

