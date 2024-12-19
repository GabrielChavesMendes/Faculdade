/**
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico: ed01_EXTRA1
  *
  * Matricula: 1453522  Nome: Gabriel_Chaves_Mendes
  * Versao:  1.0                Data: 27/02/2024
  *
  * Dados:
  * - Feito na IDE CodeBlocks
  *
  * Resultados(SAIDAS):
  * -Exercicio E1:
        Escreva a area da circunferencia: 5
        Um setimo do raio da circunferencia e: 0.180224
**/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double area;

    printf("Escreva a area da circunferencia: ");
    scanf("%lf", &area);

    double raio = sqrt(area / M_PI);
    raio = raio / 7;

    printf("Um setimo do raio da circunferencia e: %lf", raio);

return 0;
}
