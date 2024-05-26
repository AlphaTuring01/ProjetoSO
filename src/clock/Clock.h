#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <iostream>
#include <time.h>

class Clock {
    private:
        int time=-1;

    public:
        Clock();
        Clock(const Clock& c);
        void start();
        void stop();
        void tick();
        int get_time();
};

#endif