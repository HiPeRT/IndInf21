/**
 * Purpose: count the total number of even numbers inside an array
 *          using the reduction paradygm
 * @Author Samuele Toscani
 * @Version 1.0
*/

/**
 * TODO: fix any bugs
*/

#include <iostream>
#include <string>

#include "inc/ArrayReduction.hpp"

#define NUM_NUMBERS 20

using namespace std;


int main(int argc, char const *argv[])
{
    // array
    uint8_t numbers[NUM_NUMBERS] = {1, 1, 3, 5,
                                    2, 3, 5, 11,
                                    4, 6, 7, 13,
                                    8, 0, 8, 17,
                                    2, 4, 6, 21};

    // print array
    uint8_t lenNumbers = sizeof(numbers)/sizeof(numbers[0]);
    cout << "Numbers[" << to_string(lenNumbers) << "]: {";;
    for(uint8_t i=0; i<NUM_NUMBERS-1; i++) {
        cout << to_string(numbers[i]) << ", ";
    }
    cout << to_string(numbers[NUM_NUMBERS-1]) << "}" << endl;

    // instance array raduction object
    ArrayReduction arrayReduction(numbers, lenNumbers);

    // creata threads
    arrayReduction.createThreads();

    // join threads
    arrayReduction.joinThreads();
    arrayReduction.destroyAttrThreads();

    // print total even numbers
    uint8_t evenNumbersCount = arrayReduction.getEvenNumbersCount();
    cout << "Counter even numbers: " << to_string(evenNumbersCount) << endl;

    return 0;
}
