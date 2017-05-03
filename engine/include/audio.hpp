#ifndef AUDIO_HPP
#define AUDIO_HPP

#include "sdl2includes.hpp"

namespace engine{

    class Audio{
    public:
        Audio(std::string audioPath, std::string audioType);
        ~Audio();
        void play(const int timesToPlay);
        void pause();
        void resume();
        void stop();
    private:
        Mix_Music* audioMusic = NULL;
        Mix_Chunk* audioEffect = NULL;
    };
}
#endif
