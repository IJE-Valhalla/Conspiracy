#include "collision_manager.hpp"
#include "log.h"

using namespace engine;

CollisionManager CollisionManager::instance;

void CollisionManager::addGuardFieldOfVision(FieldOfVision* f){
        guardsVision.push_back(f);
}
void CollisionManager::addCameraFieldOfVision(FieldOfVision* f){
        camerasVision.push_back(f);
}
void CollisionManager::addWall(GameObject* g){
        wallList.push_back(g);
}

void CollisionManager::addCameraSwitch(GameObject* g){
    cameraSwitchList.push_back(g);
}

void CollisionManager::addCameraLever(GameObject* g){
    if(g != NULL){
        cameraLeverList.push_back(g);
    }
}

void CollisionManager::addGuard(GameObject* g){
        guardList.push_back(g);
}

void CollisionManager::addPaper(GameObject* g){
        paperList.push_back(g);
}

void CollisionManager::addDoor(GameObject* g){
        doorList.push_back(g);
}

void CollisionManager::addSwitch(GameObject* g){
        switchList.push_back(g);
}

void CollisionManager::addChair(GameObject* g){
        chairList.push_back(g);
}

void CollisionManager::addFinishPoint(GameObject* g){
        finishPointList.push_back(g);
}

bool CollisionManager::verifyCollisionWithWalls(GameObject* g1){
        for(GameObject * wall : wallList) {
                if(verifyCollision(wall, g1)) {
                        return true;
                }
        }
        for(GameObject* door : doorList) {
                if(door->isEnabled() && verifyCollision(door,g1)) {
                        return true;
                }
        }
        return false;
}

bool CollisionManager::verifyCollisionWithWallsAndChairs(GameObject* g1){
        for(GameObject * wall : wallList) {
                if(verifyCollision(wall, g1)) {
                        return true;
                }
        }
        for(GameObject * chair : chairList) {
                if(verifyCollision(chair, g1)) {
                        return true;
                }
        }
        for(GameObject* door : doorList) {
                if(door->isEnabled() && verifyCollision(door,g1)) {
                        return true;
                }
        }
        return false;
}

std::pair<std::string, GameObject *> CollisionManager::verifyCollisionWithChairs(GameObject* g1){
        std::string collision = "";
        for(GameObject * chair : chairList) {
                if((collision = verifyCollisionChair(chair, g1))!="none") {
                        return std::pair<std::string, GameObject*>(collision, chair);
                }
        }
        return std::pair<std::string, GameObject*>(collision, NULL);
}

bool CollisionManager::verifyCollisionWithOtherChairs(GameObject* g){
  for(GameObject * chair : chairList) {
      if(chair != g){
            if(verifyCollision(chair, g)) {
                    return true;
            }
      }
  }
  return false;
}


bool CollisionManager::verifyCollisionWithGuardsBody(GameObject* g){
        for(GameObject * enemy : guardList) {
                if(verifyCollision(enemy, g)) {
                        return true;
                }
        }
        return false;
}


bool CollisionManager::verifyCollisionWithGuards(GameObject* g1){
    bool status = verifyCollisionWithGuardsBody(g1);

    if(status){
            return status;
        }else{
            status = verifyCollisionWithFieldsOfVision(g1, guardsVision);
            return status;
        }
}

bool CollisionManager::verifyCollisionWithCameras(GameObject* g1){
    return verifyCollisionWithFieldsOfVision(g1, camerasVision);
}

bool CollisionManager::verifyCollisionWithFieldsOfVision(GameObject* g1, std::vector<FieldOfVision*> fields){
    bool isVisible = true;
    for(FieldOfVision* field : fields) {
        if(field->isActive()){
            for(Line* line : field->getLines()) {
                    if(verifyRectangleCollisionWithLine(g1,line->getPoint1(),line->getPoint2())) {
                            std::pair<double,double> playerCenter = g1->getCenter();
                            int distanceBetweenPlayer = calculateDistance(playerCenter,line->getPoint1());
                            // Margin between player and line
                            // Or else just touching a line would make you lose
                            if(distanceBetweenPlayer < field->getRange()*0.85) {
                                    for(auto wall : wallList) {
                                            if(verifyRectangleCollisionWithLine(wall,line->getPoint1(),line->getPoint2())) {
                                                    std::pair<double,double> wallCenter = wall->getCenter();
                                                    int distanceBetweenWall = calculateDistance(wallCenter,line->getPoint1());
                                                    //Wall in front of player
                                                    if(distanceBetweenWall < distanceBetweenPlayer) {
                                                            isVisible = false;
                                                    }
                                            }
                                    }
                                    if((isVisible && g1->isVisible())) {
                                            field->playEffect();
                                            return true;
                                    }
                            }
                    }
            }
        }
    }
    return false;
}
GameObject* CollisionManager::verifyCollisionWithSwitches(GameObject* g1){
        for(GameObject * doorSwitch : switchList) {
                if(verifyCollision(doorSwitch, g1)) {
                        return doorSwitch;
                }
        }
        return NULL;
}

GameObject* CollisionManager::verifyCollisionWithCameraSwitches(GameObject* g){
    for(GameObject * cameraSwitch : cameraSwitchList) {
            if(verifyCollision(cameraSwitch, g)) {
                    return cameraSwitch;
            }
    }
    return NULL;

}

GameObject* CollisionManager::verifyCollisionWithCameraLevers(GameObject* g){
    for(GameObject * lever : cameraLeverList) {
            if(verifyCollision(lever, g)) {
                    return lever;
            }
    }
    return NULL;
}

GameObject* CollisionManager::verifyCollisionWithPapers(GameObject* g1){
        for(GameObject * paper : paperList) {
                if(verifyCollision(paper, g1)) {
                        return paper;
                }
        }
        return NULL;
}

GameObject* CollisionManager::verifyCollisionWithFinishPoints(GameObject* g1){
    for(GameObject * finishPoint : finishPointList) {
            if(verifyCollision(finishPoint, g1)) {
                    return finishPoint;
            }
    }
    return NULL;
}


double CollisionManager::calculateDistance(std::pair<double,double> center, std::pair<double,double> lineCenter){
        return sqrt(((center.first-lineCenter.first)*
                     (center.first-lineCenter.first))+
                    ((center.second-lineCenter.second)*
                     (center.second-lineCenter.second)));
}
void CollisionManager::resetLists(){
        wallList.clear();
        guardList.clear();
        paperList.clear();
        doorList.clear();
        switchList.clear();
        chairList.clear();
        guardsVision.clear();
        camerasVision.clear();
        cameraLeverList.clear();
        cameraSwitchList.clear();
}

bool CollisionManager::verifyCollision( GameObject* g1, GameObject* g2){
        //The sides of the rectangles
        int leftA, rightA, topA, bottomA;
        int leftB, rightB, topB, bottomB;

        //Calculate the sides of rect A
        leftA = g1->getPositionX();
        rightA = leftA + g1->getWidth();
        topA = g1->getPositionY();
        bottomA = topA + g1->getHeight();

        //Calculate the sides of rect B
        leftB = g2->getPositionX();
        rightB = leftB + g2->getWidth();
        topB = g2->getPositionY();
        bottomB = topB + g2->getHeight();

        if(g2->getWidth() == 0 || g2->getHeight() == 0) {
                return false;
        }
        if(g1->getWidth() == 0 || g1->getHeight() == 0) {
                return false;
        }

        //If any of the sides from A are outside of B
        if( bottomA <= topB ) { return false; }
        if( topA >= bottomB ) { return false; }
        if( rightA <= leftB ) { return false; }
        if( leftA >= rightB ) { return false; }
        //If none of the sides from A are outside B
        return true;
}
bool CollisionManager::verifyRectangleCollisionWithLine(GameObject* g, std::pair<int, int> a, std::pair<int, int> b){
        std::pair<std::pair<int, int>, std::pair<int, int> > top;
        std::pair<std::pair<int, int>, std::pair<int, int> > right;
        std::pair<std::pair<int, int>, std::pair<int, int> > left;
        std::pair<std::pair<int, int>, std::pair<int, int> > bottom;

        top.first.first = g->getPositionX();
        top.first.second = g->getPositionY();
        top.second.first = g->getPositionX()+g->getWidth();
        top.second.second= g->getPositionY();

        right.first.first = g->getPositionX()+g->getWidth();
        right.first.second = g->getPositionY();
        right.second.first = g->getPositionX()+g->getWidth();
        right.second.second= g->getPositionY()+g->getHeight();

        left.first.first = g->getPositionX();
        left.first.second = g->getPositionY();
        left.second.first = g->getPositionX();
        left.second.second= g->getPositionY()+g->getHeight();

        bottom.first.first = g->getPositionX();
        bottom.first.second = g->getPositionY()+g->getHeight();
        bottom.second.first = g->getPositionX()+g->getWidth();
        bottom.second.second= g->getPositionY()+g->getHeight();

        if(verifyLineCollisionWithLine(top.first,top.second,a,b)) {return true; }
        if(verifyLineCollisionWithLine(right.first,right.second,a,b)) {return true; }
        if(verifyLineCollisionWithLine(left.first,left.second,a,b)) {return true; }
        if(verifyLineCollisionWithLine(bottom.first,bottom.second,a,b)) {return true; }
        return false;
}

bool CollisionManager::verifyLineCollisionWithLine(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c, std::pair<int, int> d){
        return (CCW(a,b,c)*CCW(a,b,d)<0 && CCW(c,d,b)*CCW(c,d,a)<0);
}

double CollisionManager::CCW(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c){
        return (b.first-a.first)*(c.second-a.second) - (b.second-a.second)*(c.first-a.first);
}


std::string CollisionManager::verifyCollisionChair(GameObject* g1, GameObject* g2){
        //The sides of the rectangles
        int leftA, rightA, topA, bottomA;
        int leftB, rightB, topB, bottomB;

        //Calculate the sides of rect A
        leftA = g1->getPositionX();
        rightA = leftA + g1->getWidth();
        topA = g1->getPositionY();
        bottomA = topA + g1->getHeight();

        //Calculate the sides of rect B
        leftB = g2->getPositionX();
        rightB = leftB + g2->getWidth();
        topB = g2->getPositionY();
        bottomB = topB + g2->getHeight();

        if(g2->getWidth() == 0 || g2->getHeight() == 0) {
                return "none";
        }
        if(g1->getWidth() == 0 || g1->getHeight() == 0) {
                return "none";
        }

        if(rightB > (leftA - 3) && rightA > (rightB)) {
                if((bottomB < (bottomA) && bottomB > (topA)) || (topB < bottomA && topB > topA)) {
                        return "right";
                }
                if((bottomA < bottomB && bottomA > topB) || (topA < bottomB && topA > topB)) {
                        return "right";
                }
        }

        if(leftB < (rightA + 3) && leftA < (leftB)) {
                if((bottomB < bottomA && bottomB > topA) ||(topB < bottomA && topB > topA)) {
                        return "left";
                }
                if((bottomA < bottomB && bottomA > topB) || (topA < bottomB && topA > topB)) {
                        return "left";
                }
        }

        if(topB <= (bottomA + 3) && (topB) > topA) {
                if((leftB >= leftA && leftB <= rightA) || (rightB <= rightA && rightB >= leftA)) {
                        return "up";
                }
                if((leftA >= leftB && leftA <= rightB) || (rightA <= rightB && rightA >= leftB)) {
                        return "up";
                }
        }

        if(bottomB >= (topA - 3) && bottomA > (bottomB)) {
                if((leftB >= leftA && leftB <= rightA) || (rightB <= rightA && rightB >= leftA)) {
                        return "down";
                }
                if((leftA >= leftB && leftA <= rightB) || (rightA <= rightB && rightA >= leftB)) {
                        return "down";
                }
        }

        return "none";
}
