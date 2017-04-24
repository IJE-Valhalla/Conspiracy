#include <engine.hpp>
#include <iostream>

namespace engine{

  const std::string GAME_NAME = "Default";
  const std::pair <int, int> WINDOW_SIZE (800, 600);

  SDL_Window *gameWindow;
  SDL_Renderer *gameCanvas;


  bool InitSDL(){
    std::cout << "SDL init" << std::endl;

    std::cout << "SDL audio and video init" << std::endl;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0){
      return false;
    }

    int imgFlags = IMG_INIT_PNG;
    std::cout << "SDL image init" << std::endl;
    if(!(IMG_Init(imgFlags) & imgFlags)){
      return false;
    }

    std::cout << "SDL TTF init" << std::endl;
    if(TTF_Init() == -1){
      return false;
    }

    std::cout << "SDL mixer init" << std::endl;
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
      return false;
    }

    return true;
  }


  bool FinalizeSDL(){
    std::cout << "Finalizing SDL" << std::endl;

    std::cout << "Finalizing Mixer" << std::endl;
    Mix_Quit();

    std::cout << "Finalizing TTF" << std::endl;
    TTF_Quit();

    std::cout << "Finalizing Mixer" << std::endl;
    IMG_Quit();

    std::cout << "Finalizing audio and video" << std::endl;
    SDL_Quit();

    return true;
  }


  bool CreateWindow(std::string windowTitle, std::pair<int, int> windowSize){
    std::cout << "Create window" << std::endl;
    gameWindow = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, windowSize.first,
                                  windowSize.second, SDL_WINDOW_SHOWN);

    if(gameWindow == NULL){
      return false;
    }

    std::cout << "Create canvas" << std::endl;
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


  bool Run(){
    bool isRunning = true;

    if(!InitSDL()){
      std::cout << "ERRO AO INICIAR SDL" << std::endl;
      exit(-1);
    }else if(!CreateWindow(GAME_NAME, WINDOW_SIZE)){
      std::cout << "ERRO AO CRIAR JANELA" << std::endl;
      exit(-1);
    }
    char var;
    while(isRunning){
      std::cin >> var;
      if(var == 'a'){
        isRunning = false;
        FinalizeSDL();
      }
    }
  }


  SDL_Window* GetGameWindow(){
    return gameWindow;
  }
}
