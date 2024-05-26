#ifndef __PROCESSO_H__
#define __PROCESSO_H__

#include <string>
#include <iostream>

class Processo {
    private:
        std::string nome;
        int cpu_burst, num_bursts, entry_time, id;

    public:
        friend std::ostream& operator<<(std::ostream& os, const Processo& p);

        Processo(std::string nome, int id, int cpu_burst, int entry_time);
        Processo(const Processo& p);
        Processo(Processo&& p);
        
        int get_entry_time();
        int get_CPU_burst();
        int get_num_bursts();
        std::string get_nome();
        int get_id();
        
};

#endif