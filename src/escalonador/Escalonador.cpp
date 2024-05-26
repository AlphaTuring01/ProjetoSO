#include <time.h>
#include <stdexcept>

#include "Escalonador.h"
#include "processo/Processo.h"
#include "dispatcher/Dispatcher.h"


void Escalonador::next_process(int interrupt_code) {
    if (interrupt_code >= 0) {
        //finished process
    } else if(interrupt_code == -1) {
        // unfinished process
    } else{
        // invalid interrupt code
        throw std::runtime_error("Invalid interrupt code");
    }
}