#ifndef GUARD_HPP
#define GUARD_HPP

#include "engine.hpp"
#include "input_manager.hpp"
#include "animation.hpp"
#include "enemy.hpp"
#include "collision_manager.hpp"

using namespace engine;

class Guard: public Enemy{
public:
    Guard(std::string objectName, double positionX, double positionY, int width, int height);
    ~Guard();
    void update(double timeElapsed);
    void draw();
    void addWay(int key, std::pair<std::string, int> way);
    Animation * getAnimation();
private:
    void walkInX(double & incX);
    void walkInY(double & incY);
    void specialAction();
    int idleAnimationNumber;
    int wayActual;
    bool wayActive;
    Animation* animator;
    std::string direction;
    std::unordered_map< int, std::pair<std::string, int>> ways;
    std::unordered_map< int, std::pair<std::string, int>>::iterator search;
};

#endif
