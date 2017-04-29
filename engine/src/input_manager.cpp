#include "input_manager.hpp"
#include "log.h"


namespace engine{

    InputManager::InputManager(){
        quitRequest = false;
        keyPress = KeyPress::KEY_PRESS_DEFAULT;
    }

    InputManager::~InputManager(){

    }

    void InputManager::update(SDL_Event event){
        keyPress =  KeyPress::KEY_PRESS_DEFAULT;
        while(SDL_PollEvent(&event)){
            switch (event.key.keysym.sym){
                case SDLK_UP:
                    keyPress = KeyPress::KEY_PRESS_UP;
                    INFO("UP");
                break;
                case SDLK_DOWN:
                    keyPress = KeyPress::KEY_PRESS_DOWN;
                    INFO("DOWN");
                break;
                case SDLK_RIGHT:
                    keyPress = KeyPress::KEY_PRESS_RIGHT;
                    INFO("RIGHT");
                break;
                case SDLK_LEFT:
                    keyPress = KeyPress::KEY_PRESS_LEFT;
                    INFO("LEFT");
                break;
                case SDLK_SPACE:
                    keyPress = KeyPress::KEY_PRESS_SPACE;
                    INFO("SPACE");
                break;
                case SDLK_1:
                    keyPress = KeyPress::KEY_PRESS_ONE;
                    INFO("ONE");
                break;
                case SDLK_2:
                    keyPress = KeyPress::KEY_PRESS_TWO;
                    INFO("TWO");
                break;
                case SDLK_3:
                    keyPress = KeyPress::KEY_PRESS_THREE;
                    INFO("THREE");
                break;
            }

            switch(event.type){
                case SDL_QUIT:
                    keyPress = KeyPress::QUIT;
                    quitRequest = true;
                break;
            }
        }
    }

     InputManager::KeyPress InputManager::getKeyPress(){
         return keyPress;
    }

    bool InputManager::getQuitRequest(){
        return quitRequest;
    }
}
