#include "rectangle.hpp"

Rectangle::Rectangle(std::string objectName, double positionX, double positionY,
  int width, int height, bool newAlphaActive, const Color &newColor): GameObject(objectName,
                                                 positionX,
                                                 positionY,
                                                 width, height){

      color = newColor;
      alphaActive = newAlphaActive;
      init();
}

Rectangle::~Rectangle(){

}

void Rectangle::init(){
    SDL_Surface *surface;

    surface = SDL_CreateRGBSurface(0, getWidth(),getHeight(), 8, 0, 0, 0,0);

    if (surface == NULL) {
        ERROR("Create surface failed.");
        exit(-1);
    }

    setWidth((int)(surface->w));
    setHeight((int)(surface->h));

    texture = SDL_CreateTextureFromSurface(WindowManager::getGameCanvas(), surface);
    SDL_FreeSurface(surface);
}

void Rectangle::update(double timeElapsed){
    timeElapsed = timeElapsed;

    if(isEnabled()) {
        verifyAlpha();
    }
}

void Rectangle::draw(){
    if(isEnabled()) {
      SDL_Rect clipRect = {0, 0, getWidth(), getHeight()};
      SDL_Rect renderQuad = {(int)getPositionX(), (int)getPositionY(), clipRect.w, clipRect.h};

      SDL_RenderCopy(WindowManager::getGameCanvas(), texture, &clipRect, &renderQuad);
    }
}

void Rectangle::verifyAlpha(){
    if(alphaActive){
        SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
        SDL_SetTextureAlphaMod(texture, color.a);
        SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    }
}

void Rectangle::setAlphaActive(bool isActive){
    alphaActive = isActive;
}

bool Rectangle::getAlphaActive(){
    return alphaActive;
}

void Rectangle::setColor(const Color &newColor){
    color = newColor;
}
