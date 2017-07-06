#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "alien.hpp"
#include "alien_bilu.hpp"
#include "alien_etemer.hpp"
#include "alien_varginha.hpp"
#include "input_manager.hpp"
#include "audio.hpp"
#include "engine.hpp"
#include "header.hpp"

using namespace engine;

class Player: public GameObject{
public:
    Player(std::pair<int, int> biluPosition, std::pair<int, int> etemerPosition,
          std::pair<int,int> varginhaPosition, int paperQuantity, int stageNumber);
    ~Player();
    void update(double timeElapsed);
    void draw();
    bool isDead();
    Alien * getBilu();
    Alien * getVarginha();
    Alien * getEtemer();
    void updatePaperQuantity(int newValue);
private:
    Animation* exclamationAnimation;
    Alien *bilu, *varginha, *etemer;
    Audio *varginha_sound_effect, *etemer_sound_effect, *bilu_sound_effect;
    Header * header;
    int selectedAlien;
    void idleAnimation(Alien * alien);
    void waitAnimation(int beforeAlien);
};
#endif
