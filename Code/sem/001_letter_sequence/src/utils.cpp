#include "../inc/utils.hpp"

void request_sequence(string *sequence)
{
	cout << "sequence: ";
	cin >> *sequence;
	cout << *sequence << " [" << to_string((*sequence).size()) << "]" << endl;
}

void reset_general(string *sequence)
{
	fsm_recognize_sequence.reset_state();
	letter_in_sequence.reset_index();
	request_sequence(sequence);
}

void handle_error()
{
	cout << "Error handler" << endl;
	// do something
}
