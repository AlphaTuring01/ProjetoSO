#include <time.h>

#include "Processo.h"


Processo::Processo(std::string nome, int id, int cpu_burst, int entry_time):
nome(nome), cpu_burst(cpu_burst), id(id), entry_time(entry_time) {}

Processo::Processo(const Processo& p):
nome(p.nome), cpu_burst(p.cpu_burst), num_bursts(p.num_bursts), entry_time(p.entry_time), id(p.id) {}

Processo::Processo(Processo&& p):
nome(p.nome), cpu_burst(p.cpu_burst), num_bursts(p.num_bursts), entry_time(p.entry_time), id(p.id) {}

std::ostream& operator<<(std::ostream& os, const Processo& p) {
    os << "Process(name=" << p.nome << ", id=" << p.id << ", cpu_burst=" << p.cpu_burst << ")";
    return os;
}