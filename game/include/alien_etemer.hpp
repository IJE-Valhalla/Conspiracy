#ifndef ALIEN_ETEMER_HPP
#define ALIEN_ETEMER_HPP

#include "alien.hpp"
#include <time.h>

class Etemer: public Alien{
public:
    Etemer(std::string objectName, double positionX, double positionY,
                                                     int width, int height);
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
