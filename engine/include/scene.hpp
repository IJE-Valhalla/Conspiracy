#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "log.h"

namespace engine{
    class Scene{
    public:
        Scene(int id): sceneId(id){}
        virtual void load();
        virtual void draw();
        virtual void update(int timeElapsed);
        virtual void unload();
        int getId();
    private:
        int sceneId;
        //vector<GameObject *> gameObjects;
    };
}
#endif
