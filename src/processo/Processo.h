#ifndef __PROCESSO_H__
#define __PROCESSO_H__

#include "clock/Clock.h"
#include "programa/Programa.h"

#include <iostream>
#include <string>


class Processo {
    private:
        Programa prog;
        int id, entry_time;
        Clock current_burst, total, io, fcfs_wait;
        static Clock global_clock;

    public:
        friend std::ostream& operator<<(std::ostream& os, const Processo& p);

        Processo(Programa p);
        Processo(const Processo& p);
        Processo(Processo&& p);

        int get_id();
        Programa get_programa();

        bool is_finished();
        bool burst_finished();

        int get_total_burst_time();
        int get_current_burst_time();

        void inc_exec_clock();
        void inc_fcfs_clock();
        void inc_io_clock();

};

#endif