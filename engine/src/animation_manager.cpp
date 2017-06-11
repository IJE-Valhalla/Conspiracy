#include "animation_manager.hpp"

using namespace engine;

AnimationManager AnimationManager::instance;
void AnimationManager::add_animation_quad(AnimationQuad* newQuad){
    animationQuads.push_back(newQuad);
}
void AnimationManager::clearAnimationQuads(){
    animationQuads.clear();
}
void AnimationManager::draw_quads(){
        //ORDER QUADS BY Y;
    for(AnimationQuad * quad : animationQuads) {
        SDL_RenderCopy(WindowManager::getGameCanvas(), quad->getTexture(), quad->getClipRect(), quad->getRenderQuad());
    }
    clearAnimationQuads();
}
