#ifndef UTILS_H
#define UTILS_H

#include <iostream>

#include "FsmRecognizeSequence.hpp"
#include "LetterInSequence.hpp"

using namespace std;

extern LetterInSequence letter_in_sequence;
extern FsmRecognizeSequence fsm_recognize_sequence;

void request_sequence(string *sequence);
void reset_general(string *sequence);
void handle_error();

#endif