#ifndef LINE_HPP
#define LINE_HPP

#include <utility>
namespace engine{

class Line{
public:
    Line(int x1, int y1, int x2, int y2);
    ~Line();
    std::pair<int,int> getPoint1();
    std::pair<int,int> getPoint2();
private:
    std::pair<int,int> point1;
    std::pair<int,int> point2;
};

}
#endif
