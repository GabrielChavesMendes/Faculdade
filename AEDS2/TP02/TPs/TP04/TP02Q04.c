#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int id[100];
    char names[200];
}Pokemon;

char *strsep(char **stringp, const char *delim){
    char *start = *stringp;
    char *p;

    if (start == NULL){
        return NULL;
    }

    p = strpbrk(start, delim);
    if (p){
        *p = '\0';
        *stringp = p + 1;
    }else{
        *stringp = NULL;
    }

    return start;
}

bool pesquisaBinaria(int array[], int n, int id){

    bool resp = false;
    int dir = n - 1, esq = 0, meio;

    while (esq <= dir){
        meio = (esq + dir) / 2;
        if (array[meio] == id){
            return true;
        }else if (array[meio] < id){
            esq = meio + 1;
        }else {
            dir = meio - 1;
        }
    }
    return false;
}

void lerArquivo(Pokemon poke, int tam){

    FILE* arquivo;
    arquivo = fopen("/tmp/pokemon.csv", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return false;
    }else{
        char linha[400];

        fgets(linha, sizeof(linha), arquivo);

        while(fgets(linha, sizeof(linha), arquivo) != NULL){
            char nome[100];
            int ids;
            char *linha_copy = linha;
            char *parte;
            int generation;
            bool achou = false;

            parte = strsep(&linha_copy, ",");
            ids = atoi(parte);

            parte = strsep(&linha_copy, ",");
            generation = atoi(parte);

            parte = strsep(&linha_copy, ",");
            strcpy(nome, parte);

            if(strcmp(poke.names, nome) == 0){
                if (pesquisaBinaria(poke.id, tam, ids)){
                    printf("SIM\n");
                }else{
                    printf("NAO\n");
                }
            fclose(arquivo);
            return;
            }
        }
    }
    fclose(arquivo);
}

int main (void){
    bool verdade = true;
    char num[4];
    char nome[20];
    int i = 0;
    Pokemon poke;

    while (verdade){
        scanf("%s", num);
        if (strcmp(num, "FIM") == 0){
            verdade = false;
        }else{
            poke.id[i] = atoi(num);
            i++;
        }
    }

    //Ordena os ids para a pesquisa binaria
    for (int x = 0; x < i - 1; x++){
        for (int y = x + 1; y < i; y++){
            if (poke.id[x] > poke.id[y]){
                int temp = poke.id[x];
                poke.id[x] = poke.id[y];
                poke.id[y] = temp;
            }
        }
    }

    verdade = true;

    while (verdade){
        scanf("%s", nome);
        if (strcmp(nome, "FIM") == 0){
            verdade = false;
        }else{
            strcpy(poke.names, nome);
            lerArquivo(poke, i);
        }
    }

    return 0;
}
