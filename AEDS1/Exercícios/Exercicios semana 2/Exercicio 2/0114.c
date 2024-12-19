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
  * -Exercicio 0114:
        Insira o primeiro lado do retangulo: 3
        Insira o segundo lado do retangulo: 5
        O perimetro e: 0
        A area e: 2

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

    int lado1novo = lado1 / 4;
    int lado2novo = lado2 / 4;

    int area = lado1novo * lado2novo;
    int perimetro = (lado1novo * 2) + (lado2novo * 2);

    printf("O perimetro e: %d\n", area);
    printf("A area e: %d", perimetro);

return 0;
}
