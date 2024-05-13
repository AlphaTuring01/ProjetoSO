#include <string>


class Processo {
    private:
        std::string nome;
        int burstDeCpu, quantidadeDeBursts;
        int tempoDeExecucao;
        int status;
};
