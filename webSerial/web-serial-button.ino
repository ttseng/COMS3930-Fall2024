/*
  Web Serial Example
  Writes "L" when Left button (GPIO0) is pressed and "R" with Right button (GPIO35) is pressed
  Prints received message onto display
*/

#include "TFT_eSPI.h"

TFT_eSPI tft= TFT_eSPI();

#define BUTTON_LEFT 0
#define BUTTON_RIGHT 35

volatile bool leftButtonPressed = false;
volatile bool rightButtonPressed = false;

void setup() {
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(1);

  pinMode(BUTTON_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_LEFT), pressedLeftButton, FALLING);
  attachInterrupt(digitalPinToInterrupt(BUTTON_RIGHT), pressedRightButton, FALLING);
  Serial.begin(115200);
}

void pressedLeftButton() {
  leftButtonPressed = true;
}

void pressedRightButton() {
  rightButtonPressed = true;
}

void loop() {
  if (leftButtonPressed) {
    Serial.println("L");
    leftButtonPressed = false;
  }
  if (rightButtonPressed) {
    Serial.println("R");
    rightButtonPressed = false;
  }

  // check if there's any incoming serial data
  if (Serial.available() > 0) {
    // clear last message
    tft.fillScreen(TFT_BLACK);

    // get new message
    String message = Serial.readStringUntil('\n');

    // display the message on the ESP32 display
    tft.setCursor(0, 0);
    tft.setTextSize(5);
    tft.println(message);
  }
}
