#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "sprite.hpp"

namespace engine{
    class Animation : public Sprite{
    public:
        Animation(std::string newDirectory, int rows, int columns, double allTime);
        ~Animation();

        void init();
        void update();
        void draw(int x, int y);
        void next();
        void shutdown();

        void setCurrentPositionFrame(int positionFrame);
        void setInterval(int firstPositionFrame, int lastPositionFrame);
        std::pair<int,int> getInterval();

    private:
        int currentPositionFrame;
        int quantity;
        int widthFrame;
        int heightFrame;
        double totalTime;
        double startTime;
        double timeElapsed;
        double stepTime;
        std::pair<int, int> interval;
        std::pair<int, int> matrix; // rows and columns
    };
}
#endif
