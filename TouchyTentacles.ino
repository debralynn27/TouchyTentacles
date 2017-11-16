//Three dangling tentacles of light controlled by three touch sensors. By your powers combined, the tentacles activate! (but subtly and beautifully)
// Debra Lemak 11/10/17
#include "FastLED.h"
#include <CapacitiveSensor.h>
//https://github.com/PaulStoffregen/CapacitiveSensor

#define NUM_LEDS_PER_STRIP 25      // number of LEDs in strip
#define tent1pin 0                 // data pin for tentacle 1 strand of leds
#define tent2pin 1                 // data pin for tentacle 2 strand of leds
#define tent3pin 2                 // data pin for tentacle 3 strand of leds

CRGB leds; 
  
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
  fill_solid(tent1leds, NUM_LEDS_PER_STRIP, CRGB(0,0,0));         // fill all black
  fill_solid(tent2leds, NUM_LEDS_PER_STRIP, CRGB(0,0,0));         // fill all black
  fill_solid(tent3leds, NUM_LEDS_PER_STRIP, CRGB(0,0,0));         // fill all black
  FastLED.show();                                   // show 
  blendingType = LINEARBLEND;                       // options are LINEARBLEND or NOBLEND - linear is 'cleaner'
  //cs_4_6.set_CS_AutocaL_Millis(0xFFFFFFFF);         // turn off autocalibrate on channel 1 - just as an example
  //cs_4_8.set_CS_AutocaL_Millis(0xFFFFFFFF);         // turn off autocalibrate on channel 1 - just as an example
  //cs_4_10.set_CS_AutocaL_Millis(0xFFFFFFFF);         // turn off autocalibrate on channel 1 - just as an example
}

void loop(){
  //check sensors
  long sensor1 =  cs_4_6.capacitiveSensor(80);
  long sensor2 =  cs_4_8.capacitiveSensor(80);
  long sensor3 =  cs_4_10.capacitiveSensor(80);
  tentacle1(sensor1);
  tentacle2(sensor2);
  tentacle3(sensor3);
  FastLED.show();
  }
 
 
 
 void tentacle1(long sensor1){ 
   if(sensor1 >= 1000){
      purplepaint1();
      addYellowGlitter1(80);\7777777
  }
    else 
      aquapaint1(); 
    
  }
  
void tentacle2(long sensor2){ 
   if(sensor2 >= 1000){
     // addYellowGlitter(80, tent2leds);
      purplepaint2();
  }
    else 
      aquapaint2(); 
    
  }

   void tentacle3(long sensor3){ 
   if(sensor3 >= 1000){
   //   addYellowGlitter(80, tent3leds);
      purplepaint3();
  }
    else 
      aquapaint3(); 
    
  } 

//////
void addYellowGlitter1( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    tent1leds[ random16(NUM_LEDS_PER_STRIP) ] += CRGB::Yellow;
  }
}
////////////

void purplepaint1 (){
    for( int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    float fractionOfTheWayAlongTheStrip = (float)i / (float)(NUM_LEDS_PER_STRIP-1);
    uint8_t amountOfBlending = fractionOfTheWayAlongTheStrip * 255;
    CRGB pixelColor = blend( CRGB::Blue, CRGB::Red, amountOfBlending);
    tent1leds[i] = pixelColor;
  }}

void aquapaint1 (){
    for( int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    float fractionOfTheWayAlongTheStrip = (float)i / (float)(NUM_LEDS_PER_STRIP-1);
    uint8_t amountOfBlending = fractionOfTheWayAlongTheStrip * 255;
    CRGB pixelColor = blend( CRGB::Blue, CRGB::Green, amountOfBlending);
    tent1leds[i] = pixelColor;
  }}

void purplepaint2 (){
    for( int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    float fractionOfTheWayAlongTheStrip = (float)i / (float)(NUM_LEDS_PER_STRIP-1);
    uint8_t amountOfBlending = fractionOfTheWayAlongTheStrip * 255;
    CRGB pixelColor = blend( CRGB::Blue, CRGB::Red, amountOfBlending);
    tent2leds[i] = pixelColor;
  }}

void aquapaint2 (){
    for( int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    float fractionOfTheWayAlongTheStrip = (float)i / (float)(NUM_LEDS_PER_STRIP-1);
    uint8_t amountOfBlending = fractionOfTheWayAlongTheStrip * 255;
    CRGB pixelColor = blend( CRGB::Blue, CRGB::Green, amountOfBlending);
    tent2leds[i] = pixelColor;
  }}

void purplepaint3 (){
    for( int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    float fractionOfTheWayAlongTheStrip = (float)i / (float)(NUM_LEDS_PER_STRIP-1);
    uint8_t amountOfBlending = fractionOfTheWayAlongTheStrip * 255;
    CRGB pixelColor = blend( CRGB::Blue, CRGB::Red, amountOfBlending);
    tent3leds[i] = pixelColor;
  }}

void aquapaint3 (){
    for( int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    float fractionOfTheWayAlongTheStrip = (float)i / (float)(NUM_LEDS_PER_STRIP-1);
    uint8_t amountOfBlending = fractionOfTheWayAlongTheStrip * 255;
    CRGB pixelColor = blend( CRGB::Blue, CRGB::Green, amountOfBlending);
    tent3leds[i] = pixelColor;
  }}77k
