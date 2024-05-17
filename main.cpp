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
    
    while(!(RR.empty() && FCFS.empty() && IO.empty())) {
        // Entrada em RR
        if(processos.size() > processosConsumados ) {
            for(Processo p: processos) {
                if(p.pegarSegundoDeEntrada() == tempoTotal) {
                    RR.push_back(p);
                    processosConsumados++;
                }
            }
        }

        // QUEM EXECUTA?
        if(!RR.empty()) {
            // aumentar o tempoDeStatus e de Exec do Primeiro da Fila;
            // aumentar o tempoDeStatus do pessoal de FCFS, só podem ficar no Max 30 mseg lá
        } else if(!FCFS.empty()) {
            // aumenta  o tempo Exec do primeiro da Fila;
            // aumentar o tempoDeStatus dos outros da Fila;
        } else {
            // RR e FCFS tão vazias... 
        }

        // MOVIMENTAÇÃO ENTRE AS FILAS
        if(!RR.empty()) {
            if(RR[0].acabou()) {
                // Sai da fila e não vai para nenhuma
                RR.erase(RR.begin());
            } else if(RR[0].acabouBurst()) {
                // Sai da Fila
                Processo pCopia = RR[0];
                RR.erase(RR.begin());
                // Zera o tempo de Burst
                pCopia.zerarTempoDeExecLocal();
                // Zera tempo de Status
                pCopia.zerarTempoDeStatus();
                // Vai para IO
                IO.push_back(pCopia);
            } else if(RR[0].pegarTempoDeStatus() == QUANTUM_RR) {
                // Vai para fila FCFS
                Processo pCopia = RR[0];
                RR.erase(RR.begin());
                // Zera tempo de Status
                pCopia.zerarTempoDeStatus();
                FCFS.push_back(pCopia);
            }
        } else if(!FCFS.empty()) {
            if(FCFS[0].acabou()) {
                // Sai da fila e não vai para nenhuma
                FCFS.erase(FCFS.begin());
            } else if(FCFS[0].acabouBurst()) {
                // Sai da fila e vai para IO
                Processo pCopia = FCFS[0];
                FCFS.erase(FCFS.begin());
                // Zera tempo de Status
                pCopia.zerarTempoDeExecLocal();
                pCopia.zerarTempoDeStatus();
            }

            // Mover todos com tempo de Status == 30 para RR
            // Zerar Tempo de Status
            // É possivel 2 processos chegarem em Q1 ao mesmo tempo?? Do jeito que o problema é descrito, NON.

            std::vector<Processo>::iterator possivelProcesso = IO.begin();
            while(possivelProcesso->pegarTempoDeStatus() == 30 || possivelProcesso == IO.end()) possivelProcesso++;
            if(possivelProcesso == IO.end()) {
                // Move de IO para RR
            }
        }

        // IO sempre incrementa e quando chega em TIME_IO volta para RR
        if(!IO.empty()) {
            // Incrementa o tempo de status do primeiro da Fila
            // Se o tempo for 20, bota o processo para fila RR
        }


        tempoTotal++;

        // Processo de Escrita em Arquivo/Variavel/Etc, quem executou em cada tempo
    }

    // Processo de Leitura do Arquivo/Variavel/Etc e Desenho do diagrama de Gantt


    return 0;

}