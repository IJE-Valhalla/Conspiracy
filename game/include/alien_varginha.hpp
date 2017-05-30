#ifndef ALIEN_VARGINHA_HPP
#define ALIEN_VARGINHA_HPP

#include "alien.hpp"

class Varginha: public Alien{
public:
    Varginha(std::string objectName, double positionX, double positionY, int width, int height);
protected:
    void specialAction();
private:
    bool isInvisible;
};

#endif
