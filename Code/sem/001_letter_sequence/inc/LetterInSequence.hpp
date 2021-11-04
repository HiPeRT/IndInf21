#ifndef LETTER_IN_SEQUENCE_H
#define LETTER_IN_SEQUENCE_H

#include <iostream>

using namespace std;

class LetterInSequence
{
    private:
        uint8_t _index = 0;
        string _sequence;
    public:
        LetterInSequence();

        uint8_t get_index();
        void set_index(uint8_t index);
        
        void reset_index();
        
        char next_letter(string *sequence);
        bool end_sequence(string *sequence);

};

#endif