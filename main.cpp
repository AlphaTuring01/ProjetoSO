#include <iostream>
#include <queue>
#include <vector>

#define QUANTUM  10
#define IOTIME   20
#define FCFSTIME 30

using namespace std;

class Processo {
    private:
        int id, entrada, burst, ios;
        int tempoBurst, tempoExec, tempoFCFS;

    public:
        Processo(int id, int entrada, int burst, int ios):
        id(id), entrada(entrada), burst(burst), ios(ios),
        tempoBurst(0), tempoExec(0), tempoFCFS(0) {
            if(id <= 0) throw runtime_error("ID não pode ser 0 ou menor!!");
        }

        Processo(const Processo &p):
        id(p.id), entrada(p.entrada), burst(p.burst), ios(p.ios),
        tempoBurst(p.tempoBurst), tempoExec(p.tempoExec), tempoFCFS(p.tempoFCFS) {
            if(id <= 0) throw runtime_error("ID não pode ser 0 ou menor!!");
        }

        int pegarID() { return id; }
        int pegarEntrada() const { return entrada; }
        int pegarBurst() {return burst; }
        int pegarIOs() { return ios; }

        void zerarTempoBurst() { tempoBurst = 0; }
        void zerarTempoFCFS() { tempoFCFS = 0; }

        void incremetarTempoExec() { tempoBurst++; tempoExec++; }
        void incremetarTempoFCFS() { tempoFCFS++; }

        int pegarTempoFCFS() { return tempoFCFS; }

        bool acabou() {
            return tempoExec >= (ios+1)*burst;
        }

        bool burstAcabou() {
            return tempoBurst >= burst;
        }

        bool operator<(const Processo &p) const {
            if(p.entrada < entrada) return true;
            else if(p.entrada == entrada) return p.id < id;
            else return false;
        }
};

ostream &operator<<(ostream &os, Processo p) {
    return os << p.pegarID();
}

void operator>>(queue<Processo> &F1, queue<Processo> &F2) {
    Processo pCopia = F1.front();
    F1.pop();
    F2.push(pCopia);
}

void operator>>(priority_queue<Processo> &F1, queue<Processo> &F2) {
    Processo pCopia = F1.top();
    F1.pop();
    F2.push(pCopia);
}

void print_queue(queue<Processo> q) {
    while(!q.empty()) {
        cout << q.front().pegarID() - 1 << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    priority_queue<Processo> Entradas;
    queue<Processo> RR;
    queue<Processo> FCFS;
    queue<Processo> IO;

    vector<int> hist;

    int RRtimer = 0;
    int IOtimer = -1;
    int runtime = -1;
    bool execFCFS;
    bool nowFCFS;
    
    int qnt_processos;
    cout << "Quantidade de Processos: ";
    cin >> qnt_processos;
    int mseg_ent, burst, ios;
    cout << "Digite agora (MSEG EM QUE ENTRA, BURST DE CPU, QNT DE IOS):" << endl;
    for(int i=1;i<=qnt_processos;i++) {
        cin >>  mseg_ent >> burst >> ios;
        Entradas.push(Processo(i,mseg_ent,burst,ios));
    }
    
    while(!Entradas.empty() || !RR.empty() || !FCFS.empty() || !IO.empty()) {
        
        runtime++;
        
        execFCFS = false;
        nowFCFS  = false;

        while(!Entradas.empty() && Entradas.top().pegarEntrada() == runtime) Entradas >> RR;
        
        if(!RR.empty()) {
            hist.push_back(RR.front().pegarID());
            RR.front().incremetarTempoExec();
            RRtimer++;
            if(RR.front().acabou()) {
                RRtimer = 0;
                RR.pop();
            } else if(RR.front().burstAcabou()) {
                RRtimer = 0;
                RR.front().zerarTempoBurst();
                RR >> IO;
            } else if(RRtimer == QUANTUM) {
                RRtimer = 0;
                RR >> FCFS;
            }
        } else if(!FCFS.empty()) {
            hist.push_back(FCFS.front().pegarID());
            FCFS.front().incremetarTempoExec();
            execFCFS = true;
            if(FCFS.front().acabou()) {
                FCFS.pop();
            } else if(FCFS.front().burstAcabou()) {
                FCFS.front().zerarTempoBurst();
                FCFS >> IO;
            }
        } else hist.push_back(0);

        if(!FCFS.empty()) {
            queue<Processo> incFCFS;
            
            if(!execFCFS) FCFS.front().incremetarTempoFCFS();
            else FCFS.front().zerarTempoFCFS();
            
            FCFS >> incFCFS;
            while(FCFS.size() > 1) {
                FCFS.front().incremetarTempoFCFS();
                FCFS >> incFCFS;
            }
            if(!FCFS.empty() && !nowFCFS) {
                FCFS.front().incremetarTempoFCFS();
                FCFS >> incFCFS;
            }
            
            while(!incFCFS.empty()) {
                if(incFCFS.front().pegarTempoFCFS() == FCFSTIME + 1) {
                    incFCFS.front().zerarTempoFCFS();
                    incFCFS >> RR;
                } else incFCFS >> FCFS;
            }
        }
        
        if(!IO.empty()) {
            IOtimer++;
            if(IOtimer == IOTIME) {
                IOtimer = -1;
                IO >> RR;
                if(!IO.empty()) IOtimer++;
            }
        }

        cout << "time: " << runtime << endl << "- RR: ";
        print_queue(RR);
        cout << "- FCFS: ";
        print_queue(FCFS);
        cout << "- IO: ";
        print_queue(IO);
        cout << "\n" << "==================================" << "\n" << endl; 
    }
    
    int nower = hist[0];
    int prevTime = 0;
    cout << "\nSummary: \n\n";
    for(int i=0;i<hist.size();i++) {
        if(nower != hist[i])
        {
            cout << "De " << prevTime << " ate " << i << ", processo na CPU: " << ((hist[i-1] - 1 >= 0) ? (string("P") + to_string(hist[i-1]-1)) : "None (All in IO)") << endl;
            nower = hist[i];
            prevTime=i;
        }
    }
    cout << "De " << prevTime << " ate " << hist.size() << ", processo na CPU: " << ((hist[hist.size()-1] - 1 >= 0) ? (string("P") + to_string(hist[hist.size()-1]-1)) : "None (All in IO)") << endl;

    return 0;
}