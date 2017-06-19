#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <utility>
#include "log.h"
#include "window_manager.hpp"
#include "sdl_manager.hpp"
#include "sdl2includes.hpp"
#include "scene_manager.hpp"
#include "sprite.hpp"
#include "scene_manager.hpp"
#include "input_manager.hpp"
#include "game_object.hpp"
#include "animation.hpp"
#include "animation_manager.hpp"
#include <vector>
#include <iostream>

namespace engine{

  void run();
  void loadEngine();
  SceneManager* getSceneManager();
}
#endif
