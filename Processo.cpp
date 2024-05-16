#include "Processo.h"

Processo::Processo(std::string nome, int burstDeCpu, int quantidadeDeBursts):
nome(nome), burstDeCpu(burstDeCpu), quantidadeDeBursts(quantidadeDeBursts) {
    tempoDeExecucao = 0;
    status = 0;
}

Processo::Processo(const Processo& p):
nome(p.nome), burstDeCpu(p.burstDeCpu), quantidadeDeBursts(p.quantidadeDeBursts) {
    tempoDeExecucao = 0;
    status = 0;
}
