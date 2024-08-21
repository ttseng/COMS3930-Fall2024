#include "TFT_eSPI.h"

TFT_eSPI tft= TFT_eSPI();

void setup() {
  tft.init();
  tft.setRotation(1); // 1 = landscape, 2 = portrait
  tft.fillScreen(TFT_BLUE);
}

void loop() {
  tft.setTextWrap(true);
  tft.setTextSize(3);
  
  tft.setCursor(0, 0); // origin
  tft.setTextColor(TFT_WHITE);
  tft.setTextFont(1);
  
  tft.println("Hello World!");

  tft.setTextColor(TFT_YELLOW);
  tft.println(123456);
}