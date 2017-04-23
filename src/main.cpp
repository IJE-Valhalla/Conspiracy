#include <iostream>

#include "engine.hpp"

using namespace engine;

int main(int, char**){
  std::string title = "TEST";
  std::pair <int, int> size(800, 600);
  InitSDL();
  CreateWindow(title, size);
  if(GetGameWindow() == NULL){
    std::cout << "NO" << std::endl;
  }else{
    std::cout << "YE" << std::endl;
  }

  return 0;
}
