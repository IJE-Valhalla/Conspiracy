#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <sdl2includes.hpp>
#include <string>
#include <utility>

namespace engine{

  bool InitSDL();
  bool FinalizeSDL();
  bool CreateWindow(std::string windowTitle, std::pair<int, int> windowSize);
  SDL_Window* GetGameWindow();
}
#endif
