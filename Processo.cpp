#include "Processo.h"

Processo::Processo(std::string nome, int burstDeCpu, int quantidadeDeBursts, int segundoDeEntrada):
nome(nome), burstDeCpu(burstDeCpu), quantidadeDeBursts(quantidadeDeBursts), segundoDeEntrada(segundoDeEntrada) {}

Processo::Processo(const Processo& p):
nome(p.nome), burstDeCpu(p.burstDeCpu), quantidadeDeBursts(p.quantidadeDeBursts), segundoDeEntrada(segundoDeEntrada) {}
