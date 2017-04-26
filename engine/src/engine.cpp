#include <engine.hpp>
#include "scene_manager.hpp"

namespace engine{

  const std::string GAME_NAME = "Default";
  const std::pair <int, int> WINDOW_SIZE (800, 600);

  SDL_Window *gameWindow;
  SDL_Renderer *gameCanvas;
  SceneManager* sceneManager;

  bool initSDL(){

    INFO("SDL init");

    INFO("SDL audio and video init");
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0){
      return false;
    }

    int imgFlags = IMG_INIT_PNG;
    INFO("SDL image init");
    if(!(IMG_Init(imgFlags) & imgFlags)){
      return false;
    }

    INFO("SDL TTF init");
    if(TTF_Init() == -1){
      return false;
    }

    INFO("SDL mixer init");
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
      return false;
    }

    return true;
  }


  bool finalizeSDL(){
    INFO("Finalizing SDL");

    INFO("Finalizing Mixer");
    Mix_Quit();

    INFO("Finalizing TTF");
    TTF_Quit();

    INFO("Finalizing Mixer");
    IMG_Quit();

    INFO("Finalizing audio and video");
    SDL_Quit();

    return true;
  }


  bool createWindow(std::string windowTitle, std::pair<int, int> windowSize){
    INFO("Create window");
    gameWindow = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, windowSize.first,
                                  windowSize.second, SDL_WINDOW_SHOWN);

    if(gameWindow == NULL){
      return false;
    }

    INFO("Create canvas");
    gameCanvas = SDL_CreateRenderer(gameWindow, -1,
                                    SDL_RENDERER_ACCELERATED |
                                    SDL_RENDERER_PRESENTVSYNC);

    if(gameCanvas == NULL){
      return false;
    }

    SDL_SetRenderDrawColor(gameCanvas, 0, 0, 0, 0);
    SDL_RenderClear(gameCanvas);
    SDL_RenderPresent(gameCanvas);

    return true;
  }


  bool destroyWindow(){
    INFO("Destroying canvas");
    SDL_DestroyRenderer(gameCanvas);
    gameCanvas = NULL;

    INFO("Destroying window");
    SDL_DestroyWindow(gameWindow);
    gameWindow = NULL;

    return true;
  }

  void loadEngine(){
      sceneManager = new SceneManager();
  }
  void run(){
    bool isRunning = true;

    if(!initSDL()){
      ERROR("ERRO AO INICIAR SDL");
      exit(-1);
    }else if(!createWindow(GAME_NAME, WINDOW_SIZE)){
      ERROR("ERRO AO CRIAR JANELA");
      exit(-1);
    }

    while(isRunning){
      SDL_Event evt;
      while(SDL_PollEvent(&evt) != 0){
        if (evt.type == SDL_QUIT){
          isRunning = false;
          finalizeSDL();
          destroyWindow();
        }
      }
      if(sceneManager->getCurrentScene() != NULL){
          //To do: Calculate timeElapsed
          int timeElapsed = 5;
          sceneManager->getCurrentScene()->update(timeElapsed);
          sceneManager->getCurrentScene()->draw();
      }
    }
  }


  SDL_Window* GetGameWindow(){
    return gameWindow;
  }
}
