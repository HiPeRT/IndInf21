/**
 * Purpose: HW initialization and update all the inputs of the system after the data processing
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
 * HW initialization and update all the inputs of the system after the data processing
*/
class OutImage
{
    private:
        uint8_t _greenLedPin;
        uint8_t _yellowLedPin;
        uint8_t _redLedPin;

        bool _greenLed;
        bool _yellowLed;
        bool _redLed;

        // initialization
        void init();
        int8_t initGreenLed();
        int8_t initYellowLed();
        int8_t initRedLed();

    public:
        /**
         * constructor
         * @param green led pin, yellow led pin, red led pin
         * @return output image object
        */
        OutImage(uint8_t greenLedPin, uint8_t yellowLedPin, uint8_t redLedPin);

        void setGreenLed(bool greenLed);
        void setYellowLed(bool yellowLed);
        void setRedLed(bool redLed);

        void write();
};
