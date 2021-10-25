#include "../inc/LetterInSequence.hpp"

LetterInSequence::LetterInSequence()
{

}

uint8_t LetterInSequence::get_index()
{
    return _index;
}

void LetterInSequence::set_index(uint8_t index)
{
    _index = index;
}

void LetterInSequence::reset_index()
{
    _index = 0;
}

char LetterInSequence::next_letter(string *sequence)
{
	char letter = (*sequence)[_index];
	_index ++;
	return letter;
}

bool LetterInSequence::end_sequence(string *sequence)
{
	return _index >= (*sequence).size();
}
