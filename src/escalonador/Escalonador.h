#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__


#include <queue>
#include <tuple>
#include "processo/Processo.h"


class Escalonador{
    private:
    std::queue<Processo> q0;
    std::queue<Processo> q1;
    int quantum;

    public:
    Escalonador(int quantum);

    std::tuple<std::queue<Processo>, std::queue<Processo>> get_process_queues();
    int get_quantum();
    int set_quantum(int quantum);


    Escalonador& add_process(Processo p);
    void next_process(int interrupt_code);
    void run();

};

#endif