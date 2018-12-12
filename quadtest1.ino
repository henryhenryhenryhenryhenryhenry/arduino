#include <Servo.h>
#include <Time.h>

unsigned long ch1;// pin 10
unsigned long ch2;// pin 11
unsigned long ch3;// pin 12
unsigned long ch4;// pin 13

unsigned long och1;// old ch1
unsigned long och2;// old ch2
unsigned long och3;// old ch3
unsigned long och4;// old ch4

unsigned long dch1;// delta ch1
unsigned long dch2;// delta ch2
unsigned long dch3;// delta ch3
unsigned long dch4;// delta ch4

Servo frLf;  // pwm pin 3 // motor #1
Servo frRt; // pwm pin 5 // motor #2
Servo bkRt;  // pwm pin 6 // motor #3
Servo bkLf;   // pwm pin 9 // motor #4

int enable = 0;

void setup() {
  //Serial.begin(9600);
  
  frLf.attach( 3);
  frRt.attach(5);
  bkRt.attach( 6);
  bkLf.attach(  9);

  enable = 1;

}

void loop() {
  ch1 = pulseIn(12,HIGH);
  ch2 = pulseIn(12,HIGH);
  ch3 = pulseIn(12,HIGH);
  ch4 = pulseIn(12,HIGH);

  dch1 = ch1 - och1;
  dch2 = ch2 - och2;
  dch3 = ch3 - och3;
  dch4 = ch4 - och4;
  
  if(enable){
    frLf.writeMicroseconds((ch3      ) + 3*dch2 );
    frRt.writeMicroseconds((ch3 + 370) + 3*dch2 );
    bkRt.writeMicroseconds((ch3 - 80 ) - 3*dch2 );
    bkLf.writeMicroseconds((ch3      ) - 3*dch2 );
  }

  och1 = ch1;
  och2 = ch2;
  och3 = ch3;
  och4 = ch4;
}





