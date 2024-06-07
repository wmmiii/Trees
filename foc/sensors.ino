bool gotSensor() {
  //check to see if there's a command for this tree on the wifi buffer
  //if command {
    //return true;
  //} else {
    return false;
  //}

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