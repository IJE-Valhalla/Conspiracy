#include "input_manager.hpp"

InputManager* InputManager::m_instance = NULL;

InputManager* InputManager::instance() {
    if(!m_instance) {
        m_instance = new InputManager;
    }
    return m_instance;
}

void InputManager::update(SDL_Event event) {
    while(SDL_PollEvent(&event)){
        switch(event.type) {
            case SDL_QUIT:
                m_quit_event = true;
                break;
        }
    }
}

bool InputManager::quit_event() {
    return m_quit_event;
}