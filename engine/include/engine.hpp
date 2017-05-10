#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <utility>
#include "log.h"
#include "window_manager.hpp"
#include "sdl_manager.hpp"
#include "sdl2includes.hpp"
#include "scene_manager.hpp"

namespace engine{

  void run();
  void loadEngine();
  SceneManager* getSceneManager();
}
#endif
