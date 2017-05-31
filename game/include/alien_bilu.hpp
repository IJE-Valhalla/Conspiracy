#ifndef ALIEN_BILU_HPP
#define ALIEN_BILU_HPP

#include "alien.hpp"

class Bilu: public Alien{
public:
    Bilu(std::string objectName, double positionX, double positionY, int width, int height);
protected:
    void specialAction();
};

#endif
