#ifndef ENGINE_SPRITE_HPP
#define ENGINE_SPRITE_HPP

#include <iostream>
#include <string>

#include "sdl2include.h"

namespace engine{
  class Sprite{
  public:
    Sprite(std::string newDirectory);
    ~Sprite();

    bool init();
    bool shutdown();
    void draw(int x, int y);
    void setClip(int x, int y, int w, int h);

  private:
    SDL_Texture * texture;
    SDL_Rect clipRect;
    std::string directory;
    int width;
    int height;

  };
}

#endif
