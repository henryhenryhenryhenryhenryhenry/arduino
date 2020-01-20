
/************************
 * type in text via serial
 * arduino will convert it to morse and send it out on pin 13
 * 
 * 
 * A .-
 * B -...
 * C -.-.
 * D -..
 * E .
 * F ..-.
 * G --.
 * H ....
 * I ..
 * J .---
 * K -.-
 * L .-..
 * M --
 * N -.
 * O ---
 * P .--.
 * Q --.-
 * R .-.
 * S ...
 * T -
 * U ..-
 * V ..-
 * W .--
 * X -..-
 * Y -.--
 * Z --..
 * 
 * 1 .----
 * 2 ..---
 * 3 ...--
 * 4 ....-
 * 5 .....
 * 6 -....
 * 7 --...
 * 8 ---..
 * 9 ----.
 * 0 -----
 * 
 */
static unsigned int waittime = 100;
static unsigned int long_pulse_time = 5;
static unsigned int short_pulse_time = 1;
static unsigned int between_word_time = 5;
static unsigned int between_pulse_time = 3;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);

  delay(waittime);
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  
  Serial.begin(9600);
  while(!Serial){;}

  Serial.println();
  Serial.println("type text and arduino will output morse");
  Serial.println();

}

void loop() {
  
  if (Serial.available() > 0) {
    int char1 = Serial.read();
    //Serial.println(char1);
    char char2 = char1;
    //Serial.println(char2);
    printmorse(char1);


  }
}

void printmorse(char x){
  Serial.println();
  if(x == ' '){
    Serial.print("space ");
    delay(between_word_time * waittime);
    return;
  }
  if( !( x>=48 && x<=57 ) && !( x>=65 && x<=90 ) && !( x>=97 && x<=122) ){
    Serial.println("invalid character");
    return;
  }
  if( x>=65 && x<=90){
    x+=32;
  }
  switch(x){
    case 'a': Serial.print("a ");
      ps();pl();
      break;
    case 'b': Serial.print("b ");
      pl();ps();ps();ps();
      break;
    case 'c': Serial.print("c ");
      pl();ps();pl();ps();
      break;
    case 'd': Serial.print("d ");
      pl();ps();ps();
      break;
    case 'e': Serial.print("e ");
      ps();
      break;
    case 'f': Serial.print("f ");
      ps();ps();pl();ps();
      break;
    case 'g': Serial.print("g ");
      pl();pl();ps();
      break;
    case 'h': Serial.print("h ");
      ps();ps();ps();ps();
      break;
    case 'i': Serial.print("i ");
      ps();ps();
      break;
    case 'j': Serial.print("j ");
      ps();pl();pl();pl();
      break;
    case 'k': Serial.print("k ");
      pl();ps();pl();
      break;
    case 'l': Serial.print("l ");
      ps();pl();ps();ps();
      break;
    case 'm': Serial.print("m ");
      pl();pl();
      break;
    case 'n': Serial.print("n ");
      pl();ps();
      break;
    case 'o': Serial.print("o ");
      pl();pl();pl();
      break;
    case 'p': Serial.print("p ");
      ps();pl();pl();ps();
      break;
    case 'q': Serial.print("q ");
      pl();pl();ps();pl();
      break;
    case 'r': Serial.print("r ");
      ps();pl();ps();
      break;
    case 's': Serial.print("s ");
      ps();ps();ps();
      break;
    case 't': Serial.print("t ");
      pl();
      break;
    case 'u': Serial.print("u ");
      ps();ps();pl();
      break;
    case 'v': Serial.print("v ");
      ps();ps();ps();pl();
      break;
    case 'w': Serial.print("w ");
      ps();pl();pl();
      break;
    case 'x': Serial.print("x ");
      pl();ps();ps();pl();
      break;
    case 'y': Serial.print("y ");
      pl();ps();pl();pl();
      break;
    case 'z': Serial.print("z ");
      pl();pl();ps();ps();
      break;
    case '0': Serial.print("0 ");
      pl();pl();pl();pl();pl();
      break;
    case '1': Serial.print("1 ");
      ps();pl();pl();pl();pl();
      break;
    case '2': Serial.print("2 ");
      ps();ps();pl();pl();pl();
      break;
    case '3': Serial.print("3 ");
      ps();ps();ps();pl();pl();
      break;
    case '4': Serial.print("4 ");
      ps();ps();ps();ps();pl();
      break;
    case '5': Serial.print("5 ");
      ps();ps();ps();ps();ps();
      break;
    case '6': Serial.print("6 ");
      pl();ps();ps();ps();ps();
      break;
    case '7': Serial.print("7 ");
      pl();pl();ps();ps();ps();
      break;
    case '8': Serial.print("8 ");
      pl();pl();pl();ps();ps();
      break;
    case '9': Serial.print("9 ");
      pl();pl();pl();pl();ps();
      break;
  }
}

void pl(){//pulse long
  Serial.print("-");
  digitalWrite(13, HIGH);
  //digitalWrite(12, HIGH);
  delay( long_pulse_time * waittime );
  digitalWrite(13, LOW);
  //digitalWrite(12, LOW);
  delay( between_pulse_time * waittime );
}

void ps(){//pulse short
  Serial.print(".");
  digitalWrite(13, HIGH);
  //digitalWrite(11, HIGH);
  delay( short_pulse_time * waittime );
  digitalWrite(13, LOW);
  //digitalWrite(11, LOW);
  delay( between_pulse_time * waittime );
}














