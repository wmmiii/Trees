Project will use WS2812B pebble lights and ESP32

ESP32 on Amazon: https://www.amazon.com/gp/product/B08D5ZD528

![51FzgrVl-cL _AC_](https://github.com/hoopgeek/Trees/assets/5124257/ee415a72-84c3-46a9-97f4-9a52da86331e)

One of the ESP32s will run the foc-ap sketch.  This is a little http server that keeps track of the states of each of the trees in the forest.  Any time a tree has a state change, it will report it to the server.  The trees will also pole the server frequently to see if the state of the forest is changing.
