// include the necessary libraries
#include <SPI.h>
#include <SD.h>
#include <TFT.h>  // Arduino LCD library

// pin definition for the Uno
#define sd_cs  4
#define lcd_cs 10
#define dc     9
#define rst    8

// pin definition for the Leonardo
//#define sd_cs  8
//#define lcd_cs 7
//#define dc     0
//#define rst    1

TFT TFTscreen = TFT(lcd_cs, dc, rst);

// this variable represents the image to be drawn on screen
PImage image1;

void setup() {
  // initialize the GLCD and show a message
  // asking the user to open the serial line
  TFTscreen.begin();
  TFTscreen.background(255, 0, 0);
  delay(10);
  TFTscreen.background(0, 255, 0);
  delay(10);
  TFTscreen.background(0, 0, 255);
  delay(10);
  TFTscreen.background(0, 0, 0);
  delay(10);

  TFTscreen.stroke(0, 0, 255);
  TFTscreen.println();
  TFTscreen.println(F("Arduino TFT Bitmap Example"));
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.println(F("Initializing"));
  delay(1000);
  
  //TFTscreen.background(255, 255, 255);

  TFTscreen.println(F("Initializing SD card"));
  if (!SD.begin(sd_cs)) {
    TFTscreen.println(F("no SD card found"));
  }else{
    TFTscreen.println(F("SD card OK"));
  }

  image1 = TFTscreen.loadImage("arduino.bmp");
  if (!image1.isValid()) {
    TFTscreen.println(F("images failed to load"));
  }else{
    TFTscreen.println(F("images loaded successfully"));
  }

  int width = TFTscreen.width();
  int height = TFTscreen.height();
  
  TFTscreen.println(F("screen is 128 by 160 px"));
  TFTscreen.println(F("filler"));
  TFTscreen.println(F("filler."));
  TFTscreen.println(F("filler.."));
  TFTscreen.println(F("filler..."));
  TFTscreen.println(F("filler...."));
  TFTscreen.println(F("filler"));
  TFTscreen.println(F("filler."));
  
  TFTscreen.image(image1, 159, 127);

}

void loop() {
  // put your main code here, to run repeatedly:

}
