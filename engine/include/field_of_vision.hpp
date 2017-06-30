#ifndef FIELD_OF_VISION_HPP
#define FIELD_OF_VISION_HPP

#include "line.hpp"
#include "animation_manager.hpp"
#include <vector>
#include <math.h>

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
        std::vector<Line*> getLines();
    private:
        Line* centerLine;
        std::vector<Line*> lines;
        std::pair<double,double> center;
        void resetLines();
        void createLines(double x, double y, int range);
        int range;
        double totalAngle;
        int numberOfLines;
    };
}
#endif
