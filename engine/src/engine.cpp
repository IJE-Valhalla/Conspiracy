#include "engine.hpp"
#include "sprite.hpp"
#include "scene_manager.hpp"
#include "input_manager.hpp"
#include "game_object.hpp"
#include <vector>
#include <iostream>

namespace engine{

    const std::string GAME_NAME = "Default";
    const std::pair <int, int> WINDOW_SIZE (800, 600);

    SceneManager* sceneManager;
    WindowManager* windowManager;
    SDLManager* sdlManager;
    double prevTime = 0.0;


    void loadEngine(){
        sceneManager = new SceneManager();
        windowManager = new WindowManager();
        sdlManager = new SDLManager();
    }

    double getDelta(){
        double currentTime = SDL_GetTicks();
        double deltaTime = (currentTime - prevTime)/100.0;

        prevTime = currentTime;

        return deltaTime;
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
            SDL_Delay(55);

            if(sceneManager->getCurrentScene() != NULL){
                //To do: Calculate timeElapsed
                int timeElapsed = 5;
                sceneManager->getCurrentScene()->update(timeElapsed);
                sceneManager->getCurrentScene()->draw();
            }
        }
    }



}
