#include "engine.hpp"
#include "log.h"


// Global static pointer to ensure a single instance of the class
Engine* Engine::m_instance = NULL;

double step_time = 0;
double time_elapsed = 0;

const int IMG_FLAGS = IMG_INIT_PNG;
const double FRAME_RATE = 60.0;
const double FRAME_TIME = 1000.0/FRAME_RATE;


Engine* Engine::instance() {
    if(!m_instance) {
        m_instance = new Engine;
        m_instance->window_manager = WindowManager();
        m_instance->input_manager = InputManager::instance();
    }
    return m_instance;
}

void Engine::init() {
    INFO("Initialising SDL");

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0){
        ERROR("Failed to initialise SDL Sound and Video" + SDL_GetError());
        exit(-1);
    }

    if(!(IMG_Init(IMG_FLAGS) & IMG_FLAGS)){
        ERROR("Failed to initialise SDL Image" + SDL_GetError());
        exit(-1);
    }

    if(TTF_Init() == -1){
        ERROR("Failed to initialise SDL TTF" + SDL_GetError());
        exit(-1);
    }

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        ERROR("Failed to initialise SDL Mixer" + SDL_GetError());
        exit(-1);
    }
}

void Engine::finalize() {
    INFO("Finalising SDL");

    INFO("Finalizing Mixer");
    Mix_Quit();

    INFO("Finalizing TTF");
    TTF_Quit();

    INFO("Finalizing Mixer");
    IMG_Quit();

    INFO("Finalizing audio and video");
    SDL_Quit();
}

void Engine::new_game(std::string game_name, std::pair<int, int> window_size) {
    window_manager.create_window(game_name, window_size);
}

void Engine::run() {
    bool running = true;
    SDL_Event event;

    while(running) {
        step_time = SDL_GetTicks();

        input_manager->update(event);
        SDL_RenderClear(window_manager.canvas());

        if(input_manager->quit_event()) {
            running = false;
            window_manager.close_window();
            continue;
        }

        time_elapsed = SDL_GetTicks() - step_time;

        if(FRAME_TIME > time_elapsed) {
            SDL_Delay(FRAME_TIME - time_elapsed);
                time_elapsed = SDL_GetTicks() - step_time;
        }
    }
}