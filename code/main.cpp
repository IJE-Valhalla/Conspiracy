#include "engine.hpp"
#include <iostream>
#include <sdl2includes.hpp>

const std::string GAME_NAME = "Conspiracy";

int main(int, char**){
    
    Engine *engine = Engine::instance();
    engine->init();
    engine->new_game(GAME_NAME, std::make_pair(800, 600));
    engine->run();
    engine->finalize();

    return 0;
}
