#include "Shape.hpp"

class Circle : public Shape
{
    private:
        int _radius;

    public:
        float Area()
        {
            return 3.14 * this->_radius * this->_radius;
        }
};