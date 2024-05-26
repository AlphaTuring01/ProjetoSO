#include <iostream>
#include <queue>
#include <string>
#include <stdexcept>
#include "roundrobin.h"
#include "Fila.h"


void RoundRobin::run(Fila &f){
    if(is_empty()) throw std::runtime_error("Fila vazia");
    process_queue.front().inc_exec_clock();
    clock.tick();

    if(process_queue.front().is_finished()){
        process_queue.pop();    
    }

    if(process_queue.front().burst_finished()){
        process_queue 
    }

    if(quantum == clock.get_time()){
        clock.start();

    }
}