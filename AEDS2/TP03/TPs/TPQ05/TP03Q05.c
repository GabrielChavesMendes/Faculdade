#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


//STRUCT POKEMON
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
    int removidos[20];
    int quant_removi;
}Comando;

//TIPO CELULA
typedef struct Celula {
	int elemento;        // Elemento inserido na celula.
	struct Celula* prox; // Aponta a celula prox.
} Celula;

Celula* novaCelula(int elemento) {
   Celula* nova = (Celula*) malloc(sizeof(Celula));
   nova->elemento = elemento;
   nova->prox = NULL;
   return nova;
}

//LISTA PROPRIAMENTE DITA
Celula* primeiro;
Celula* ultimo;

void start () {
   primeiro = novaCelula(-1);
   ultimo = primeiro;
}

// Insere um elemento na primeira posicao da lista.

void inserirInicio(int x) {
   Celula* tmp = novaCelula(x);
   tmp->prox = primeiro->prox;
   primeiro->prox = tmp;
   if (primeiro == ultimo) {
      ultimo = tmp;
   }
   tmp = NULL;
}

// Insere um elemento na ultima posicao da lista.

void inserirFim(int x) {
   ultimo->prox = novaCelula(x);
   ultimo = ultimo->prox;
}


//Remove um elemento da primeira posicao da lista.

int removerInicio() {
   if (primeiro == ultimo) {
      printf("Erro ao remover!");
   }

   Celula* tmp = primeiro;
   primeiro = primeiro->prox;
   int resp = primeiro->elemento;
   tmp->prox = NULL;
   free(tmp);
   tmp = NULL;
   return resp;
}


//Remove um elemento da ultima posicao da lista.

int removerFim() {
   if (primeiro == ultimo) {
      printf("Erro ao remover!");
   }

   // Caminhar ate a penultima celula:
   Celula* i;
   for(i = primeiro; i->prox != ultimo; i = i->prox);

   int resp = ultimo->elemento;
   ultimo = i;
   free(ultimo->prox);
   i = ultimo->prox = NULL;

   return resp;
}

int tamanho() {
   int tamanho = 0;
   Celula* i;
   for(i = primeiro; i != ultimo; i = i->prox, tamanho++);
   return tamanho;
}

//Inserir um elemento em determinada posição da lista

void inserir(int x, int pos) {

   int tam = tamanho();

   if(pos < 0 || pos > tam){
      printf("Erro ao inserir posicao (%d/ tamanho = %d) invalida!", pos, tam);
   } else if (pos == 0){
      inserirInicio(x);
   } else if (pos == tam){
      inserirFim(x);
   } else {
      // Caminhar ate a posicao anterior a insercao
      int j;
      Celula* i = primeiro;
      for(j = 0; j < pos; j++, i = i->prox);

      Celula* tmp = novaCelula(x);
      tmp->prox = i->prox;
      i->prox = tmp;
      tmp = i = NULL;
   }
}

//Remover um elemento em determinada posição da lista

int remover(int pos) {
   int resp;
   int tam = tamanho();

   if (primeiro == ultimo){
      printf("Erro ao remover (vazia)!");
   } else if(pos < 0 || pos >= tam){
      printf("Erro ao remover posicao (%d/ tamanho = %d) invalida!", pos, tam);
   } else if (pos == 0){
      resp = removerInicio();
   } else if (pos == tam - 1){
      resp = removerFim();
   } else {
      // Caminhar ate a posicao anterior a insercao
      Celula* i = primeiro;
      int j;
      for(j = 0; j < pos; j++, i = i->prox);

      Celula* tmp = i->prox;
      resp = tmp->elemento;
      i->prox = tmp->prox;
      tmp->prox = NULL;
      free(tmp);
      i = tmp = NULL;
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

void imprimir_removidos(Pokemon *p) {
    printf("(R) %s\n", p->name);
}

void imprimir(int n, Pokemon *p) {
    printf("[%d] [#%d -> %s: %s - [%s] - %s - %.1fkg - %.1fm - %d%% - %s - %d gen] - %s\n", n,
           p->id, p->name, p->description, p->types, p->abilities, p->weight, p->height, p->captureRate, p->isLegendary ? "true" : "false", p->generation, p->captureDate);
}

//FUNÇÃO PARA ENCONTRA OS IDS REMOVIDOS NO ARQUIVO PEGAR AS INFORMAÇÕES E IMPRIMIR
void Ids_removidos(Comando *array, int j) {

    Pokemon *p = (Pokemon *)malloc(sizeof(Pokemon));

    FILE *arquivo = fopen("/tmp/pokemon.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[400];
    fgets(linha, sizeof(linha), arquivo); // Ignora cabeçalho

    for (int i = 0; i < array->quant_removi; i++) {
        rewind(arquivo);
        fgets(linha, sizeof(linha), arquivo); // Ignora o cabeçalho novamente

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
                imprimir_removidos(p);
                break;
            }
        }
    }
    fclose(arquivo);
}

//FUNÇÃO PARA ENCONTRAR OS IDS DA LISTA E IMPRIMIR AS INFORMÇÕES
void Lista_simples(int n, int ids) {
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

    arquivo = fopen("/tmp/pokemon.csv", "r");

    fgets(linha, sizeof(linha), arquivo); // Ignora cabe alho

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

        if (p->id ==  ids) {
            imprimir(n, p);
            break;
        }
    }

    fclose(arquivo);
    free(p);
}

void mostrar(int tam) {
    Celula* i;
    int n = 0;

    for (i = primeiro->prox; i != NULL; i = i->prox) { //Percorre a lista até ser NULL, celula por celula
        Lista_simples(n, i->elemento);
        n++;
   }
}

//MAIN

int main(void) {
    bool verdade = true;
    char num[4];
    int i = 0;
    int valor;
    Comando comando;
    comando.tam = 0;
    comando.quant_removi = 0;
    int g = 0;

    start(); //Inicializa a lista

    // Leitura de IDs
    while (verdade && i < 50) {
        scanf("%s", num);
        if (strcmp(num, "FIM") == 0) {
            verdade = false;
        } else {
            valor = atoi(num);
            inserirFim(valor); //Insere os primeiros valores no fim para fazer uma lista não invertida
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
            inserirInicio(entrada);
            i++;

        } else if (strcmp(comandos, "IF") == 0) {
            scanf("%d", &entrada);
            inserirFim(entrada);
            i++;

        } else if (strcmp(comandos, "I*") == 0) {
            scanf("%d", &position);
            scanf("%d", &entrada);
            inserir(entrada, position);
            i++;

        } else if (strcmp(comandos, "RI") == 0) {
            comando.removidos[g] = removerInicio();
            comando.quant_removi++;
            g++;
            i--;

        } else if (strcmp(comandos, "RF") == 0) {
            comando.removidos[g] = removerFim();
            comando.quant_removi++;
            g++;
            i--;

        } else if (strcmp(comandos, "R*") == 0) {
            scanf("%d", &position);
            comando.removidos[g] = remover(position);
            comando.quant_removi++;
            g++;
            i--;
        }
    }

    Ids_removidos(&comando, g);
    mostrar(i);

    return 0;
}
