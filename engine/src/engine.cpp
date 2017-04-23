#include <engine.hpp>
#include <iostream>

bool Engine::InitSDL(){
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

bool Engine::FinalizeSDL(){
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

Engine* Engine::GetInstance(){
  if(!instance){
    instance = new Engine;
  }
  return instance;
}
