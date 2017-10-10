#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "sprite.hpp"
#include <unordered_map>
#include "animation_quad.hpp"
#include "animation_manager.hpp"
#include "log.h"
#include <string.h>
#include "window_manager.hpp"

namespace engine{
    class Animation : public Sprite{
    public:
        Animation(std::string newDirectory, int rows, int columns, double allTime);
        ~Animation();

        void init();
        void update();
        void draw(int x, int y);
        void draw_instant(int x, int y);
        void draw_collider(int x, int y, int width, int height);
        void next();
        void shutdown();
        void setTotalTime(double newTotalTime);
        void setCurrentPositionFrame(int positionFrame);
        int getCurrentPositionFrame();
        void setInterval(std::string action);
        void addAction(std::string name_action, int initial, int last);
        std::pair<std::string, std::pair<int, int>> getInterval();
        void setDrawSize(int width, int height);
        std::string getCurrentAction();
    private:
        int currentPositionFrame{0};
        int quantity{0};
        std::string currentAction{};
        int widthFrame{0}, drawWidth{0};
        int heightFrame{0}, drawHeight{0};
        double totalTime{0.0};
        double startTime{0.0};
        double timeElapsed{0.0};
        double stepTime{0.0};
        std::pair<std::string, std::pair<int, int>> interval{};
        std::pair<int, int> matrix{}; // rows and columns
        std::unordered_map<std::string, std::pair<int,int>> list_actions{};
    };

}
#endif
