/**
 * Purpose: class test
 * @Author Samuele Toscani
 * @Version 1.0
*/

/**
 * TODO: fix any bugs
*/


#pragma once

#include <iostream>

#define _INITIAL 0
#define _ERROR -1

using namespace std;


/**
 * class test
*/
class ClassTest
{
    private:
        int8_t _state;
        int8_t _maxValue;

    public:
        /**
         * constructor
         * @param max value to reach
         * @return fsm traffic light object
        */
        ClassTest(int8_t maxValue);

        int8_t getState();
        void setState(int8_t state);

        void addValueToState(int8_t value);
        bool checkReachMaxValue();

};
