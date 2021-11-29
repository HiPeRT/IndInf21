/**
 * Purpose: sub array
 * @Author Samuele Toscani
 * @Version 1.0
*/

/**
 * TODO: fix any bugs
*/


#pragma once

#include <iostream>

#define _ERROR -1
#define _OK 0

using namespace std;


/**
 * sub array
*/
class SubArray
{
    private:
        uint8_t *_numbers;
        uint8_t _startIndex;
        uint8_t _numElements;

    public:
        /**
         * constructor
         * @param array of numbers
         * @return sub array object
        */
        SubArray(uint8_t *numbers);

        uint8_t *getNumbers();
        uint8_t getStartIndex();
        void setStartIndex(uint8_t startIndex);
        uint8_t getNumElements();
        void setNumElements(uint8_t numElements);
};
