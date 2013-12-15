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
 Function to setup and tweak servo pin and positions.
 The max_left, max_right and center numbers are result of calibration.
 Looking at front of robo:
            / -.- \
         ==/___ ___\==
 left thigh | | | | right thigh
 left shin  | | | | right shin  
 */
void servoSetup() {  

  /* pin, max_left, max_right, center */
  servo[LEFT_THIGH].init(9, 145, 19, 83);  /* init: center */
  servo[RIGHT_THIGH].init(10, 134, 5, 72); /* init: center */
  servo[RIGHT_SHIN].init(11, 145, 35, -1); /* init: left */
  servo[LEFT_SHIN].init(6, 125, 22, -1);   /* init: right */ 
}
