#include "traffic_light.h"

void toRed_Road(){
  digitalWrite(trafficRedRoad,HIGH);
  digitalWrite(trafficGreRoad,LOW);
  digitalWrite(trafficYelRoad,LOW);
}

void toGre_Road(){
  digitalWrite(trafficRedRoad,LOW);
  digitalWrite(trafficGreRoad,HIGH);
  digitalWrite(trafficYelRoad,LOW);
}

void toYel_Road(){
  digitalWrite(trafficRedRoad,LOW);
  digitalWrite(trafficGreRoad,LOW);
  digitalWrite(trafficYelRoad,HIGH);
}

void toRed_Side(){
  digitalWrite(trafficRedSide,HIGH);
  digitalWrite(trafficGreSide,LOW);
  digitalWrite(trafficYelSide,LOW);
}

void toGre_Side(){
  digitalWrite(trafficRedSide,LOW);
  digitalWrite(trafficGreSide,HIGH);
  digitalWrite(trafficYelSide,LOW);
}

void toYel_Side(){
  digitalWrite(trafficRedSide,LOW);
  digitalWrite(trafficGreSide,LOW);
  digitalWrite(trafficYelSide,HIGH);
}

light lightRoad;
void trafficLightSetup(){
  lightRoad = green;
}

void trafficLightLoop(){
  trafficLightLoop_Road();
}


void trafficLightLoop_Road(){
  switch(lightRoad){
    case red:
      Serial.println("Red");
    break;
    
    case green:
      Serial.println("Green");
    break;
    
    case yellow:
      Serial.println("Yellow");
    break;
  }
}
