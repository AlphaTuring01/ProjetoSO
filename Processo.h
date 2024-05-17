#ifndef __PROCESSO_H__
#define __PROCESSO_H__

#include <string>

class Processo {
    private:
        std::string nome;
        int burstDeCpu, quantidadeDeBursts, segundoDeEntrada;

    public:
        Processo(std::string nome, int burstDeCpu, int quantidadeDeBursts, int segundoDeEntrada);
        Processo(const Processo& p);
};

#endif