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

// Swap das alturas
void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Swap dos nomes
void swapChar(char a[][100], char b[][100], int i, int j) {
    char temp[100];
    strcpy(temp, a[i]);
    strcpy(a[i], a[j]);
    strcpy(a[j], temp);
}

// Swap dos ids
void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void construir(double altura[], char nomes[][100], int ids[], int tamHeap) {
    for (int i = tamHeap; i > 1 && (altura[i] > altura[i/2] ||
            (altura[i] == altura[i/2] && strcmp(nomes[i], nomes[i/2]) > 0)); i /= 2) {
        swap(&altura[i], &altura[i/2]);
        swapChar(nomes, nomes, i, i/2);
        swapInt(&ids[i], &ids[i/2]);
    }
}

int getMaiorFilho(double altura[], char nomes[][100], int i, int tamHeap) {
    int filho;
    if (2 * i == tamHeap ||
        altura[2 * i] > altura[2 * i + 1] ||
        (altura[2 * i] == altura[2 * i + 1] && strcmp(nomes[2 * i], nomes[2 * i + 1]) > 0)) {
        filho = 2 * i;
    } else {
        filho = 2 * i + 1;
    }
    return filho;
}

void reconstruir(double altura[], char nomes[][100], int ids[], int tamHeap) {
    int i = 1;
    while (i <= tamHeap / 2) {
        int filho = getMaiorFilho(altura, nomes, i, tamHeap);
        if (altura[i] < altura[filho] ||
            (altura[i] == altura[filho] && strcmp(nomes[i], nomes[filho]) < 0)) {
            swap(&altura[i], &altura[filho]);
            swapChar(nomes, nomes, i, filho);
            swapInt(&ids[i], &ids[filho]);
            i = filho;
        } else {
            break;
        }
    }
}

void HeapSort_Parcial(double altura[], char nomes[][100], int ids[], int n) {

    double alturaTmp[n + 1];
    char nomesTmp[n + 1][100];
    int idsTmp[n + 1];

    for (int i = 0; i < n; i++) {
        alturaTmp[i + 1] = altura[i];
        strcpy(nomesTmp[i + 1], nomes[i]);
        idsTmp[i + 1] = ids[i];
    }

    for (int tamHeap = 2; tamHeap <= n; tamHeap++) {
        construir(alturaTmp, nomesTmp, idsTmp, tamHeap);
    }

    int tamHeap = n;
    while (tamHeap > 1) {
        swap(&alturaTmp[1], &alturaTmp[tamHeap]);
        swapChar(nomesTmp, nomesTmp, 1, tamHeap);
        swapInt(&idsTmp[1], &idsTmp[tamHeap]);
        tamHeap--;
        reconstruir(alturaTmp, nomesTmp, idsTmp, tamHeap);
    }

    for (int i = 0; i < n; i++) {
        altura[i] = alturaTmp[i + 1];
        strcpy(nomes[i], nomesTmp[i + 1]);
        ids[i] = idsTmp[i + 1];
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
    double altura[200];
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

                while (*linhaCopy != '\0'){ // Peso e altura
                    parte = strsep(&linhaCopy, ",");
                    parte = strsep(&linhaCopy, ",");

                    parte = strsep(&linhaCopy, ",");
                    if (parte){
                        altura[j] = atof(parte);
                    }
                    break;
                }

                j++;
                break;
            }
        }
    }

    fclose(arquivo);

    HeapSort_Parcial(altura, nomes, ids, j);

    arquivo = fopen("/tmp/pokemon.csv", "r");

    fgets(linha, sizeof(linha), arquivo);

    int k = 10; // Limitador para ordenacao parcial

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
