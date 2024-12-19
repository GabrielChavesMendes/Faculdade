/**
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico: ed01_EXTRA2
  *
  * Matricula: 1453522  Nome: Gabriel_Chaves_Mendes
  * Versao:  1.0                Data: 27/02/2024
  *
  * Dados:
  * - Feito na IDE CodeBlocks
  *
  * Resultados(SAIDAS):
  * -Exercicio E2:
        Digite o volume da esfera: 5
        O raio de 5/8 do volume da esfera e 1.102587. E a area da sua superficie e 15.276912
**/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double volume;

    printf("Digite o volume da esfera: ");
    scanf("%lf", &volume);

    volume = (volume / 8) * 5;

    double raio = cbrt(((4 * M_PI) / 3) / volume);

    double area = 4 * (M_PI * pow(raio, 2));

    printf("O raio de 5/8 do volume da esfera e %lf. E a area da sua superficie e %lf", raio, area);
return 0;
}
