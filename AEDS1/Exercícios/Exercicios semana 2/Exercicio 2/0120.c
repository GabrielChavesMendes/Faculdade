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
  * -Exercicio 0120:
        Escreva o raio do circulo: 5
        O volume da esfera e: 220.893234
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

  float raio;

  printf("Escreva o raio do circulo: ");
  scanf("%f", &raio);

  raio = (raio / 4) * 3;

  float volume = ((pow(raio, 3) * M_PI) / 3) * 4;

  printf("O volume da esfera e: %f", volume);

return 0;
}
