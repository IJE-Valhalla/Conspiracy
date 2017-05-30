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

    bool CollisionManager::verifyCollisionWithWalls(GameObject* g1){
        std::vector<GameObject*>::iterator wall;
        for(wall=wallList.begin() ; wall < wallList.end(); wall++) {
            if(verifyCollision((*wall), g1)){
                return true;
            }
        }
        return false;
    }

    bool CollisionManager::verifyCollisionWithEnemies(GameObject* g1){
        for(GameObject * enemy : enemyList) {
            if(verifyCollision((enemy), g1)){
                return true;
            }
        }
        return false;
    }

    void CollisionManager::resetWallList(){
        wallList.clear();
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

        //If any of the sides from A are outside of B
        if( bottomA <= topB ){ return false;}
        if( topA >= bottomB ){ return false;}
        if( rightA <= leftB ){ return false;}
        if( leftA >= rightB ){ return false;}
        //If none of the sides from A are outside B
        return true;
    }
