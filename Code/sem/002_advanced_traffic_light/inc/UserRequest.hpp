/**
 * Purpose: user request class to filter signal and add feature, based on the input image
 * @Author Samuele Toscani
 * @Version 1.0
*/

/**
 * TODO: add anti-debounce filter to the simple reading of the button
*/


#pragma once

#include <iostream>

#include "InImage.hpp"

#define mex(text, x) {cout << text << to_string(x) << endl;}
#define carriage {cout << endl;}
#define dR(pin) digitalRead(pin)
#define dW(pin, val) digitalWrite(pin, val)
#define aR(pin) analogRead(pin)
#define aW(pin, val) analogWrite(pin, val)

using namespace std;


/**
 * user request class to filter signal and add feature
 * based on the input image
*/
class UserRequest
{
    private:
        InImage *_inImage;
        bool _retainedRequest;

    public:

        /**
         * constructor
         * @param pointer to input image 
         * @return user request object
        */
        UserRequest(InImage *inImage);

        bool getUserButton();
        // get user request to cross
        bool getRetainedRequest();
        // after get request, if true reset it (call it with false)
        void setRetainedRequest(bool retainedRequest);
};
