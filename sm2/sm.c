
#include <stdio.h>

// .
typedef void *(*pF)(void); // for typecast for calling function

#define NEXT(x,y,z) return (x)
// States -- you need this forward dcl for the compiler and calling

// NEEXT(next,here,cond)   
//                 |---- condition to be put on the arc in state machine
//             |-------- state we are in just now (just for graph)
//       |-------------- next state we will jump to 
//
// all driven from main (or here setup fct)
#define LED_ON 0
#define LED_OFF 1
#define LED_SAVE 2
int led_on();      // as name indicates ...
int led_off();
int led_save();

int (*fAr[])(void) ={led_on, led_off,led_save};




/**
* Turn on leds 
* @return led_off next_state
* @remark only to be called after start of ...
*/
int led_on() {
  printf("on\n");
  // parms: next state, actual state, condition for statechange
  // all three parms used for state machine by dot (image)
  // only next state (here it is led_off) is used by the state machine
  NEXT(LED_OFF,LED_ON,always);     // BLA BLAB blabla

}

/**
* Turn off leds 
* @return led_on next_state
* @return led_save next_state
* @remark only to be called after start of ...
*/
int led_off() {
  printf("off \n");
  if (1)
    NEXT(LED_ON,LED_OFF,condition1);
  else
    NEXT(LED_SAVE,LED_OFF,cond2);
}

/**
* Sacve leds 
* @return led_on next_state
* @return led_off next_state
* @remark only to be called after start of ...
*/

int led_save() {
  printf("off \n");
  if (1)
    NEXT(LED_ON,LED_SAVE,alarm);
  else
    NEXT(LED_OFF,LED_SAVE,peace);
}


int fRef=LED_ON, fOld=0; 

void main() {


  while(1) {
     fOld=fRef;
     
    fRef =  (*fAr[fRef])();    // next state is called here
    printf("next to be called %i\n",fRef);
    // here statefunc is last and oldfunc is last last
  }
  return ;                            // should not get here
} 

