/*
 reads pwm values from a =n rc receiver and puts them on the serial monitor
*/


#include <Servo.h>

unsigned long channel_1;
unsigned long channel_2;
unsigned long channel_3;
unsigned long channel_4;

Servo frontright; // pwm pin 3
Servo frontleft;  // pwm pin 5
Servo backright;  // pwm pin 6
Servo backleft;   // pwm pin 9

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);//channel 1
  pinMode(4,INPUT);//channel 2
  pinMode(7,INPUT);//channel 3
  pinMode(8,INPUT);//channel 4

  frontright.attach(3);
  frontleft.attach(5);
  backright.attach(6);
  backleft.attach(9);
}

void loop() {
  
  channel_1 = pulseIn(2,HIGH);
  channel_2 = pulseIn(4,HIGH);
  channel_3 = pulseIn(7,HIGH);
  channel_4 = pulseIn(8,HIGH);
  
  Serial.print("ch1: ");
  Serial.print(channel_1);
  Serial.print(", ch2: ");
  Serial.print(channel_2);
  Serial.print(", ch3: ");
  Serial.print(channel_3);
  Serial.print(", ch4: ");
  Serial.println(channel_4);

  frontright.writeMicroseconds(channel_1);
  frontleft.writeMicroseconds(channel_2);
  backright.writeMicroseconds(channel_3);
  backleft.writeMicroseconds(channel_4);
  
  delay(10);
}
