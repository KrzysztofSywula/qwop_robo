#include <Servo.h>

#ifndef MY_SERVO_H
#define MY_SERVO_H

class MyServo : public Servo {
  public:
    void init(int pin, int max_left, int max_right, int center);
    
    void setRight();
    void setLeft();
    void setCenter();
    void turnLeft();
    void turnRight();
    
  private:
    int max_left;
    int max_right;
    int center;
    int pin;
};

extern MyServo servo[];

void servoSetup(void);

#endif
