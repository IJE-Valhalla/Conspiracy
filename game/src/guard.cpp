#include "guard.hpp"
#define GUARDSPRITE "assets/sprites/seguranca_sheet.png"

Guard::Guard(double positionX,
             double positionY,
             int width,
             int height,
             std::string initialDirection,
             double newWaitingTime): GameObject(GUARDSPRITE,
                                            positionX,
                                            positionY,
                                            width,
                                            height){

        animator = new Animation(GUARDSPRITE, 1, 10, 0.5);
        exclamation = new Animation("assets/sprites/exclamation.png",1, 1, 0.5);

        animator->addAction("right",6,9);
        animator->addAction("left",1,4);
        animator->addAction("up",6,9);
        animator->addAction("down",1,4);
        animator->addAction("idle_right",5,5);
        animator->addAction("idle_left",0,0);
        animator->addAction("idle_up",5,5);
        animator->addAction("idle_down",0,0);

        range = 150;
        int angleOfVision = 60;
        quantityRepeatWay = 2;
        currentRepeat = 0;

        fieldOfVision = new FieldOfVision(positionX+width/2,positionY-7, range, angleOfVision);
        talkingBar = new ProgressBar(positionX, positionY, 45, 5, 0.0025);

        std::vector<unsigned int> backColor = {255, 0, 0, 255};
        std::vector<unsigned int> frontColor = {0, 0, 0, 255};
        detectionBar = new ProgressBar(positionX, positionY, 30, 5, 0.01, backColor, frontColor);

        idleAnimationNumber = 0;
        waitingTime = newWaitingTime;
        wayActive = false;
        talking = false;
        wayActual = 1;
        direction = initialDirection;
        lastDirection = initialDirection;

        timerHorizontal = new Timer();
        timerVertical = new Timer();

        timerHorizontal->start();
        timerVertical->start();
}

Guard::~Guard(){
}

void Guard::update(double timeElapsed){
        auto incY = 0.1*timeElapsed;
        auto incX = 0.1*timeElapsed;

        // To Do: Use Time Elapsed in angleOfVision.
        if(talking) {
                wayActive = false;
                incX = 0.0;
                incY = 0.0;
        }else{
                if(wayActive) {
                        incY = 0.15*timeElapsed;
                        incX = 0.15*timeElapsed;
                }else{
                        stop(incX, incY);
                }

                walkInX(incX);
                walkInY(incY);
                fieldOfVision->updateCenter(incX,incY);
        }
        if(incX == 0.0 && incY == 0.0) {
                if(idleAnimationNumber) {
                        animator->setInterval("idle_right");
                }else{
                        animator->setInterval("idle_left");
                }
        }

        if(talking){
                talkingBar->update(timeElapsed);
        }
        if(detecting){
            detectionBar->update(timeElapsed);
            if(detectionBar->getPercent() <= 0.0){
                detecting = false;
                wayActive = true;
            }
        }

        animator->update();
        exclamation->update();
        selectLine();
}

void Guard::walkInX(double & incX){
        int beforeWay = wayActual;

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
        if(CollisionManager::instance.verifyCollisionWithWallsAndChairs(this)) {
                if (!wayActive) {
                        verifyDeadLockHorizontal();

                        if(direction == "left") {
                                direction = "right";
                        }else if(direction == "right"){
                                direction = "left";
                        }
                }

                setPositionX(getPositionX()+(incX*(0-1)));
                incX = 0;
                if (beforeWay == wayActual){
                    nextWay();
                }
        }
}

void Guard::walkInY(double & incY){
        int beforeWay = wayActual;

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
        if(CollisionManager::instance.verifyCollisionWithWallsAndChairs(this)) {
                if (!wayActive) {
                        verifyDeadLockVertical();

                        if(direction == "down") {
                                direction = "up";
                        }else if(direction == "up"){
                                direction = "down";
                        }
                }

                setPositionY(getPositionY()+(incY*(0-1)));
                incY = 0;
                if (beforeWay == wayActual){
                    nextWay();
                }
        }
}

void Guard::walkInXSpecial(double & incX){
        if(ways[wayActual].first == "right") {
                incX = incX * (1);
                idleAnimationNumber = 5;
                animator->setInterval("right");
                direction = "right";
                if(getPositionX()+incX > ways[wayActual].second) {
                        incX = 0.0;
                        nextWay();
                }
        }else if(ways[wayActual].first == "left") {
                incX = incX * (-1);
                idleAnimationNumber = 0;
                animator->setInterval("left");
                direction = "left";
                if(getPositionX()+incX < ways[wayActual].second) {
                        incX = 0.0;
                        nextWay();
                }
        }else {
                incX = 0;
        }
}

void Guard::walkInYSpecial(double & incY){
        if(ways[wayActual].first == "down") {
                incY = incY * (1);
                idleAnimationNumber = 5;
                animator->setInterval("down");
                direction = "down";
                if(getPositionY()+incY > ways[wayActual].second) {
                        incY = 0.0;
                        nextWay();
                }
        }else if(ways[wayActual].first == "up") {
                incY = incY * (-1);
                idleAnimationNumber = 0;
                animator->setInterval("up");
                direction = "up";
                if(getPositionY()+incY < ways[wayActual].second) {
                        incY = 0.0;
                        nextWay();
                }
        }else {
                incY = 0;
        }
}

void Guard::draw(){
        animator->draw(getPositionX()-10, getPositionY()-10);
        animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());

        if(detecting) {
            detectionBar->setPositionX(getPositionX() - 10);
            detectionBar->setPositionY(getPositionY() - 20);
            AnimationManager::instance.addProgressBar(detectionBar);
        }
        if(wayActive){
            exclamation->draw(getPositionX(), getPositionY()-30);
        }
        if(talking) {
                AnimationManager::instance.addProgressBar(talkingBar);
                if(talkingBar->getPercent() <= 0.0) {
                        notTalkingToETemer();
                }
        }
        AnimationManager::instance.addGuardVision(fieldOfVision);
        //fieldOfVision->draw();
}

void Guard::addWay(int key, std::string p_direction, int point){
        std::pair<std::string, int> way(p_direction, point);
        ways[key] = way;
}

void Guard::verifyDistance(GameObject* alien){
        double distance = sqrt((pow(getPositionX() - alien->getPositionX(), 2.0)) +  (pow(getPositionY() - alien->getPositionY(), 2.0)));
// TODO Definir quando irá iniciar o percurso especial do guarda
    //std::cout << alien->getName() << std::endl;
    if(alien->getName().compare("assets/sprites/varginha_sheet.png") == 0){
        //std::cout << "AQUI" << std::endl;
        if(distance < 150 && alien->isVisible() && !wayActive){
            detecting = true;
        }else{
            detectionBar->resetPercent();
            detecting = false;
        }
    }else if(distance < 150){
        wayActive = true;
    }
}

void Guard::selectLine(){
        std::string action = animator->getCurrentAction();
        if(lastDirection != action) {
                lastDirection = action;
                if(action == "right" || action == "idle_right") {
                        fieldOfVision->setAngle(0);
                }else if(action == "left" || action == "idle_left") {
                  fieldOfVision->setAngle(180);
                }else if(action == "up") {
                        fieldOfVision->setAngle(90);
                }else if(action == "down") {
                        fieldOfVision->setAngle(270);
                }
        }
}
int Guard::getRange(){
        return range;
}
FieldOfVision* Guard::getFieldOfVision(){
        return fieldOfVision;
}

void Guard::talkingToETemer(std::string status){
        talking = true;
        if(status == "right") {
                idleAnimationNumber = 5;
        }else{
                idleAnimationNumber = 0;
        }
        talkingBar->resetPercent();
        talkingBar->setPositionX(getPositionX() - 10);
        talkingBar->setPositionY(getPositionY() - 20);
}

void Guard::notTalkingToETemer(){
        talking = false;
}
double Guard::getTalkingBarPercent(){
        return talkingBar->getPercent();
}


void Guard::verifyDeadLockHorizontal(){
  if(timerHorizontal->elapsed_time()/100.0 < (waitingTime + 3)){
          if(direction == "right") {
                  direction = "up";
          }else if(direction == "left"){
                  direction = "down";
          }
  }
  timerHorizontal->step();
}

void Guard::verifyDeadLockVertical(){
  if(timerVertical->elapsed_time()/100.0 < (waitingTime + 3)){
          if(direction == "down"){
                  direction = "left";
          }else if(direction == "up"){
                direction = "right";
          }
  }
  timerVertical->step();
}

void Guard::stop(double &incX, double &incY){
      if(((timerVertical->elapsed_time()/100.0) < waitingTime || (timerHorizontal->elapsed_time()/100.0) < waitingTime) && !wayActive){
        incX = 0.0;
        incY = 0.0;
      }
}

void Guard::setWaitingTime(double newWaitingTime){
      waitingTime = newWaitingTime;
}

void Guard::nextWay(){
    search = ways.find(wayActual + 1);

    if(wayActive){
        if(search != ways.end()){
                wayActual++;
        }else{
                currentRepeat ++;
                wayActual = 1;
                if (currentRepeat >= quantityRepeatWay){
                    wayActive = false;
                    currentRepeat = 0;
                }
        }
    }
}
