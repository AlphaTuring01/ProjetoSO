#ifndef __PROCESSO_H__
#define __PROCESSO_H__

#include <string>

class Processo {
    private:
        std::string nome;
        int burstDeCpu, quantidadeDeBursts, segundoDeEntrada;

        int tempoDeExecLocal, tempoDeExecGlobal, tempoDeStatus;

    public:
        Processo(std::string nome, int burstDeCpu, int quantidadeDeBursts, int segundoDeEntrada);
        Processo(const Processo& p);
        int pegarSegundoDeEntrada();
        bool acabou();
        bool acabouBurst();
        int pegarTempoDeStatus();
        void zerarTempoDeExecLocal();
        void zerarTempoDeStatus();
        void incrementarTempoDeExec();
        void incrementarTempoDeStatus();
};

#endif