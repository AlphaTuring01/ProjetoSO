#include <iostream>
#include <vector>
#include <queue>
#include "Processo.cpp"

//DEBUG
#define gay(x) std::cout<<x<<std::endl

#define QUANTUM_RR 10

int main(int argc, char *argv[]) {
    // Receber processos
    
    std::priority_queue<Processo> processos;

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

        processos.push(Processo(nome,burstDeCpu,quantidadeDeBursts,segundoDeEntrada));
    }
    

    std::vector<Processo> RR;
    std::vector<Processo> FCFS;
    std::vector<Processo> IO;
    
    int tempoTotal = -1;
    bool FCFSexec = false;
    std::string pNome = "NENHUM";
    
    while(!(RR.empty() && FCFS.empty() && IO.empty() && processos.empty())) {
        tempoTotal++;
        FCFSexec = false;
        pNome = "NENHUM";

        if(!processos.empty()) {
            while(!processos.empty() && tempoTotal == processos.top().pegarSegundoDeEntrada()) {
                RR.push_back(processos.top());
                processos.pop();
            }
        }

        if(!RR.empty()) {
            pNome = RR[0].pegarNome();
            RR[0].incrementarTempoDeExec();
            RR[0].incrementarTempoDeStatus();

            if(RR[0].acabou()) {
                RR.erase(RR.begin());
            } else if(RR[0].acabouBurst()) {
                // Algo aqui
            } else if(RR[0].pegarTempoDeStatus() == QUANTUM_RR) {
                // Algo aqui
            }
        }
        
        std::cout << pNome << " " << tempoTotal << std::endl;

        if(tempoTotal > 40) break;

    }

    // Processo de Leitura do Arquivo/Variavel/Etc e Desenho do diagrama de Gantt


    return 0;

}