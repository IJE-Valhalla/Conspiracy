#ifndef ENGINE_TEXT_MANAGER_HPP
#define ENGINE_TEXT_MANAGER_HPP

#include <iostream>
#include <string>
#include <map>

#include "sdl2includes.hpp"
#include "engine.hpp"
#include "log.h"

namespace engine{
  class TextManager{
  public:
      TTF_Font* loadFont(std::string path, int size);
      void unload();
      static TextManager instance;
  private:
      TextManager() = default;
      std::map<std::pair<std::string, int>, TTF_Font *> listFont{};
  };
}

#endif
