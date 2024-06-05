# PROJETO SO

Projeto de Sistemas Operacionais realizado em grupo no Instituto Militar de Engenharia (IME)

## GRUPO

- Fabricio Asfora Romero Assunção
- Johannes Elias Joseph Salomão
- Williams Bruce Gonzaga
- Roosevelth Soares
- Léo Victor Cruz Vasconcelos

## DESCRIÇÃO

Fazer um programa que simule o algoritmo de
escalonamento de múltiplas filas (com realimentação) com as
seguintes características:

- São utilizadas 2 filas de processos prontos (Q0 e Q1).
- Os processos iniciam na fila Q0.
- A fila Q0 usa o escalonamento Round-Robin com quantum de 10mseg.
- A fila Q1 usa o escalonamento FCFS.
- O escalonamento entre as filas é por prioridade com preempção. Q0 é a fila com maior prioridade e Q1 tem prioridade baixa.
- Um processo passa da fila Q0 para a fila Q1 quando sofre preempção por tempo.
- Um processo passa da fila Q1 para a fila Q0 quando este processo fica 30mseg na fila Q1 sem ser escalonado.

- Além disso, considere que:
  - Todos os surtos de CPU de um mesmo processo têm a mesma duração (dada como entrada);
  - Só existe um dispositivo de E/S no sistema e este só
  atende um pedido de cada vez;
  - Qualquer operação de E/S leva 20mseg para ser executada pelo dispositivo.
- O programa receberá como entrada a configuração
da fila Q0 no instante 0:
  - Total de processos da fila;
  - A duração do surto de CPU de cada processo; e
  - O número de operações de E/S de cada processo.

- O programa deve gerar como saída uma descrição
do diagrama de Gantt resultante.

## DETALHES DA SOLUÇÃO

Será passado ao programa um arquivo contendo o input do usuário. Este input consiste nos seguintes números:

- número de processos
- tempo de entrada(em ms)
- burst CPU de cada processo
- número de operações I/O de cada processo

Exemplo:

``` txt
2
0 2 3
1 23 8
```

Neste exemplo, temos dois processos: P0, com tempo de entrada 0ms, burst de CPU de 2ms e 3 operações de I/O, enquanto P1 possui tempo de entrada de 1ms, burst de 23ms e 8 operações de I/O

O logging completo por milissegundo é registrado no arquivo log.txt, enquanto no terminal será printado o sumário.
