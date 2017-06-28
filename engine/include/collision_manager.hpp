#ifndef COLLISION_MANAGER_HPP
#define COLLISION_MANAGER_HPP

#include <vector>
#include "engine.hpp"
#include "game_object.hpp"
#include "line.hpp"

using namespace engine;

class CollisionManager{
public:
    bool verifyCollisionWithWalls(GameObject* g);
    bool verifyCollisionWithEnemies(GameObject* g);
    GameObject* verifyCollisionWithPapers(GameObject* g);
    GameObject* verifyCollisionWithSwitches(GameObject* g);
    bool verifyCollision(GameObject* g1, GameObject* g2);
    std::string verifyCollisionWithTables(GameObject* g1);
    std::string verifyCollisionTable(GameObject* g1, GameObject* g2);
    void addWall(GameObject* g);
    void addEnemy(GameObject* g);
    void addPaper(GameObject* g);
    void addDoor(GameObject* g);
    void addSwitch(GameObject* g);
    void addTable(GameObject* g);
    void resetLists();
    static CollisionManager instance;
private:
    double CCW(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c);
    bool verifyLineCollisionWithLine(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c, std::pair<int, int> d);
    bool verifyRectangleCollisionWithLine(GameObject* g, std::pair<int, int> a, std::pair<int, int> b);
    std::vector<GameObject*> wallList;
    std::vector<GameObject*> enemyList;
    std::vector<GameObject*> paperList;
    std::vector<GameObject*> doorList;
    std::vector<GameObject*> switchList;
    std::vector<GameObject*> tableList;
};

#endif
