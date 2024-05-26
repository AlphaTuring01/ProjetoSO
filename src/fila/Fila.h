#ifndef __FILA_H__
#define __FILA_H__

#include <queue>
#include <iostream>
#include <string>

#include "processo/Processo.h"

class Fila{
    protected:
        std::queue<Processo> process_queue;
    public:
        void add_processo(Processo p);
        bool is_empty();
        void operator>>(Fila &f); // empurra um processo para a outra fila
};

#endif