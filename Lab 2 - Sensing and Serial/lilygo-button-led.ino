/*
  LILYGO LED & Pushbutton Example
  Pushbutton on 15
  LED on 2 with 220Ω resistor
*/

#define BUTTON_PIN 15
#define LED_PIN 2

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // use internal pullup resistor
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  Serial.println(buttonState);

  if (!buttonState) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
