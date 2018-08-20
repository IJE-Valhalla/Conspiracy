#include "engine.hpp"
#include <memory>

namespace engine{

    const std::string GAME_NAME = "Conspiracy";
    const std::pair <int, int> WINDOW_SIZE (960, 640);

    std::shared_ptr<SceneManager> sceneManager{nullptr};
    std::shared_ptr<WindowManager> windowManager{nullptr};
    std::shared_ptr<SDLManager> sdlManager{nullptr};
    double startTime;
    double stepTime;
    double timeElapsed;
    double frameTime;
    double frameRate = 60.0;
    SceneManager* getSceneManager(){
        return sceneManager.get();
    }
    void loadEngine(){
        sceneManager = std::make_shared<SceneManager>();
        windowManager = std::make_shared<WindowManager>();
        sdlManager = std::make_shared<SDLManager>();
        startTime = SDL_GetTicks();
        stepTime = startTime;
        frameTime = 1000.0/frameRate;

        if(!sdlManager->initSDL()){
            ERROR("ERRO AO INICIAR SDL");
            exit(-1);
        }else if(!windowManager->createWindow(GAME_NAME, WINDOW_SIZE)){
            ERROR("ERRO AO CRIAR JANELA");
            exit(-1);
        }
    }

    void run(){
        bool isRunning = true;
        SDL_Event event;

        while(isRunning){
            stepTime = SDL_GetTicks();

            engine::InputManager::instance.update(event);
            SDL_RenderClear(WindowManager::getGameCanvas());

            if(engine::InputManager::instance.getQuitRequest()){
                isRunning = false;
                sdlManager->finalizeSDL();
                windowManager->destroyWindow();
                continue;
            }


            timeElapsed = SDL_GetTicks() - stepTime;
            DEBUG("TICKS:" + std::to_string(SDL_GetTicks()));
            DEBUG("frameTime:" + std::to_string(frameTime));
            DEBUG("timeElapsed: " + std::to_string(timeElapsed));
            if(frameTime > timeElapsed){
                DEBUG("SDL_DELAY: " + std::to_string(frameTime - timeElapsed));
                SDL_Delay(frameTime - timeElapsed);
                timeElapsed = SDL_GetTicks() - stepTime;
            }

            if(sceneManager->getCurrentScene() != NULL){
              sceneManager->getCurrentScene()->update(timeElapsed);
              sceneManager->getCurrentScene()->draw();
            }
            AnimationManager::instance.draw_quads();
            SDL_RenderPresent(WindowManager::getGameCanvas());
        }
    }
}
