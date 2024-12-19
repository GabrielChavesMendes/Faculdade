#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int Quantidade_Maiusculo(char *frase){

    int tam = strlen(frase);
    int cont = 0;

    for(int i = 0; i < tam; i++){
        if(frase[i] >= 'A' && frase[i] <= 'Z'){
            cont++;
        }
    }
    return cont;
}

int main(void){

    char frase[70];
    bool verdade = false;

    while(!verdade){

        fgets(frase, 70, stdin);

        if(frase[0] == 'F' && frase[1] == 'I' && frase[2] == 'M'){
            verdade = true;
        }else{
            int quantidade = Quantidade_Maiusculo(frase);

            printf("%d\n", quantidade);
        }

    }

    return 0;
}
