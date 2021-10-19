#include <iostream>
#include <wiringPi.h>
using namespace std;

int main()
{
	// Init
	wiringPiSetup();
	pinMode(0, OUTPUT);
		
	digitalWrite(0, true); // Turn led 0 on
	
	delay(1000); // 1 second delay
	
	digitalWrite(0, false); // Turn led 0 off
	
	return 0;
}
