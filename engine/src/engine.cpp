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

        engine::Animation animation("assets/sprites/bomberman2.png", 4, 6, 15.0);
        animation.init();
        animation.setInterval(6,11);
        int x=0, y=0, actual = 1;;
        animation.update(0,0);

        SDL_Event event;

        while(isRunning){

            engine::InputManager::instance.update(event);
            SDL_RenderClear(WindowManager::getGameCanvas());

            if(engine::InputManager::instance.getQuitRequest()){
                isRunning = false;
                sdlManager->finalizeSDL();
                windowManager->destroyWindow();
            }

            if(engine::InputManager::instance.isKeyPressed(SDLK_RIGHT) && actual == 1){
                    x+=5;
                    animation.setInterval(0,5);
                    animation.update(x,y);
                }
                if(engine::InputManager::instance.isKeyPressed(SDLK_LEFT) && actual == 1){
                    x-=5;
                    animation.setInterval(18,22);
                    animation.update(x,y);
                }

                if(engine::InputManager::instance.isKeyPressed(SDLK_UP)  && actual == 1){
                    y-=5;
                    animation.setInterval(12,17);
                    animation.update(x,y);

                }

                if(engine::InputManager::instance.isKeyPressed(SDLK_DOWN)  && actual == 1){
                    y+=5;
                    animation.setInterval(6,11);
                    animation.update(x,y);

                }
            animation.draw();
            SDL_RenderPresent(WindowManager::getGameCanvas());
            animation.next();
            SDL_Delay(50);

            if(sceneManager->getCurrentScene() != NULL){
                //To do: Calculate timeElapsed
                int timeElapsed = 5;
                sceneManager->getCurrentScene()->update(timeElapsed);
                sceneManager->getCurrentScene()->draw();
            }
        }
    }



}
