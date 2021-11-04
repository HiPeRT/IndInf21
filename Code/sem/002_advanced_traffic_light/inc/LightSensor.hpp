/**
 * Purpose: light sensor class to filter signal and add feature, based on the input image
 * @Author Samuele Toscani
 * @Version 1.0
*/

/**
 * TODO: add timed filter to the simple reading of the sensor
*/


#pragma once

#include <iostream>

#include "InImage.hpp"
#include "Timer.hpp"

#define mex(text, x) {cout << text << to_string(x) << endl;}
#define carriage {cout << endl;}
#define dR(pin) digitalRead(pin)
#define dW(pin, val) digitalWrite(pin, val)
#define aR(pin) analogRead(pin)
#define aW(pin, val) analogWrite(pin, val)

using namespace std;


/**
 * light sensor class to filter signal and add feature
 * based on the input image
*/
class LightSensor
{
    private:
        InImage *_inImage;

    public:

        /**
         * constructor
         * @param pointer to input iamge
         * @return light sensor object
        */
        LightSensor(InImage *inImage);

        bool getLightSensor();
};
