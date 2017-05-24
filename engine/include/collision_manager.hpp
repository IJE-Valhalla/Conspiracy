#ifndef COLLISION_MANAGER_HPP
#define COLLISION_MANAGER_HPP

#include <vector>
#include "engine.hpp"
#include "game_object.hpp"

using namespace engine;

class CollisionManager{
public:
    bool verifyCollisionWithWalls(GameObject* g);
    bool verifyCollision(GameObject* g1, GameObject* g2);
    void addWall(GameObject* g);
    void resetWallList();
    static CollisionManager instance;
private:
    std::vector<GameObject*> wallList;
};

#endif
