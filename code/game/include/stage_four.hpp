#ifndef STAGE_FOUR_HPP
#define STAGE_FOUR_HPP

#include "engine.hpp"
#include "game_scene.hpp"
#include "player.hpp"
#include "wall.hpp"
#include "game_object.hpp"
#include "guard.hpp"
#include "paper_table.hpp"
#include "door_system.hpp"
#include "table.hpp"
#include "finish_point.hpp"

#include <typeinfo>

class StageFour: public GameScene{
public:
    StageFour(int id, std::string newTiledFile);
private:
    void createGuards();
    void createAliens();
    void createDoorSystems();
    void createPapers();
    void createTables();
    void createFinishPoints();
    void createChairs();
};

#endif
