#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <sdl2includes.hpp>
#include <string>
#include <utility>
#include "log.h"

namespace engine{

  bool InitSDL();
  bool FinalizeSDL();
  bool CreateWindow(std::string windowTitle, std::pair<int, int> windowSize);
  bool DestroyWindow();
  void Run();
  SDL_Window* GetGameWindow();
  SDL_Renderer* getGameCanvas();

}
#endif
