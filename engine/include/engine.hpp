#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <sdl2includes.hpp>
#include <string>
#include <utility>
#include "log.h"

namespace engine{

  bool initSDL();
  bool finalizeSDL();
  bool createWindow(std::string windowTitle, std::pair<int, int> windowSize);
  bool destroyWindow();
  void run();
  void loadEngine();
  SDL_Window* GetGameWindow();
}
#endif
