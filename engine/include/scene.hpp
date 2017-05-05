#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "log.h"

namespace engine{
    class Scene{
    public:
        Scene(int id);
        Scene(){}
        ~Scene(){}
        virtual void load(){}
        virtual void draw(){}
        virtual void update(int timeElapsed) = 0;
        virtual void unload(){}
        virtual void init(){}
        int getId();
        void setId(int id);
    protected:
        int sceneId;
        //vector<GameObject *> gameObjects;
    };
}
#endif
