#pragma once 

#include <iostream>
#include <queue>
#include <string>

#include "Fila.h"

class FCFS: public Fila{
    private:
        int max_time;
    public:
        FCFS(int max_time);
};