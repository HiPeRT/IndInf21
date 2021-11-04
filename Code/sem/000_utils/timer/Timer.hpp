/**
 * Purpose: non blocking timer, it needs to be checked if it is expired
 * @Author Samuele Toscani
 * @Version 1.0
*/

/**
 * TODO: add pause and play feature
*/


#pragma once

#include <iostream>
#include <wiringPi.h>


/**
 * non blocking timer
 * it needs to be checked if it is expired
*/
class Timer
{
    private:
        uint32_t _pauseTimeMs;
        uint32_t _startTimeMs;
        bool _enable;

    public:
        /**
         * constructor
         * @param pause time (ms) to wait
         * @return timer object
        */
        Timer(uint32_t pauseTimeMs);

        uint32_t getPauseTimeMs();
        void setPauseTimeMs(uint32_t pauseTimeMs);

        // start count of the timer
        uint32_t start();
        // check if the timer is expired
        bool expired();
};
