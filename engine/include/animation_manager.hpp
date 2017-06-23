#ifndef ANIMATION_MANAGER_HPP
#define ANIMATION_MANAGER_HPP

#include "animation_quad.hpp"
#include "window_manager.hpp"
#include "progress_bar.hpp"
#include "input_manager.hpp"
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
    void addProgressBar(ProgressBar* newProgressBar);
    void addLine(std::pair<std::pair<int,int>,std::pair<int,int>> line);
private:
    bool isActive;
    std::vector<AnimationQuad*> animationQuads;
    std::vector<SDL_Rect*> colliderRects;
    std::vector<ProgressBar*> progressBars;
    std::vector<std::pair<std::pair<int,int>,std::pair<int,int>>> lines;
    void clearAnimationQuads();
    void draw_colliders();
    void drawLinesOfVision();
    void drawProgressBars();
};

}
#endif
