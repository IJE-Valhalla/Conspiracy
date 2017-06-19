#ifndef ALIEN_ETEMER_HPP
#define ALIEN_ETEMER_HPP

#include "alien.hpp"
#include <time.h>

class Etemer: public Alien{
public:
    Etemer(std::string objectName, double positionX, double positionY,
                                                     int width, int height);
    void update(double timeElapsed);
protected:
    void specialAction();
};

#endif
