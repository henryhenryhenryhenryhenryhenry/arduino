void setup() {
  pinMode(13,OUTPUT);//B
  pinMode(12,OUTPUT);//G
  pinMode(11,OUTPUT);//R

}

void loop() {
  ledBlack();
  //ledWhite();
  ledRed();
  ledGreen();
  ledBlue();
  //ledCyan();
  //ledYellow();
  //ledMagenta();
}

void ledRed(){
  digitalWrite(11, HIGH);//R
  digitalWrite(12, LOW);//G
  digitalWrite(13, LOW);//B
  delay(500);
}
void ledGreen(){
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(500);
}
void ledBlue(){
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(500);
}
void ledCyan(){
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  delay(500);
}
void ledYellow(){
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(500);
}
void ledMagenta(){
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(500);
}
void ledWhite(){
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  delay(500);
}
void ledBlack(){
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  delay(500);
}

