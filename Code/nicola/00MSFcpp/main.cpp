#include "inc/input.hpp"
#include "inc/next_state.hpp"
#include "inc/check_state.hpp"

int main() {

    int table[3][3] = { {2,1,3}, {-1,1,3}, {0,-1,-1} };
    int state=0;

    while (1)
    {
        state = NextState(table,state, Input());
        state = CheckState(state);
    }
    return 0;
}