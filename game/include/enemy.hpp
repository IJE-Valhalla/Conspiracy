#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "engine.hpp"
#include "input_manager.hpp"
#include "animation.hpp"
#include "game_object.hpp"
#include "collision_manager.hpp"

using namespace engine;

class Enemy: public GameObject{
public:
    Enemy(){};
    Enemy(std::string objectName, double positionX, double positionY, int width, int height);
    virtual ~Enemy();
    virtual void update(double timeElapsed) = 0;
    virtual void draw() = 0;
};

#endif
