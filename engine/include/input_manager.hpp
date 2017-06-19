#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include "sdl2includes.hpp"
#include <unordered_map>

namespace engine{

    class InputManager{

    public:
        enum KeyPress{
            KEY_PRESS_UP = SDLK_UP,
            KEY_PRESS_DOWN = SDLK_DOWN,
            KEY_PRESS_RIGHT = SDLK_RIGHT,
            KEY_PRESS_LEFT = SDLK_LEFT,
            KEY_PRESS_SPACE = SDLK_SPACE,
            KEY_PRESS_ONE = SDLK_1,
            KEY_PRESS_TWO = SDLK_2,
            KEY_PRESS_THREE = SDLK_3,
            KEY_PRESS_ESC = SDLK_ESCAPE,
            KEY_PRESS_ENTER = SDLK_RETURN
        };

        static InputManager instance;
        void update(SDL_Event event);
        bool getQuitRequest();
        void setQuitRequest(bool isRequest);
        void Update(void);

        bool isKeyTriggered(int iKeyCode);
        bool isKeyPressed(int iKeyCode);
        bool isKeyReleased(int iKeyCode);

    private:
        InputManager(): quitRequest(false){}
        bool quitRequest;
        std::unordered_map<int, bool> keyActive;
        std::unordered_map<int, bool> keyPrevious;
    };
}
#endif
