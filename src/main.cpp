#include <iostream>

#include "game.hpp"
#include "scene.hpp"
#include "sprite.hpp"

using namespace engine;

int main(int, char**){
  Game::instance.setGameProperties("Litigium", 1024, 600);

  Scene scene("Colorful");

  Game::instance.addScene(scene);
  Game::instance.run();

  return 0;
}
