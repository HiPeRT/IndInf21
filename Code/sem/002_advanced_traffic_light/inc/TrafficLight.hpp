/**
 * Purpose: traffic light class to add feature, based on the output image
 * @Author Samuele Toscani
 * @Version 1.0
*/

/**
 * TODO: fix any bugs
*/


#pragma once

#include <iostream>

#include "OutImage.hpp"

#define mex(text, x) {cout << text << to_string(x) << endl;}
#define carriage {cout << endl;}
#define dR(pin) digitalRead(pin)
#define dW(pin, val) digitalWrite(pin, val)
#define aR(pin) analogRead(pin)
#define aW(pin, val) analogWrite(pin, val)

using namespace std;


/**
 * traffic light class to add feature
 * based on the output image
*/
class TrafficLight
{
    private:
        OutImage *_outImage;
        
    public:
        
        /**
         * constructor
         * @param pointer to output image
         * @return traffic light object
        */
        TrafficLight(OutImage *outImage);

        void setGreenLed(bool greenLed);
        void setYellowLed(bool yellowLed);
        void setRedLed(bool redLed);
        void turnOffLeds();
};
