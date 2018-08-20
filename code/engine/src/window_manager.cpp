#include "window_manager.hpp"

void WindowManager::create_window(std::string name, std::pair<int, int> size, std::string icon_path) {
    m_window = SDL_CreateWindow(
        name.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        size.first,
        size.second,
        SDL_WINDOW_SHOWN
    );

    if(m_window == nullptr) {
        ERROR("UNABLE TO OPEN A WINDOW!" + SDL_GetError());
        exit(-1);
    }

    set_window_icon(icon_path);

    m_surface = SDL_GetWindowSurface(m_window);

    // Black screen
    SDL_FillRect(m_surface, NULL, SDL_MapRGB(m_surface->format, 0x00, 0x00, 0x00));

    //Update the surface
    SDL_UpdateWindowSurface(m_window);
}

void WindowManager::close_window() {
     SDL_DestroyWindow(m_window);
     free(m_window);
}

void WindowManager::set_window_icon(std::string path) {
    SDL_Surface * image = IMG_Load(path.c_str());

    SDL_SetWindowIcon(m_window, image);
    SDL_FreeSurface(image);
}

SDL_Window* WindowManager::window() {
    return m_window;
}

SDL_Renderer* WindowManager::canvas() {
    return m_canvas;
}