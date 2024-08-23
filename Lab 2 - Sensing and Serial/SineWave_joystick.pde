/**
 * Sine Wave
 * by Daniel Shiffman.
 * Modified to take in Serial input from Arduino (with the format x, y, sw)
 * Render a simple sine wave.
 */

import processing.serial.*;

Serial myPort;  // Create object from Serial class
String val;      // Data received from the serial port

int xspacing = 16;   // How far apart should each horizontal location be spaced
int w;              // Width of entire wave

int canvasWidth = 640;
int canvasHeight = 4095;

int analogMax = 4095;
boolean sw = false;

int colorValue = 0;

float theta = 0.0;  // Start angle at 0
float amplitude = 75.0;  // Height of wave
float period = 500.0;  // How many pixels before the wave repeats
float dx;  // Value for incrementing X, a function of period and xspacing
float[] yvalues;  // Using an array to store height values for the wave

void setup() {
  size(640, 360);
  w = width+16;
  dx = (TWO_PI / period) * xspacing;
  yvalues = new float[w/xspacing];
 
  // set up serial
  printArray(Serial.list());
  String portName = Serial.list()[1];
  println(portName);
  myPort = new Serial(this, portName, 9600); // ensure baudrate is consistent with arduino sketch
}

void draw() {

  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.readStringUntil('\n');         // read it and store it in val
  }
  val = trim(val);
  println(val);
  int[] xyz = int(split(val, ','));

  // use if statement to check serial input length to prevent ArrayIndexOutOfBounds errors
  if (xyz.length == 3) {
    int x = xyz[0];
    int y = xyz[1];
    int z = xyz[2];

    xspacing = int(map(x, 0, analogMax, 15, 50)); // default is 500.0
    amplitude = map(y, analogMax, 0, 0, 150); // default is 75
    if (z == 0 ) {
      colorValue += 10;
      if (colorValue >= 255) {
        colorValue = 0;
      }
    }
  }
  background(color(0, 0, colorValue));
  calcWave();
  renderWave();
}

void calcWave() {
  // Increment theta (try different values for 'angular velocity' here
  theta += 0.02;

  // For every x value, calculate a y value with sine function
  float x = theta;
  for (int i = 0; i < yvalues.length; i++) {
    yvalues[i] = sin(x)*amplitude;
    x+=dx;
  }
}

void renderWave() {
  noStroke();
  fill(255);
  // A simple way to draw the wave with an ellipse at each location
  for (int x = 0; x < yvalues.length; x++) {
    ellipse(x*xspacing, height/2+yvalues[x], 16, 16);
  }
}
