const char* serverClock = "http://192.168.4.1/clock";

bool gotCommand() {
  //check to see if there's a command for this tree on the wifi buffer
  //if command {
    //return true;
  //} else {
    return false;
  //}

}

//sets global clockOffset
void getClockOffset() {
  // if(WiFi.status()== WL_CONNECTED ){ 
  //   String serverMillis = httpGETRequest(serverClock);
  //   if (isValidNumber(serverMillis)) {
  //     clockOffset =  serverMillis.toInt() - millis();
  //   }
  // } 
}

void tellForest(String msg) {
  sendMessage(msg);
}

boolean isValidNumber(String str){
  for(byte i=0;i<str.length();i++) {
    if(isDigit(str.charAt(i))) return true;
  }
  return false;
}

void sendMessage(String status)
{
  
  Serial.println();
  Serial.println("Start Sending....");

  Serial.println("Blah blah blah");
  
  // Serialize the message
  DynamicJsonDocument doc(1024);
  doc["status"] = status; 
  String msg;
  serializeJson(doc, msg); //
  mesh.sendBroadcast( msg );
  Serial.println("Message from Node2");
  Serial.println(msg);
}

// Deserialize the message
void receivedCallback( uint32_t from, String &msg ) {

  Serial.println("Message ="); Serial.println(msg);
  String json = msg.c_str();;
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, json);
  if (error)
  {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
  } else {
    if (doc["status"] == "ACTIVATED") {
      Serial.println("** ACTIVATED **");
      treeState = ACTIVATED;
      activeTime = millis();
    }
    if (doc["status"] == "DEACTIVATED") {
      Serial.println("** DEACTIVATED **");
    }
  }
}

void newConnectionCallback(uint32_t nodeId) {
  Serial.printf("--> startHere: New Connection, nodeId = %u\n", nodeId);
}
void changedConnectionCallback() {
  Serial.printf("Changed connections\n");
}
void nodeTimeAdjustedCallback(int32_t offset) {
  Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(), offset);
}

//not using
String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}