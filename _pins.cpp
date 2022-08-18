#include "_pins.h"

void pinModeSetup(){
  pinMode(PRIPin, INPUT);
  pinMode(trafficRedRoad, OUTPUT);
  pinMode(trafficGreRoad, OUTPUT);
  pinMode(trafficYelRoad, OUTPUT);
  pinMode(trafficRedSide, OUTPUT);  
  pinMode(trafficGreSide, OUTPUT);
  pinMode(trafficYelSide, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}
