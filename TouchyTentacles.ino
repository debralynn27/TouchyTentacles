//Three dangling tentacles of light controlled by three touch sensors. By your powers combined, the tentacles activate! (but subtly and beautifully)
// Debra Lemak 11/10/17
#include "FastLED.h"
#include <CapacitiveSensor.h>
//https://github.com/PaulStoffregen/CapacitiveSensor

#define NUM_LEDS 25       // number of LEDs in strip - count starts at 0, not 1
#define DataPin 3        // data pin
int t1count = 0;

CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8); // 1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

CRGB startColor( CRGB::Red);
CRGB endColor( CRGB::Blue);

TBlendType blendingType; //tBlendType is a data type like int/char/uint8_t etc., used to choose LINERBLEND and NOBLEND

CRGB leds[NUM_LEDS];

void setup()
{
  delay(2000);                                      // saftey first  
  FastLED.addLeds<WS2811,DataPin,RGB>(leds,NUM_LEDS);   //.setCorrection(CRGB( 255, 255, 240));
  fill_solid(leds, NUM_LEDS, CRGB(0,0,0));         // fill all black
  FastLED.show();                                   // show 
  Serial.begin(115200);                             // monitor speed
  blendingType = LINEARBLEND;                       // options are LINEARBLEND or NOBLEND - linear is 'cleaner'
  cs_4_8.set_CS_AutocaL_Millis(0xFFFFFFFF);// turn off autocalibrate on channel 1 - just as an example
}

void loop(){
  long sensor1 =  cs_4_8.capacitiveSensor(50);
  purplepaint();
 
  if(sensor1 >= 1000&&t1count <500){
  addYellowGlitter(80);
  purplepaint();
  t1count ++;
  }
  else if (sensor1 >= 1000&&t1count >=500)
  {
    orangepaint();
    addBlueGlitter(80);
  }
  
    FastLED.show();
  }
 

//////
void addYellowGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::Yellow;
  }
}
////////////

//////
void addBlueGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::Blue;
  }
}
////////////

void purplepaint (){
    for( int i = 0; i < NUM_LEDS; i++) {

    // First, figure out what 'percentage' of the way along
    // the strip we are at this particular pixel:
    float fractionOfTheWayAlongTheStrip = (float)i / (float)(NUM_LEDS-1);

    // Now calculate how much of each color we should blend together
    // at this particular point along the strip.
    // 0 = pure 'start color', 255 = pure 'end color'
    uint8_t amountOfBlending = fractionOfTheWayAlongTheStrip * 255;

    // Mix up a new color, which is a blend of the start and end colors
    // Use the blend function to get the right mix for this particular pixel
    CRGB pixelColor = blend( CRGB::Red, CRGB::Blue, amountOfBlending);

    // set this pixel to the blended color:
    leds[i] = pixelColor;
  }}

void orangepaint (){
    for( int i = 0; i < NUM_LEDS; i++) {
    float fractionOfTheWayAlongTheStrip = (float)i / (float)(NUM_LEDS-1);
    uint8_t amountOfBlending = fractionOfTheWayAlongTheStrip * 255;
    CRGB pixelColor = blend( CRGB::Red, CRGB::Yellow, amountOfBlending);
    leds[i] = pixelColor;
  }}
