#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *Combinador(char *frase1, char *frase2) {


    int tam = strlen(frase1) + strlen(frase2);

    char *frase3 = (char *)malloc((tam + 1) * sizeof(char));
    int indice1 = 0, indice2 = 0;

    /*loop para percorrer a frase3 preenchendo-a alternadament com os caracteres da frase1 e frase2
    se o i divido por 2 der 0, ele ira colocar no indice par a letra da frase1, se nao, com a frase2
    e se contador ainda nao atigir o tamanho de uma das frases ira preencher o restante da frase3 com o
    restante da frase que sobrar*/

    for (int i = 0; i < tam; i++) {
        if (i % 2 == 0 && indice1 < strlen(frase1)) {
            frase3[i] = frase1[indice1];
            indice1++;
        } else if (indice2 < strlen(frase2)) {
            frase3[i] = frase2[indice2];
            indice2++;
        } else if (indice1 < strlen(frase1)) {
            frase3[i] = frase1[indice1];
            indice1++;
        }
    }

    frase3[tam] = '\0'; //Certificando que a ultima posicao sera um '\0'
    return frase3;
}

int main(void) {

    char frase1[300];
    char frase2[300];

    while (scanf("%s", frase1) != EOF && scanf("%s", frase2) != EOF){
        int i = 0, j = 0;

        frase1[strcspn(frase1, "\n")] = '\0';
        frase2[strcspn(frase2, "\n")] = '\0';

        char *frase3 = Combinador(frase1, frase2);

        printf("%s\n", frase3);

        free(frase3);

        for (int k = 0; k < 300; k++){
            frase1[k] = '\0';
            frase2[k] = '\0';
        }
    }

    return 0;
}
