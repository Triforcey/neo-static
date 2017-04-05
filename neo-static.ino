#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      64

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

String serialString = "";
int pixelColor[3];
int rgbIndex = 0;
int pixelIndex = 0;

void setup() {
	pixels.begin();
	Serial.begin(115200);
	Serial.setTimeout(25);

	// For NeoPixels on Trinket.
	#if defined (__AVR_ATtiny85__)
	  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
	#endif
}

void loop() {
	while (Serial.available()) {
		char serialIn = Serial.read();
		if (isDigit(serialIn)) {
			serialString += serialIn;
		} else if (serialIn == '-') {
			pixelColor[rgbIndex] = serialString.toInt();
			serialString = "";
			rgbIndex++;
		} else if (serialIn == ',' || serialIn == '\n') {
			pixelColor[rgbIndex] = serialString.toInt();
			serialString = "";
			rgbIndex = 0;
			if (pixelIndex < NUMPIXELS) pixels.setPixelColor(pixelIndex, pixels.Color(pixelColor[0], pixelColor[1], pixelColor[2]));
			pixelIndex++;
		}
		if (serialIn == '\n') {
			pixelIndex = 0;
			pixels.show();
		}
	}
}
