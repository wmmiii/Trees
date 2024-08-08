//legs 60 LEDs down each
// 1||2 3||4 5||6
//     1    2    3

void activePattern() {
  if (millis() - startActiveTime < 3000) {
    //start with a base coat of the default blue spruce
    blueSpruce();
    //layer on growing up the tree for 3 seconds on the activated side
    //do the grow up tree routine
    for (int i = 0; i < (millis() - startActiveTime) / 50; ++i) {
      if (activeSensor == 1 || activeSensor == 2) {
        leds[i + 120] = CHSV(floor(256 / 60) * i, 255, 255);  //branch 3
        leds[239 - i] = CHSV(floor(256 / 60) * i, 255, 255);  //branch 4
      }
      if (activeSensor == 3 || activeSensor == 1) {
        leds[i] = CHSV(floor(256 / 60) * i, 255, 255);        //branch 1
        leds[119 - i] = CHSV(floor(256 / 60) * i, 255, 255);  //branch 2
      }
      if (activeSensor == 2 || activeSensor == 3) {
        leds[i + 240] = CHSV(floor(256 / 60) * i, 255, 255);  //branch 5
        leds[359 - i] = CHSV(floor(256 / 60) * i, 255, 255);  //branch 6
      }
    }
    //twinkle the leading LED
    if (random8(3) == 1) {
      int lastLED = (millis() - startActiveTime) / 50 - 1;
      if (lastLED < 0) lastLED = 0;  //just in case
      if (activeSensor == 1 || activeSensor == 2) {
        leds[lastLED + 120] = CRGB::White;  //twinkle the leading LED
        leds[239 - lastLED] = CRGB::White;  //twinkle the leading LED
      }
      if (activeSensor == 3 || activeSensor == 1) {
        leds[lastLED] = CRGB::White;        //twinkle the leading LED
        leds[119 - lastLED] = CRGB::White;  //twinkle the leading LED
      }
      if (activeSensor == 2 || activeSensor == 3) {
        leds[lastLED + 240] = CRGB::White;  //twinkle the leading LED
        leds[359 - lastLED] = CRGB::White;  //twinkle the leading LED
      }
    }
  } else {
    //what do we do after fully active?
    //color wash (offset steps every 3/60 seconds: 50,000 microseconds)
    //by using getNodeTime() all the trees will have their patterns in sync
    int offest = (mesh.getNodeTime() / 50000L) % 60;
    for (int i = 0; i < 60; ++i) {
      leds[i + 120] = CHSV(floor(256 / 60) * offset, 255, 255);  //branch 3
      leds[239 - i] = CHSV(floor(256 / 60) * offset, 255, 255);  //branch 4
      leds[i] = CHSV(floor(256 / 60) * offset, 255, 255);        //branch 1
      leds[119 - i] = CHSV(floor(256 / 60) * offset, 255, 255);  //branch 2
      leds[i + 240] = CHSV(floor(256 / 60) * offset, 255, 255);  //branch 5
      leds[359 - i] = CHSV(floor(256 / 60) * offset, 255, 255);  //branch 6
    }
  }
}

// colorful test pattern, different color for each leg for orentation and LED check
void testPattern() {
  for (int i = 0; i < NUM_LEDS; ++i) leds[i] = CRGB::Black;
  byte _hue = 0;
  if (masterHue >= 255) {
    masterHue = 0;
  } else {
    ++masterHue;
  }
  _hue = masterHue;

  for (int i = 0; i < 120; ++i) {
    leds[i] = CHSV(0, 255, 32);
    leds[i + 120] = CHSV(160, 255, 32);
    leds[i + 240] = CHSV(96, 255, 32);
    // leds[random(360)] = CRGB::White;
  }
}


//default blue spruce mode
void blueSpruce() {
  for (int i = 0; i < NUM_LEDS; ++i) {
    //the random blue tint is to make it shimmer
    if (random8(10) == 1) {
      leds[i] = CHSV(93, 255, 32);  //blueish
    } else {
      leds[i] = CHSV(40, 255, 32);  //greenish
    }
  }
}

//all off
void darkForest() {
  //probably a sexy little command for this but I don't know it
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::Black;
  }
}

//tree rotate
void patternRotate() {
  for (int i = 0; i < NUM_LEDS; ++i) leds[i] = CRGB::Black;
  byte _hue = 0;
  if (masterHue >= 255) {
    masterHue = 0;
  } else {
    ++masterHue;
  }
  _hue = masterHue;

  for (int i = 0; i < 120; ++i) {
    leds[i] = CHSV((theClock() / 20) % 256, 255, 255);
    leds[i + 120] = CHSV((theClock() / 20 + 83) % 256, 255, 255);
    leds[i + 240] = CHSV((theClock() / 20 + 166) % 256, 255, 255);
    leds[random(360)] = CRGB::White;
  }
}

//sparkle
void patternSparkle() {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::Black;
    if (random8(100) == 1) {
      leds[i] = CRGB::White;
    }
  }
}

//tree strobe
void patternStrobe() {
  if (random8(100) == 1 && patternTime == 0) {
    patternTime = millis();
  }
  if (millis() > patternTime + 200) {
    patternTime = 0;
  }
  if (patternTime > 0) {
    for (int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CRGB::White;
    }
  } else {
    for (int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CRGB::Black;
    }
  }
}

//colorful
void patternColorful() {
  if (random8(100) == 1 && patternTime == 0) {
    patternTime = millis();
  }
  if (millis() > patternTime + 200) {
    patternTime = 0;
  }
  if (patternTime > 0) {
    for (int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CHSV(random8(), 255, 255);
    }
  } else {
    for (int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CRGB::Black;
    }
  }
}

//fire
void patternFire() {
  patternStrobe();  //untill we have something here
}

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

  for (int i = 0; i < NUM_LEDS; ++i) {
    // Calculate wipe effect.
    long wipe = (i - t / WIPE_SPEED) / (NUM_LEDS * WIPE_PERIOD) * WIPE_DISTANCE;

    // Calculate base gradient.
    long gradient = i / GRADIENT_SPEED + t / GRADIENT_SPEED;

    // Smash 'em together into one cool effect.
    int h = abs(wipe + gradient) % 256;

    leds[i] = CHSV(h, 255, VALUE);
  }
}
