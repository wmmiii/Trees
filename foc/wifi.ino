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
  if(WiFi.status()== WL_CONNECTED ){ 
    String serverMillis = httpGETRequest(serverClock);
    if (isValidNumber(serverMillis)) {
      clockOffset =  serverMillis.toInt() - millis();
    }
  } 
}

boolean isValidNumber(String str){
  for(byte i=0;i<str.length();i++) {
    if(isDigit(str.charAt(i))) return true;
  }
  return false;
}

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