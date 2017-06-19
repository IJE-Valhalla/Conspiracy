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
        void setInterval(std::string action);
        void addAction(std::string name_action, int initial, int last);
        std::pair<std::string, std::pair<int, int>> getInterval();

    private:
        int currentPositionFrame;
        int quantity;
        int widthFrame;
        int heightFrame;
        double totalTime;
        double startTime;
        double timeElapsed;
        double stepTime;
        std::pair<std::string, std::pair<int, int>> interval;
        std::pair<int, int> matrix; // rows and columns
        std::unordered_map<std::string, std::pair<int,int>> list_actions;
    };

}
#endif
