#include "choice.hpp"
#include "sdl2includes.hpp"

Choice::Choice(std::string objectName, double positionX, double positionY,
                                     int width, int height, std::string title, int sizeTitle) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    button = new Button("assets/fonts/font.ttf", positionX + (width/2)*0.2, positionY + height, 200, 150, title, sizeTitle);
    sprite = new Sprite(objectName);
    chosen = false;
}

Choice::~Choice(){}

void Choice::update(double timeElapsed){
    timeElapsed = timeElapsed;
    INFO(timeElapsed);

}

void Choice::draw(){
    INFO("TEXT DRAW");
    sprite->draw(getPositionX(), getPositionY());
    button->draw();
    // Passar para o SDL


        SDL_Surface *surface;

        surface = SDL_CreateRGBSurface(0, getWidth(),getHeight(),32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0x00000000);

        if (surface == NULL) {
            SDL_Log("SDL_CreateRGBSurface() failed: %s", SDL_GetError());
            exit(1);
        }

        int width = surface->w;
        int height = surface->h;

        SDL_Texture* texture = SDL_CreateTextureFromSurface(WindowManager::getGameCanvas(), surface);
        SDL_FreeSurface(surface);

        SDL_Rect  clipRect = {0, 0, width, height};
        SDL_Rect renderQuad = {(int)getPositionX(), (int)getPositionY(), clipRect.w, clipRect.h};

        int alpha = 0;
        if(chosen){
          alpha = 0;
        }else{
          alpha = 220;
        }
        SDL_SetTextureAlphaMod( texture, alpha);
        SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

        SDL_RenderCopy(WindowManager::getGameCanvas(), texture, &clipRect, &renderQuad);

}

void Choice::setTextColor(Color * newTextColor){
    button->setTextColor(newTextColor);
}

void Choice::setBackgroundColor(Color * newBackgroundColor){
    button->setTextColor(newBackgroundColor);
}

Text * Choice::getText(){
    return button->getText();
}

void Choice::setChosen(bool isChosen){
  chosen = isChosen;
}
