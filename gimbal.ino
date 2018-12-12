
#include <Servo.h>

char val=0;
int panVal=1500;
int tiltVal=750;

Servo pan;
Servo tilt;

void setup() {
  Serial.begin(9600);
  pan.attach(9);
  tilt.attach(10);
  pan.writeMicroseconds(panVal);
  tilt.writeMicroseconds(tiltVal);
}

void loop() {
  val=0;
  val=Serial.read();
  Serial.print("pan: ");
  Serial.print(panVal);
  Serial.print(" tilt: ");
  Serial.println(tiltVal);
  if(val=='d'&&panVal>800){
    panVal-=50;
  }else if(val=='a'&&panVal<2200){
    panVal+=50;
  }else if(val=='w'&&tiltVal>650){
    tiltVal-=50;
  }else if(val=='s'&&tiltVal<1800){
    tiltVal+=50;
  }
  pan.writeMicroseconds(panVal);
  tilt.writeMicroseconds(tiltVal);
  delay(100);
}
