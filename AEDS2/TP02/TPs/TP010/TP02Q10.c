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

void swap(int geracao[], int ids[], char nomes[][100], int i, int j) {
    int tempGeracao = geracao[i];
    geracao[i] = geracao[j];
    geracao[j] = tempGeracao;

    char tempNome[100];
    strcpy(tempNome, nomes[i]);
    strcpy(nomes[i], nomes[j]);
    strcpy(nomes[j], tempNome);

    int tempId = ids[i];
    ids[i] = ids[j];
    ids[j] = tempId;
}

void QuickSort(int geracao[], char nomes[][100], int ids[], int n, int esq, int dir) {
    int i = esq, j = dir, pivo = geracao[(esq + dir) / 2];
    char pivoNome[100];
    strcpy(pivoNome, nomes[(esq + dir) / 2]);

    while (i <= j) {
        while (geracao[i] < pivo || (geracao[i] == pivo && strcmp(nomes[i], pivoNome) < 0)) {
            i++;
        }

        while (geracao[j] > pivo || (geracao[j] == pivo && strcmp(nomes[j], pivoNome) > 0)) {
            j--;
        }

        if (i <= j) {
            swap(geracao, ids, nomes, i, j);
            i++;
            j--;
        }
    }

    if (esq < j)
        QuickSort(geracao, nomes, ids, n, esq, j);

    if (i < dir)
        QuickSort(geracao, nomes, ids, n, i, dir);
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
    int geracao[50];
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
                geracao[j] = atoi(parte);

                parte = strsep(&linhaCopy, ","); // Nome
                strcpy(nomes[j], parte);

                j++;
                break;
            }
        }
    }

    fclose(arquivo);

    QuickSort(geracao, nomes, ids, j, 0, j-1);

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