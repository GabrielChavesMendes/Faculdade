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
  * -Exercicio 0112:
        Escreva o lado do primeiro quadrado: 5
        A area do segundo quadrado e 4 e o seu perimetro e 8
**/


#include <stdio.h>
#include <stdlib.h>

int main()
{

    int lado;

    printf("Escreva o lado do primeiro quadrado: ");
    scanf("%d", &lado);

    int lado2 = lado / 2;

    int area = pow(lado2, 2); //sinal da potencia
    int perimetro = lado2 * 4;

    printf("\nA area do segundo quadrado e %d e o seu perimetro e %d\n", area, perimetro);


return 0;
}

