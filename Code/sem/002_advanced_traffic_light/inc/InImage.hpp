/**
 * Purpose: HW initialization and scan all the inputs of the system before the data processing
 * @Author Samuele Toscani
 * @Version 1.0
*/

/**
 * TODO: fix any bugs
*/


#pragma once

#include <iostream>
#include <wiringPi.h>

#define mex(text, x) {cout << text << to_string(x) << endl;}
#define carriage {cout << endl;}
#define dR(pin) digitalRead(pin)
#define dW(pin, val) digitalWrite(pin, val)
#define aR(pin) analogRead(pin)
#define aW(pin, val) analogWrite(pin, val)

using namespace std;


/**
 * HW initialization and scan all the inputs of the system before the data processing
*/
class InImage
{
    private:
        uint8_t _userButtonPin;
        uint8_t _lightSensorPin;

        bool _userButton;
        bool _lightSensor;

        // initialization
        void init();
        int8_t initUserButton();
        int8_t initLightSensor();

    public:
        /**
         * constructor
         * @param user button pin, light sensor pin
         * @return input image object
        */
        InImage(uint8_t userButtonPin, uint8_t lightSensorPin);

        bool getUserButton();
        bool getLightSensor();

        void read();
};
