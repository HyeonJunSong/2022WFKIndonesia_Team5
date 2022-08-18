#include "earthQuake.h"

Servo servo;

void earthQuakeSetup(){
  servo.attach(servoPin);
}

void earthQuakeLoop(){
  char c = Serial.read();
  switch(c){
    case '1':
      servo.write(2);
      break;
    case '2':
      servo.write(90);
      break;
    case '3':
      servo.write(178);
      break;
  }
}
