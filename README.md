Este projeto se trata de uma atividade avaliativa da disciplina de Estrutura de Dados.

Este trabalho tem como principal objetivo realizar uma análise dos algoritmos de ordenação, levando
em consideração, principalmente, seus respectivos tempos de execução, assim como comparar os diferentes
cenários de cada uma das tarefas de ordenação.

Os códigos foram feitos utilizando a linguagem de programação C.

Para executar os códigos deste trabalho é necessário ter um compilador C instalado na máquina (gcc).

Para gerar os gráficos, é necessário ter o Gnuplot instalado.

======== Diretório dos codigos =========

\fontes\nome_algoritmo\algoritmo.c

========================================


======== Comandos para executar ========

Na pasta do arquivo C, execute:

gcc -Wall arquivo.c -o arquivo

./arquivo tamanho_vetor

========================================


======== Como gerar os gráficos ========

Para gerar os gráficos, use o gnuplot no diretório \grafico\nome_algoritmo\nome_caso ou \grafico\nome_algoritmo

Com o terminal aberto neste diretório, digite:

gnuplot

plot "arquivo.txt" with linespoint