#include <stdio.h>

int main(){

   int N, C, M; //N = total de figurinhas de um album, C = figurinhas carimbadas, M = quantidade de figurinhas compradas


   printf("Escreva a quantidade de figurinhas do album: ");
   scanf("%d", &N);

   printf("Agora escreva quantas figurinhas foram carimbadas: ");
   scanf("%d", &C);

   printf("Agora escreva a quantidade de figurinhas já compradas: ");
   scanf("%d",&M);

    int Xi[C], Yi[M];

   printf("Escreva quais são as figurinhas carimbadas: ");
   for(int i=0; i<C; i++){
    scanf("%d", &Xi[i]);
   }
   printf("Escreva agora quais figurinhas foram compradas: ");
   for(int j=0; j<M; j++){
    scanf("%d", &Yi[j]);
   }

   int cont = 0;
   int iguais = 0;

   /*for(int j = 0; j < M; j++){
    for(int j = 1; j < M; j++){
        if(Yi[j] == Yi[j]){
            iguais++;
            break;
        }
    }
   }

   M = M - iguais;*/

   for(int i = 0; i < C; i++){
    for(int j = 0; j < M; j++){
        if(Xi[i] != Yi[j]){
            cont++;
        }
    }
   }

   int faltam = N - cont;

   printf("Faltam %d", faltam);


return 0;
}
