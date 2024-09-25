#include <TFT_eSPI.h>   
#define WIDTH 240
#define HEIGHT 135    

TFT_eSPI tft = TFT_eSPI();  
TFT_eSprite spr = TFT_eSprite(&tft);
TFT_eSprite bkg = TFT_eSprite(&tft);

// Include the header files that contain the icons
#include "shiba.h"

uint16_t colors[4] = {TFT_GREEN, TFT_CYAN, TFT_MAGENTA, TFT_PINK};

void setup()
{
  tft.begin();
  tft.setRotation(1);	// landscape
  tft.setSwapBytes(true);
  
  bkg.createSprite(WIDTH, HEIGHT);
  bkg.setSwapBytes(true);
  spr.createSprite(WIDTH, HEIGHT);
}

int x_pos = 0;

void loop() {
  // Draw the icons
  bkg.fillSprite(TFT_BLUE);
  spr.pushImage(0, 0, shibaWidth, shibaHeight, shiba);
  spr.pushToSprite(&bkg, x_pos, tft.height()/2 - shibaHeight/2, TFT_BLACK);
  bkg.pushSprite(0, 0);

  x_pos +=1;
  if(x_pos > tft.width()) { x_pos = -shibaWidth;}
}