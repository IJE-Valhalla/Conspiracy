#include "sprite.hpp"
#include "game.hpp"


using namespace engine;

Sprite::Sprite(std::string newDirectory){
  directory = newDirectory;
}

Sprite::~Sprite(){

}

bool Sprite::init(){
  SDL_Surface * image = NULL;
  image = IMG_Load(directory.c_str());

  if(image == NULL){
    return false;
  }

  texture = SDL_CreateTextureFromSurface(Game::instance.getCanvas(), image);

  if(texture == NULL){
    return false;
  }

  setClip(0, 0, image->w, image->h);

  SDL_FreeSurface(image);

  return true;
}

bool Sprite::shutdown(){
  SDL_DestroyTexture(texture);
  texture = NULL;

  return true;
}

void Sprite::draw(int x, int y){
  SDL_Rect renderQuad = SDL_Rect{x, y, clipRect.w, clipRect.h};

  SDL_RenderCopy(Game::instance.getCanvas(), texture, NULL, &renderQuad);
}

void Sprite::setClip(int x, int y, int w, int h){
  clipRect = SDL_Rect{x, y, w, h};
}
