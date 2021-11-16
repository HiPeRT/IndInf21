#include <iostream>
using namespace std;

void foo(int *p2)
{
	cout << hex << "[STAMPA] Address of p2: 0x" << (unsigned long long) &p2 << endl;
	cout << hex << "[STAMPA] What's inside the pointer 0x" << (unsigned long long) p2 << endl;
	cout << dec << "[STAMPA] Value in heap is " << *p2 << endl;
}