#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <string>
#include "sdl2includes.hpp"
#include "window_manager.hpp"
#include "input_manager.hpp"


class Engine {
    public:
        static Engine* instance();
        void init();
        void finalize();
        void new_game(std::string game_name, std::pair<int, int> window_size);
        void run();

    private:
        Engine(){}; // block construction
        Engine(Engine const&){}; // block copies
        Engine& operator=(Engine const&){}; // block assigns
        static Engine* m_instance;

        WindowManager window_manager;
        InputManager *input_manager;
};

#endif
