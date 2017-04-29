#ifndef AUDIO_HPP
#define AUDIO_HPP

namespace engine{

    class Audio{
    public:
        Audio(const std::string audioPath, const std::string audioType);
        play(const int timesToPlay);
        pause();
        resume();
        stop();
    private:
        Mix_Music* audioMusic = NULL;
        Mix_Chunk* audioEffect = NULL;
    };
}
