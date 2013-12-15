#include <Servo.h>

#ifndef MY_SERVO_H
#define MY_SERVO_H

#define LEFT_THIGH 0
#define RIGHT_THIGH 1
#define RIGHT_SHIN 2
#define LEFT_SHIN 3

class MyServo : public Servo {
  public:
    void init(int pin, int max_left, int max_right, int center);
    
    void setRight();  /* sets servo to max_right position */
    void setLeft();   /* sets servo to max_left position */
    void setCenter(); /* sets servo to center position */
    void turnLeft();  /* turns servo to the left, speed determined by DELAY define */
    void turnRight(); /* turns right */
    
  private:
    int max_left;
    int max_right;
    int center;
    int pin;
};

extern MyServo servo[];

void servoSetup(void);

#endif
