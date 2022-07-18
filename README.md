# Atividade Pratica - Busca em String - Casamento de padrões

Encontrar padões em strings em um problema recorrente com diversas aplicações. Entre os exemplos de aplicação estão a determinação de diferenças genéticas entre espécies e a identificação de mutações no genoma de um determinado vírus que levam a novas variantes, por exemplo.

Existem diversos algoritmos que realizam busca de uma string dentro de outra como por exemplo, o algoritmo naive ou força-bruta O(nm) e o algoritmo KMP (Knuth, Morris e Pratt) que é uma proposta para resolução do problema de buscar uma substring com tempo linear O(n). 

## Objetivo

O objetivo da atividade prática é compreender melhor os dois algoritmos de busca em strings mencionados, através da implementação e comparação entre eles.

## Conteúdo

Nesse repositório se encontram o arquivo BuscaString.cpp onde devem ser implementados os algoritmos. E o arquivo texto.txt contendo o codigo genetico do vírus MonkeyPox.

bs-lib/ <br>
--- input/ <br>
------- texto.txt <br>
--- BuscaString.cpp

## O que deve ser feito?

Você deve acompanhar o tutorial feito em sala e implementar as funções para buscar uma substring usando força-bruta e usando o algoritmo KMP.

Para a entrega, instrumente o código para calcular e imprimir o numero de comparações realizadas por cada método e o tempo que cada método leva para retornar uma busca sem sucesso.

## Compilação e Execução

Para compilar:

```
cmake -B build
cmake --build build
```

Para executar:

- executável na basta build + texto.txt na pasta input + padrao

```
./build/main ./bs-lib/input/texto.txt GATTACACCCCAAAAACCCC
```
