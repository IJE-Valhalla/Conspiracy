#ifndef AUDIO_HPP
#define AUDIO_HPP

#include "sdl2includes.hpp"
#include <string>


namespace engine{

    class Audio{
    public:
        Audio(std::string audioPath, std::string audioType, int volume);
        ~Audio();
        void play(const int timesToPlay);
        void pause();
        void resume();
        void stop();
    private:
        Mix_Music* audioMusic{nullptr};
        Mix_Chunk* audioEffect{nullptr};
    };
}
#endif
