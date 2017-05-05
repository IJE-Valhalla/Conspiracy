#include "engine.hpp"
#include "sprite.hpp"
#include "scene_manager.hpp"
#include "input_manager.hpp"
#include "game_object.hpp"
#include "animation.hpp"
#include <vector>
#include <iostream>


namespace engine{

    const std::string GAME_NAME = "Default";
    const std::pair <int, int> WINDOW_SIZE (800, 600);

    SceneManager* sceneManager;
    WindowManager* windowManager;
    SDLManager* sdlManager;
    double startTime;
    double stepTime;
    double timeElapsed;
    double frameTime;
    double frameRate = 60.0;
    SceneManager* getSceneManager(){
        return sceneManager;
    }
    void loadEngine(){
        sceneManager = new SceneManager();
        windowManager = new WindowManager();
        sdlManager = new SDLManager();
        startTime = SDL_GetTicks();
        stepTime = startTime;
        frameTime = 1000.0/frameRate;
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
        SDL_Event event;

        while(isRunning){

            engine::InputManager::instance.update(event);
            SDL_RenderClear(WindowManager::getGameCanvas());

            if(engine::InputManager::instance.getQuitRequest()){
                isRunning = false;
                sdlManager->finalizeSDL();
                windowManager->destroyWindow();
            }
            SDL_RenderPresent(WindowManager::getGameCanvas());

            if(sceneManager->getCurrentScene() != NULL){
                sceneManager->getCurrentScene()->update(timeElapsed);
                sceneManager->getCurrentScene()->draw();
            }


            timeElapsed = SDL_GetTicks() - stepTime;
            if(frameTime > timeElapsed){
                SDL_Delay(frameTime - timeElapsed);
            }
            stepTime = SDL_GetTicks();
        }
    }
}
