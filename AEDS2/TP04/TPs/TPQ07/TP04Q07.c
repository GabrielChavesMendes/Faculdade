#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// STRUCT PARA ARMAZENAR POKEMON ================================================
typedef struct {
    int id;
    char name[100];
    int generation;
} Pokemon;

//Funcao strsep ================================================
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

typedef struct Celula {
    int elemento;
    struct Celula *prox;
} Celula;

typedef struct Lista {
    Celula *primeiro;
    Celula *ultimo;
} Lista;

typedef struct HashIndiretoLista {
    Lista *tabela;
    int tamanho;
} HashIndiretoLista;

Celula* novaCelula(int elemento) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = elemento;
    nova->prox = NULL;
    return nova;
}

void inicializarLista(Lista *lista) {
    lista->primeiro = novaCelula(NULL);
    lista->ultimo = lista->primeiro;
}

void inserirInicio(Lista *lista, int elemento) {
    Celula *tmp = novaCelula(elemento);
    tmp->prox = lista->primeiro->prox;
    lista->primeiro->prox = tmp;
    if (lista->primeiro == lista->ultimo) {
        lista->ultimo = tmp;
    }
}

int pesquisar(Lista *lista, int elemento) {
    int index = 0;
    for (Celula *i = lista->primeiro->prox; i != NULL; i = i->prox) {
        if (i->elemento == elemento) {
            return index;
        }
        index++;
    }
    return -1;
}

// Funções para Hash
void inicializarHash(HashIndiretoLista *hash, int tamanho) {
    hash->tamanho = tamanho;
    hash->tabela = (Lista *)malloc(tamanho * sizeof(Lista));
    for (int i = 0; i < tamanho; i++) {
        inicializarLista(&hash->tabela[i]);
    }
}

int h(int elemento, int tamanho) {
    return elemento % tamanho;
}

int pesquisarHash(HashIndiretoLista *hash, int elemento) {
    int pos = h(elemento, hash->tamanho);
    return pesquisar(&hash->tabela[pos], elemento);
}

void inserirHash(HashIndiretoLista *hash, int elemento) {
    int pos = h(elemento, hash->tamanho);
    inserirInicio(&hash->tabela[pos], elemento);
}

//Buscar informacoes de um Pokemon ==============================
void BuscarPokemon(int id, char* nome) {
    FILE* arquivo = fopen("/tmp/pokemon.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[400];
    Pokemon p;
    fgets(linha, sizeof(linha), arquivo); // Ignora cabe�alho

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char* linhaCopy = linha;
        char* parte;

        parte = strsep(&linhaCopy, ",");
        p.id = atoi(parte);

        if (p.id == id) {
            parte = strsep(&linhaCopy, ",");
            p.generation = atoi(parte);

            parte = strsep(&linhaCopy, ",");
            strcpy(nome, parte);
            break;
        }
    }
    fclose(arquivo);
}

int ASCII_name(const char *nome) {
    int valor = 0;

    for (int i = 0; i < strlen(nome); i++) {
        char ch = nome[i];
        valor += (int)ch;
    }

    return valor;
}

//Main ===========================================================
int main() {

    HashIndiretoLista hash;
    inicializarHash(&hash, 21);

    char num[10];
    int valor;
    bool verdade = true;
    char nome[100];

    while (verdade) {
        scanf("%s", num);
        if (strcmp(num, "FIM") == 0) {
            verdade = false;
        } else {
            valor = atoi(num);
            BuscarPokemon(valor, nome);
            int ascii_valor = ASCII_name(nome);
            inserirHash(&hash, ascii_valor);
        }
    }

    verdade = true;
    char nome_pokemon[20];
    int achei;

    while (verdade) {
        scanf("%s", nome_pokemon);
        if (strcmp(nome_pokemon, "FIM") == 0) {
            verdade = false;
        } else {
            printf("=> %s: ", nome_pokemon);

            int ascii_valor = ASCII_name(nome_pokemon);
            achei = pesquisarHash(&hash, ascii_valor);

            if(achei != -1){
                printf("(Posicao: %d) SIM\n", achei);
            }else{
                printf("NAO\n");
            }
        }
    }
    return 0;
}
