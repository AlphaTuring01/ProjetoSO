#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__


#include <queue>
#include "processo/Processo.h"


class Escalonador{
    private:
    std::queue<Processo> process_queue;
    int quantum;

    public:
    Escalonador(int quantum);

    std::queue<Processo> get_process_queue();
    int get_quantum();
    int set_quantum(int quantum);
    

    bool add_process(Processo p);
    void run();

};

#endif