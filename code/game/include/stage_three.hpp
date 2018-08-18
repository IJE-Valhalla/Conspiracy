#ifndef STAGE_THREE_HPP
#define STAGE_THREE_HPP

#include "engine.hpp"
#include "game_scene.hpp"
#include "player.hpp"
#include "wall.hpp"
#include "game_object.hpp"
#include "guard.hpp"
#include "paper_table.hpp"
#include "door_system.hpp"
#include "finish_point.hpp"

#include <typeinfo>

class StageThree: public GameScene{
public:
    StageThree(int id, std::string newTiledFile);
private:
    void createGuards();
    void createAliens();
    void createDoorSystems();
    void createPapers();
    void createFinishPoints();
    void createChairs();
};

#endif
