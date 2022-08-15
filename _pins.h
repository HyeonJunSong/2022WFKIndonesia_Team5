#include <Arduino.h>

//digital
#define PRIPin 2
#define trafficRedRoad 3
#define trafficGreRoad 4
#define trafficYelRoad 5
#define trafficRedSide 6
#define trafficGreSide 7
#define trafficYelSide 8
#define trigPin 9
#define echoPin 10

//Analog
//A4 : LCD_SDA
//A5 : LCD_SCL

void pinModeSetup();

////
//+ other Settings
#define DistanceStandard 50
#define RoadYellowTime 5000
#define SideGreenTime 10000
#define SideGreenFlickTime 10000
#define SideGreenFlickCycle 500
#define CoolTime 5000
