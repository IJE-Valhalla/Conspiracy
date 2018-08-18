#ifndef LINE_HPP
#define LINE_HPP

#include <utility>
#include <math.h>
#include "log.h"

#define PI 3.14159265

namespace engine{

class Line{
public:
    Line(double x1, double y1, int size, double angle);
    Line(Line* referenceLine);
    Line(double x1, double y1, double x2, double y2);
    ~Line();
    std::pair<double,double> getPoint1();
    std::pair<double,double> getPoint2();
    void updatePosition(double incX, double incY);
    void setPoint1(double x, double y);
    void setPoint2(double x, double y);
    double getAngle();
    void rotateLine(double angle);
    void changeAngleTo(double angle);
private:
    std::pair<double,double> point1{};
    std::pair<double,double> point2{};
    double angle{0.0};
};

}
#endif
