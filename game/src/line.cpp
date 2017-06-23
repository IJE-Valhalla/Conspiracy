#include "line.hpp"

using namespace engine;

Line::Line(int x1, int y1, int x2, int y2){
    point1.first = x1;
    point1.second = y1;
    point2.first = x2;
    point2.second = y2;
}

std::pair<int,int> Line::getPoint1(){
    return point1;
}
std::pair<int,int> Line::getPoint2(){
    return point2;
}
