#include <TFT_eSPI.h>

#define WIDTH 135
#define HEIGHT 240
#define SIZE1 50
#define SIZE2 25

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite spr = TFT_eSprite(&tft);

uint16_t red = 0xB926;
uint16_t pink = 0xD4D7;

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  spr.createSprite(HEIGHT, WIDTH);
}

void drawCircle1() {
  spr.fillCircle(tft.width()/2, tft.height()/2, SIZE1, TFT_BLUE);
  spr.fillRect(tft.width()/2-SIZE1/2, tft.height()/2-SIZE1/2, SIZE1, SIZE1, TFT_YELLOW);
  spr.pushSprite(0, 0);
}

void drawCircle2() {
  spr.fillCircle(tft.width()/2, tft.height()/2, SIZE2, TFT_GREEN);
  spr.fillRect(tft.width()/2-SIZE2/2, tft.height()/2-SIZE2/2, SIZE2, SIZE2, TFT_PURPLE);
  spr.pushSprite(0, 0);
}

int counter = 0;

void loop() {
  spr.fillSprite(TFT_BLACK);
  if (counter % 2) {
    drawCircle1();
  } else {
    drawCircle2();
  }
  counter += 1;
  delay(500);
}
