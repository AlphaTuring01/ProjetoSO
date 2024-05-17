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
            } else if(RR[0].acabouBurst()) {
                // Sai da Fila e vai para IO
                // Zera o tempo de Burst
                // Zera tempo de Status
            } else if(RR[0].pegarTempoDeStatus() == QUANTUM_RR) {
                // Vai para fila FCFS
                // Zera tempo de Status
            }
        } else if(!FCFS.empty()) {
            if(FCFS[0].acabou()) {
                // Sai da fila e não vai para nenhuma
            } else if(FCFS[0].acabouBurst()) {
                // Sai da fila e vai para IO
                // Zera tempo de Status
            }

            // Mover todos com tempo de Status == 30 para RR
            // Zerar Tempo de Status 
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