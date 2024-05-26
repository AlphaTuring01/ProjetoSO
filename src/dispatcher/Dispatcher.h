#ifndef __DISPATCHER_H__
#define __DISPATCHER_H__


#include "processo/Processo.h"
#include "escalonador/Escalonador.h"


class Dispatcher {
    private:
        Escalonador* scheduler;
        int quantum;
        Processo process;

    public:
        Dispatcher(int quantum, Escalonador* scheduler);

        Dispatcher& set_process(Processo p);
        
        void stop(int interrupt_code);

        void run();
        void terminate();
};

#endif