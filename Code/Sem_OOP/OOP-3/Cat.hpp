#include "Animal.hpp"

#include <iostream>
using namespace std;

class Cat : public Animal
{
  public:

    Cat() { }

    void Print()
    {
      cout << "I am a cat" << endl;
    }


};