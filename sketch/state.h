#ifndef STATE_H
#define STATE_H

typedef enum { STATE_NOTHING, STATE_INITIAL, STATE_Q, STATE_W, STATE_O, STATE_P ,NUM_STATES } state_t;

typedef state_t state_func_t();

state_t do_state_nothing();
state_t do_state_initial();
state_t do_state_q();
state_t do_state_w();
state_t do_state_o();
state_t do_state_p();

state_func_t* const state_table[ NUM_STATES ] = {
    do_state_nothing, do_state_initial, do_state_q, do_state_w, do_state_o, do_state_p
};

state_t run_state( state_t cur_state); 

#endif
