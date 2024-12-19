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
  * -Exercicio 0113:
        Insira o primeiro lado do retangulo: 3
        Insira o segundo lado do retangulo: 5
        A area e: 90
**/


#include <stdio.h>
#include <stdlib.h>

int main()
{

    int lado1, lado2;

    printf("Insira o primeiro lado do retangulo: ");
    scanf("%d", &lado1);

    printf("Insira o segundo lado do retangulo: ");
    scanf("%d", &lado2);

    int area = (lado1 * lado2) * 6;

    printf("A area e: %d", area);


return 0;
}
