/*
TouchInterrupt
This is an example how to use Touch Interrupts and read touch values
Just touch (or pinch) Pins 2 / 32 on the ESP 32 to read different values
*/

int threshold = 40; // the bigger the threshold, the more sensible is the touch
bool touchLeftDetected = false;
bool touchRightDetected = false;
uint8_t touchLeftVal = 0;
uint8_t touchRightVal = 0;

void gotTouchLeft(){
 touchLeftDetected = true;
 touchLeftVal = touchRead(T2);
}

void gotTouchRight(){
 touchRightDetected = true;
 touchRightVal = touchRead(T9);
}

void setup() {
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Interrupt Test");
  touchAttachInterrupt(T2, gotTouchLeft, threshold); // setup on T2, pin 2 on TTGO
  touchAttachInterrupt(T9, gotTouchRight, threshold); // setup on T9, pin 32 on TTGO
}

void loop(){
  if(touchLeftDetected){
    touchLeftDetected = false;
    Serial.println(touchLeftVal);
  }
  if(touchRightDetected){
    touchRightDetected = false;
    Serial.println(touchRightVal);
  }
}