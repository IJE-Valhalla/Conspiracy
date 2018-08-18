#include "finish_point.hpp"

FinishPoint::FinishPoint(std::string objectName, double positionX,
                                                 double positionY,
                                                 int width,
                                                 int height,
                                                 std::string alienNames): GameObject(objectName,
                                                                                     positionX,
                                                                                     positionY,
                                                                                     width,
                                                                                     height){
    aliens = alienNames;
    if(objectName.compare("assets/sprites/cenary/tapete.png") == 0){
        animator = new Animation(objectName, 2, 1, 0.5);
        orientation = "UPDOWN";
    }else{
        animator = new Animation(objectName, 1, 2, 0.5);
        orientation = "LEFTRIGHT";
    }
    etemerAnim = new Animation("assets/sprites/cenary/SAIDA_TEMER.png", 1, 1, 0.5);
    biluAnim = new Animation("assets/sprites/cenary/SAIDA_BILU.png", 1, 1, 0.5);
    varginhaAnim = new Animation("assets/sprites/cenary/SAIDA_VARGINHA.png", 1, 1, 0.5);
}

void FinishPoint::update(double timeElapsed){
    timeElapsed = timeElapsed;
    animator->update();
    biluAnim->update();
    etemerAnim->update();
    varginhaAnim->update();
}

std::string FinishPoint::getAlienNames(){
    return aliens;
}

void FinishPoint::draw(){
    animator->draw_instant(getPositionX(), getPositionY());

    if(orientation.compare("UPDOWN") == 0){
        if(aliens.compare("EBV") == 0){
            etemerAnim->draw_instant(getPositionX()+1, getPositionY()+3.5);
            biluAnim->draw_instant(getPositionX()+12, getPositionY()+3.5);
            varginhaAnim->draw_instant(getPositionX()+23, getPositionY()+3.5);
        }else if(aliens.compare("EB") == 0){
            etemerAnim->draw_instant(getPositionX()+1, getPositionY()+3.5);
            biluAnim->draw_instant(getPositionX()+23, getPositionY()+3.5);
        }else if(aliens.compare("BV") == 0){
            biluAnim->draw_instant(getPositionX()+1, getPositionY()+3.5);
            varginhaAnim->draw_instant(getPositionX()+23, getPositionY()+3.5);
        }else if(aliens.compare("EV") == 0){
            etemerAnim->draw_instant(getPositionX()+1, getPositionY()+3.5);
            varginhaAnim->draw_instant(getPositionX()+23, getPositionY()+3.5);
        }else if(aliens.compare("E") == 0){
            etemerAnim->draw_instant(getPositionX()+12, getPositionY()+3.5);
        }else if(aliens.compare("B") == 0){
            biluAnim->draw_instant(getPositionX()+12, getPositionY()+3.5);
        }else if(aliens.compare("V") == 0){
            varginhaAnim->draw_instant(getPositionX()+12, getPositionY()+3.5);
        }
    }else{
        if(aliens.compare("EBV") == 0){
            etemerAnim->draw_instant(getPositionX()+3.5, getPositionY()+1);
            biluAnim->draw_instant(getPositionX()+3.5, getPositionY()+12);
            varginhaAnim->draw_instant(getPositionX()+3.5, getPositionY()+23);
        }else if(aliens.compare("EB") == 0){
            etemerAnim->draw_instant(getPositionX()+3.5, getPositionY()+1);
            biluAnim->draw_instant(getPositionX()+3.5, getPositionY()+23);
        }else if(aliens.compare("BV") == 0){
            biluAnim->draw_instant(getPositionX()+3.5, getPositionY()+1);
            varginhaAnim->draw_instant(getPositionX()+2, getPositionY()+23);
        }else if(aliens.compare("EV") == 0){
            etemerAnim->draw_instant(getPositionX()+3.5, getPositionY()+1);
            varginhaAnim->draw_instant(getPositionX()+3.5, getPositionY()+23);
        }else if(aliens.compare("E") == 0){
            etemerAnim->draw_instant(getPositionX()+3.5, getPositionY()+12);
        }else if(aliens.compare("B") == 0){
            biluAnim->draw_instant(getPositionX()+3.5, getPositionY()+12);
        }else if(aliens.compare("V") == 0){
            varginhaAnim->draw_instant(getPositionX()+3.5, getPositionY()+12);
        }
    }
}
