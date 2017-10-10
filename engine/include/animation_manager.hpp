#ifndef ANIMATION_MANAGER_HPP
#define ANIMATION_MANAGER_HPP

#include "animation_quad.hpp"
#include "window_manager.hpp"
#include "progress_bar.hpp"
#include "input_manager.hpp"
#include "field_of_vision.hpp"
#include "line.hpp"
#include "color.hpp"
#include <algorithm>
#include <vector>
#include "log.h"

namespace engine{
class FieldOfVision;

class AnimationManager{
public:
    static AnimationManager instance;
    void add_animation_quad(AnimationQuad *newQuad);
    void draw_quads();
    void add_collider(SDL_Rect* renderQuad);
    void addProgressBar(ProgressBar* newProgressBar);
    void addFieldOfVision(FieldOfVision* field);
    void addGuardVision(FieldOfVision* field);
    void addLine(Line* line);
    void setBackgroundColor(const Color &backgroundColor);
private:
    AnimationManager() = default;
    bool isActive{false};
    Color color{100,100,100,0};
    std::vector<AnimationQuad*> animationQuads{};
    std::vector<SDL_Rect*> colliderRects{};
    std::vector<ProgressBar*> progressBars{};
    std::vector<FieldOfVision*> fields{};
    std::vector<FieldOfVision*> guardsVision{};
    void clearAnimationQuads();
    void draw_colliders();
    void drawLinesOfVision();
    void drawProgressBars();
    void drawLine(Line* line);
    void drawTriangleVision(std::vector<Line*> lines);
};

}
#endif
