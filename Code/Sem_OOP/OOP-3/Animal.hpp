#include "IPrintableObject.hpp"
#include "IObjectWithSound.hpp"

#include <iostream>
using namespace std;

class Animal : public IPrintableObject, public IObjectWithSound
{
  public:
    Animal() { }
    virtual void Print()
    {
      cout << "I am an animal" << endl;
    }
    
    virtual void Play()
    {
      cout << "SOME SOUND" << endl;
    }
};