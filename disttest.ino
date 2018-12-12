#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_24bargraph bar = Adafruit_24bargraph();

#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters).
                        //Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);//NewPing setup of pins and maximum distance

double percentDist =0;
int filled =0;
int pingval=0;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

  bar.begin(0x70);  // pass in the address
  bar.setBrightness(15);// (0-15)
  
  int i;
  for(i=0;i<24;i++){
    bar.setBar(i, LED_RED);
    bar.writeDisplay();
    delay(10);
  }

  for(i=0;i<24;i++){
    bar.setBar(i, LED_YELLOW);
    bar.writeDisplay();
    delay(10);
  }

  for(i=0;i<24;i++){
    bar.setBar(i, LED_GREEN);
    bar.writeDisplay();
    delay(10);
  }


  pinMode(9, OUTPUT); // Sets the trigPin as an Output
  pinMode(10, INPUT); // Sets the echoPin as an Input
}



void loop() {
  delay(30);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  bar.clear();
  pingval=sonar.ping_cm();
  Serial.print("Ping: ");
  Serial.print(pingval); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  bar.setBar(pingval/3, LED_YELLOW);
  bar.writeDisplay();
}
