#include "collision_manager.hpp"
#include "log.h"

using namespace engine;

CollisionManager CollisionManager::instance;

    void CollisionManager::addWall(GameObject* g){
        wallList.push_back(g);
    }

    void CollisionManager::addEnemy(GameObject* g){
        enemyList.push_back(g);
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

    void CollisionManager::addTable(GameObject* g){
        tableList.push_back(g);
    }

    bool CollisionManager::verifyCollisionWithWalls(GameObject* g1){
        for(GameObject * wall : wallList) {
            if(verifyCollision(wall, g1)){
                return true;
            }
        }
        for(GameObject* door: doorList){
            if(door->isEnabled() && verifyCollision(door,g1)){
                return true;
            }
        }
        return false;
    }

    std::string CollisionManager::verifyCollisionWithTables(GameObject* g1){
        std::string collision = "";
        for(GameObject * table : tableList) {
            if((collision = verifyCollisionTable(table, g1))!="none"){
                WARN(collision);
            }
        }
        return "None";
    }

    bool CollisionManager::verifyCollisionWithEnemies(GameObject* g1){
        for(GameObject * enemy : enemyList) {
            if(verifyCollision(enemy, g1)){
                return true;
            }
        }
        return false;
    }

    GameObject* CollisionManager::verifyCollisionWithSwitches(GameObject* g1){
        for(GameObject * doorSwitch : switchList) {
            if(verifyCollision(doorSwitch, g1)){
                return doorSwitch;
            }
        }
        return NULL;
    }

    GameObject* CollisionManager::verifyCollisionWithPapers(GameObject* g1){
        for(GameObject * paper : paperList) {
            if(verifyCollision(paper, g1)){
                return paper;
            }
        }
        return NULL;
    }

    void CollisionManager::resetLists(){
        wallList.clear();
        enemyList.clear();
        paperList.clear();
        doorList.clear();
        switchList.clear();
        tableList.clear();
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

        if(g2->getWidth() == 0 || g2->getHeight() == 0){
            return false;
        }
        if(g1->getWidth() == 0 || g1->getHeight() == 0){
            return false;
        }


        //If any of the sides from A are outside of B
        if( bottomA <= topB ){ return false;}
        if( topA >= bottomB ){ return false;}
        if( rightA <= leftB ){ return false;}
        if( leftA >= rightB ){ return false;}
        //If none of the sides from A are outside B
        return true;
    }
    bool CollisionManager::verifyRectangleCollisionWithLine(GameObject* g, std::pair<int, int> a, std::pair<int, int> b){
        std::pair<std::pair<int, int>, std::pair<int, int>> topo;
        std::pair<std::pair<int, int>, std::pair<int, int>> direita;
        std::pair<std::pair<int, int>, std::pair<int, int>> esquerda;
        std::pair<std::pair<int, int>, std::pair<int, int>> embaixo;

        topo.first.first = g->getPositionX();
        topo.first.second = g->getPositionY();
        topo.second.first = g->getPositionX()+g->getWidth();
        topo.second.second= g->getPositionY();

        direita.first.first = g->getPositionX()+g->getWidth();
        direita.first.second = g->getPositionY();
        direita.second.first = g->getPositionX()+g->getWidth();
        direita.second.second= g->getPositionY()+g->getHeight();

        esquerda.first.first = g->getPositionX();
        esquerda.first.second = g->getPositionY();
        esquerda.second.first = g->getPositionX();
        esquerda.second.second= g->getPositionY()+g->getHeight();

        embaixo.first.first = g->getPositionX();
        embaixo.first.second = g->getPositionY()+g->getHeight();
        embaixo.second.first = g->getPositionX()+g->getWidth();
        embaixo.second.second= g->getPositionY()+g->getHeight();

        if(verifyLineCollisionWithLine(topo.first,topo.second,a,b)){return true;}
        if(verifyLineCollisionWithLine(direita.first,direita.second,a,b)){return true;}
        if(verifyLineCollisionWithLine(esquerda.first,esquerda.second,a,b)){return true;}
        if(verifyLineCollisionWithLine(embaixo.first,embaixo.second,a,b)){return true;}
        
        return false;
    }

    bool CollisionManager::verifyLineCollisionWithLine(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c, std::pair<int, int> d){
        return (CCW(a,b,c)*CCW(a,b,d)<0 && CCW(c,d,b)*CCW(c,d,a)<0);
    }

    double CollisionManager::CCW(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c){
        return (b.first-a.first)*(c.second-a.second) - (b.second-a.second)*(c.first-a.first);
    }


    std::string CollisionManager::verifyCollisionTable(GameObject* g1, GameObject* g2){
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

        //If any of the sides from A are outside of B
        if( bottomA > topB ){ return "top";}
        if( topA < bottomB ){ return "bottom";}
        if( rightA > leftB ){ return "right";}
        if( leftA < rightB ){ return "left";}
        //If none of the sides from A are outside B
        return "none";
    }
