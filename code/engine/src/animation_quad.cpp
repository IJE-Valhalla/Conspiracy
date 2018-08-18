#include "animation_quad.hpp"

using namespace engine;

AnimationQuad::AnimationQuad(double p_x, double p_y, SDL_Rect* p_renderQuad, SDL_Rect* p_clipRect, SDL_Texture* p_texture){
    x = p_x;
    y = p_y;
    renderQuad = p_renderQuad;
    clipRect = p_clipRect;
    texture = p_texture;
}

AnimationQuad::~AnimationQuad(){

}

SDL_Rect* AnimationQuad::getRenderQuad(){
    return renderQuad;
}
SDL_Rect* AnimationQuad::getClipRect(){
    return clipRect;
}
SDL_Texture* AnimationQuad::getTexture(){
    return texture;
}
double AnimationQuad::getX(){
    return x;
}
double AnimationQuad::getY(){
    return y;
}
