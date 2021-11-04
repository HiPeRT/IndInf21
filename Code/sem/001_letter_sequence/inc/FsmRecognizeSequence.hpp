#ifndef FSM_RECOGNIZE_SEQUENCE_H
#define FSM_RECOGNIZE_SEQUENCE_H

#include <iostream>

using namespace std;

class FsmRecognizeSequence
{
    private:
        int8_t _state = 0;
        int8_t _old_state = 0;
        int8_t _FINAL_STATE = 3;
        int8_t _ERROR_STATE = -1;
        char _letter;
    public:
        FsmRecognizeSequence();

        int8_t get_state();
        void set_state(int8_t state);
        int8_t get_old_state();
        void set_old_state(int8_t old_state);
        
        void reset_state();
        void print_sfn();
        bool in_final_state();
        bool in_error_state();

        int8_t s0();
        int8_t s1();
        int8_t s2();
        int8_t s3();
        void fsm(char letter);
        void mfn();
};

#endif