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
        SaveManager() = default;
        std::string path{"save.txt"};
        int stageNumberUnlock{0};
      };
}
#endif
