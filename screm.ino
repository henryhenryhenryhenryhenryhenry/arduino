#include <math.h>

#define x1pin 2
#define y1pin 3
#define x2pin 4
#define y2pin 5
#define x3pin 6
#define y3pin 7

#define alarm_pin 8


//x is fwd, y is up
int pulse1x, pulse1y;
int acc1x, acc1y;

int pulse2x, pulse2y;
int acc2x, acc2y;

int pulse3x, pulse3y;
int acc3x, acc3y;

int sum_acc_x, sum_acc_y;

unsigned int ledstate = 0;

double angle_abv_hrzn;
double rad2deg = 180/3.14;

int alarm_pwm = 0;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  
  digitalWrite(13, ledstate);

  Serial.begin(9600);
  pinMode(x1pin, INPUT);
  pinMode(y1pin, INPUT);
  pinMode(x2pin, INPUT);
  pinMode(y2pin, INPUT);
  pinMode(x3pin, INPUT);
  pinMode(y3pin, INPUT);
}

void loop() {
  alarm_pwm = pulseIn(alarm_pin, HIGH);
  
  pulse1x = pulseIn(x1pin, HIGH);
  pulse1y = pulseIn(y1pin, HIGH);

  pulse2x = pulseIn(x2pin, HIGH);
  pulse2y = pulseIn(y2pin, HIGH);

  pulse3x = pulseIn(x3pin, HIGH);
  pulse3y = pulseIn(y3pin, HIGH);

  acc1x = ((pulse1x / 10) - 500) * 8;
  acc1y = ((pulse1y / 10) - 500) * 8;

  acc2x = ((pulse2x / 10) - 500) * 8;
  acc2y = ((pulse2y / 10) - 500) * 8;

  acc3x = ((pulse3x / 10) - 500) * 8;
  acc3y = ((pulse3y / 10) - 500) * 8;


  sum_acc_x = (acc1x + acc2x + acc3x)/3;
  sum_acc_y = (acc1y + acc2y + acc3y)/3;
  angle_abv_hrzn = atan2(sum_acc_y , sum_acc_x);
  angle_abv_hrzn = angle_abv_hrzn * rad2deg;
  angle_abv_hrzn += 90;
  
  /*
  Serial.print(acc1x);
  Serial.print("\t");
  Serial.print(acc2x);
  Serial.print("\t");
  Serial.print(acc3x);
  Serial.print("\t");
  */
  Serial.print(sum_acc_x);
  Serial.print("\t");

  /*
  Serial.print(acc1y);
  Serial.print("\t");
  Serial.print(acc2y);
  Serial.print("\t");
  Serial.print(acc3y);
  Serial.print("\t");
  */
  Serial.print(sum_acc_y);
  Serial.print("\t");

  Serial.print("angle above horiz: ");
  Serial.print(angle_abv_hrzn);
  Serial.print("\t");
  
  Serial.println();
  delay(100);

  if(angle_abv_hrzn < -50 || angle_abv_hrzn > 250){
    ledstate = 1;
  }else if(alarm_pwm > 1500){
    ledstate = 1;
  }else{
    ledstate = 0;
  }

  digitalWrite(13, ledstate);
}
