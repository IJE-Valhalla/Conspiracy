#include "timer.hpp"

using namespace engine;

void Timer::start(){
    ticks = step_ticks = SDL_GetTicks();
}

void Timer::stop(){
    ticks = 0;
    step_ticks = 0;
}

void Timer::step(){
    step_ticks = SDL_GetTicks();
}

unsigned int Timer::elapsed_time(){
    return SDL_GetTicks() - step_ticks;
}

unsigned int Timer::total_elapsed_time(){
    return SDL_GetTicks() - ticks;
}
