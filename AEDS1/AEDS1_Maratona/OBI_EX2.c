#include <stdio.h>

int main(){

   int L, C;
   printf("Escreva a largura: ");
   scanf("%d", &L);

   printf("Escreva o comprimento: ");
   scanf("%d", &C);

   int lajota3 = 1; //tanto no comprimento quanto na largura ele ocupa 1cm no total, pois é 0,5 em cada ponta

   int largura2 = L - lajota3;
   int compri2 = C - lajota3;

   int lajota2 = (largura2 * 2) + (compri2 * 2);


    // Cálculos para lajotas do tipo 1
    int lajota1 = L * C + (L - 1) * (C - 1); //área total + a área sem as LAJOTAS3


   printf("Lajotas 1 é: %d\n", lajota1);
   printf("Lajotas 2 é: %d", lajota2);


return 0;
}
