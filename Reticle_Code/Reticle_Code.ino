#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(-1);

//this format allows easy manipulation of the image
int const sightcorner[][12] PROGMEM = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void setup() {


  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  //assemble and draw reticle

  //display.drawBitmap(0, 0,  reticleGerman_Stick_Sight, 128, 64, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.display();

}

void loop() {

  drawSightEdges(sightcorner, )
  display.display();
}

void initializeDisplay() {

}

//draw an image stored as an int array instead of byte array
//if i run out of space, then use this, it might save some
/*
void drawSightEdges(int image[][12] , bool flipLR = false, bool flipUpDown = false) {

  for (int i = 0; i <= (sizeof(image)) / sizeof(image[0]); i++) {
    for (int j = 0; j <= (sizeof(image[0])) / sizeof(image[0][0]); j++) {
      if(overwrite
      display.drawPixel(i, j, SSD1306_WHITE);
    }
  }
}
*/
long readVCC() {
  long result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(4); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA, ADSC));
  result = ADCL;
  result |= ADCH << 8;
  result = 1125300L / result; // Back-calculate AVcc in mV
  return result;
}
