#include "earthQuake.h"

Servo servo;

void earthQuakeSetup(){
  servo.attach(servoPin);
}

bool ifTrigged = false;
bool ifPushed = false;

void earthQuakeLoop(){
//  char c = Serial.read();
//  switch(c){
//    case '1':
//      servo.write(2);
//      break;
//    case '2':
//      servo.write(90);
//      break;
//    case '3':
//      servo.write(178);
//      break;
//  }

  int buttonVal = digitalRead(buttonPin);
  if(buttonVal == HIGH && ifPushed == false){
    ifPushed = true;

    if(ifTrigged){
      servo.write(defaultAngle);
      ifTrigged = false;
    }
    else{
      servo.write(activeAngle);
      ifTrigged = true;
    }
  }
  else if(buttonVal == LOW && ifPushed == true){
    ifPushed = false;
  }
}
