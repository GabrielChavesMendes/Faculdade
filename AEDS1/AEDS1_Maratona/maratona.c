#include <stdio.h>

int main(){

     
    int criancas;
    int ganhou = 0;
    int perdeu = 0;
    char partida;

    for(int i = 0; i < 6; i++){
        scanf(" %c", &partida);
        if (partida == 'V'){
          ganhou++;
        }else if(partida == 'P'){
           perdeu++;
        }
    }
     
    if(ganhou == 5 || ganhou == 6){
        printf("1");
    }
    if(ganhou == 4 || ganhou == 3){
        printf("2");
    }
    if(ganhou == 2 || ganhou == 1){
        printf("1");
    }



    return 0;
}