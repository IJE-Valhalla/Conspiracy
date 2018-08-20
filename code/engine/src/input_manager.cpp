#include "input_manager.hpp"
#include "log.h"

using namespace engine;

InputManager InputManager::instance;

    void InputManager::update(SDL_Event event){
        int keyAction = 0, previousAction = 0;

        while(SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_QUIT:
                quitRequest = true;
                break;
                case SDL_KEYDOWN:
                    keyAction = event.key.keysym.sym;
                    if(!event.key.repeat){
                        keyActive[keyAction] = true;
                        keyPrevious[keyAction] = false;
                        INFO("PUSH");
                    }else if(event.key.repeat){
                        keyPrevious[keyAction] = true;
                    }
                break;
                case SDL_KEYUP:
                    previousAction = event.key.keysym.sym;
                    keyPrevious = keyActive;
                    keyActive[previousAction] = false;
                    INFO("RELEASE");
                break;
            }
        }
    }


    bool InputManager::getQuitRequest(){
        return quitRequest;
    }

    bool InputManager::isKeyPressed(int iKeyCode) {
        return keyActive[iKeyCode];
    }

    bool InputManager::isKeyReleased(int iKeyCode){
        return (!keyActive[iKeyCode] && keyPrevious[iKeyCode]);
    }

    bool InputManager::isKeyTriggered(int iKeyCode){
        if(keyActive[iKeyCode] && !keyPrevious[iKeyCode]){
            keyPrevious[iKeyCode] = true;
            return true;
        }
        return false;
    }

    void InputManager::setQuitRequest(bool isRequest){
        quitRequest = isRequest;
    }
