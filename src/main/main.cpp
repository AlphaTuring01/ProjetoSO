// #include <iostream>
// #include <vector>
// #include "processo/Processo.h"

// const int QUANTUM_RR = 10;

// int main(int argc, char *argv[]) {
//     std::cout << "Hello, World!" << std::endl;
// return 0;
// }


#include <iostream>
#include <vector>
#include <queue>
#include <string>


const int QUANTUM = 10;

class Processo{
    private:
        int id, burst, ioQuantity, queueTime, runTime, IOTime, readyTime, burstTime;

    public:
        Processo(int id, int burst, int ioQuantity):
            id(id), burst(burst), ioQuantity(ioQuantity), queueTime(0), runTime(0), readyTime(-1), burstTime(0) {}
    
        int get_id(){ return id; }
        int get_burst(){ return burst; }
        int get_ioQuantity(){ return ioQuantity; }

        int get_queueTime(){ return queueTime; }
        int set_queueTime(int time){ queueTime = time; }

        int get_runTime(){ return runTime; }
        int set_runTime(int time){ runTime = time; }

        int get_readyTime(){ return readyTime; }
        int set_readyTime(int time){ readyTime = time; }

        int get_burstTime(){ return burstTime; }
        int set_burstTime(int time){ burstTime = time; }

        int increment(int code){
            switch(code){
                case 0:
                    burstTime++;
                    runTime++;
                    break;
                case 1:
                    IOTime++;
                    break;
                case 2:
                    readyTime++;
                    break;
                default:
                    break;
            }
        }

        bool is_over(){
            return runTime == burst * (ioQuantity + 1);
        }
        bool is_burst_over(){
            return burstTime == burst;
        }

};

class Sistema{
    private:
        std::vector<std::queue<Processo>> filas; // 0 -> RR, 1 -> FCFS, 2 -> IO
        std::vector<int> historico;

    public:
        void run(){
            while(!filas[0].empty() || !filas[1].empty() || !filas[2].empty()){
                if(!filas[0].empty()){
                    filas[0].front().increment(0);
                    if(filas[0].front().is_over()){
                        filas[0].pop();
                    } else if(filas[0].front().is_burst_over()){

                    } else if(QUANTUM == filas[0].front().get_burstTime()){

                    }
                } else if(!filas[1].empty()){

                }
                else historico.push_back(0);
            }
        }
};

