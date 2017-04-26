#include <engine.hpp>
#include "scene_manager.hpp"

namespace engine{

    const std::string GAME_NAME = "Default";
    const std::pair <int, int> WINDOW_SIZE (800, 600);

    SceneManager* sceneManager;
    WindowManager* windowManager;
    SDLManager* sdlManager;

    void loadEngine(){
      sceneManager = new SceneManager();
      windowManager = new WindowManager();
      sdlManager = new SDLManager();
    }
    void run(){
        bool isRunning = true;

        if(!sdlManager->initSDL()){
            ERROR("ERRO AO INICIAR SDL");
            exit(-1);
        }else if(!windowManager->createWindow(GAME_NAME, WINDOW_SIZE)){
            ERROR("ERRO AO CRIAR JANELA");
            exit(-1);
        }

        while(isRunning){
            SDL_Event evt;
            while(SDL_PollEvent(&evt) != 0){
                if (evt.type == SDL_QUIT){
                    isRunning = false;
                    sdlManager->finalizeSDL();
                    windowManager->destroyWindow();
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
}
