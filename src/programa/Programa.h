#ifndef __PROGRAMA_H__
#define __PROGRAMA_H__

#include <string>

class Programa{
    private:
        int cpu_burst, id, num_bursts; 

    public:
        friend std::ostream &operator<<(std::ostream &os, const Programa &p);

        Programa(int id, int cpu_burst, int num_bursts);
        int get_CPU_burst();
        int get_num_bursts();
        int get_id();
        int get_entry_time();
};

#endif