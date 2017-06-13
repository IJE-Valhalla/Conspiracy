#include "audio.hpp"
#include "log.h"
#include "string"

using namespace engine;

Audio::Audio(std::string audioPath, std::string audioType, int volume){
    if(audioType.compare("MUSIC") == 0){
        audioMusic = Mix_LoadMUS(audioPath.c_str());
        Mix_VolumeMusic(volume);
        if(audioMusic == NULL){
            ERROR("Audio file could not be loaded");
        }
    }else if(audioType.compare("EFFECT") == 0){
        audioEffect = Mix_LoadWAV(audioPath.c_str());
        Mix_VolumeChunk(audioEffect, volume);
        if(audioEffect == NULL){
            ERROR("Audio file could not be loaded");
        }
    }else{
        ERROR("Audio type is not correct");
    }
}

Audio::~Audio(){}

void Audio::play(const int timesToPlay){
    if(audioMusic != NULL){
        if(Mix_PlayMusic(audioMusic, timesToPlay) == -1){
            ERROR("Audio could not be played");
        }
    }else{
        if(Mix_PlayChannel(-1, audioEffect, timesToPlay) == -1){
            ERROR("Audio could not be played");
        }
    }
}

void Audio::pause(){
    if(audioMusic != NULL){
        if(Mix_PausedMusic() != 1){
            Mix_PauseMusic();
        }else{
            ERROR("This audio has already been paused");
        }
    }else{
        ERROR("Audio effects can not be paused");
    }
}

void Audio::resume(){
    if(audioMusic != NULL){
        if(Mix_PausedMusic() == 1){
            Mix_ResumeMusic();
        }else{
            ERROR("This audio is not paused");
        }
    }else{
        ERROR("Audio effects can not be resumed");
    }
}

void Audio::stop(){
    if(audioMusic != NULL){
        Mix_HaltChannel(0);
    }else if(audioEffect != NULL){
        Mix_HaltChannel(-1);
    }else{
        ERROR("Audio effects can not be stopped");
    }
}
