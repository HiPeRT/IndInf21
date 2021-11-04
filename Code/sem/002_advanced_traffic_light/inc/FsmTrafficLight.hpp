/**
 * Purpose: finite state machine to control the traffic light cycle and user request to cross
 * @Author Samuele Toscani
 * @Version 1.0
*/

/**
 * TODO: fix any bugs
*/


#pragma once

#include <iostream>

#include "TrafficLight.hpp"
#include "UserRequest.hpp"
#include "Timer.hpp"

#define _INITIAL 0
#define _GREEN 10
#define _GREEN_WAITING_REQUEST 20
#define _GREEN_RECEIVED_REQUEST 21 
#define _YELLOW 30
#define _RED 40
#define _ERROR -1

#define mex(text, x) {cout << text << to_string(x) << endl;}
#define carriage {cout << endl;}
#define dR(pin) digitalRead(pin)
#define dW(pin, val) digitalWrite(pin, val)
#define aR(pin) analogRead(pin)
#define aW(pin, val) analogWrite(pin, val)

using namespace std;


/**
 * finite state machine to control the traffic light cycle and user request to cross
*/
class FsmTrafficLight
{
    private:
        int8_t _state;
        int8_t _oldState;
        TrafficLight *_trafficLight;
        UserRequest *_userRequest;
        Timer *_timerGreen, *_timerYellow, *_timerRed;

        // functions associated to each state
        int8_t initialState();
        int8_t greenState();
        int8_t greenReceivedRequestState(); // green on and timer not expired, request already received
        int8_t greenWaitingRequestState(); // green on and timer expired, in waiting of user request
        int8_t yellowState();
        int8_t redState();

    public:
        /**
         * constructor
         * @param pointer to traffic light, pointer to user request
         * red pause time (ms), yellow pause time (ms), green pause time (ms)
         * @return fsm traffic light object
        */
        FsmTrafficLight(TrafficLight *trafficLight, UserRequest *userRequest,
                        uint32_t greenPauseTimeMs, uint32_t yellowPauseTimeMs, uint32_t redPauseTimeMs);

        void initTimers(uint32_t greenPauseTimeMs, uint32_t yellowPauseTimeMs, uint32_t redPauseTimeMs);
        
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
