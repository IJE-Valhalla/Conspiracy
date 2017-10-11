#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "game_object.hpp"
#include "log.h"

namespace engine{
    class Scene{
    public:
        Scene(int id);
        virtual ~Scene() = default;
        virtual void load();
        virtual void draw();
        virtual void update(double timeElapsed) = 0;
        virtual void unload();
        int getId();
        void setId(int id);
    protected:
        int sceneId{0};
    };
}
#endif
