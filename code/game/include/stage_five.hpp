#ifndef STAGE_FIVE_HPP
#define STAGE_FIVE_HPP

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

class StageFive: public GameScene{
public:
    StageFive(int id, std::string newTiledFile);
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
