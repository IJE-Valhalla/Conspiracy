#include "field_of_vision.hpp"

using namespace engine;

FieldOfVision::FieldOfVision(double x, double y, int size, double angle){
    range = size;
    totalAngle = angle;

    catchEffect = new Audio("assets/sounds/GUARDAVIU.wav", "EFFECT", 128);
    active = true;
    //not including centerLine
    numberOfLines = 28;
    createLines(x,y,range);
}

void FieldOfVision::resetLines(){
    //free(centerLine);
    for(auto line: lines){
        free(line);
    }
    lines.clear();
}

void FieldOfVision::deactivate(){
    active = false;
}
bool FieldOfVision::isActive(){
    return active;
}

void FieldOfVision::createLines(double x, double y, int size){
    resetLines();
    centerLine = new Line(x,y,size, 0);

    int angleInc = (totalAngle/2)/(numberOfLines/2);
    for(int i = 0, lineAngle = angleInc; i<numberOfLines/2; i++, lineAngle += angleInc){
        Line* newUpperLine = new Line(centerLine);
        newUpperLine->rotateLine(lineAngle);
        lines.push_back(newUpperLine);

        Line* newLowerLine = new Line(centerLine);
        newLowerLine->rotateLine(-lineAngle);
        lines.push_back(newLowerLine);
    }
}
void FieldOfVision::updateCenter(double incX, double incY){
    centerLine->updatePosition(incX,incY);
    for(auto line: lines){
        line->updatePosition(incX,incY);
    }
}

void FieldOfVision::draw(){
    if(active){
        Line* bottomLine = NULL;
        Line* upperLine = NULL;
        Line* frontLine = NULL;
        int i = 0;
        for(auto line:lines){
            if(i++ == 0){
                bottomLine = line;
                upperLine = line;
            }
            if(line->getAngle() > upperLine->getAngle()){
                upperLine = line;
            }
            if(line->getAngle() < bottomLine->getAngle()){
                bottomLine = line;
            }
        }
        frontLine = new Line(bottomLine->getPoint2().first,bottomLine->getPoint2().second,upperLine->getPoint2().first,upperLine->getPoint2().second);
        AnimationManager::instance.addLine(bottomLine);
        AnimationManager::instance.addLine(upperLine);
        AnimationManager::instance.addLine(frontLine);
    }

}

void FieldOfVision::incrementAngle(double angle){
    centerLine->rotateLine(angle);
    for(auto line:lines){
        line->rotateLine(angle);
    }
}

void FieldOfVision::setAngle(double angle){
    centerLine->changeAngleTo(angle);
    int angleInc = (totalAngle/2)/(numberOfLines/2);

    int lineAngle = angle;
    int i = 0;
    bool inverteu = false;
    for(auto line:lines){
        if(i >= numberOfLines/2 && !inverteu){
            lineAngle = angle;
            angleInc *= (-1);
            inverteu = true;
        }
        lineAngle -= angleInc;
        line->changeAngleTo(lineAngle);
        i++;
    }
}

std::vector<Line*> FieldOfVision::getLines(){
    std::vector<Line*> linesReturn;
    linesReturn.push_back(centerLine);
    for(auto line:lines){
        linesReturn.push_back(line);
    }
    return linesReturn;
}

int FieldOfVision::getRange(){
    return range;
}

void FieldOfVision::playEffect(){
    catchEffect->play(0);
}
