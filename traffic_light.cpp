#include "traffic_light.h"

light lightRoad;
light lightSide;
traffic trafficStatus;

unsigned long timeStamp;

void trafficLightSetup(){
  lightRoad = green;
  lightSide = red;
  trafficStatus = roadGreen;
  timeStamp = millis();
  toGre_Road();
  toRed_Side();
}


void trafficLightLoop(){
  
  switch (trafficStatus){
    case coolTime:
      if(millis() - timeStamp > CoolTime){
        trafficStatus = roadGreen;
        timeStamp = millis();
      }
      break;
      
    case roadGreen:
      if(ifPassengerExist()){
        trafficStatus = roadYellow;
        timeStamp = millis();

        toYel_Road();
      }
      break;
      
    case roadYellow:
      if(millis() - timeStamp > RoadYellowTime){
        trafficStatus = sideGreen;
        timeStamp = millis();

        toRed_Road();
        toGre_Side();
      }
      break;
      
    case sideGreen:
      if(millis() - timeStamp > SideGreenTime){
        trafficStatus = sideFlick;
        timeStamp = millis();
      }
      break;
    case sideFlick:
      if(millis() - timeStamp > SideGreenFlickTime){
        trafficStatus = coolTime;
        timeStamp = millis();

        toGre_Road();
        toRed_Side();
      }
      else{
        if((millis() - timeStamp) % (SideGreenFlickCycle * 2) > SideGreenFlickCycle){
          toGre_Side();
        }
        else{
          toOff_Side();
        }
      }
      break;
  }
}

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

void toOff_Side(){
  digitalWrite(trafficRedSide,LOW);
  digitalWrite(trafficGreSide,LOW);
  digitalWrite(trafficYelSide,LOW);
}

bool ifPassengerExist(){
  digitalWrite(trigPin,LOW);
  digitalWrite(echoPin,LOW);    //INPUT 핀이어도 센서를 끄는 의미로 write가능
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  //거리 측정
  unsigned long duration= pulseIn(echoPin,HIGH);
  float distance=((float)(340*duration)/10000)/2;
  //Serial.println(distance);
  
  return distance < DistanceStandard;
}
