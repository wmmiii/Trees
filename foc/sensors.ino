bool gotSensor() {
  //check to see if there's detection from a sensor
  //gotta kinda debounce this a little too.
  //keep track of detection, time since last detection, and distance
  
  // long duration, distance;
  // digitalWrite(TRIG_PIN, LOW);  
  // delayMicroseconds(2); 
  // digitalWrite(TRIG_PIN, HIGH);
  // delayMicroseconds(10); 
  // digitalWrite(TRIG_PIN, LOW);
  // duration = pulseIn(ECHO_PIN, HIGH);
  // distance = (duration/2) / 29.1;
  // Serial.println (distance);

  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Wait for pulse on echo pin
  //TODO: need to put a timeout limit on this incase the sensor breaks of is dissconnected.
  // commented because it locks up the program when there's no sensor attached.  while ( digitalRead(ECHO_PIN) == 0 );

  unsigned long t1; 
  unsigned long t2;
  unsigned long pulse_width;
  float cm;
  float inches;


  // Measure how long the echo pin was held high (pulse width)
  // Note: the micros() counter will overflow after ~70 min
  t1 = micros();
  while ( digitalRead(ECHO_PIN) == 1);
  t2 = micros();
  pulse_width = t2 - t1;
  inches = pulse_width / 148.0;
  // Serial.println(inches);

  if (inches < 50) {
    Serial.println("*** DETECTION ***");
    return true;
  } else {
    Serial.println("");
    return false;
  }

}

//update the array where we are keeping track of what trees are active
void setForestState(byte _treeNumber, bool _treeState) {
  forestState[_treeNumber] = _treeState;
  //check to see if hte whole forest is active
  int _thisTree = 1;
  forestState[0] = false; 
  while (forestState[_thisTree]) {
    ++_thisTree;
    if (_thisTree > NUM_TREES) {
      //all the trees are active
      forestState[0] = true;
      break;
    }
  }

}