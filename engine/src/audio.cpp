#include "audio.hpp"
#include "log.h"
#include "string"

using namespace engine;

Audio::Audio(std::string audioPath, std::string audioType){
    if(audioType.compare("MUSIC") == 0){
        audioMusic = Mix_LoadMUS(audioPath.c_str());
        if(audioMusic == NULL){
            ERROR("Audio file could not be loaded");
        }
    }else if(audioType.compare("EFFECT") == 0){
        audioEffect = Mix_LoadWAV(audioPath.c_str());
        if(audioEffect == NULL){
            ERROR("Audio file could not be loaded");
        }
    }else{
        ERROR("Audio type is not correct");
    }
}
