#include <stdio.h>

int main() {

    int num[5];
    int cresc = 0;
    int decres = 0;


    for(int i = 0; i < 5; i++)
    {
        printf("Escreva o restante dos numeros de 1 a 13 para as cartas: ");
        scanf("%d", &num[i]); //Preenche o array com os numeros digitados
    }

    for(int i = 0; i < 4; i++){ //Loop para varrer o array ( o array vai até o índice 3 pois o "num[i+1] já acessa o último valor sem sair do array)
        if (num[i] < num[i+1]){ //Se o valor no índice i for menor que o valor do indice i+1 acrescenta +1 em "cresc"
            cresc++;
        }else if(num[i] > num[i+1]){ //Mas se o valor de i for maior que o de i+1 acrescenta +1 em "decres"
              decres++;
         }
    }

     if(cresc == 4){
        printf("C");
     }else if(decres == 4) {
        printf("D");
      }else{
         printf("N");
       }

    return 0;
}
