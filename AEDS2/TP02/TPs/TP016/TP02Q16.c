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

void Insercao_Parcial(char captura[][200], char nomes[][100], int ids[], int n) {
        for (int i = 1; i < n; i++) {
        char tmpData[20];
        char tmpNome[100];
        int tmpId = ids[i];

        strcpy(tmpData, captura[i]);
        strcpy(tmpNome, nomes[i]);

        int j = i - 1;

        // Converter data para o formato yyyy/mm/dd para comparacao
        char dataAtual[9], dataAnterior[9];
        snprintf(dataAtual, sizeof(dataAtual), "%.4s%.2s%.2s", tmpData + 6, tmpData + 3, tmpData);   // yyyy+mm+dd
        snprintf(dataAnterior, sizeof(dataAnterior), "%.4s%.2s%.2s", captura[j] + 6, captura[j] + 3, captura[j]);

        while (j >= 0 && (strcmp(dataAnterior, dataAtual) > 0 || (strcmp(dataAnterior, dataAtual) == 0 && strcmp(nomes[j], tmpNome) > 0))) {

            strcpy(captura[j + 1], captura[j]);
            strcpy(nomes[j + 1], nomes[j]);
            ids[j + 1] = ids[j];

            j--;

            if (j >= 0) {
                snprintf(dataAnterior, sizeof(dataAnterior), "%.4s%.2s%.2s", captura[j] + 6, captura[j] + 3, captura[j]);
            }
        }

        strcpy(captura[j + 1], tmpData);
        strcpy(nomes[j + 1], tmpNome);
        ids[j + 1] = tmpId;
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
    char name[200];
    char nomes[100][100];
    char Dia_Captura[200][200];
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

                int lendario;

                parte = strsep(&linhaCopy, ","); // Descricao

                parte = strsep(&linhaCopy, ","); // Tipos

                parte = strsep(&linhaCopy, "\"");

                parte = strsep(&linhaCopy, "\""); // Habilidades

                while (*linhaCopy != '\0'){ // Altura e peso
                    parte = strsep(&linhaCopy, ",");
                    parte = strsep(&linhaCopy, ",");

                    parte = strsep(&linhaCopy, ",");

                    break;
                }

                parte = strsep(&linhaCopy, ","); // Taxa de captura

                parte = strsep(&linhaCopy, ","); // Lendario


                parte = strsep(&linhaCopy, "\n"); // Dia de captura
                strcpy(Dia_Captura[j], parte);

                j++;
                break;
            }
        }
    }

    fclose(arquivo);

    Insercao_Parcial(Dia_Captura, nomes, ids, j);

    arquivo = fopen("/tmp/pokemon.csv", "r");

    fgets(linha, sizeof(linha), arquivo);

    int k = 10; //Limitador para ordenacao parcial

    for (int i = 0; i < k; i++){
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
