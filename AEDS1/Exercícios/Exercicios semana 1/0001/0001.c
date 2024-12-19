/**
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico: Anexo_C02
  *
  * Matricula: 1453522  Nome: Gabriel_Chaves_Mendes
  * Versao:  1.0                Data: 22/02/2024
  *
  * Dados:
  * - Feito na IDE CodeBlocks
  *
  * Resultados(SAIDAS):
  * -Exercicio 0001:
          Escreva o lado do primeiro quadrado: 5

          A area do segundo quadrado e: 225
**/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int lado;

    printf("Escreva o lado do primeiro quadrado: ");
    scanf("%d", &lado);

    int lado2 = lado * 3;

    int area = pow(lado2, 2); //sinal da potencia

    printf("\nA area do segundo quadrado e: %d\n", area);

    return 0;
}
