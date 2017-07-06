#ifndef ALIEN_ETEMER_HPP
#define ALIEN_ETEMER_HPP

#include "alien.hpp"
#include <time.h>

class Etemer: public Alien{
public:
    Etemer(double positionX, double positionY);
    void update(double timeElapsed);
    void draw();
    void verifyDistance(GameObject* guard);
protected:
    void specialAction(GameObject* guard, double distance);
    void walkInX(double & incX);
    void walkInY(double & incY, double );

private:
    bool talking;
    void moveChair();
};

#endif
