#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "alien.hpp"
#include "game_object.hpp"
#include "engine.hpp"

using namespace engine;

class Player: public GameObject{
public:
    Player();
    ~Player();
    void update(int timeElapsed);
    void draw();
private:
    Alien *bilu, *varginha, *etemer;
    int selectedAlien;
};
#endif
