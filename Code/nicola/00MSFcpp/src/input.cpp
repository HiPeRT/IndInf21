#include <iostream>

using namespace std;

char Input() {
    printf("Insert a, b or c: ");
    string input;
    getline(cin, input);
    return input[0];
}