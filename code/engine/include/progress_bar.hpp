#ifndef PROGRESS_BAR_HPP
#define PROGRESS_BAR_HPP

#include "sdl2includes.hpp"
#include "window_manager.hpp"
#include "game_object.hpp"

#include <vector>

namespace engine{
    class ProgressBar: public GameObject{
    public:
        ProgressBar(double positionX, double positionY, int width, int height, double increment);
        ProgressBar(double positionX, double positionY, int width, int height,
                    double increment, std::vector<unsigned int> newBackColor, std::vector<unsigned int> newFrontColor);
        ~ProgressBar();
        void update(double timeElapsed);
        void draw();
        double getPercent();
        void resetPercent();

    private:
        double percent{0.0};
        double progressIncrement{0.0};
        int pw{0};
        int px{0};
        SDL_Rect *backRect{nullptr};
        SDL_Rect *frontRect{nullptr};
        SDL_Color backColor{};
        SDL_Color frontColor{};
        SDL_Color oldColor{};
    };
}

#endif
