/*
*
*/

#include <sprite.hpp>
#include <log.h>

Sprite::Sprite(std::string path) {
    m_path = path;
    init();
}

Sprite::Sprite(std::string path, std::pair<double, double> position) {
    m_path = path;
    m_position = position;
    init();
}

void Sprite::init() {
    if(m_path == "") {
        ERROR("INVALID PATH!");
        exit(-1);
    }

    SDL_Surface * image = IMG_Load(m_path.c_str());

    if(image== nullptr) {
        ERROR("FAILED TO LOAD IMAGE!")
        exit(-1);
    }

    // m_texture = std::shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(Canvas::canvas(), image), [=](SDL_Texture *t)
    //     {
    //         INFO("Destroy sprite.");
    //         SDL_DestroyTexture(t);
    //     });

    // m_size = std::make_pair(image->w, image->h);
    // SDL_FreeSurface(image);
}