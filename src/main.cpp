//  FARM DATA RELAY SYSTEM
//
//  ESP-NOW Sensor Example
//
//  Developed by Timm Bogner (timmbogner@gmail.com) for Sola Gratia Farm in Urbana, Illinois, USA.
//  An example of how to send data via ESP-NOW using FDRS.
//

#include <Arduino.h>
#include "fdrs_node_config.h"
#include <fdrs_node.h>

time_t lastruntime;

float readTemp() {
  return 22.069;
}

float readHum() {
  return random(0, 100);
}

void fdrs_recv_cb(DataReading theData) {
  DBG("ID: " + String(theData.id));
  DBG("Type: " + String(theData.t));
  DBG("Data: " + String(theData.d));
}

void setup() {
  beginFDRS();
  pingFDRS(1000);
  addFDRS(fdrs_recv_cb);
  subscribeFDRS(READING_ID);
  lastruntime = millis();
}
void loop() {
loopFDRS();
if(millis() - lastruntime > 30 * 1000) {
  pingFDRS(1000);

  float data1 = readHum();
  loadFDRS(data1, HUMIDITY_T);
  float data2 = readTemp();
  loadFDRS(data2, TEMP_T);
  if(sendFDRS()){
      DBG("Big Success!");
  } else {
      DBG("Nope, not so much.");
  }

  lastruntime = millis();
  }
}
