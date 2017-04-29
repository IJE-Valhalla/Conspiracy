#include "engine.hpp"
#include "sprite.hpp"
#include "scene_manager.hpp"
#include "input_manager.hpp"


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
        ///////////////
            srand(time(NULL));
            int x = 0;
            int y = 250;
            engine::Sprite sprite("assets/sprite/runner.png", 8, 108, 140);
            sprite.init();
            sprite.draw(x, y);
///////////////
        engine::InputManager * inputManager = new engine::InputManager();
        SDL_Event event;
        while(isRunning){
            inputManager->update(event);
            if(inputManager->getQuitRequest()){
                isRunning = false;
                sdlManager->finalizeSDL();
                windowManager->destroyWindow();
            }
            engine::InputManager::KeyPress keyPress = inputManager->getKeyPress();
            if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_RIGHT){
                x+=5;
            }

            //////////////
                SDL_Delay(90);
                SDL_RenderClear(WindowManager::getGameCanvas());
                sprite.update(x,y);
                SDL_RenderPresent(WindowManager::getGameCanvas());
//////////////////

            if(sceneManager->getCurrentScene() != NULL){
                //To do: Calculate timeElapsed
                int timeElapsed = 5;
                sceneManager->getCurrentScene()->update(timeElapsed);
                sceneManager->getCurrentScene()->draw();
            }
        }
    }


}
