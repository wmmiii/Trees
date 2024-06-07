

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
 
  for (int i=0;i<(NUM_LEDS)-offset; ++i) {
    if (i+offset < NUM_LEDS) {
      leds[i+offset] = CHSV(_hue, 255, 255);
      if (_hue >= 255) {
        _hue = 0;
      } else {
        ++_hue;
      }
    }
  }
}

//default blue spruce mode
void bluespruce() {
  for (int i=0;i<NUM_LEDS; ++i) {
    //the random blue tint is to make it shimmer
    if (random8(10)==1) {
      leds[i] = CHSV(185, 192, 128); //blueish
    } else {
      leds[i] = CHSV(167, 192, 128); //greenish
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

