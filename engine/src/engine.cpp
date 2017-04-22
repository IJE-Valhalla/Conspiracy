#include <engine.hpp>
#include <iostream>

Engine::InitSDL(){
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

    std::cout << "SDL mixer init"
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
      return false;
    }

    return true;
}
