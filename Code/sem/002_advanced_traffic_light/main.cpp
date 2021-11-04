/**
 * Purpose: traffic light with day/night cycle and user request to cross
 *          HW setup:
 *              - 3 leds (green, yellw red): traffic light
 *              - 1 button: user request to cross
 *              - 1 light sensor: to switch from day to night cycle and vice versa
 *          SW specifications:
 *              - day cycle: traffic light is always set green, 
 *                           when a user request occurs the cycle starts,
 *                           traffic light switch to yellow and red, then go back on green (using non blocking timers).
 *                           User request is served only when the green is on and when a timer is expired,
 *                           this allow vehicles to have some time to pass
 *              - night cycle: blinking yellow with no user requests served
 *              - in/out image: inspired by PLC managing cycle,
 *                              scan all inputs, cycle control, update all outputs
 * @Author Samuele Toscani
 * @Version 1.0
*/

/**
 * TODO: fix any bugs
*/


#include <iostream>

#include "inc/InImage.hpp"
#include "inc/OutImage.hpp"
#include "inc/TrafficLight.hpp"
#include "inc/UserRequest.hpp"
#include "inc/LightSensor.hpp"
#include "inc/FsmTrafficLight.hpp"
#include "inc/FsmTrafficLightBlinkingYellow.hpp"
#include "inc/FsmCycleController.hpp"

#define redLedPin 3
#define yellowLedPin 2
#define greenLedPin 0
#define userButtonPin 1
#define lightSensorPin 4

#define mex(text, x) {cout << text << to_string(x) << endl;}
#define carriage {cout << endl;}

using namespace std;


int main(int argc, char const *argv[])
{
    // setup
    InImage inImage(userButtonPin, lightSensorPin);
    OutImage outImage(greenLedPin, yellowLedPin, redLedPin);

    TrafficLight trafficLight(&outImage);
    UserRequest userRequest(&inImage);
    LightSensor lightSensor(&inImage);

    FsmTrafficLight fsmTrafficLight(&trafficLight, &userRequest,
                                    5000, 1000, 5000);
    FsmTrafficLightBlinkingYellow fsmTrafficLightBlinkingYellow(&trafficLight,
                                                                1000);
    FsmCycleController fsmCycleController(&fsmTrafficLight, &fsmTrafficLightBlinkingYellow,
                                          &lightSensor);

    // loop
    while(true) {
        inImage.read();

        fsmCycleController.sfn();
        fsmCycleController.mfn();

        outImage.write();
    }

    return 0;
}
