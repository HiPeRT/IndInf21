#include <iostream>
#include <unistd.h>

using namespace std;

#define BLUE 0
#define RED 1
#define YELLOW 2
#define GREEN 3
#define ERROR -1
#define INPUT_OUT_OF_BOUND -2

#define TABLE_SIZE 4
                                        //      a        b          c       else
const int transitionTable[][TABLE_SIZE] = { {YELLOW,    RED,      GREEN,    ERROR}, //state BLUE
                                            {ERROR,      RED,      GREEN,    ERROR}, //state RED
                                            {BLUE,      ERROR,     ERROR,     ERROR}, //state YELLOW
                                            {ERROR,      ERROR,     ERROR,     ERROR}};//state GREEN

const int ledTable[TABLE_SIZE] = {BLUE, RED, YELLOW, GREEN};

int getNextState(int state, int input) {
    return transitionTable[state][input];
}

int convertInput(char letter){
    return letter - 'a';
}

int getInputFromUser() {
    char input;

    cout << "\n--->";
    cin >> input;
    
    input = convertInput(input);
    if (input < 0 || input > 3) {
        return INPUT_OUT_OF_BOUND;
    }
    return input;
}

void printLedState(int state) {
    for (int i=0; i < TABLE_SIZE; ++i) {
        if (state == i) {
            cout << ledTable[i] << ": ON\n";
        }
        cout << ledTable[i] << ": OFF\n";
    }
}

#define INITIAL_STATE 0

int main() {
    int state = INITIAL_STATE, nextState, input;
    while(state < 3) {

        printLedState(state);

        input = getInputFromUser();
        if (input == INPUT_OUT_OF_BOUND) {
            cout << "input out of bound\n";
            continue;
        }

        nextState = getNextState(state, input);
        if (nextState == ERROR) {
            cout << "input not legal\n";
            continue;
        }
        state = nextState;
    }
    cout << "last state reached.. exiting\n";
}