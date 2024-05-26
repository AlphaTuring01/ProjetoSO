#include "Clock.h"


#include <stdexcept>


Clock::Clock(): time(-1) {}

void Clock::start() {
    time = 0;
}

void Clock::stop() {
    time = -1;
}

void Clock::tick() {
    if(time != -1) time++;
    else throw std::runtime_error("Clock is stopped");
}

int Clock::get_time() {
    return time;
}