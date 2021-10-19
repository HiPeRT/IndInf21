#include <stdio.h>

#define SUCCESS 0
#define FAIL 1

#define INPUT_NOT_LEGAL -1
#define INPUT_OUT_OF_BOUND -2

void usage(){
    printf("\e[1;1H\e[2Jusage: automata [a] [b] [c]\n");
}

#define TABLE_SIZE 4
#define FINAL_STATE 3
                                        //  a   b   c   else
const int transitionTable[][TABLE_SIZE] = { {2, 1,  3,  -1}, //state 0
                                            {-1,1,  3,  -1}, //state 1
                                            {0,-1, -1,  -1}, //state 2
                                            {-1,-1, -1, -1}};//state 3

int convertInput(char letter){
    return letter - 'a';
}

int getNextState(int state, int input){
    if (input >= FINAL_STATE || input < 0){
        return INPUT_OUT_OF_BOUND;
    }
    return transitionTable[state][input];
}

int main(int argc, char *argv[]) {
    usage();
    int counter = 1, state = 0, input;

    if (argc < 2){
        usage();
        printf("no arguments passed\n");
    }

    while (counter < argc){
        printf("state: %d\n", state);

        input = convertInput(*argv[counter]);
        state = getNextState(state, input);
        counter++;

        if (state == INPUT_OUT_OF_BOUND){
            usage();
            printf("input %c out of bound\n", *argv[counter-1]);
            break;
        } else if (state == INPUT_NOT_LEGAL) {
            usage();
            printf("input not legal\n");
            break;
        } else if (state == FINAL_STATE) {
            printf("last state reached.. exiting\n");
            break;
        }
        printf(" input: %c ---> state reached: %d\n", *argv[counter-1], state);
    }
    printf("\nexiting..\n");
}