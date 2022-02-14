#include "Rectangle.hpp"

class Square : public Rectangle
{
  public:
     // Setter function
    void SetHeight(int h)
    {
        if(h >= 0)
            this->_height = this->_width = h;
    }
    
    void SetWidth(int w)
    {
        if(w >= 0)
            this->_height = this->_width = w;
    }
};