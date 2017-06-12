#ifndef ANIMATION_MANAGER_HPP
#define ANIMATION_MANAGER_HPP

#include "animation_quad.hpp"
#include "window_manager.hpp"
#include <algorithm>
#include <vector>
#include "log.h"

namespace engine{

class AnimationManager{
public:
    static AnimationManager instance;
    void add_animation_quad(AnimationQuad *newQuad);
    void draw_quads();
    void add_collider(SDL_Rect* renderQuad);
private:
    std::vector<AnimationQuad*> animationQuads;
    std::vector<SDL_Rect*> colliderRects;
    void clearAnimationQuads();
    void draw_colliders();
};

}
#endif
