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
  * -Exercicio 0119:
        Escreva o raio do circulo: 5
        A area do semicirculo e: 1.090831
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

 float raio;

 printf("Escreva o raio do circulo: ");
 scanf("%f", &raio);

 raio = raio / 6;

 float area = (M_PI * pow(raio, 2)) / 2;

 printf("A area do semicirculo e: %f", area);


return 0;
}
