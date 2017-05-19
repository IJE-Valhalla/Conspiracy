#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "alien.hpp"
#include "input_manager.hpp"
//#include "game_object.hpp"
#include "engine.hpp"

using namespace engine;

class Player: public GameObject{
public:
    Player();
    ~Player();
    void update(double timeElapsed);
    void draw();
private:
    Alien *bilu, *varginha, *etemer;
    int selectedAlien;

    void waitAnimation(int timeElapsed, int beforeAlien);
};
#endif
