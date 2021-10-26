#include <iostream>
#include "03-lib.h"

using namespace std;

int main()
{
	int * p = new int;
	*p = 11;
	
	cout << hex << "[MAIN] Address of p: 0x" << (unsigned long long) &p << endl;
	cout << hex << "[MAIN] What's inside the pointer 0x" << (unsigned long long) p << endl;
	cout << dec << "[MAIN] Value in heap is " << *p << endl;
	
	foo(p);
	
	delete p;
	
	return 0;
}