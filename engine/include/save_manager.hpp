#ifndef SAVE_MANAGER_HPP
#define SAVE_MANAGER_HPP

#include <iostream>
#include <fstream>
#include "log.h"

namespace engine{
    class SaveManager{
    public:
        static SaveManager instance;
        int getStageNumberUnlock();
        void verifySave();
        void saveActualSituation(int unlockNumber);
    private:
        SaveManager(): path("save.txt"){}
        std::string path;
        int stageNumberUnlock;
      };
}
#endif
