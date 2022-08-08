#include "_pins.h"
#include "traffic_light.h"

void setup() {
  pinModeSetup();
  trafficLightSetup();
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  trafficLightLoop();
}
