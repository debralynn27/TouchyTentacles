//Three dangling tentacles of light controlled by three touch sensors. By your powers combined, the tentacles activate! (but subtly and beautifully)
// Debra Lemak 11/10/17
#include "FastLED.h"
#include <CapacitiveSensor.h>
//https://github.com/PaulStoffregen/CapacitiveSensor

#define NUM_LEDS_PER_STRIP 25      // number of LEDs in strip
#define tent1pin 0                 // data pin for tentacle 1 strand of leds
#define tent2pin 1                 // data pin for tentacle 2 strand of leds
#define tent3pin 2                 // data pin for tentacle 3 strand of leds
  
CRGB tent1leds[NUM_LEDS_PER_STRIP];
CRGB tent2leds[NUM_LEDS_PER_STRIP];
CRGB tent3leds[NUM_LEDS_PER_STRIP];

CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);   // 1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);   // 1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_10 = CapacitiveSensor(4,10); // 1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

TBlendType blendingType; 
//tBlendType is a data type like int/char/uint8_t etc., used to choose LINERBLEND and NOBLEND



void setup()
{
  delay(2000);                                      // saftey first  
  FastLED.addLeds<WS2811,tent1pin,RGB>(tent1leds,NUM_LEDS_PER_STRIP);   
  FastLED.addLeds<WS2811,tent2pin,RGB>(tent2leds,NUM_LEDS_PER_STRIP);   
  FastLED.addLeds<WS2811,tent3pin,RGB>(tent3leds,NUM_LEDS_PER_STRIP);   
  fill_solid(tent1leds, NUM_LEDS, CRGB(0,0,0));         // fill all black
  fill_solid(tent2leds, NUM_LEDS, CRGB(0,0,0));         // fill all black
  fill_solid(tent3leds, NUM_LEDS, CRGB(0,0,0));         // fill all black
  FastLED.show();                                   // show 
  blendingType = LINEARBLEND;                       // options are LINEARBLEND or NOBLEND - linear is 'cleaner'
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);         // turn off autocalibrate on channel 1 - just as an example
}

void loop(){
  //check sensors
  long sensor1 =  cs_4_6.capacitiveSensor(50);
  long sensor2 =  cs_4_8.capacitiveSensor(50);
  long sensor3 =  cs_4_10.capacitiveSensor(50);
  
  //assign colors to tentacle lights
  tentacle1();
  tentacle2();
  tentacle3();
  FastLED.show();
  }
 
 
 
 void tentacle1(){ 
   if(sensor1 >= 1000){
      addYellowGlitter(80,tent1leds );
      purplepaint(tent1leds);
  }
    else 
      aquapaint(tent1leds); 
    
  }
  
  void tentacle2(){ 
   if(sensor2 >= 1000){
      addYellowGlitter(80, tent2leds);
      purplepaint(tent2leds);
  }
    else 
      aquapaint(tent2leds); 
    
  }
  
   void tentacle3(){ 
   if(sensor3 >= 1000){
      addYellowGlitter(80, tent3leds);
      purplepaint(tent3leds);
  }
    else 
      aquapaint(tent3leds); 
    
  } 

//////
void addYellowGlitter( fract8 chanceOfGlitter, int leds) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS_PER_STRIP) ] += CRGB::Yellow;
  }
}
////////////

//////
void addBlueGlitter( fract8 chanceOfGlitter, int leds) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS_PER_STRIP) ] += CRGB::Blue;
  }
}
////////////

void purplepaint (int leds){
    for( int i = 0; i < NUM_LEDS_PER_STRIP; i++) {

    // First, figure out what 'percentage' of the way along
    // the strip we are at this particular pixel:
    float fractionOfTheWayAlongTheStrip = (float)i / (float)(NUM_LEDS-1);

    // Now calculate how much of each color we should blend together
    // at this particular point along the strip.
    // 0 = pure 'start color', 255 = pure 'end color'
    uint8_t amountOfBlending = fractionOfTheWayAlongTheStrip * 255;

    // Mix up a new color, which is a blend of the start and end colors
    // Use the blend function to get the right mix for this particular pixel
    CRGB pixelColor = blend( CRGB::Blue, CRGB::Red, amountOfBlending);

    // set this pixel to the blended color:
    leds[i] = pixelColor;
  }}

void aquapaint (int leds){
    for( int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    float fractionOfTheWayAlongTheStrip = (float)i / (float)(NUM_LEDS-1);
    uint8_t amountOfBlending = fractionOfTheWayAlongTheStrip * 255;
    CRGB pixelColor = blend( CRGB::Blue, CRGB::Green, amountOfBlending);
    leds[i] = pixelColor;
  }}
