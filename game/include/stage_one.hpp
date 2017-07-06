#ifndef STAGE_ONE_HPP
#define STAGE_ONE_HPP

#include "engine.hpp"
#include "game_scene.hpp"
#include "player.hpp"
#include "wall.hpp"
#include "game_object.hpp"
#include "guard.hpp"
#include "camera.hpp"
#include "paper_table.hpp"
#include "door_system.hpp"
#include "camera_lever.hpp"
#include "camera_switch.hpp"
#include "camera_system.hpp"
#include "finish_point.hpp"


#include <typeinfo>

class StageOne: public GameScene{
public:
    StageOne(int id, std::string newTiledFile);
private:
    void createGuards();
    void createAliens();
    void createDoorSystems();
    void createPapers();
    void createFinishPoints();
};

#endif
