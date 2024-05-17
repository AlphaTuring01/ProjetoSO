#include <iostream>
#include <vector>
#include "Processo.cpp"

#define QUANTUM_RR 10

int main(int argc, char *argv[]) {
    // Receber processos
    
    std::vector<Processo> processos;

    for(int index=1;index<argc;index++) {
        std::string stringProcesso = std::string(argv[index]);
        if(stringProcesso.front() != '%' || stringProcesso.back() != '%') {
            std::cout << "Sintaxe do processo não entendida (Chaves)" << std::endl;
            exit(1);
        } 
        
        stringProcesso.erase(stringProcesso.begin());
        stringProcesso.pop_back();
        
        std::size_t posicaoDaPrimeiraVirgula = stringProcesso.find_first_of(",");
        std::size_t posicaoDaSegundaVirgula  = stringProcesso.find(",", posicaoDaPrimeiraVirgula+1);
        std::size_t posicaoDaUltimaVirgula   = stringProcesso.find_last_of(",");

        if(posicaoDaPrimeiraVirgula == std::string::npos || 
           posicaoDaUltimaVirgula == std::string::npos   ||
           posicaoDaSegundaVirgula == posicaoDaUltimaVirgula  ) {
            std::cout << "Sintaxe do processo não entendida (Virgulas)" << std::endl;
            exit(1);
        }

        std::string nome       = stringProcesso.substr(0,posicaoDaPrimeiraVirgula);
        int burstDeCpu         = std::stoi(stringProcesso.substr(posicaoDaPrimeiraVirgula+1, posicaoDaSegundaVirgula - posicaoDaPrimeiraVirgula - 1));
        int quantidadeDeBursts = std::stoi(stringProcesso.substr(posicaoDaSegundaVirgula+1, posicaoDaUltimaVirgula - posicaoDaSegundaVirgula - 1));
        int segundoDeEntrada   = std::stoi(stringProcesso.substr(posicaoDaUltimaVirgula+1, stringProcesso.size() - posicaoDaUltimaVirgula - 1));

        processos.push_back(Processo(nome,burstDeCpu,quantidadeDeBursts,segundoDeEntrada));
    }
    

    std::vector<Processo> RR;
    std::vector<Processo> FCFS;
    std::vector<Processo> IO;
    
    int tempoTotal = 0;
    int processosConsumados = 0;
    bool jaExec;

    while(1) {
        //Magica

        tempoTotal++;
    }



    return 0;

}