#include "engine.hpp"
#include "sprite.hpp"
#include "scene_manager.hpp"
#include "input_manager.hpp"
#include "game_object.hpp"
#include <vector>
#include <iostream>

#include <chrono>


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
/////////////////////////////////////////////////////////////////////////////////////////////////
            srand(time(NULL));
            int x = 0;
            int y = 250;
            int x1 = 250;
            int y1 = 250;
            int x2 = 500;
            int y2 = 500;
            int actual = 1;
            engine::Sprite * sprite = new Sprite("assets/sprite/bomberman2.png", 23, 36, 60, 80);
            engine::GameObject gameObject("asddsa", 0, 250, 23,60, sprite);

            engine::Sprite * sprite2 = new Sprite("assets/sprite/bomberman2.png", 23, 36, 60, 80);
            engine::GameObject gameObject2("asddsa", 0, 250, 23,60, sprite2);

            engine::Sprite * sprite3 = new Sprite("assets/sprite/bomberman2.png", 23, 36, 60, 80);
            engine::GameObject gameObject3("asddsa", 0, 250, 23,60, sprite3);

            engine::Sprite * sprite4 = new Sprite("assets/sprite/background.jpg", 1, 800, 600, 0);

            gameObject.getSprite()->init();
            gameObject.getSprite()->draw(x, y);

            gameObject2.getSprite()->init();
            gameObject2.getSprite()->draw(x1, y1);

            gameObject3.getSprite()->init();
            gameObject3.getSprite()->draw(x2, y2);

            SDL_Delay(40);
            sprite4->init();
            engine::InputManager * inputManager = new engine::InputManager();
            SDL_Event event;
////////////////////////////////////////////////////////////////////////////////
        while(isRunning){
            double delta = getDelta();
            // INFO("DELTA" << delta);
            inputManager->update(event);
            SDL_RenderClear(WindowManager::getGameCanvas());

            if(inputManager->getQuitRequest()){
                isRunning = false;
                sdlManager->finalizeSDL();
                windowManager->destroyWindow();
            }
/////////////////////////////////////////////////////////////////////////////////

                //
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_ONE){
                //     actual = 1;
                // }
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_TWO){
                //     actual = 2;
                // }
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_THREE){
                //     actual = 3;
                // }
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_DEFAULT && keyLast == engine::InputManager::KeyPress::KEY_PRESS_RIGHT){
                //     gameObject.getSprite()->setCurrentPositionFrame(3);
                // }
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_DEFAULT && keyLast == engine::InputManager::KeyPress::KEY_PRESS_DOWN){
                //     gameObject.getSprite()->setCurrentPositionFrame(9);
                // }
                //
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_DEFAULT && keyLast == engine::InputManager::KeyPress::KEY_PRESS_UP){
                //     gameObject.getSprite()->setCurrentPositionFrame(15);
                // }
                if(delta>0.25){
                if(inputManager->isKeyPressed(SDLK_RIGHT) && actual == 1){
                    x+=20*delta;
                    gameObject.getSprite()->setInterval(1,6);
                    gameObject.getSprite()->update(x,y);
                }
                if(inputManager->isKeyPressed(SDLK_LEFT) && actual == 1){
                    x-=20*delta;
                    gameObject.getSprite()->setInterval(19,23);
                    gameObject.getSprite()->update(x,y);
                }

                if(inputManager->isKeyPressed(SDLK_UP)  && actual == 1){
                    y-=20*delta;
                    gameObject.getSprite()->setInterval(13,18);
                    gameObject.getSprite()->update(x,y);

                }

                if(inputManager->isKeyPressed(SDLK_DOWN)  && actual == 1){
                    y+=20*delta;
                    gameObject.getSprite()->setInterval(7,12);
                    gameObject.getSprite()->update(x,y);

                }

                //
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_RIGHT && actual == 2){
                //     x1+=20*delta;
                //     gameObject2.getSprite()->setInterval(1,6);
                //     inputManager->setKeyPress(engine::InputManager::KeyPress::KEY_PRESS_DEFAULT);
                //     gameObject2.getSprite()->update(x1,y1);
                // }
                //
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_LEFT  && actual == 2){
                //     x1-=5;
                //     gameObject2.getSprite()->setInterval(19,23);
                //     inputManager->setKeyPress(engine::InputManager::KeyPress::KEY_PRESS_DEFAULT);
                //     gameObject2.getSprite()->update(x1,y1);
                // }
                //
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_UP  && actual == 2){
                //     y1-=5;
                //     gameObject2.getSprite()->setInterval(13,18);
                //     inputManager->setKeyPress(engine::InputManager::KeyPress::KEY_PRESS_DEFAULT);
                //     gameObject2.getSprite()->update(x1,y1);
                // }
                //
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_DOWN  && actual == 2){
                //     y1+=5;
                //     gameObject2.getSprite()->setInterval(7,12);
                //     inputManager->setKeyPress(engine::InputManager::KeyPress::KEY_PRESS_DEFAULT);
                //     gameObject2.getSprite()->update(x1,y1);
                // }
                //
                //
                //
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_RIGHT && actual == 3){
                //     x2+=5;
                //     gameObject3.getSprite()->setInterval(1,6);
                //     inputManager->setKeyPress(engine::InputManager::KeyPress::KEY_PRESS_DEFAULT);
                //     gameObject3.getSprite()->update(x2,y2);
                // }
                //
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_LEFT  && actual == 3){
                //     x2-=5;
                //     gameObject3.getSprite()->setInterval(19,23);
                //     inputManager->setKeyPress(engine::InputManager::KeyPress::KEY_PRESS_DEFAULT);
                //     gameObject3.getSprite()->update(x2,y2);
                // }
                //
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_UP  && actual == 3){
                //     y2-=5;
                //     gameObject3.getSprite()->setInterval(13,18);
                //     inputManager->setKeyPress(engine::InputManager::KeyPress::KEY_PRESS_DEFAULT);
                //     gameObject3.getSprite()->update(x2,y2);
                // }
                // if(keyPress == engine::InputManager::KeyPress::KEY_PRESS_DOWN  && actual == 3){
                //     y2+=5;
                //     gameObject3.getSprite()->setInterval(7,12);
                //     inputManager->setKeyPress(engine::InputManager::KeyPress::KEY_PRESS_DEFAULT);
                //     gameObject3.getSprite()->update(x2,y2);
                // }
            }
                sprite4->draw(0,0);
                gameObject.getSprite()->draw(x,y);
                gameObject2.getSprite()->draw(x1,y1);
                gameObject3.getSprite()->draw(x2,y2);
                SDL_RenderPresent(WindowManager::getGameCanvas());
                SDL_Delay(55);
///////////////////////////////////////////////////////////////////////////////////

            if(sceneManager->getCurrentScene() != NULL){
                //To do: Calculate timeElapsed
                int timeElapsed = 5;
                sceneManager->getCurrentScene()->update(timeElapsed);
                sceneManager->getCurrentScene()->draw();
            }
        }
    }



}
