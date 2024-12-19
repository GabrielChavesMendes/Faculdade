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
  * -Exercicio 0111:
        Escreva o lado do primeiro quadrado: 5
        A area do quadrado e 225
**/


#include <stdio.h>
#include <stdlib.h>

int main()
{

    int lado;

    printf("Escreva o lado do primeiro quadrado: ");
    scanf("%d", &lado);

    lado = lado * 3;

    int area = pow(lado, 2); //sinal da potencia

    printf("\nA area do quadrado e %d\n", area);


return 0;
}

