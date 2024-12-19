#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int generation;
    char name[100];
    char description[150];
    char types[200];
    char abilities[200];
    double weight;
    double height;
    int captureRate;
    bool isLegendary;
    char captureDate[50];
} Pokemon;

void construtorPrimario(Pokemon *p, int id, int generation, char name[50], char description[150], char types[100], char abilities[100], double weight, double height, int captureRate, bool isLegendary, char captureDate[30])
{
    p->id = id;
    p->generation = generation;
    strcpy(p->name, name);
    strcpy(p->description, description);
    strcpy(p->types, types);
    strcpy(p->abilities, abilities);
    p->weight = weight;
    p->height = height;
    p->captureRate = captureRate;
    p->isLegendary = isLegendary;
    strcpy(p->captureDate, captureDate);
}

void construtorSecundario(Pokemon *p)
{
    p->id = 0;
    p->generation = 0;
    strcpy(p->name, " ");
    strcpy(p->description, " ");
    strcpy(p->types, " ");
    strcpy(p->abilities, " ");
    p->weight = 0.0;
    p->height = 0.0;
    p->captureRate = 0;
    p->isLegendary = true;
    strcpy(p->captureDate, " ");
}

void imprimir(Pokemon *p)
{
    printf("[#%d -> %s: %s - [%s] - %s - %.1fkg - %.1fm - %d%% - %s - %d gen] - %s\n",
           p->id, p->name, p->description, p->types, p->abilities, p->weight, p->height, p->captureRate, p->isLegendary ? "true" : "false", p->generation, p->captureDate);
}

char *strsep(char **stringp, const char *delim)
{
    char *start = *stringp;
    char *p;

    if (start == NULL)
    {
        return NULL;
    }

    p = strpbrk(start, delim);
    if (p)
    {
        *p = '\0';
        *stringp = p + 1;
    }
    else
    {
        *stringp = NULL;
    }

    return start;
}

void lerArquivo(int num)
{
    //Alocação do ponteiro
    Pokemon *p = (Pokemon *)malloc(sizeof(Pokemon));

    FILE *arquivo;
    arquivo = fopen("/tmp/pokemon.csv", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[400];
    int cont = 1;
    char tipo2[50];

    // Lê a primeira linha (cabecalho) e ignora
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        if (cont == num)
        {
            int lendario;
            char *parte;
            char *linhaCopy = linha;

            parte = strsep(&linhaCopy, ",");
            p->id = atoi(parte);

            parte = strsep(&linhaCopy, ",");
            p->generation = atoi(parte);

            parte = strsep(&linhaCopy, ",");
            strcpy(p->name, parte);

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
        cont++;
    }

    fclose(arquivo);
    free(p);
}

int main(void)
{
    bool verdade = true;
    char num[4];

    while (verdade)
    {
        scanf("%s", num);
        if (strcmp(num, "FIM") == 0)
        {
            verdade = false;
        }
        else
        {
            int numero = atoi(num);
            lerArquivo(numero);
        }
    }

    return 0;
}
