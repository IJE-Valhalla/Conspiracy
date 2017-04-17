#include "game.hpp"

using namespace engine;

Game Game::instance;

void Game::setGameProperties(std::string newTitle, int newWidth, int newHeight){
  this->title = newTitle;
  this->width = newWidth;
  this->height = newHeight;
}

void Game::run(){

  if (!initSDL() || !createWindow()){
    destroyWindow();
    exit(-1);
  }
  scene->init();


  while(SDL_QuitRequested() == SDL_FALSE){
    SDL_RenderClear(canvas);
    scene->draw();
    setBackgroundColor(rand()%255, rand()%255, rand()%255, rand()%255);
    SDL_RenderPresent(canvas);
    SDL_Delay(700);

  }
}

void Game::addScene(Scene & newScene){
  scene = &newScene;
}

Scene & Game::getScene(){
  return * scene;
}

bool Game::initSDL(){
  int videoInit = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

  if(videoInit){
    return false;
  }

  int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
  int imageInit = IMG_Init(imageFlags);

  if(!imageInit){
    return false;
  }

  int ttfInit = TTF_Init();

  if(ttfInit == -1){
    return false;
  }

  return true;
}

bool Game::createWindow(){
  window = SDL_CreateWindow(
       title.c_str(),
       SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED,
       width,
       height,
       SDL_WINDOW_SHOWN
     );

  if(window == NULL){
    return false;
  }

  canvas = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
      );

  if(canvas == NULL){
    return false;
  }

  setBackgroundColor(0,0,0,0);

  return true;
}

void Game::setColorCanvas(){
  SDL_SetRenderDrawColor(canvas,
                         backgroundColor.r, backgroundColor.b,
                         backgroundColor.g, backgroundColor.a);
}

void Game::setBackgroundColor(unsigned char r, unsigned char b, unsigned char g, unsigned char a){
  backgroundColor = SDL_Color{r, b, g, a};
  setColorCanvas();
}

bool Game::destroyWindow(){
    TTF_Quit();

    IMG_Quit();

    SDL_Quit();

    return true;
}

SDL_Renderer * Game::getCanvas(){
  return canvas;
}
