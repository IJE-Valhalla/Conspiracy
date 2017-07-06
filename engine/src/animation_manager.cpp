#include "animation_manager.hpp"

using namespace engine;

AnimationManager AnimationManager::instance;
void AnimationManager::add_animation_quad(AnimationQuad* newQuad){
    animationQuads.push_back(newQuad);
}

void AnimationManager::add_collider(SDL_Rect* newQuad){
    colliderRects.push_back(newQuad);
}
void AnimationManager::addLine(Line* line){
    lines.push_back(line);
}
void AnimationManager::addProgressBar(ProgressBar* newProgressBar){
    progressBars.push_back(newProgressBar);
}

void AnimationManager::clearAnimationQuads(){
    for(auto animationQuad: animationQuads){
        free(animationQuad);
    }
    for(auto collider: colliderRects){
        free(collider);
    }
    animationQuads.clear();
    lines.clear();
    progressBars.clear();
    colliderRects.clear();

}

void AnimationManager::draw_quads(){
    if(InputManager::instance.isKeyTriggered(InputManager::KEY_PRESS_L)){
        if(isActive){
            isActive = false;
        }else{
            isActive = true;
        }
    }
    std::sort(animationQuads.begin(), animationQuads.end(),[](const AnimationQuad* lhs, const AnimationQuad* rhs){ return lhs->y < rhs->y; });
    for(AnimationQuad * quad : animationQuads) {
        SDL_RenderCopy(WindowManager::getGameCanvas(), quad->getTexture(), quad->getClipRect(), quad->getRenderQuad());
    }
    if(isActive){
        draw_colliders();
    }
    drawProgressBars();
    drawLinesOfVision();
    clearAnimationQuads();
}
void AnimationManager::drawLinesOfVision(){

    SDL_SetRenderDrawColor(WindowManager::getGameCanvas(), 230, 0, 0, 1);
    for(auto line: lines){
        SDL_RenderDrawLine(WindowManager::getGameCanvas(), line->getPoint1().first, line->getPoint1().second, line->getPoint2().first, line->getPoint2().second);
    }
    int color = 100;
    SDL_SetRenderDrawColor(WindowManager::getGameCanvas(), color, color, color, 1);
}
void AnimationManager::draw_colliders(){
    for(SDL_Rect * quad : colliderRects) {
        SDL_RenderDrawRect(WindowManager::getGameCanvas(), quad);
    }
}

void AnimationManager::drawProgressBars(){
    for(ProgressBar * progressBar : progressBars) {
        progressBar->draw();
    }
}
