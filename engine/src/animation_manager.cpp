#include "animation_manager.hpp"

using namespace engine;

AnimationManager AnimationManager::instance;
void AnimationManager::add_animation_quad(AnimationQuad* newQuad){
    animationQuads.push_back(newQuad);
}

void AnimationManager::add_collider(SDL_Rect* newQuad){
    colliderRects.push_back(newQuad);
}

void AnimationManager::clearAnimationQuads(){
    animationQuads.clear();
}

void AnimationManager::draw_quads(){
        //ORDER QUADS BY Y;
    std::sort(animationQuads.begin(), animationQuads.end(),[](const AnimationQuad* lhs, const AnimationQuad* rhs){ return lhs->y < rhs->y; });
    for(AnimationQuad * quad : animationQuads) {
        SDL_RenderCopy(WindowManager::getGameCanvas(), quad->getTexture(), quad->getClipRect(), quad->getRenderQuad());
    }
    draw_colliders();
    clearAnimationQuads();
}

void AnimationManager::draw_colliders(){
    for(SDL_Rect * quad : colliderRects) {
        SDL_RenderDrawRect(WindowManager::getGameCanvas(), quad);
    }
    colliderRects.clear();
}
