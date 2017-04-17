#ifndef ENGINE_SCENE_HPP
#define ENGINE_SCENE_HPP

#include <iostream>
#include <string>

#include "sdl2include.h"
#include "sprite.hpp"

namespace engine{
  class Scene{
  public:
    Scene(std::string newName);
    ~Scene();

    void addSprite(Sprite & newSprite);
    void init();
    void draw();
    void shutdown();

  private:
    std::string name;
    Sprite * sprite;
  };
}

#endif
