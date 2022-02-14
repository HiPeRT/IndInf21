#include "IShape.hpp"

class Shape : public IShape
{
    private:
        // We assume every color has a code
        int _color;

    public:

        // I define no costructors, nor destructors: it is automatically
        // created for us, a ctod/dtor that does barely nothing

        void SetColor(int color)
        {
            this->_color = color;
        }

        int GetColor()
        {
            return this->_color;
        }
};