#include "_pins.h"
#include "traffic_light.h"
#include "earthQuake.h"

void setup() {
  Serial.begin(9600);
  pinModeSetup();
  trafficLightSetup();
  earthQuakeSetup();
  pinMode(13, OUTPUT);
}

void loop() {
  trafficLightLoop();
  earthQuakeLoop();
}
