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

void swap(char nomes[][100], int i, int j) {
    char temp[100];
    strcpy(temp, nomes[i]);
    strcpy(nomes[i], nomes[j]);
    strcpy(nomes[j], temp);
}

void Selecao_recursiva(char nomes[][100], int num, int i) {
    if (i >= num - 1) {
        return;
    }

    int menor = i;
    for (int j = i + 1; j < num; j++) {
        if (strcmp(nomes[j], nomes[menor]) < 0) {
            menor = j;
        }
    }

    if (menor != i) {
        swap(nomes, i, menor);
    }

    Selecao_recursiva(nomes, num, i + 1);
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
    char nomes[100][100];
    char name[200];
    int id, j = 0;

    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *parte;
        char *linhaCopy = linha;

        parte = strsep(&linhaCopy, ",");
        id = atoi(parte);

        for (int i = 0; i < num; i++) {
            if (id == ids[i]) {
                parte = strsep(&linhaCopy, ",");
                parte = strsep(&linhaCopy, ",");
                strcpy(nomes[j], parte);
                j++;
                break;
            }
        }
    }

    fclose(arquivo);

    Selecao_recursiva(nomes, j, 0);

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

            if (strcmp(p->name, nomes[i]) == 0){
                int lendario;

                parte = strsep(&linhaCopy, ",");
                strcpy(p->description, parte);

                parte = strsep(&linhaCopy, ",");
                strcpy(p->types, "'");
                strcat(p->types, parte);
                strcat(p->types, "'");

                // Le os tipos adicionais
               parte = strsep(&linhaCopy, "\"");

                if (parte != NULL && strlen(parte) > 0 && strcmp(parte, ",") != 0){

                    parte[strlen(parte) - 1] = '\0'; //Remove o ultimo caractere do tipo 2 por ser uma virgula

                    strcat(p->types, ", '");
                    strcat(p->types, parte);
                    strcat(p->types, "'");
                }


                parte = strsep(&linhaCopy, "\"");
                strcpy(p->abilities, parte);

                // Ignora a parte entre aspas e le peso e altura
                while (*linhaCopy != '\0')
                {
                    parte = strsep(&linhaCopy, ",");
                    parte = strsep(&linhaCopy, ",");
                    if (parte)
                    {
                        p->weight = atof(parte);
                    }

                    parte = strsep(&linhaCopy, ",");
                    if (parte)
                    {
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
