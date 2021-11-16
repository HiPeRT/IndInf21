#include <iostream>
#include "inc/00-blink.h"

using namespace std;

int main() {
    int blink = 0;
    while (1) {
        cout << "LED:" << (blink ? "ON" : "OFF") << endl;
        blink = next_blink(blink);
    }
}