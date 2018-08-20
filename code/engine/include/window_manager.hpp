#ifndef __WINDOW_MANAGER_HPP_
#define __WINDOW_MANAGER_HPP_

#include <string>
#include <utility>
#include <sdl2includes.hpp>
#include "log.h"


class WindowManager {
    public:
        WindowManager() = default;
        virtual ~WindowManager() = default;

        void create_window(std::string name, std::pair<int, int> size, std::string icon_path = "");

        SDL_Window* window();
        SDL_Renderer* canvas();

        void open();
        void close_window();
        void set_window_icon(std::string path);
    
    private:
        std::string window_name;
        std::pair<int, int> window_size;
        std::string m_icon_path;
        SDL_Window *m_window;
        SDL_Renderer *m_canvas;
        SDL_Surface *m_surface;
};

#endif
