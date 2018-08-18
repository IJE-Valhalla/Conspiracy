#ifndef FIELD_OF_VISION_HPP
#define FIELD_OF_VISION_HPP

#include "line.hpp"
#include "animation_manager.hpp"
#include <vector>
#include <math.h>
#include "audio.hpp"

namespace engine{
    class FieldOfVision{
    public:
        FieldOfVision(double x, double y, int range, double totalAngle);
        ~FieldOfVision();
        void updateCenter(double x, double y);
        void draw();
        void incrementAngle(double angleIncrement);
        void setAngle(double angle);
        int getRange();
        void deactivate();
        int getAngle();
        bool isActive();
        std::vector<Line*> getLines();
        void playEffect();
    private:
        bool active{false};
        int range{0};
        int numberOfLines{0};
        double totalAngle{0.0};
        Line* centerLine{nullptr};
        Audio* catchEffect{nullptr};
        std::vector<Line*> lines{};
        std::pair<double,double> center{};

        void resetLines();
        void createLines(double x, double y, int range);

    };
}
#endif
