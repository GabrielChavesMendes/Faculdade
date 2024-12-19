#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int id;
    char name[100];
    char description[200];
    char types[200];
    char abilities[200];
    double weight;
    double height;
    int captureRate;
    bool isLegendary;
    int generation;
    char captureDate[20];
} Pokemon;

void insercao_peso(int peso[], char nomes[][100], int ids[], int n, int j, int h) {
    for (int i = (h + j); i < n; i += h) {
        int tmp = peso[i];
        char nomeTmp[100];
        strcpy(nomeTmp, nomes[i]);
        int idTmp = ids[i];

        int k = i - h;

        while (k >= 0 && (peso[k] > tmp || (peso[k] == tmp && strcmp(nomes[k], nomeTmp) > 0))) {
            peso[k + h] = peso[k];
            strcpy(nomes[k + h], nomes[k]);
            ids[k + h] = ids[k];
            k -= h;
        }

        peso[k + h] = tmp;
        strcpy(nomes[k + h], nomeTmp);
        ids[k + h] = idTmp;
    }
}

void ShellSort(int peso[], char nomes[][100], int ids[], int n) {
    int h = 1;

    while (h < n / 3) {
        h = h * 3 + 1;
    }

    while (h >= 1) {
        for (int i = 0; i < h; i++) {
            insercao_peso(peso, nomes, ids, n, i, h);
        }
        h /= 3;
    }
}

void imprimir(Pokemon *p) {
    printf("[#%d -> %s: %s - [%s] - %s - %.1fkg - %.1fm - %d%% - %s - %d gen] - %s\n",
    p->id, p->name, p->description, p->types, p->abilities, p->weight, p->height, p->captureRate, p->isLegendary ? "true" : "false", p->generation, p->captureDate);
}

char *strsep(char **stringp, const char *delim) {
    char *start = *stringp;
    char *p;

    if (start == NULL) {
        return NULL;
    }

    p = strpbrk(start, delim);
    if (p) {
        *p = '\0';
        *stringp = p + 1;
    } else {
        *stringp = NULL;
    }

    return start;
}

void Ordena(int* ids, int num){
    Pokemon *p = (Pokemon *)malloc(sizeof(Pokemon));

    FILE *arquivo;
    arquivo = fopen("/tmp/pokemon.csv", "r");

    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[400];
    int cont = 0;
    float peso[50];
    char name[200];
    char nomes[100][100];
    int id, j = 0;

    fgets(linha, sizeof(linha), arquivo);

    for(int i = 0; i < num; i++){
        rewind(arquivo);
        fgets(linha, sizeof(linha), arquivo);

        while(fgets(linha, sizeof(linha), arquivo) != NULL) {
            char *linhaCopy = linha;
            char *parte = strsep(&linhaCopy, ","); // Extrai o ID da linha
            id = atoi(parte);

            if(id == ids[i]) {
                parte = strsep(&linhaCopy, ","); // Geracao

                parte = strsep(&linhaCopy, ","); // Nome
                strcpy(nomes[j], parte);

                parte = strsep(&linhaCopy, ","); // Descricao

                parte = strsep(&linhaCopy, ","); // Tipos

                parte = strsep(&linhaCopy, "\"");
                if (parte != NULL && strlen(parte) > 0 && strcmp(parte, ",") != 0) {
                    parte[strlen(parte) - 1] = '\0';
                }

                parte = strsep(&linhaCopy, "\""); // Habilidades

                while (*linhaCopy != '\0'){
                    parte = strsep(&linhaCopy, ",");
                    parte = strsep(&linhaCopy, ",");
                    if (parte) {
                        peso[j] = atof(parte);
                    }
                    strsep(&linhaCopy, ",");
                    break;
                }
                j++;
                break;
            }
        }
    }

    fclose(arquivo);

    ShellSort(peso, nomes, ids, j);

    arquivo = fopen("/tmp/pokemon.csv", "r");

    fgets(linha, sizeof(linha), arquivo);

    for (int i = 0; i < j; i++){
        rewind(arquivo);
        fgets(linha, sizeof(linha), arquivo);

        while (fgets(linha, sizeof(linha), arquivo) != NULL){
            char *linhaCopy = linha;
            char *parte;

            parte = strsep(&linhaCopy, ",");
            p->id = atoi(parte);

            parte = strsep(&linhaCopy, ",");
            p->generation = atoi(parte);

            parte = strsep(&linhaCopy, ",");
            strcpy(p->name, parte);

            int lendario;

            parte = strsep(&linhaCopy, ",");
            strcpy(p->description, parte);

            parte = strsep(&linhaCopy, ",");
            strcpy(p->types, "'");
            strcat(p->types, parte);
            strcat(p->types, "'");

            parte = strsep(&linhaCopy, "\"");

            if (parte != NULL && strlen(parte) > 0 && strcmp(parte, ",") != 0){

                parte[strlen(parte) - 1] = '\0';
                strcat(p->types, ", '");
                strcat(p->types, parte);
                strcat(p->types, "'");
            }

            parte = strsep(&linhaCopy, "\"");
            strcpy(p->abilities, parte);

            while (*linhaCopy != '\0'){
                parte = strsep(&linhaCopy, ",");
                parte = strsep(&linhaCopy, ",");
                if (parte){
                    p->weight = atof(parte);
                }

                parte = strsep(&linhaCopy, ",");
                if (parte){
                    p->height = atof(parte);
                }
                break;
            }

            parte = strsep(&linhaCopy, ",");
            p->captureRate = atoi(parte);

            parte = strsep(&linhaCopy, ",");
            lendario = atoi(parte);
            p->isLegendary = (lendario == 1);

            parte = strsep(&linhaCopy, "\n");
            strcpy(p->captureDate, parte);

            if (p->id == ids[i]){
                imprimir(p);
                break;
            }
        }
    }
    fclose(arquivo);
    free(p);
}

int main(void) {
    bool verdade = true;
    char num[4];
    int ids[200];
    int i = 0;

    // Leitura de IDs
    while (verdade) {
        scanf("%s", num);
        if (strcmp(num, "FIM") == 0) {
            verdade = false;
        } else {
            ids[i] = atoi(num);
            i++;
        }
    }

    Ordena(ids, i);

    return 0;
}
