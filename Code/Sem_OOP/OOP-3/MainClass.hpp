#include "Cat.hpp"

int main ()
{
  Cat *tommy = new Cat;

  tommy->Print();
  tommy->Animal::Print();

  return 0;
}