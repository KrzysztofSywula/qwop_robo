#include "state.h"
#include "servo.h"

state_t run_state( state_t cur_state) {
    return state_table[ cur_state ]();
};

state_t do_state_nothing() {
  return STATE_NOTHING;
}

state_t do_state_initial() {
  servo[LEFT_THIGH].setCenter();
  servo[RIGHT_THIGH].setCenter();
  servo[RIGHT_SHIN].setLeft();
  servo[LEFT_SHIN].setRight();
  return STATE_INITIAL;
}

state_t do_state_q() {
  servo[LEFT_THIGH].turnLeft();
  servo[RIGHT_THIGH].turnLeft();
  return STATE_Q;
}

state_t do_state_w() {
  servo[RIGHT_THIGH].turnRight();
  servo[LEFT_THIGH].turnRight();
  return STATE_W;
}

state_t do_state_o() {
  servo[LEFT_SHIN].turnLeft();
  servo[RIGHT_SHIN].turnLeft();
  return STATE_O;
}

state_t do_state_p() {
  servo[RIGHT_SHIN].turnRight();
  servo[LEFT_SHIN].turnRight();
  return STATE_P;
}
