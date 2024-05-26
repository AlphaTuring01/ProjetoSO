#pragma once

#include <iostream>
#include <queue>
#include <string>
#include "Fila.h"


class RoundRobin: public Fila{
    private:
        int quantum;
        Clock clock;
    public:
        RoundRobin(int quantum): quantum(quantum){
            clock.start();
        };
        void run(Fila &f);        
};