/**
 * Purpose: array reduction
 * @Author Samuele Toscani
 * @Version 1.0
*/

/**
 * TODO: fix any bugs
*/


#pragma once

#include <iostream>
#include <pthread.h>

#include "../inc/SubArray.hpp"

#define NUM_THREADS 5
#define NUM_SUB_ARRAY 5
#define _ERROR -1
#define _OK 0

using namespace std;


/**
 * array reduction
*/
class ArrayReduction
{
    private:
        uint8_t *_numbers;
        uint8_t _lenNumbers;
        uint8_t _evenNumbersCount;
        SubArray *_subArray[NUM_SUB_ARRAY];
        pthread_t _thread[NUM_THREADS];
        pthread_attr_t _attr;
        uint8_t *_ret;

        static void *evenNumbers(void *args);

    public:
        /**
         * constructor
         * @param array of numbers, lenght of the array
         * @return array reduction object
        */
        ArrayReduction(uint8_t *numbers, uint8_t lenNumbers);

        uint8_t getEvenNumbersCount();
        void setEvenNumbersCount(uint8_t evenNumbersCount);

        int8_t createThreads();
        int8_t joinThreads();
        int8_t destroyAttrThreads();
};
