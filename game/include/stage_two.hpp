#ifndef STAGE_TWO_HPP
#define STAGE_TWO_HPP

#include "engine.hpp"
#include "game_scene.hpp"
#include "player.hpp"
#include "wall.hpp"
#include "game_object.hpp"
#include "guard.hpp"
#include "paper_table.hpp"
#include "door_system.hpp"

#include <typeinfo>

class StageTwo: public GameScene{
public:
    StageTwo(int id, std::string newTiledFile);
private:
    void initializeColliders();
    void createGuards();
    void createAliens();
    void createDoorSystems();
    void createPapers();
};

#endif
