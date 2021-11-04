/**
 * Purpose: finite state machine to control the traffic light blinking yellow
 * @Author Samuele Toscani
 * @Version 1.0
*/

/**
 * TODO: fix any bugs
*/


#pragma once

#include <iostream>
#include <wiringPi.h>

#include "TrafficLight.hpp"
#include "Timer.hpp"

#define _INITIAL 0
#define _YELLOW_ON 10
#define _YELLOW_OFF 20
#define _ERROR -1

#define mex(text, x) {cout << text << to_string(x) << endl;}
#define carriage {cout << endl;}
#define dR(pin) digitalRead(pin)
#define dW(pin, val) digitalWrite(pin, val)
#define aR(pin) analogRead(pin)
#define aW(pin, val) analogWrite(pin, val)

using namespace std;


/**
 * finite state machine to control the traffic light blinking yellow
*/
class FsmTrafficLightBlinkingYellow
{
    private:
        int8_t _state;
        int8_t _oldState;
        TrafficLight *_trafficLight;
        Timer *_timerBlinkingYellow;

        // functions associated to each state
        int8_t initialState();
        int8_t yellowOnState(); 
        int8_t yellowOffState(); 

    public:
        /**
         * constructor
         * @param pointer to traffic light,
         * blinking yellow pause time (ms)
         * @return fsm traffic light blinking yellow object
        */
        FsmTrafficLightBlinkingYellow(TrafficLight *trafficLight,
                                      uint32_t blinkingYellowPauseTimeMs);

        void initTimers(uint32_t blinkingYellowPauseTimeMs);
        
        int8_t getState();
        void setState(int8_t state);
        int8_t getOldState();
        void setOldState(int8_t old_state);
        
        void reset_state();
        bool in_error_state();

        // state function to update the state
        void sfn();
        // machine function to update the output
        void mfn();
};
