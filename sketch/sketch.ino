#include "state.h"
#include "servo.h"
#include <Servo.h>

state_t cur_state;
char value;

void setup() 
{ 
  servoSetup();
  Serial.begin(115200);
  cur_state = STATE_INITIAL;
} 

void loop() 
{ 
  char value = Serial.read();
  if(value == 'q') 
    cur_state = STATE_Q;
  else if(value == 'w')
    cur_state = STATE_W;
  else if(value == 'o')
    cur_state = STATE_O;
  else if(value == 'p')
    cur_state = STATE_P;
  else if(value == 'n')
    cur_state = STATE_NOTHING;
  else if(value == 'i')
    cur_state = STATE_INITIAL;
  Serial.println(cur_state);

  run_state( cur_state); 
}
