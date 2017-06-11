#ifndef ANIMATION_QUAD_HPP
#define ANIMATION_QUAD_HPP

#include "sdl2includes.hpp"
namespace engine{

class AnimationQuad{
public:
    AnimationQuad(double p_x, double p_y, SDL_Rect* p_renderQuad, SDL_Rect* p_clipRect, SDL_Texture* p_texture);
    ~AnimationQuad();
    SDL_Rect* getRenderQuad();
    SDL_Rect* getClipRect();
    SDL_Texture* getTexture();
    double getX();
    double getY();
    double x;
    double y;
private:
    SDL_Rect* renderQuad;
    SDL_Rect* clipRect;
    SDL_Texture* texture;
};
}
#endif
