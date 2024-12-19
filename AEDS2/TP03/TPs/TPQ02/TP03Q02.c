#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXTAM 800

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

typedef struct {
    int tam;
    int ids[100];
    int removidos[50];
    int quant_removi;
} Comando;

void inserirInicio(Comando *array, int x) {
    if (array->tam >= MAXTAM) {
        printf("Erro ao inserir!\n");
        return;
    }
    for (int i = array->tam; i > 0; i--) {
        array->ids[i] = array->ids[i - 1];
    }
    array->ids[0] = x;
    array->tam++;
}

void inserirFim(Comando *array, int x) {
    if (array->tam >= MAXTAM) {
        printf("Erro ao inserir!\n");
        return;
    }
    array->ids[array->tam] = x;
    array->tam++;
}

void inserir(Comando *array, int x, int pos) {
    if (array->tam >= MAXTAM || pos < 0 || pos > array->tam) {
        printf("Erro ao inserir!\n");
        return;
    }
    for (int i = array->tam; i > pos; i--) {
        array->ids[i] = array->ids[i - 1];
    }
    array->ids[pos] = x;
    array->tam++;
}

int removerInicio(Comando *array) {
    if (array->tam == 0) {
        printf("Erro ao remover!\n");
        return -1;
    }
    int resp = array->ids[0];
    array->tam--;
    for (int i = 0; i < array->tam; i++) {
        array->ids[i] = array->ids[i + 1];
    }
    return resp;
}

int removerFim(Comando *array) {
    if (array->tam == 0) {
        printf("Erro ao remover!\n");
        return -1;
    }
    return array->ids[--array->tam];
}

int remover(Comando *array, int pos) {
    if (array->tam == 0 || pos < 0 || pos >= array->tam) {
        printf("Erro ao remover!\n");
        return -1;
    }
    int resp = array->ids[pos];
    array->tam--;
    for (int i = pos; i < array->tam; i++) {
        array->ids[i] = array->ids[i + 1];
    }
    return resp;
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

void imprimir_removidos(int n, Pokemon *p) {
    printf("(R) %s\n", p->name);
}

void imprimir(int n, Pokemon *p) {
    printf("[%d] [#%d -> %s: %s - [%s] - %s - %.1fkg - %.1fm - %d%% - %s - %d gen] - %s\n", n,
           p->id, p->name, p->description, p->types, p->abilities, p->weight, p->height, p->captureRate, p->isLegendary ? "true" : "false", p->generation, p->captureDate);
}

void Ids_removidos(Comando *array) {
    Pokemon *p = (Pokemon *)malloc(sizeof(Pokemon));

    FILE *arquivo = fopen("/tmp/pokemon.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[400];
    int cont = 0;
    float peso[50];
    char name[200];
    char nomes[100][100];
    int id, j = 0;

    fgets(linha, sizeof(linha), arquivo); // Ignora cabe alho

    for (int i = 0; i < array->quant_removi; i++) {
        rewind(arquivo);
        fgets(linha, sizeof(linha), arquivo);

        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            char *linhaCopy = linha;
            char *parte = strsep(&linhaCopy, ","); // Extrai o ID da linha
            id = atoi(parte);

            if (id ==  array->ids[i]) {
                parte = strsep(&linhaCopy, ","); // Gera  o

                parte = strsep(&linhaCopy, ","); // Nome
                strcpy(nomes[j], parte);

                parte = strsep(&linhaCopy, ","); // Descri  o

                parte = strsep(&linhaCopy, ","); // Tipos

                parte = strsep(&linhaCopy, "\"");
                if (parte != NULL && strlen(parte) > 0 && strcmp(parte, ",") != 0) {
                    parte[strlen(parte) - 1] = '\0';
                }

                parte = strsep(&linhaCopy, "\""); // Habilidades

                while (*linhaCopy != '\0') {
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

    arquivo = fopen("/tmp/pokemon.csv", "r");

    int n = 0;

    fgets(linha, sizeof(linha), arquivo); // Ignora cabe alho

    for (int i = 0; i < j; i++) {
        rewind(arquivo);
        fgets(linha, sizeof(linha), arquivo);

        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            char *linhaCopy = linha;
            char *parte;

            parte = strsep(&linhaCopy, ",");
            p->id = atoi(parte);

            parte = strsep(&linhaCopy, ",");
            p->generation = atoi(parte);

            parte = strsep(&linhaCopy, ",");
            strcpy(p->name, parte);

            if (p->id ==  array->removidos[i]) {
                imprimir_removidos(n, p);
                n++;
                break;
            }
        }
    }
    fclose(arquivo);
    free(p);
}

void Lista_flex(Comando *array) {
    Pokemon *p = (Pokemon *)malloc(sizeof(Pokemon));

    FILE *arquivo = fopen("/tmp/pokemon.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[400];
    int cont = 0;
    float peso[50];
    char name[200];
    char nomes[100][100];
    int id, j = 0;

    fgets(linha, sizeof(linha), arquivo); // Ignora cabe alho

    for (int i = 0; i < array->tam; i++) {
        rewind(arquivo);
        fgets(linha, sizeof(linha), arquivo);

        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            char *linhaCopy = linha;
            char *parte = strsep(&linhaCopy, ","); // Extrai o ID da linha
            id = atoi(parte);

            if (id ==  array->ids[i]) {
                parte = strsep(&linhaCopy, ","); // Gera  o

                parte = strsep(&linhaCopy, ","); // Nome
                strcpy(nomes[j], parte);

                parte = strsep(&linhaCopy, ","); // Descri  o

                parte = strsep(&linhaCopy, ","); // Tipos

                parte = strsep(&linhaCopy, "\"");
                if (parte != NULL && strlen(parte) > 0 && strcmp(parte, ",") != 0) {
                    parte[strlen(parte) - 1] = '\0';
                }

                parte = strsep(&linhaCopy, "\""); // Habilidades

                while (*linhaCopy != '\0') {
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

    arquivo = fopen("/tmp/pokemon.csv", "r");

    int n = 0;

    fgets(linha, sizeof(linha), arquivo); // Ignora cabe alho

    for (int i = 0; i < j; i++) {
        rewind(arquivo);
        fgets(linha, sizeof(linha), arquivo);

        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
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

            if (parte != NULL && strlen(parte) > 0 && strcmp(parte, ",") != 0) {
                parte[strlen(parte) - 1] = '\0';
                strcat(p->types, ", '");
                strcat(p->types, parte);
                strcat(p->types, "'");
            }

            parte = strsep(&linhaCopy, "\"");
            strcpy(p->abilities, parte);

            while (*linhaCopy != '\0') {
                parte = strsep(&linhaCopy, ",");
                parte = strsep(&linhaCopy, ",");
                if (parte) {
                    p->weight = atof(parte);
                }

                parte = strsep(&linhaCopy, ",");
                if (parte) {
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

            if (p->id ==  array->ids[i]) {
                imprimir(n, p);
                n++;
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
    int i = 0;
    Comando comando;
    comando.tam = 0;
    comando.quant_removi = 0;
    int g = 0;

    // Leitura de IDs
    while (verdade && i < 50) {
        scanf("%s", num);
        if (strcmp(num, "FIM") == 0) {
            verdade = false;
        } else {
            comando.ids[i] = atoi(num);
            i++;
            comando.tam++;
        }
    }

    // Leitura de comandos
    int quant;
    scanf("%d", &quant);
    char comandos[3];
    int entrada;
    int position;
    for (int k = 0; k < quant; k++) {
        scanf("%s", comandos);

        if (strcmp(comandos, "II") == 0) {
            scanf("%d", &entrada);
            inserirInicio(&comando, entrada);

        } else if (strcmp(comandos, "IF") == 0) {
            scanf("%d", &entrada);
            inserirFim(&comando, entrada);

        } else if (strcmp(comandos, "I*") == 0) {
            scanf("%d", &position);
            scanf("%d", &entrada);
            inserir(&comando, entrada, position);

        } else if (strcmp(comandos, "RI") == 0) {
            comando.removidos[g] = removerInicio(&comando);
            comando.quant_removi++;
            g++;

        } else if (strcmp(comandos, "RF") == 0) {
            comando.removidos[g] = removerFim(&comando);
            comando.quant_removi++;
            g++;

        } else if (strcmp(comandos, "R*") == 0) {
            scanf("%d", &position);
            comando.removidos[g] = remover(&comando, position);
            comando.quant_removi++;
            g++;
        }
    }

    Ids_removidos(&comando);
    Lista_flex(&comando);

    return 0;
}
