#include <stdio.h>
#include <string.h>

int diamante_areia(char minerio[]){

    int tam = strlen(minerio);
    int indice = 1;
    int cont = 0;

    for(int i = 0; i < tam; i++){
        if(minerio[i] == '<'){
            indice++;
        }else if(minerio[i] == '>'){
            indice--;
            cont++;
        }
    }
    return cont;
}

int main(void){

    int N;
    char minerio[1000];

    scanf("%d", &N);
    getchar();

    for(int i = 0; i < N; i++){
        fgets(minerio, sizeof(minerio), stdin);

        int cont = diamante_areia(minerio);
        printf("%d\n", cont);
    }

    return 0;
}
