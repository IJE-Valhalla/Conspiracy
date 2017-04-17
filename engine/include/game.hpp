#ifndef ENGINE_GAME_HPP
#define ENGINE_GAME_HPP

#include <iostream>
#include <string>

#include "sdl2include.h"
#include "scene.hpp"

namespace engine{
  class Game{
  public:
    static Game instance;

    void setGameProperties(std::string newTitle, int newWidth, int newHeight);

    void run();
    void addScene(Scene & newScene);
    SDL_Renderer * getCanvas();
    Scene & getScene();
    void setBackgroundColor(unsigned char r, unsigned char b, unsigned char g, unsigned char a);

  private:
    SDL_Window* window;
    SDL_Renderer* canvas;
    Scene* scene;
    SDL_Color backgroundColor;
    std::string title;
    int width;
    int height;

    bool createWindow();
    bool destroyWindow();
    bool initSDL();
    void setColorCanvas();
  };
}
#endif
