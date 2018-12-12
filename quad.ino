/*
 takes in pwm inputs from a rc reciever and uses them
    to control the four motors of a quadcopter
    copyright Henry Lindbo 2017
*/


#include <Servo.h>
#include <Time.h>

unsigned long channel_1;// pin 2
unsigned long channel_2;// pin 4
unsigned long channel_3;// pin 7
unsigned long channel_4;// pin 8

Servo frontRight; // pwm pin 3
Servo frontLeft;  // pwm pin 5
Servo backRight;  // pwm pin 6
Servo backLeft;   // pwm pin 9

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);//channel 1
  pinMode(4,INPUT);//channel 2
  pinMode(7,INPUT);//channel 3
  pinMode(8,INPUT);//channel 4

  frontRight.attach(3);
  frontLeft.attach( 5);
  backRight.attach( 6);
  backLeft.attach(  9);

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  if(second()%2==1){//        blink to know arduino is working correctly
    digitalWrite(13, HIGH);
  }else if((second()%2==0)&&channel_3>1050){
    digitalWrite(13, LOW);
  }
  
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

  //frontRight.writeMicroseconds(channel_1);
  //frontLeft.writeMicroseconds(channel_2);
  //backRight.writeMicroseconds(channel_3);
  //backLeft.writeMicroseconds(channel_4);

  updateRotors();
  
  delay(10);//remove this!
}

void updateRotors(){
  if(channel_3<1050){//not sure about this val
    frontRight.writeMicroseconds(0);//or whatever value cuts off the motors
    frontLeft.writeMicroseconds( 0);
    backRight.writeMicroseconds( 0);
    backLeft.writeMicroseconds(  0);
    return;
  }
  frontRight.writeMicroseconds(channel_3*((-channel_1-channel_2-channel_4)/3));
  frontLeft.writeMicroseconds( channel_3*((+channel_1-channel_2+channel_4)/3));
  backRight.writeMicroseconds( channel_3*((-channel_1+channel_2+channel_4)/3));
  backLeft.writeMicroseconds(  channel_3*((+channel_1+channel_2-channel_4)/3));
}


