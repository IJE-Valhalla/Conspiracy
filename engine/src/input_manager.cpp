#include "input_manager.hpp"
#include "log.h"


namespace engine{

    InputManager::InputManager(){
        quitRequest = false;
        ///--- Initialize the las frame array to 0
       memset(m_piPreviousInput, 0, sizeof(Uint8)*SDL_NUM_SCANCODES);
       ///--- Copy the current status
       memcpy(m_piCurrentInput, SDL_GetKeyboardState(NULL), sizeof(Uint8)*SDL_NUM_SCANCODES);
    }

    InputManager::~InputManager(){

    }

    void InputManager::Update(void){
        INFO("KEY PUSH");
        memcpy(m_piPreviousInput, m_piCurrentInput, sizeof(Uint8)*SDL_NUM_SCANCODES);
        memcpy(m_piCurrentInput, SDL_GetKeyboardState(NULL), sizeof(Uint8)*SDL_NUM_SCANCODES);
    }

    bool InputManager::isKeyPressed(int iKeyCode) {
        int i = (int)iKeyCode;
        return keyActive[i];
    }

    bool InputManager::isKeyReleased(int iKeyCode){
        return (m_piCurrentInput[iKeyCode]==0 && m_piPreviousInput[iKeyCode]==1);
    }

    bool InputManager::isKeyTriggered(int iKeyCode){
        return (m_piCurrentInput[iKeyCode]==1 && m_piPreviousInput[iKeyCode]==0);
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
     InputManager::KeyPress InputManager::getKeyPress(){
         return keyPress;
    }

    void InputManager::setKeyPress(InputManager::KeyPress key){
        keyPress = key;
   }
    bool InputManager::getQuitRequest(){
        return quitRequest;
    }

}
