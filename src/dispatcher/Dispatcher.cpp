#include <time.h>

#include "Dispatcher.h"
#include "escalonador/Escalonador.h"
#include "processo/Processo.h"




void Dispatcher::stop(int interrupt_code) {
    this->scheduler->next_process(interrupt_code);
}