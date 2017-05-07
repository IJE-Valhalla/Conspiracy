
#include "player.hpp"

using namespace engine;

Player::Player(){

    bilu = new Alien("Bilu", 0, 0, 50, 50);
    varginha = new Alien("Varginha", 0,70, 50, 50);
    etemer = new Alien("ETemer", 0,130, 50, 50);
    selectedAlien = 1;
}

Player::~Player(){}

void Player::update(int timeElapsed){
    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_ONE)){
        selectedAlien = 1;
    } else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_TWO)){
        selectedAlien = 2;
    } else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_ONE)){
        selectedAlien = 3;
    }

    switch(selectedAlien){
        case 1: bilu->update(timeElapsed); break;
        case 2: varginha->update(timeElapsed); break;
        case 3: etemer->update(timeElapsed); break;
    }
}

void Player::draw(){
    bilu->draw();
    varginha->draw();
    etemer->draw();
}
