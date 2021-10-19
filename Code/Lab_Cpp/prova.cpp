#include <iostream>
using namespace std;

void foo(int * param)
{
    cout << "address of param is " << &param << endl;
    cout << "value of param is " << param << endl;
    cout << "content of (value of *)param is " << *param << endl;

}

int main()
{
    int *a = new int;
    *a = 11;

    cout << "address of a is " << &a << endl;
    cout << "value of a is " << a << endl;
    cout << "content of (value of *)a is " << *a << endl;

    foo(a);
    return 0;
}