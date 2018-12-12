#include <Time.h>

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  if(second()%2==1){
    digitalWrite(13, HIGH);
  }else if(second()%2==0){
    digitalWrite(13, LOW);
  }
}
