#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "sprite.hpp"

namespace engine{
    class Animation : public Sprite{
    public:
        Animation(std::string newDirectory, int rows, int columns, double allTime);
        ~Animation();

        void init();
        void update(int x, int y);
        void draw();
        void shutdown();

        void setCurrentPositionFrame(int positionFrame);
        void setInterval(int firstPositionFrame, int lastPositionFrame);

    private:
        int currentPositionFrame;
        int quantity;
        double totalTime;
        std::pair<int, int> interval;
        std::pair<int, int> matrix;
        std::pair<int, int> lenght;
    };
}
#endif
