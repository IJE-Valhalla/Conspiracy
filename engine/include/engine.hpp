#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <sdl2includes.hpp>

class Engine{

public:
  bool InitSDL();
  bool FinalizeSDL();
  static Engine* GetInstance();

private:
  static Engine *instance;
  Engine();
};
#endif
