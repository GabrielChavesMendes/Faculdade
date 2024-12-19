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
  * -Exercicio 0116:
        Escreva a base do triangulo: 5
        A altura e: 12.990381
        A area e: 97.427856
        O perimetro e: 45.000000
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

 float lado;

 printf("Escreva a base do triangulo: ");
 scanf("%f", &lado);

 lado = lado * 3;

 float altura = (lado * sqrt(3)) / 2;

 float area = (lado * altura) / 2;

 float perimetro = lado * 3;

 printf("A altura e: %f\n", altura);
 printf("A area e: %f\n", area);
 printf("O perimetro e: %f\n", perimetro);

return 0;
}
