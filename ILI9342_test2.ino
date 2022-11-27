#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "M5CoreDisplay.h"

auto LCD = M5CoreDisplay();
long long t1, t2;


void setup() {
  Serial.begin(115200);
  delay(1000); // otherwise ESP32 screws up serial console.
  LCD.begin();
  t1 = millis();
  LCD.fillScreen(WHITE);
  delay(100);
  LCD.fillScreen(RED);
  delay(100);
  LCD.fillScreen(GREEN);
  delay(100);
  LCD.fillScreen(BLUE);
  delay(100);
  LCD.fillScreen(BLACK);
  delay(100);

  LCD.setCursor(10, 10);        //Move the cursor position to (x,y).
  LCD.setTextColor(WHITE);      //Set the font color to white.
  LCD.setTextSize(1);           //Set the font size
  LCD.printf("Display Test!");  //Serial output format string.

  // draw graphic
  delay(100);
  LCD.drawRect(100, 100, 50, 50, BLUE);  // draw a 50x50 blue rectangle outline at (x,y).
  delay(100);
  LCD.fillRect(100, 100, 50, 50, BLUE);  // draw a blue filled rectangle 50x50 at (x,y)
  delay(100);
  LCD.drawCircle(100, 100, 50, RED);     // draw a red circle outline. radius 50, center (x,y)
  delay(100);
  LCD.fillCircle(100, 100, 50, RED);     // draw a filled red circle
  delay(100);
  LCD.drawTriangle(30, 30, 180, 100, 80, 150, YELLOW); // triangle outline with vertices (x1,y1),(x2,y2),(x3,y3)
  delay(100);
  LCD.fillTriangle(30, 30, 180, 100, 80, 150, YELLOW); // now filled one.
  t2 = millis();
  Serial.println(t2-t1); // 1277ms. 1100ms sleep -> 177ms



}


void loop() {
  // draw triangles randomly on screen with random colour.
  LCD.fillTriangle(random(LCD.width()-1), random(LCD.height()-1),
                   random(LCD.width()-1), random(LCD.height()-1),
                   random(LCD.width()-1), random(LCD.height()-1),
                   random(0xfffe));
}
