#include <unistd.h>

#include <iostream>
using namespace std;

const int timeoutMs = 1000;

int main()
{
    bool onoff = true;
    while(1)
    {
        cout << "Led is " << (onoff ? "ON" : "OFF") << endl;
        onoff = !onoff;
        
        usleep(timeoutMs * 1000);
    }
}