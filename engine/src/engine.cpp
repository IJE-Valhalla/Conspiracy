#include <engine.hpp>
#include <iostream>

using namespace engine;

bool InitSDL(){
    std::cout << "SDL init";

    std::cout << "SDL audio and video init";
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0){
      return false;
    }

    int imgFlags = IMG_INIT_PNG;
    std::cout << "SDL image init";
    if(!(IMG_Init(imgFlags) & imgFlags)){
      return false;
    }

    std::cout << "SDL TTF init";
    if(TTF_Init() == -1){
      return false;
    }

    std::cout << "SDL mixer init";
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
      return false;
    }

    return true;
}

bool FinalizeSDL(){
  std::cout << "Finalizing SDL";

  std::cout << "Finalizing Mixer";
  Mix_Quit();

  std::cout << "Finalizing TTF";
  TTF_Quit();

  std::cout << "Finalizing Mixer";
  IMG_Quit();

  std::cout << "Finalizing audio and video";
  SDL_Quit();

  return true;
}

bool CreateWindow(std::string windowTitle, std::pair<int, int> windowSize){
  std::cout << "Create window";
  gameWindow = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, windowSize.first,
                                windowSize.second, SDL_WINDOW_SHOWN);

  if(gameWindow == NULL){
    return false;
  }

  std::cout << "Create canvas";
  gameCanvas = SDL_CreateRenderer(gameWindow, -1,
                                  SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);

  if(gameCanvas == NULL){
    return false;
  }
  
  return true;
}
