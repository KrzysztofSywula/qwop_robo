#include "Arduino.h"
#include "servo.h"
#include <Servo.h>

#define DELAY 2
#define NUM_OF_SERVOS 4 /*a maximum of eight servo objects can be created*/

void MyServo::init(int pin, int max_left, int max_right, int center) {
  this->pin = pin;
  this->max_left = max_left;
  this->max_right = max_right; 
  this->center = center;
  this->attach(pin);
}
    
void MyServo::setRight() {
  this->write(max_right);
}
    
void MyServo::setLeft() {
  this->write(max_left);
}
void MyServo::setCenter() {
  this->write(center);
}
void MyServo::turnLeft() {
  if(this->read() < max_left)
    this->write(this->read() + 1);
  delay(DELAY);
}
void MyServo::turnRight() {
  if(this->read() > max_right)
    this->write(this->read() - 1);
  delay(DELAY);
}

MyServo servo[NUM_OF_SERVOS];

/*
 Function to setup and calibrate servo pin and positions.
 Looking at front of robo:
             ___ ___
 left thigh | | | | right thigh
 left shin  | | | | right shin  
 */
void servoSetup() {  

  /* pin, max_left, max_right, center */
  servo[0].init(9, 145, 19, 83);  /* left thigh, init: center */
  servo[1].init(10, 134, 5, 72); /* right thigh, init: center */
  servo[2].init(11, 145, 35, -1); /* right shin, init: left*/
  servo[3].init(6, 125, 22, -1); /* left shin, init: right*/ 
}
