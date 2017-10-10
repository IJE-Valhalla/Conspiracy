#include "animation_manager.hpp"

using namespace engine;

AnimationManager AnimationManager::instance;
void AnimationManager::add_animation_quad(AnimationQuad* newQuad){
    animationQuads.push_back(newQuad);
}

void AnimationManager::add_collider(SDL_Rect* newQuad){
    colliderRects.push_back(newQuad);
}
void AnimationManager::addFieldOfVision(FieldOfVision* field){
    fields.push_back(field);
}

void AnimationManager::addGuardVision(FieldOfVision* field){
    guardsVision.push_back(field);
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
    fields.clear();
    guardsVision.clear();
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
    SDL_SetRenderDrawColor(WindowManager::getGameCanvas(), color.r, color.g, color.b, color.a);
}
void AnimationManager::drawLinesOfVision(){

    SDL_SetRenderDrawColor(WindowManager::getGameCanvas(), 230, 0, 0, 1);
    if(!isActive){
        for(auto field: fields){
            drawTriangleVision(field->getLines());
        }
    }else{
        for(auto field: fields){
            for(auto line: field->getLines()){
                drawLine(line);
            }
        }
        for(auto field: guardsVision){
            for(auto line: field->getLines()){
                drawLine(line);
            }
        }
    }

    int colorLine{100};
    SDL_SetRenderDrawColor(WindowManager::getGameCanvas(), colorLine, colorLine, colorLine, 1);

}

void AnimationManager::drawTriangleVision(std::vector<Line*> lines){
    Line* bottomLine = nullptr;
    Line* upperLine = nullptr;
    Line* frontLine = nullptr;
    int i = 0;
    for(auto line:lines){
        if(i++ == 0){
            bottomLine = line;
            upperLine = line;
        }
        if(line->getAngle() > upperLine->getAngle()){
            upperLine = line;
        }
        if(line->getAngle() < bottomLine->getAngle()){
            bottomLine = line;
        }
    }
    frontLine = new Line(bottomLine->getPoint2().first,bottomLine->getPoint2().second,upperLine->getPoint2().first,upperLine->getPoint2().second);
    drawLine(bottomLine);
    drawLine(upperLine);
    drawLine(frontLine);
}
void AnimationManager::drawLine(Line* line){
    SDL_RenderDrawLine(WindowManager::getGameCanvas(), line->getPoint1().first, line->getPoint1().second, line->getPoint2().first, line->getPoint2().second);
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

void AnimationManager::setBackgroundColor(const Color &backgroundColor){
    color = backgroundColor;
}
