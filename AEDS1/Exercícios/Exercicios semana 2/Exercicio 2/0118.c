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
  * -Exercicio 0118:
        Escreva o comprimento do paralelepipedo: 3
        Escreva a largura do paralelepipedo: 4
        Escreva o altura do paralelepipedo: 5
        O volume do paralelepipedo e: 0.117188
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{

   float comprimento, largura, altura;

   printf("Escreva o comprimento do paralelepipedo: ");
   scanf("%f", &comprimento);

   printf("Escreva a largura do paralelepipedo: ");
   scanf("%f", &largura);

   printf("Escreva o altura do paralelepipedo: ");
   scanf("%f", &altura);

   comprimento = comprimento / 8;
   largura = largura / 8;
   altura = altura / 8;

   float volume = comprimento * altura * largura;

   printf("O volume do paralelepipedo e: %f", volume);

return 0;
}
