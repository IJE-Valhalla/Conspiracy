#include "guard.hpp"

Guard::Guard(std::string objectName, double positionX, double positionY,
             int width, int height, std::string initialDirection) : Enemy(objectName,
                                                                          positionX,
                                                                          positionY,
                                                                          width, height){

        animator = new Animation(objectName, 1, 10, 0.5);
        exclamation = new Animation("assets/sprites/exclamation.png",1, 1, 0.5);

        animator->addAction("right",6,9);
        animator->addAction("left",1,4);
        animator->addAction("up",6,9);
        animator->addAction("down",1,4);
        animator->addAction("idle_right",5,5);
        animator->addAction("idle_left",0,0);
        animator->addAction("idle_up",5,5);
        animator->addAction("idle_down",0,0);

        idleAnimationNumber = 0;
        wayActive = false;
        wayActual = 1;
        direction = initialDirection;
}

Guard::~Guard(){
}

void Guard::update(double timeElapsed){
        auto incY = 0.1*timeElapsed;
        auto incX = 0.1*timeElapsed;
        // To Do: Use Time Elapsed in angleOfVision.
        if(wayActive){
            incY = 0.2*timeElapsed;
            incX = 0.2*timeElapsed;
        }

        walkInX(incX);
        walkInY(incY);

        if(incX == 0 && incY == 0) {
                if(idleAnimationNumber) {
                        animator->setInterval("idle_right");
                }else{
                        animator->setInterval("idle_left");
                }
        }

        specialAction();
        animator->update();
        exclamation->update();
        selectLine();
}

void Guard::walkInX(double & incX){
        if(wayActive) {
                walkInXSpecial(incX);
        }else{
                if(direction == "right") {
                        incX = incX * (1);
                        idleAnimationNumber = 5;
                        animator->setInterval(direction);
                }else if(direction == "left") {
                        incX = incX * (-1);
                        idleAnimationNumber = 0;
                        animator->setInterval(direction);
                }else {
                        incX = 0;
                }
        }

        setPositionX(getPositionX()+incX);
        if(CollisionManager::instance.verifyCollisionWithWalls(this)) {
                if (!wayActive) {
                        if(direction == "left") {
                                direction = "right";
                        }else{
                                direction = "left";
                        }
                }
                setPositionX(getPositionX()+(incX*(0-1)));
        }
}

void Guard::walkInY(double & incY){
        if(wayActive) {
                walkInYSpecial(incY);
        }else{
                if(direction == "down") {
                        incY = incY * (1);
                        idleAnimationNumber = 5;
                        animator->setInterval(direction);
                }else if(direction == "up") {
                        incY = incY * (-1);
                        idleAnimationNumber = 0;
                        animator->setInterval(direction);
                }else {
                        incY = 0;
                }
        }

        setPositionY(getPositionY()+incY);
        if(CollisionManager::instance.verifyCollisionWithWalls(this)) {
            if (!wayActive) {
                    if(direction == "down") {
                            direction = "up";
                    }else{
                            direction = "down";
                    }
            }
                setPositionY(getPositionY()+(incY*(0-1)));
        }
}

void Guard::walkInXSpecial(double & incX){
        if(ways[wayActual].first == "right") {
                incX = incX * (1);
                idleAnimationNumber = 5;
                animator->setInterval("right");
                if(getPositionX()+incX > ways[wayActual].second) {
                        search = ways.find(wayActual + 1);
                        if(search != ways.end()) {
                                wayActual++;
                        }else{
                                wayActual = 1;
                                wayActive = false;
                        }
                }
        }else if(ways[wayActual].first == "left") {
                incX = incX * (-1);
                idleAnimationNumber = 0;
                animator->setInterval("left");
                if(getPositionX()+incX < ways[wayActual].second) {
                        search = ways.find(wayActual + 1);
                        if(search != ways.end()) {
                                wayActual++;
                        }else{
                                wayActual = 1;
                                wayActive = false;
                        }
                }
        }else {
                incX = 0;
        }
}

void Guard::walkInYSpecial(double & incY){
        if(ways[wayActual].first == "down") {
                incY = incY * (1);
                idleAnimationNumber = 5;
                direction = "down";
                animator->setInterval("down");
                if(getPositionY()+incY > ways[wayActual].second) {
                        search = ways.find(wayActual + 1);
                        if(search != ways.end()) {
                                wayActual++;
                        }else{
                                wayActual = 1;
                                wayActive = false;
                        }
                }
        }else if(ways[wayActual].first == "up") {
                incY = incY * (-1);
                idleAnimationNumber = 0;
                direction = "up";
                animator->setInterval("up");
                if(getPositionY()+incY < ways[wayActual].second) {
                        search = ways.find(wayActual + 1);
                        if(search != ways.end()) {
                                wayActual++;
                        }else{
                                wayActual = 1;
                                wayActive = false;
                        }
                }
        }else {
                incY = 0;
        }
}

void Guard::specialAction(){
        if(InputManager::instance.isKeyPressed(InputManager::KEY_PRESS_SPACE)) {
                if(idleAnimationNumber == 5) {
                }else{
                }
        }
}

void Guard::draw(){
    animator->draw(getPositionX()-10, getPositionY()-10);
    animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
    if(wayActive){
        exclamation->draw(getPositionX(), getPositionY()-30);
    }
    drawLinesOfVision();
}

void Guard::drawLinesOfVision(){
    for(auto line:lines){
        std::pair<std::pair<int,int>,std::pair<int,int>> aux;
        aux.first = line->getPoint1();
        aux.second = line->getPoint2();
        AnimationManager::instance.addLine(aux);
    }
}
void Guard::addWay(int key, std::pair<std::string, int> way){
        ways[key] = way;
}

void Guard::verifyDistance(GameObject* alien){
    double distance = sqrt((pow(getPositionX() - alien->getPositionX(), 2.0)) +  (pow(getPositionY() - alien->getPositionY(), 2.0)));
// TODO Definir quando irá iniciar o percurso especial do guarda
    if(distance < 60){
        wayActive = true;
    }
}

void Guard::selectLine(){
    lines.clear();
    int range = 200;
    int angleOfVision = 25;
    //lines of vision
    Line* middleLine, *middleUpperLine, *middleBottomLine, *upperLine, *bottomLine;

    std::pair<int,int> center;
    center.first = getPositionX() + (getWidth()/2);
    center.second = getPositionY() + (getHeight()/2);

    if(animator->getCurrentAction()=="up")
        middleLine = new Line(center.first,center.second,center.first,center.second-range);
    else if(animator->getCurrentAction() == "down")
        middleLine = new Line(center.first,center.second,center.first,center.second+range);
    else if(animator->getCurrentAction() == "right")
        middleLine = new Line(center.first,center.second,center.first+range,center.second);
    else
        middleLine = new Line(center.first,center.second,center.first-range,center.second);

    if(animator->getCurrentAction() == "up" or animator->getCurrentAction() == "down"){
        middleUpperLine = new Line(center.first, center.second, middleLine->getPoint2().first- angleOfVision, middleLine->getPoint2().second);
        upperLine = new Line(center.first, center.second, middleLine->getPoint2().first  - angleOfVision - angleOfVision, middleLine->getPoint2().second);
        middleBottomLine = new Line(center.first, center.second, middleLine->getPoint2().first  + angleOfVision, middleLine->getPoint2().second);
        bottomLine = new Line(center.first, center.second, middleLine->getPoint2().first  + angleOfVision  + angleOfVision, middleLine->getPoint2().second);
    }else{
        middleUpperLine = new Line(center.first, center.second, middleLine->getPoint2().first, middleLine->getPoint2().second - angleOfVision);
        upperLine = new Line(center.first, center.second, middleLine->getPoint2().first, middleLine->getPoint2().second - angleOfVision - angleOfVision);
        middleBottomLine = new Line(center.first, center.second, middleLine->getPoint2().first, middleLine->getPoint2().second + angleOfVision);
        bottomLine = new Line(center.first, center.second, middleLine->getPoint2().first, middleLine->getPoint2().second + angleOfVision + angleOfVision);
    }

    lines.push_back(middleLine);
    lines.push_back(middleUpperLine);
    lines.push_back(upperLine);
    lines.push_back(middleBottomLine);
    lines.push_back(bottomLine);
}
