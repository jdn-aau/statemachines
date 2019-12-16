
#include <stdio.h>

// .
typedef void *(*pF)(void); // for typecast for calling function

#define NEXT(x,y,z) return ((void *)x)
// States -- you need this forward dcl for the compiler and calling

// NEEXT(next,here,cond)   
//                 |---- condition to be put on the arc in state machine
//             |-------- state we are in just now (just for graph)
//       |-------------- next state we will jump to 
//
// all driven from main (or here setup fct)

void *led_on();      // as name indicates ...
void *led_off();
void *led_save();



pF statefunc = led_on, oldfunc = NULL;  // whrere to start

/**
* Turn on leds 
* @return led_off next_state
* @remark only to be called after start of ...
*/
void *led_on() {
  printf("on\n");
  // parms: next state, actual state, condition for statechange
  // all three parms used for state machine by dot (image)
  // only next state (here it is led_off) is used by the state machine
  NEXT(led_off,led_on,always);     // BLA BLAB blabla

}

/**
* Turn off leds 
* @return led_on next_state
* @return led_save next_state
* @remark only to be called after start of ...
*/
void *led_off() {
  printf("off \n");
  if (1)
    NEXT(led_on,led_off,condition1);
  else
    NEXT(led_save,led_off,cond2);
}

/**
* Sacve leds 
* @return led_on next_state
* @return led_off next_state
* @remark only to be called after start of ...
*/

void *led_save() {
  printf("off \n");
  if (1)
    NEXT(led_on,led_save,alarm);
  else
    NEXT(led_off,led_save,peace);
}


void main() {


  while(1) {
    oldfunc = statefunc;               // if you want to see/track the previous state  }
    statefunc = (pF)(*statefunc)();    // next state is called here
    // here statefunc is last and oldfunc is last last
  }
  return ;                            // should not get here
} 

