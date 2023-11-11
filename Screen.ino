#include <WiFi.h>
#include <WebServer.h>
#include <DNS.h>
#include <ArduinoJson.h>
#include "TetrisClass.hpp"
#include <Preferences.h>

WebServer server(80);
DynamicJsonDocument doc(256);

void setup() {
  Serial.begin(115200);
  while(!Serial);
  
}

void loop() {

}