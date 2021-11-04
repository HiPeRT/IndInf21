/**
 * Purpose: finite state machine to control the cycle of the traffic light
 * @Author Samuele Toscani
 * @Version 1.0
*/

/**
 * TODO: fix any bugs
*/


#pragma once

#include <iostream>
#include <wiringPi.h>

#include "FsmTrafficLight.hpp"
#include "FsmTrafficLightBlinkingYellow.hpp"
#include "LightSensor.hpp"

#define _INITIAL 0
#define _DAY 10
#define _DAY_TO_NIGHT 20
#define _NIGHT 30
#define _NIGHT_TO_DAY 40
#define _ERROR -1

#define mex(text, x) {cout << text << to_string(x) << endl;}
#define carriage {cout << endl;}
#define dR(pin) digitalRead(pin)
#define dW(pin, val) digitalWrite(pin, val)
#define aR(pin) analogRead(pin)
#define aW(pin, val) analogWrite(pin, val)

using namespace std;


/**
 * finite state machine to control the cycle of the traffic light
*/
class FsmCycleController
{
    private:
        int8_t _state;
        int8_t _oldState;
        FsmTrafficLight *_fsmTrafficLight;
        FsmTrafficLightBlinkingYellow *_fsmTrafficLightBlinkingYellow;
        LightSensor *_lightSensor;

        // functions associated to each state
        int8_t initialState();
        int8_t dayBehaviorState();
        int8_t dayToNightState(); // reset correctly the cycle of the traffic light
        int8_t nightBehaviorState();
        int8_t nightToDayState(); // reset correctly the cycle of the traffic light blinking yellow

    public:
        /**
         * constructor
         * @param pointer to FSM traffic light, pointer to FSM traffic light blinking yellow,
         * pointer to light sensor
         * @return FSM cycle controller object
        */
        FsmCycleController(FsmTrafficLight *fsmTrafficLight, FsmTrafficLightBlinkingYellow *fsmTrafficLightBlinkingYellow,
                           LightSensor *lightSensor);
        
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
