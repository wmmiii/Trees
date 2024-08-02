

// colorful test pattern
void testPattern() {
  for (int i = 0; i < NUM_LEDS; ++i) leds[i] = CRGB::Black; 
  byte _hue = 0;
  if (masterHue >= 255) {
    masterHue = 0;
  } else {
    ++masterHue;
  }
  _hue = masterHue;
 
  // for (int i=0;i<(NUM_LEDS)-offset; ++i) {
  //   if (i+offset < NUM_LEDS) {
  //     leds[i+offset] = CHSV(_hue, 255, 255);
  //     if (_hue >= 255) {
  //       _hue = 0;
  //     } else {
  //       ++_hue;
  //     }
  //   }
  // }
  
  for (int i=0;i<120; ++i) {
      leds[i] = CRGB::Red;
      leds[i+120] = CRGB::Blue;
      leds[i+240] = CRGB::Green;
      leds[random(360)] = CRGB::White;
    }
  
}

//default blue spruce mode
void blueSpruce() {
  for (int i=0;i<NUM_LEDS; ++i) {
    //the random blue tint is to make it shimmer
    if (random8(10)==1) {
      leds[i] = CHSV(2, 255, 64); //blueish
    } else {
      leds[i] = CHSV(47, 255, 64); //greenish
    }
    
  }
}

//activate
void activate(int side) {
  //side = 1, 2, or 3 (it's the side of the tree that detected motion)
  //up from bottom of activated side to top and then down to bottom of 2 other sides
  //use 1/3 of the offset
  for (int i=60; i<floor(offset/3)+60; ++i) {

  }
}

//tree rotate


//sparkle


//tree strobe


//colorful


//gradient wipe
void gradientWipe() {
  // A slow changing base gradient that is periodically "wiped" away with a
  // gradient of a new set of hues.
  // https://www.desmos.com/calculator/kbbzcf0hgr

  // A value that is used to map each LED index onto a shifting gradient. Higher
  // gives the LEDs a more uniform color.
  // Range: [1, NUM_LED]
  static int GRADIENT_SPREAD = 3;

  // How quickly the base gradient changes. Lower is faster.
  static int GRADIENT_SPEED = 30;

  // How far the hue should jump on the wipe.
  // Range: [0, 255]
  static int WIPE_DISTANCE = 64;

  // How frequently wipes occur where the number is the denominator of how often
  // the tree should be wiping. For example: A value of 3 indicates that a wipe
  // will be happening 1/3 of the time. The actual period time is specified by
  // GRADIENT_SPEED.
  static int WIPE_PERIOD = 3;
  
  // How fast the wipe moves across the tree. Lower is faster.
  static int WIPE_SPEED = 20;

  // The "value" of the HSV component.
  // Range: [0, 255]
  static int VALUE = 255;

  long t = theClock();

  for (int i=0;i<NUM_LEDS; ++i) {
    // Calculate wipe effect.
    long wipe = (i - t / WIPE_SPEED) / (NUM_LEDS * WIPE_PERIOD) * WIPE_DISTANCE;
    
    // Calculate base gradient.
    long gradient = i / GRADIENT_SPEED + t / GRADIENT_SPEED;

    // Smash 'em together into one cool effect.
    int h = abs(wipe + gradient) % 256;

    leds[i] = CHSV(h, 255, VALUE);
  }
}
