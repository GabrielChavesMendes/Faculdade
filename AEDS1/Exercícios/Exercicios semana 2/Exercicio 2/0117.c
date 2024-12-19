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
  * -Exercicio 0117:
        Escreva o lado do cubo: 5
        O volume do cubo e 15625.000000
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

 float lado;

 printf("Escreva o lado do cubo: ");
 scanf("%f", &lado);

 lado = lado * 5;

 float volume = pow(lado, 3);

 printf("O volume do cubo e %f", volume);

return 0;
}
