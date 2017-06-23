#ifndef PAPER_TABLE_HPP
#define PAPER_TABLE_HPP

#include "engine.hpp"
#include "animation.hpp"
#include "game_object.hpp"
#include "table.hpp"
#include "paper.hpp"


using namespace engine;

class PaperTable: public GameObject{
public:
    PaperTable(std::string objectName, double positionX, double positionY, int width, int height);
    ~PaperTable();
    void update(double timeElapsed);
    void draw();
    void init();
    Animation * getAnimation();
    Paper * getPaper();
    Table* getTable();
protected:
    Animation* animator;
    Paper* paper;
    Table* table;
};

#endif
