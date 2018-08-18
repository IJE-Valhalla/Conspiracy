#include "line.hpp"

using namespace engine;

Line::Line(double x1, double y1, int size, double p_angle){
    point1.first = x1;
    point1.second = y1;
    point2.first = x1 + size;
    point2.second = y1;
    this->angle = 0;
    if(p_angle != this->angle){
        rotateLine(angle);
    }
}
Line::Line(Line* referenceLine){
    point1.first = referenceLine->getPoint1().first;
    point1.second = referenceLine->getPoint1().second;
    point2.first = referenceLine->getPoint2().first;
    point2.second = referenceLine->getPoint2().second;
    angle = referenceLine->getAngle();
}

Line::Line(double x1, double y1, double x2, double y2){
    point1.first = x1;
    point1.second = y1;
    point2.first = x2;
    point2.second = y2;

    double deltaY = y2 - y1;
    double deltaX = x2 - x1;

    this->angle = atan2(deltaY,deltaX) * 180 / PI;
}
std::pair<double,double> Line::getPoint1(){
    return point1;
}

std::pair<double,double> Line::getPoint2(){
    return point2;
}

double Line::getAngle(){
    return angle;
}

void Line::updatePosition(double incX, double incY){
    point1.first += incX;
    point1.second += incY;

    point2.first += incX;
    point2.second += incY;
}

void Line::setPoint1(double x, double y){
    point1.first = x;
    point1.second = y;
}
void Line::setPoint2(double x, double y){
    point2.first = x;
    point2.second = y;
}

void Line::rotateLine(double p_angle){
    if(angle > 360){
        angle -= 360;
    }
    double newAngle = p_angle;

    //Centralizar na origem
    point2.first -= point1.first;
    point2.second -= point1.second;

    //transformar em radianos
    p_angle = ((-p_angle)*PI)/180.0;

    double c = cos(p_angle);
    double s = sin(p_angle);

    //rotacionar o ponto
    std::pair<double,double> aux;
    aux.first = point2.first*c - point2.second*s;
    aux.second = point2.first*s + point2.second*c;

    //Salvar o ponto rotacionado
    point2 = aux;

    //Retornar ao local anterior
    point2.first += point1.first;
    point2.second += point1.second;

    angle += newAngle;
}

void Line::changeAngleTo(double p_angle){
    rotateLine(-angle);
    rotateLine(p_angle);
}
