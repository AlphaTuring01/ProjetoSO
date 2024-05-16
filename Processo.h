#ifndef __PROCESSO_H__
#define __PROCESSO_H__

#include <string>

class Processo {
    private:
        std::string nome;
        int burstDeCpu, quantidadeDeBursts;
        int tempoDeExecucao;
        int status;

    public:
        Processo(std::string nome, int burstDeCpu, int quantidadeDeBursts);
        Processo(const Processo& p);

};

#endif