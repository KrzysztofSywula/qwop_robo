#include "state.h"
#include "servo.h"

state_t run_state( state_t cur_state) {
    return state_table[ cur_state ]();
};

state_t do_state_nothing() {
  return STATE_NOTHING;
}

state_t do_state_initial() {
  servo[0].setCenter();
  servo[1].setCenter();
  servo[2].setLeft();
  servo[3].setRight();
  return STATE_INITIAL;
}

state_t do_state_q() {
  servo[0].turnLeft();
  servo[1].turnLeft();
  return STATE_Q;
}

state_t do_state_w() {
  servo[1].turnRight();
  servo[0].turnRight();
  return STATE_W;
}

state_t do_state_o() {
  servo[2].turnLeft();
  servo[3].turnLeft();
  return STATE_O;
}

state_t do_state_p() {
  servo[2].turnRight();
  servo[3].turnRight();
  return STATE_P;
}
