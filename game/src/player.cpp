#include "log.h"
#include "player.hpp"
using namespace engine;

Player::Player(std::pair<int, int> biluPosition, std::pair<int, int> etemerPosition,
               std::pair<int,int> varginhaPosition){
        bilu = new Bilu("assets/sprites/bilu_sheet.png", biluPosition.first, biluPosition.second, 19, 22);
        varginha = new Varginha("assets/sprites/varginha_sheet.png", varginhaPosition.first, varginhaPosition.second, 10, 15);
        etemer = new Etemer("assets/sprites/etemer_sheet.png", etemerPosition.first, etemerPosition.second, 10, 22);
        header = new Header("assets/sprites/selecao_personagens_sheet(68X20).png", 0,0, 68,20);
        selectedAlien = 1;

        etemer->update(0);
        bilu->update(0);
        varginha->update(0);
        header->update(0);

        etemer->setAlienSelected();

        bilu_sound_effect = new Audio("assets/sounds/TROCABILU.wav", "EFFECT", 100);
        varginha_sound_effect = new Audio("assets/sounds/TROCAVARGINHA.wav", "EFFECT", 100);
        etemer_sound_effect = new Audio("assets/sounds/TROCATEMER.wav", "EFFECT", 100);
}

Player::~Player(){
}

void Player::update(double timeElapsed){
        int beforeAlien = selectedAlien;

        if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_ONE)) {
                selectedAlien = 1;
        } else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_TWO)) {
                selectedAlien = 2;
        } else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_THREE)) {
                selectedAlien = 3;
        }

        if(beforeAlien != selectedAlien) {
                header->setAlienSelect(selectedAlien);
                etemer->setAlienDeselect();
                bilu->setAlienDeselect();
                varginha->setAlienDeselect();

                waitAnimation(beforeAlien);
                switch(selectedAlien) {
                case 1: etemer->setAlienSelected(); etemer_sound_effect->play(0); break;
                case 2: bilu->setAlienSelected(); bilu_sound_effect->play(0); break;
                case 3: varginha->setAlienSelected(); varginha_sound_effect->play(0); break;
                }
        }

        switch(selectedAlien) {
        case 1: etemer->update(timeElapsed); break;
        case 2: bilu->update(timeElapsed); break;
        case 3: varginha->update(timeElapsed); break;
        }

        header->update(timeElapsed);
}

void Player::draw(){
        INFO("PLAYER DRAW");
        bilu->draw();
        varginha->draw();
        etemer->draw();
        header->draw();
}

void Player::waitAnimation(int beforeAlien){
        if(beforeAlien==1) {
                idleAnimation(etemer);
                etemer->update(0);
        }else if(beforeAlien==2) {
                idleAnimation(bilu);
                bilu->update(0);
        } else if(beforeAlien==3) {
                idleAnimation(varginha);
                varginha->update(0);
        }
}

void Player::idleAnimation(Alien * alien){
        if(alien->getAnimation()->getInterval().first == "right") {
                alien->getAnimation()->setInterval("idle_right");
        } else if(alien->getAnimation()->getInterval().first == "left") {
                alien->getAnimation()->setInterval("idle_left");
        } else if(alien->getAnimation()->getInterval().first == "up") {
                alien->getAnimation()->setInterval("idle_up");
        }else if(alien->getAnimation()->getInterval().first == "down") {
                alien->getAnimation()->setInterval("idle_down");
        }
}
bool Player::isDead(){
        if(!varginha->isEnabled()) {
                return true;
        }else if(!bilu->isEnabled()) {
                return true;
        }else if(!etemer->isEnabled()) {
                return true;
        }
        return false;
}

Alien * Player::getBilu(){
        return bilu;
}

Alien * Player::getVarginha(){
        return varginha;
}

Alien * Player::getEtemer(){
        return etemer;
}
