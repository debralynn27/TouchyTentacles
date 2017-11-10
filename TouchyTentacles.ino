//Three dangling tentacles of light controlled by three touch sensors. By your powers combined, the tentacles activate! (but subtly and beautifully)
// Debra Lemak 11/10/17
#include <FastLED.h>
#define NUM_LEDS 25
#define BRIGHTNESS  20
#define FRAMES_PER_SECOND 60
#define NUM_LEDS_PER_STRIP 25
#define ON 1
#define OFF 0
CRGB tentacle01[NUM_LEDS_PER_STRIP];
CRGB tentacle02[NUM_LEDS_PER_STRIP];
CRGB tentacle03[NUM_LEDS_PER_STRIP];


// constants won't change. They're used here to set pin numbers:
const int touchSensor01 = 8;     // the number of the pushbutton pin
const int touchSensor02 = 9;     // the number of the pushbutton pin
const int touchSensor03 = 10;     // the number of the pushbutton pin

// variables will change:

int sensor01Status = OFF;
int sensor02Status = OFF;
int sensor03Status = OFF;

int ledMode = 0;

void setup() {
  //Serial.begin(9600); not using Serial because I have found issues with serial messages causing my code not to work, 
  //some day I'll have more time to debug and figure out why, but for now we'll just turn it off and look away 
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin01, INPUT_PULLUP);
  pinMode(buttonPin02, INPUT_PULLUP);
  pinMode(buttonPin03, INPUT_PULLUP);
  FastLED.addLeds<WS2811, 1>(tentacle01, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 2>(tentacle02, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 3>(tentacle03, NUM_LEDS_PER_STRIP);
  FastLED.setBrightness( BRIGHTNESS );
  FastLED.clear();
}

/*
 * Main loop
 */
void loop() {
  checkInputs();
  renderEffects();
  FastLED.show();
  FastLED.delay(1000/FRAMES_PER_SECOND); 
}

/**
 * Check our inputs and set the sensor status
 */
void checkInputs() {
  // Read pins
  if (digitalRead(touchSensor01) == LOW) {
    sensor01Status = ON;
  } 
  
  if (digitalRead(touchSensor02) == LOW) {
    sensor02Status = ON;
  } 
  
  if (digitalRead(touchSensor03) == LOW) {
    sensor03Status = ON;
  } 
}

/**
 * Handle the button state to render effects
 */
void renderEffects() {
    switch (buttonPressed) {
    case buttonPin01:     
      rainbowWithGlitter();
      break;
    case buttonPin02:     
      bpm();
      break;
    case buttonPin03:     
      juggle();
      break;
    case 0:     
      break;
  }
}





void addGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}


