#include "Processo.h"

Processo::Processo(std::string nome, int burstDeCpu, int quantidadeDeBursts, int segundoDeEntrada):
nome(nome), burstDeCpu(burstDeCpu), quantidadeDeBursts(quantidadeDeBursts), segundoDeEntrada(segundoDeEntrada) {}

Processo::Processo(const Processo& p):
nome(p.nome), burstDeCpu(p.burstDeCpu), quantidadeDeBursts(p.quantidadeDeBursts), segundoDeEntrada(segundoDeEntrada) {}

int Processo::pegarSegundoDeEntrada() {
    return this->segundoDeEntrada;
}

bool Processo::acabou() {
    return this->burstDeCpu * this->quantidadeDeBursts >= this->tempoDeExecGlobal;
}

bool Processo::acabouBurst() {
    return this-> burstDeCpu >= this->tempoDeExecLocal;
}

int Processo::pegarTempoDeStatus() {
    return this->tempoDeStatus;
}

void Processo::zerarTempoDeExecLocal() {
    this->tempoDeExecLocal = 0;
}

void Processo::zerarTempoDeStatus() {
    this->tempoDeStatus = 0;
}

void Processo::incrementarTempoDeExec() {
    this->tempoDeExecGlobal++;
    this->tempoDeExecLocal++;
}

void Processo::incrementarTempoDeStatus() {
    this->tempoDeStatus++;
}