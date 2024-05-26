#include <time.h>

#include "Processo.h"


Processo::Processo(Programa p): prog(p) {}

Processo::Processo(const Processo& p): prog(p.prog) {}

Processo::Processo(Processo &&p) : prog(p.prog) {}

// std::ostream& operator<<(std::ostream& os, const Processo& p) {
//     os << "Process(name=" << p.nome << ", id=" << p.id << ", cpu_burst=" << p.cpu_burst << ")";
//     return os;
// }