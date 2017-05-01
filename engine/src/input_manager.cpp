#include "input_manager.hpp"
#include "log.h"


namespace engine{

    InputManager::InputManager(){
        quitRequest = false;
    }

    InputManager::~InputManager(){

    }

    bool InputManager::isKeyPressed(SDL_Keycode iKeyCode) {
        return keyActive[iKeyCode];
    }

    bool InputManager::isKeyReleased(SDL_Keycode iKeyCode){
        return true;
    }

    bool InputManager::isKeyTriggered(SDL_Keycode iKeyCode){
        return true;
    }

    void InputManager::update(SDL_Event event){
        while(SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_QUIT:
                    quitRequest = true;
                break;
                case SDL_KEYDOWN:
                    keyActive[event.key.keysym.sym] = true;
                    INFO("PRESS" << event.key.keysym.sym);
                break;
                case SDL_KEYUP:
                    keyActive[event.key.keysym.sym] = false;
                    INFO("PUSH");
                break;
        }
    }
}


    bool InputManager::getQuitRequest(){
        return quitRequest;
    }

}
