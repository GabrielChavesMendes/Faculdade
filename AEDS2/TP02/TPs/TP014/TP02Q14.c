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

int getMaior(char habilidades[][200], int n) {
    int max = strlen(habilidades[0]);
    for (int i = 1; i < n; i++) {
        if (strlen(habilidades[i]) > max) {
            max = strlen(habilidades[i]);
        }
    }
    return max;
}

void CountigSort(char habilidades[][200], char nomes[][100], int ids[], int n, int pos) {
    int count[256] = {0};
    char habilidades_array[n][100];
    char nomes_array[n][100];
    int ids_array[n];

    // Contar frequência
    for (int i = 0; i < n; i++) {
        int charIndex = pos < strlen(habilidades[i]) ? habilidades[i][pos] : 0;
        count[charIndex]++;
    }

    // Acumular contagens
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    // Ordenar caracteres com base na posição
    for (int i = n - 1; i >= 0; i--) {
        int charIndex = pos < strlen(habilidades[i]) ? habilidades[i][pos] : 0;
        strcpy(habilidades_array[count[charIndex] - 1], habilidades[i]);
        strcpy(nomes_array[count[charIndex] - 1], nomes[i]);
        ids_array[count[charIndex] - 1] = ids[i];
        count[charIndex]--;
    }

    // Copiar arrays ordenados para os originais
    for (int i = 0; i < n; i++) {
        strcpy(habilidades[i], habilidades_array[i]);
        strcpy(nomes[i], nomes_array[i]);
        ids[i] = ids_array[i];
    }
}

void RadixSort(char habilidades[][200], char nomes[][100], int ids[], int n) {
    int maxLen = getMaior(habilidades, n);

    for (int pos = maxLen - 1; pos >= 0; pos--) {
        CountigSort(habilidades, nomes, ids, n, pos);
    }

    // Desempatar por nome se as habilidades são iguais
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(habilidades[i], habilidades[i + 1]) == 0) {
            if (strcmp(nomes[i], nomes[i + 1]) > 0) {
                char nomes_temp[100];
                char habilidades_temp[100];
                int id_temp;

                // Troca de nomes
                strcpy(nomes_temp, nomes[i]);
                strcpy(nomes[i], nomes[i + 1]);
                strcpy(nomes[i + 1], nomes_temp);

                // Troca de habilidades
                strcpy(habilidades_temp, habilidades[i]);
                strcpy(habilidades[i], habilidades[i + 1]);
                strcpy(habilidades[i + 1], habilidades_temp);

                // Troca de IDs
                id_temp = ids[i];
                ids[i] = ids[i + 1];
                ids[i + 1] = id_temp;
            }
        }
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
    char habilidades[200][200];
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

                parte = strsep(&linhaCopy, "' ");

                parte = strsep(&linhaCopy, "'"); // Habilidades
                strcpy(habilidades[j], parte);

                j++;
                break;
            }
        }
    }

    fclose(arquivo);

    /*for(int i = 0; i < j; i++){
        printf("Pokemon: %s -> habilidade: %s\n", nomes[i], habilidades[i]);
    }*/

    RadixSort(habilidades, nomes, ids, j);

    /*for(int i = 0; i < j; i++){
        printf("Pokemon: %s -> habilidade: %s\n", nomes[i], habilidades[i]);
    }*/

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
