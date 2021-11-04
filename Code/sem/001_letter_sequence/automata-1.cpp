#include <iostream>
#include <string>

#include "inc/FsmRecognizeSequence.hpp"
#include "inc/LetterInSequence.hpp"
#include "inc/utils.hpp"

using namespace std;

LetterInSequence letter_in_sequence;
FsmRecognizeSequence fsm_recognize_sequence;

int main()
{
	string sequence;
	request_sequence(&sequence);

	while(true) {
		char letter = letter_in_sequence.next_letter(&sequence);

		fsm_recognize_sequence.fsm(letter);
		fsm_recognize_sequence.print_sfn();

		if(fsm_recognize_sequence.in_final_state()) {
			if(letter_in_sequence.end_sequence(&sequence)) {
				cout << "Correct sequence inserted" << endl;
				reset_general(&sequence);
			}
		}
		
		if(fsm_recognize_sequence.in_error_state()) {
			handle_error();
			reset_general(&sequence);
		}
	}

	cout << "End" << endl;
	return 0;
}
