#include <FastLED.h>

#define NUM_LEDS 360 //?? LEDs per branch

#define DATA_PIN 23
#define CLOCK_PIN 18

CRGB leds[NUM_LEDS];
int offset = 0;
byte masterhue;

void setup() { 

  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);

  //This is where the power is regulated.  These pebble lights are kinda weird, so it will be some trial an error....
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 1500);

  leds[0] = CRGB::Blue;
  FastLED.show();
  delay(500);
  masterhue = 0;
}

void loop() { 

  // *output 1 LED frame
  testPattern();
  FastLED.show();

  // *check for wifi communications
  if (gotCommand()) {

  }

  // *check for sensor detection
  if (gotSensor()) {

  }

  
  
  //delay(1);
  
  ++offset;
  if (offset>=NUM_LEDS) offset = 0;
}


//A few ideas for color patterns and interactive games:
// * 3 People, one on each side of tree.  Tree spins like the Wheel of Fortune wheel until it slows and lands on a winner.  Flashing light and marque to indicate winner.
// * Multiple people in front of trees, but not all of them.  Trees rotate which is lit until lands on winner.
// * Dark Blue Spruce color through the forest.  Lightning hits a tree (white flashing with sparkling sparks).  
//    Tree catches fire, orange and red flame grown from top of tree down, then spreads tree by three through the forest.  To put the fire out, three people need to stand on all sides of each tree.  When they do the fire starts burning out until the tree is saved and goes back to spruce color.  Tree can reignite though if the ones next to it are still on fire.  Takes a group effort to stop the forest fire. 
// * Graphic EQ mode: Add a microphone to the master tree and turn the forest into a graphic EQ display for music being played, each tree a different frequency by way of Fourier transform.
//
//Color patters:
// * Default Blue Spruce mode: Blue/green colored trees.
// * Tree Rotate: 3 sides rotate color to make it look like the tree is spinning.
// * Sparkle: Add glitter sparkling white LEDs to the trees.
// * Color grow up from bottom to top of trees.
// * Tree Strobe on (all as the same time, randomly, or rotating through forest)