#ifndef __INPUT_MANAGER_HPP_
#define __INPUT_MANAGER_HPP_

#include "log.h"
#include "sdl2includes.hpp"

class InputManager {
    public:
        static InputManager* instance();
        void update(SDL_Event event);
        bool quit_event();
    
    private:
        InputManager(){}; // block construction
        InputManager(InputManager const&){}; // block copies
        InputManager& operator=(InputManager const&){}; // block assigns
        static InputManager* m_instance;
        bool m_quit_event;
};

#endif