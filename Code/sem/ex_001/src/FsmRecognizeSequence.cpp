#include "../inc/FsmRecognizeSequence.hpp"

FsmRecognizeSequence::FsmRecognizeSequence()
{

}

int8_t FsmRecognizeSequence::get_state()
{
    return _state;
}

void FsmRecognizeSequence::set_state(int8_t state)
{
    _state = state;
}

int8_t FsmRecognizeSequence::get_old_state()
{
    return _old_state;
}

void FsmRecognizeSequence::set_old_state(int8_t old_state)
{
    _old_state = old_state;
}

void FsmRecognizeSequence::reset_state()
{
    _state = 0;
}

void FsmRecognizeSequence::print_sfn()
{
	string tmp_sfn = "t(";
	tmp_sfn.append(to_string(_old_state));
	tmp_sfn.append(", ");
	tmp_sfn.append(_letter == '\0' ? "!" : string(1, _letter));
	tmp_sfn.append(") = ");
	tmp_sfn.append(to_string(_state));
    cout << tmp_sfn << endl;
}

bool FsmRecognizeSequence::in_final_state()
{
	return _state == _FINAL_STATE;
}

bool FsmRecognizeSequence::in_error_state()
{
	return _state == _ERROR_STATE;
}

int8_t FsmRecognizeSequence::s0()
{
	switch(_letter) {
		case 'a':
			return 2;
			break;
		case 'b':
			return 1;
			break;
		case 'c':
			return _FINAL_STATE;
			break;
		default:
			return _ERROR_STATE;
	}
}

int8_t FsmRecognizeSequence::s1()
{
	switch(_letter) {
		case 'b':
			return 1;
			break;
		case 'c':
			return _FINAL_STATE;
			break;
		default:
			return _ERROR_STATE;
	}
}

int8_t FsmRecognizeSequence::s2()
{
	switch(_letter) {
		case 'a':
			return 0;
			break;
		default:
			return _ERROR_STATE;
	}
}

int8_t FsmRecognizeSequence::s3()
{
	switch(_letter) {
		case '\0':
			return 0;
			break;
		default:
			return _ERROR_STATE;
	}
}

void FsmRecognizeSequence::fsm(char letter)
{
    _letter = letter;
    set_old_state(_state);
	switch(_state) {
		case 0:
			_state = s0();
			break;
		case 1:
			_state = s1();
			break;
		case 2:
			_state = s2();
			break;
		case 3:
			_state = s3();
			break;
		default:
			_state = _ERROR_STATE;
			break;
	}
}

void FsmRecognizeSequence::mfn()
{
	// update output
}
