#include <stdio.h>
#include <stdbool.h>

bool Palindromo(char *frase, int inicio, int fim){

    if(inicio >= fim){
        return true;
    }

    if(frase[inicio] != frase[fim]){
        return false;
    }
    return Palindromo(frase, inicio + 1, fim - 1);
}

int main(void){

    char frase[300];
    bool verdade = false;
    int cont = 0;

    while (!verdade){

        fgets(frase, 300, stdin);
        frase[strcspn(frase, "\n")] = 0;
        int tam = strlen(frase);
        bool sim;

        if (frase[0] == 'F' && frase[1] == 'I' && frase[2] == 'M'){
          verdade = true;
        }else{
            sim = Palindromo(frase, 0, tam-1);
        }

          if(sim == true){
            printf("SIM\n");
          }else{
            printf("NAO\n");
          }
    }
}
