#ifndef COLLISION_MANAGER_HPP
#define COLLISION_MANAGER_HPP

#include <vector>
#include "engine.hpp"
#include "game_object.hpp"

using namespace engine;

class CollisionManager{
public:
    bool verifyCollisionWithWalls(GameObject* g);
    bool verifyCollisionWithEnemies(GameObject* g);
    GameObject* verifyCollisionWithPapers(GameObject* g);
    bool verifyCollision(GameObject* g1, GameObject* g2);
    void addWall(GameObject* g);
    void addEnemy(GameObject* g);
    void addPaper(GameObject* g);
    void resetLists();
    static CollisionManager instance;
private:
    std::vector<GameObject*> wallList;
    std::vector<GameObject*> enemyList;
    std::vector<GameObject*> paperList;
};

#endif
