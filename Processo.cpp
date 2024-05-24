#include "Processo.h"

Processo::Processo(std::string nome, int burstDeCpu, int quantidadeDeBursts, int segundoDeEntrada):
nome(nome), burstDeCpu(burstDeCpu), quantidadeDeBursts(quantidadeDeBursts), segundoDeEntrada(segundoDeEntrada) {}

Processo::Processo(const Processo& p):
nome(p.nome), burstDeCpu(p.burstDeCpu), quantidadeDeBursts(p.quantidadeDeBursts), segundoDeEntrada(p.segundoDeEntrada) {}

int Processo::pegarSegundoDeEntrada() const {
    return this->segundoDeEntrada;
}

bool Processo::acabou() {
    return (this->burstDeCpu * this->quantidadeDeBursts <= this->tempoDeExecGlobal);
}

bool Processo::acabouBurst() {
    return (this-> burstDeCpu <= this->tempoDeExecLocal);
}

int Processo::pegarTempoDeStatus() const {
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

std::string Processo::pegarNome() const {
    return this->nome;
}

bool Processo::operator<(const Processo &p) const {
    return this->segundoDeEntrada > p.segundoDeEntrada;
}