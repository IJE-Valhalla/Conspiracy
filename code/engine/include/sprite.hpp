/*
*
*/

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <string>
#include <memory>

#include "object.hpp"
#include "sdl2includes.hpp"
// #include "canvas.hpp"

class Sprite: public Object {

    public:
        Sprite(std::string path);
        Sprite(std::string path, std::pair<double, double> position);

        virtual ~Sprite() = default;

        void init();

    private:
        std::string m_path;
        std::pair<double, double> m_size;
        std::shared_ptr<SDL_Texture> m_texture {nullptr};
};
  
#endif
