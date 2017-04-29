#include "sdl_manager.hpp"
#include "log.h"

using namespace engine;

bool SDLManager::initSDL(){

    INFO("SDL init");

    INFO("SDL audio and video init");
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0){
        return false;
    }

    int imgFlags = IMG_INIT_PNG;
    INFO("SDL image init");
    if(!(IMG_Init(imgFlags) & imgFlags)){
        return false;
    }

    INFO("SDL TTF init");
    if(TTF_Init() == -1){
        return false;
    }

    INFO("SDL mixer init");
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        return false;
    }

    return true;
}


bool SDLManager::finalizeSDL(){
    INFO("Finalizing SDL");

    INFO("Finalizing Mixer");
    Mix_Quit();

    INFO("Finalizing TTF");
    TTF_Quit();

    INFO("Finalizing Mixer");
    IMG_Quit();

    INFO("Finalizing audio and video");
    SDL_Quit();

    return true;
}
