#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include "sdl2includes.hpp"
#include <unordered_map>

namespace engine{

    class InputManager{

    public:
        enum class KeyPress{
            KEY_PRESS_UP = SDLK_UP,
            KEY_PRESS_DOWN = SDLK_DOWN,
            KEY_PRESS_RIGHT = SDLK_RIGHT,
            KEY_PRESS_LEFT = SDLK_SPACE,
            KEY_PRESS_SPACE = SDLK_SPACE,
            KEY_PRESS_ONE = SDLK_1,
            KEY_PRESS_TWO = SDLK_2,
            KEY_PRESS_THREE = SDLK_3
        };

        InputManager();
        ~InputManager();

        void update(SDL_Event event);
        InputManager::KeyPress getKeyPress();
        void setKeyPress(InputManager::KeyPress key);
        bool getQuitRequest();
        void Update(void);

        ///--- Keyboars state function
        bool isKeyTriggered(int iKeyCode);
        bool isKeyPressed(int iKeyCode);
        bool isKeyReleased(int iKeyCode);

    private:
        KeyPress keyPress;
        bool quitRequest;

        std::unordered_map<int, bool> keyActive;

        ///--- Last frame Keyboard state
        Uint8 m_piPreviousInput[SDL_NUM_SCANCODES];
        ///--- Current frame keyboard state
        Uint8 m_piCurrentInput[SDL_NUM_SCANCODES];
    };
}
#endif
