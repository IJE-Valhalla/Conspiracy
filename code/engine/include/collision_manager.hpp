#ifndef COLLISION_MANAGER_HPP
#define COLLISION_MANAGER_HPP

#include <vector>
#include "engine.hpp"
#include "game_object.hpp"
#include "line.hpp"
#include "field_of_vision.hpp"

using namespace engine;

class CollisionManager{
public:
    bool verifyCollisionWithWalls(GameObject* g);
    bool verifyCollisionWithWallsAndChairs(GameObject* g);
    bool verifyCollisionWithGuards(GameObject* g);
    bool verifyCollisionWithCameras(GameObject* g);
    bool verifyCollisionWithOtherChairs(GameObject* g);
    GameObject* verifyCollisionWithPapers(GameObject* g);
    GameObject* verifyCollisionWithSwitches(GameObject* g);
    GameObject* verifyCollisionWithCameraSwitches(GameObject* g);
    GameObject* verifyCollisionWithCameraLevers(GameObject* g);
    GameObject* verifyCollisionWithFinishPoints(GameObject* g);
    bool verifyCollision(GameObject* g1, GameObject* g2);
    std::pair<std::string, GameObject *> verifyCollisionWithChairs(GameObject* g1);
    std::string verifyCollisionChair(GameObject* g1, GameObject* g2);
    void addWall(GameObject* g);
    void addGuard(GameObject* g);
    void addPaper(GameObject* g);
    void addDoor(GameObject* g);
    void addGuardFieldOfVision(FieldOfVision* f);
    void addCameraFieldOfVision(FieldOfVision* f);
    void addSwitch(GameObject* g);
    void addChair(GameObject* g);
    void addCameraSwitch(GameObject* g);
    void addCameraLever(GameObject* g);
    void addFinishPoint(GameObject* g);
    void resetLists();
    bool verifyCollisionWithGuardsBody(GameObject* g);
    static CollisionManager instance;
private:
    double CCW(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c);
    bool verifyLineCollisionWithLine(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c, std::pair<int, int> d);
    bool verifyRectangleCollisionWithLine(GameObject* g, std::pair<int, int> a, std::pair<int, int> b);
    bool verifyCollisionWithFieldsOfVision(GameObject*g, std::vector<FieldOfVision*> fields);

    std::vector<GameObject*> wallList{};
    std::vector<GameObject*> guardList{};
    std::vector<FieldOfVision*> guardsVision{};
    std::vector<GameObject*> paperList{};
    std::vector<FieldOfVision*> camerasVision{};
    std::vector<GameObject*> doorList{};
    std::vector<GameObject*> switchList{};
    std::vector<GameObject*> cameraLeverList{};
    std::vector<GameObject*> cameraSwitchList{};
    std::vector<GameObject*> chairList{};
    std::vector<GameObject*> finishPointList{};

    double calculateDistance(std::pair<double,double> center,std::pair<double,double> lineCenter);
};

#endif
