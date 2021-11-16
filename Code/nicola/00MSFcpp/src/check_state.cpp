#include <iostream>

using namespace std;

int CheckState(int state) {
    switch (state)
        {
            case 3: 
                cout << "FINAL STATE - return to state 0" << endl;
                return 0;
            case -1: 
                cout << "ERROR - return to state 0" << endl;
                return 0;
            default: 
                cout << "current state: " << state << endl;
                return state;
        }
}