/* 
  LILYGO Joystick Example
  Joystick X, Y, and SW are connected to pins 39, 32, and 33
  Prints out X, Y, Z values to Serial
*/

int xyzPins[] = {39, 32, 33};   //x, y, z(switch) pins
void setup() {
  Serial.begin(9600);
  pinMode(xyzPins[2], INPUT_PULLUP);  // pullup resistor for switch
}
void loop() {
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  Serial.printf("%d,%d,%d", xVal, yVal, zVal);
  Serial.println();
  delay(100);
}