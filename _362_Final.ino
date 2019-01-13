// Turning NeoPixels on and off using a HC-SRO4 Ping Sensor

/*
   This sketch reads a HC-SR04 ultrasonic rangefinder and returns the
   distance to the closest object in range. To do this, it sends a pulse
   to the sensor to initiate a reading, then listens for a pulse
   to return.  The length of the returning pulse is proportional to
   the distance of the object from the sensor.
   The Arduino then takes this information and illuminates a strip of
   NeoPixel's based on the distance of the object from the sensor.
   This code was developed partially from Ping))) code found in the public domain
   written by David A. Mellis, and adapted to the HC-SRO4 by Tautvidas Sipavicius,
   while other portions were written by Charles Gantt and Curtis Gauger from
   http://www.themakersworkbench.com.
 */

//Tell the Arduino IDE to include the FastLED library
#include <FastLED.h>
#include <Adafruit_NeoPixel.h>

//Setup the variables for the HC-SR04
//const int trigPin = 8;
//const int echoPin = 7;
//const int trigPin = A0;
//const int echoPin =A1;

//Setup the variables for the NeoPixel Strip
#define NUM_LEDS 3 // How many leds in your strip?
#define DATA_PIN 8 // What pin is the NeoPixel's data line connected to?
CRGB leds[NUM_LEDS]; // Define the array of leds

Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, DATA_PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
   //pinMode(trigPin, OUTPUT);
   //pinMode(echoPin, OUTPUT);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  //long duration, inches, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  /*// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  Serial.print(duration);
  Serial.println();
  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if ((inches <= 20))
  {*/
    fill_solid( &(leds[0]), NUM_LEDS /*number of leds*/, CRGB::Red); //{whitestrobe(30); //rainbowCycle(uint8_t
    //FastLED.show();
  //}
  //else if (inches >= 11) {
    //fill_solid( &(leds[0]), NUM_LEDS /*number of leds*/, CRGB::Black);
    //FastLED.show();
  //}
//rainbowCycle(100);
  //delay(100);
}
// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


