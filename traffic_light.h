#include "_pins.h"

void toRed_Road();
void toGre_Road();
void toYel_Road();
void toRed_Side();
void toGre_Side();
void toYel_Side();

enum light{
  red,
  green,
  yellow
};


void trafficLightSetup();
void trafficLightLoop();
void trafficLightLoop_Road();
