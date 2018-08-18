#ifndef ENGINE_COLOR_HPP
#define ENGINE_COLOR_HPP

#include "engine.hpp"

namespace engine {

class Color {
public:
        unsigned char r{0};
        unsigned char g{0};
        unsigned char b{0};
        unsigned char a{0};

        explicit Color(unsigned char colorR, unsigned char colorG, unsigned char colorB,  unsigned char colorA)
        :r(colorR), g(colorG), b(colorB), a(colorA){}
};
}

#endif
