/**************************************************************************
  Draws concentric rounded rectangles using drawSmoothRoundRect
 **************************************************************************/
#include <TFT_eSPI.h> 
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI(); 

void setup() {
  tft.init();
  tft.setRotation(1);   // 1 = landscape, 2 = portrait
  Serial.begin(115200);
}

void loop() {
  concentricRects();
}

void concentricRects(){
  tft.fillScreen(TFT_BLACK);
  uint16_t color = TFT_GREEN;
  uint16_t colors[4] = {TFT_GREEN, TFT_CYAN, TFT_MAGENTA, TFT_PINK};
  for (int16_t x = 0; x < tft.width(); x += 10) {
    int index = random(sizeof(colors)) / sizeof(colors[0]) ;
    tft.drawSmoothRoundRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2, 1, 1, x, x, colors[index]);
    // toggle below to compare how smoothRoundRect compares to regular rect.  drawSmooth functions handle anti-aliasing
    // tft.drawRect(tft.width() / 2 - x / 2, tft.height() / 2 - x / 2 , x, x, color);
    delay(500);
  }
}