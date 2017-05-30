#include "log.h"
#include "player.hpp"
using namespace engine;

Player::Player(){
    bilu = new Bilu("assets/sprites/bilu_sheet.png", 100, 0, 40, 43);
    varginha = new Varginha("assets/sprites/varginha_sheet.png", 200,70, 40, 41);
    etemer = new Etemer("assets/sprites/etemer_sheet.png", 300,130, 40, 40);
    selectedAlien = 1;

    bilu->update(0);
    varginha->update(0);
    etemer->update(0);
}

Player::~Player(){}

void Player::update(double timeElapsed){
    int beforeAlien = selectedAlien;

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_ONE)){
        selectedAlien = 1;
    } else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_TWO)){
        selectedAlien = 2;
    } else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_THREE)){
        selectedAlien = 3;
    }

    if(beforeAlien != selectedAlien){
        waitAnimation(beforeAlien);
    }

    switch(selectedAlien){
        case 1: bilu->update(timeElapsed); break;
        case 2: varginha->update(timeElapsed); break;
        case 3: etemer->update(timeElapsed); break;
    }
}

void Player::draw(){
    INFO("PLAYER DRAW");
    bilu->draw();
    varginha->draw();
    etemer->draw();
}

void Player::waitAnimation(int beforeAlien){
    if(beforeAlien==1){
        idleAnimation(bilu);
        bilu->update(0);
    }else if(beforeAlien==2){
        idleAnimation(varginha);
        varginha->update(0);
    } else if(beforeAlien==3){
        idleAnimation(etemer);
        etemer->update(0);
    }
}

void Player::idleAnimation(Alien * alien){
    if(alien->getAnimation()->getInterval().first == "right"){
        alien->getAnimation()->setInterval("idle_right");
    } else if(alien->getAnimation()->getInterval().first == "left"){
        alien->getAnimation()->setInterval("idle_left");
    } else if(alien->getAnimation()->getInterval().first == "up"){
        alien->getAnimation()->setInterval("idle_up");
    }else if(alien->getAnimation()->getInterval().first == "down"){
        alien->getAnimation()->setInterval("idle_down");
    }
}
