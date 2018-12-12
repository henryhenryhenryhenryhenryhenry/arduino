unsigned long oldms =0;
unsigned long newms;
long interval = 1000;
int ledState = LOW;

void setup() {
  pinMode(13,OUTPUT);
}

void loop() {
  newms=millis();
  if(newms-oldms>=interval){
    oldms=newms;
    if(ledState == LOW){
      ledState = HIGH;
    }else{
      ledState = LOW;
    }
    digitalWrite(13, ledState);
    if(interval<10){
      interval = 1000;
    }else{
      interval-=10;
    }
  }
}

