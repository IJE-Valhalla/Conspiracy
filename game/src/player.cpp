#include "log.h"
#include "player.hpp"
using namespace engine;

Player::Player(std::pair<int, int> biluPosition, std::pair<int, int> etemerPosition,
      std::pair<int,int> varginhaPosition){
    bilu = new Bilu("assets/sprites/bilu_sheet.png", biluPosition.first, biluPosition.second, 19, 22);
    varginha = new Varginha("assets/sprites/varginha_sheet.png", varginhaPosition.first, varginhaPosition.second, 40, 41);
    etemer = new Etemer("assets/sprites/etemer_sheet.png", etemerPosition.first, etemerPosition.second, 40, 40);
    selectedAlien = 1;

    bilu->update(0);
    varginha->update(0);
    etemer->update(0);

    varginha_sound_effect = new Audio("assets/sounds/TROCAVARGINHA.wav", "EFFECT");
    etemer_sound_effect = new Audio("assets/sounds/TROCATEMER.wav", "EFFECT");
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
        bilu->setAlienDeselect();
        varginha->setAlienDeselect();
        etemer->setAlienDeselect();

        waitAnimation(beforeAlien);
        switch(selectedAlien){
            case 1: bilu->setAlienSelected(); break;
            case 2: varginha->setAlienSelected(); varginha_sound_effect->play(0); break;
            case 3: etemer->setAlienSelected(); etemer_sound_effect->play(0); break;
        }
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
bool Player::isDead(){
    if(!varginha->isEnabled()){
        return true;
    }else if(!bilu->isEnabled()){
        return true;
    }else if(!etemer->isEnabled()){
        return true;
    }
    return false;
}
