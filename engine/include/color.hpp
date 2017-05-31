#ifndef ENGINE_COLOR_HPP
#define ENGINE_COLOR_HPP

#include "engine.hpp"

namespace engine {

class Color {
public:
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;

        Color(unsigned char colorR, unsigned char colorG, unsigned char colorB,  unsigned char colorA)
        :r(colorR), g(colorG), b(colorB), a(colorA){}


};
}

#endif
