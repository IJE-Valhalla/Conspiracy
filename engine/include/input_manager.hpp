#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include "sdl2includes.hpp"

namespace engine{
    class InputManager{
    public:
        enum class KeyPress{
            KEY_PRESS_DEFAULT;
            KEY_PRESS_UP;
            KEY_PRESS_DOWN;
            KEY_PRESS_RIGHT;
            KEY_PRESS_LEFT;
            KEY_PRESS_SPACE;
            KEY_PRESS_ONE;
            KEY_PRESS_TWO;
            KEY_PRESS_THREE;
            QUIT;
        };

        InputManager();
        ~InputManager();
        
        void update();
    private:
        KeyPress keyPress;
    };
}
#endif
