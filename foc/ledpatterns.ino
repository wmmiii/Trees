

// colorful test pattern
void testPattern() {
  for (int i = 0; i < NUM_LEDS; ++i) leds[i] = CRGB::Black; 
  byte hue = 0;
  if (masterhue >= 255) {
    masterhue = 0;
  } else {
    ++masterhue;
  }
  hue = masterhue;
 
  for (int i=0;i<(NUM_LEDS)-offset; ++i) {
    if (i+offset < NUM_LEDS) {
      leds[i+offset] = CHSV(hue, 255, 255);
      if (hue >= 255) {
        hue = 0;
      } else {
        ++hue;
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
  for (i=60; i<floor(offset/3)+60; ++i) {

  }
}

//tree rotate


//sparkle


//tree strobe


