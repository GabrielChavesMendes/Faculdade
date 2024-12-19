/**
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico: ed01
  *
  * Matricula: 1453522  Nome: Gabriel_Chaves_Mendes
  * Versao:  1.0                Data: 27/02/2024
  *
  * Dados:
  * - Feito na IDE CodeBlocks
  *
  * Resultados(SAIDAS):
  * -Exercicio 0115:
    Escreva a base do triangulo: 3
    Escreva a altura do triangulo: 4
    A altura e: 12.000000

**/

#include <stdio.h>
#include <stdlib.h>

int main()
{

 float base, altura;

 printf("Escreva a base do triangulo: ");
 scanf("%f", &base);

 printf("Escreva a altura do triangulo: ");
 scanf("%f", &altura);

 altura = altura * 2;

 float area = (base * altura) / 2;

 printf("A area e: %f\n", area);

return 0;
}
