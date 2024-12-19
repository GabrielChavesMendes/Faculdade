#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// STRUCT PARA ARMAZENAR POKEMON ================================================
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

// STRUCT DO NO DA ARVORE AVL ==================================================
typedef struct No {
    char elemento[100];
    struct No *esq, *dir;
    int nivel;
} No;

//Criar um novo no ================================================
No* criarNo(char* elemento) {
    No* novo = (No*) malloc(sizeof(No));
    strcpy(novo->elemento, elemento);
    novo->esq = NULL;
    novo->dir = NULL;
    novo->nivel = 1;
    return novo;
}

//Obter o nivel de um no ==========================================
int getNivel(No* no) {
    return (no == NULL) ? 0 : no->nivel;
}

//Atualizar o nivel de um no ======================================
void setNivel(No* no) {
    if (no != NULL) {
        no->nivel = 1 + (getNivel(no->esq) > getNivel(no->dir) ? getNivel(no->esq) : getNivel(no->dir));
    }
}

//Rotacionar um no a direita ======================================
No* rotacionarDir(No* no) {
    No* noEsq = no->esq;
    No* noEsqDir = noEsq->dir;

    noEsq->dir = no;
    no->esq = noEsqDir;

    setNivel(no);
    setNivel(noEsq);

    return noEsq;
}

//Rotacionar um no a esquerda =====================================
No* rotacionarEsq(No* no) {
    No* noDir = no->dir;
    No* noDirEsq = noDir->esq;

    noDir->esq = no;
    no->dir = noDirEsq;

    setNivel(no);
    setNivel(noDir);

    return noDir;
}

//Balancear um nO ================================================
No* balancear(No* no) {
    if (no != NULL) {
        int fator = getNivel(no->dir) - getNivel(no->esq);

        if (abs(fator) <= 1) {
            setNivel(no);
        } else if (fator == 2) {
            if (getNivel(no->dir->esq) > getNivel(no->dir->dir)) {
                no->dir = rotacionarDir(no->dir);
            }
            no = rotacionarEsq(no);
        } else if (fator == -2) {
            if (getNivel(no->esq->dir) > getNivel(no->esq->esq)) {
                no->esq = rotacionarEsq(no->esq);
            }
            no = rotacionarDir(no);
        }
    }
    return no;
}

//Inserir um elemento na arvore AVL ==============================
No* inserir(No* no, char* elemento) {
    if (no == NULL) {
        no = criarNo(elemento);
    } else if (strcmp(elemento, no->elemento) < 0) {
        no->esq = inserir(no->esq, elemento);
    } else if (strcmp(elemento, no->elemento) > 0) {
        no->dir = inserir(no->dir, elemento);
    } else {
        printf("Erro ao inserir: elemento duplicado!\n");
    }
    return balancear(no);
}

//Caminhar na arvore em ordem central ============================
void caminharCentral(No* no) {
    if (no != NULL) {
        caminharCentral(no->esq);
        printf("%s ", no->elemento);
        caminharCentral(no->dir);
    }
}

//P um elemento ================================
bool pesquisar(No* no, char* elemento) {
    if (no == NULL) {
        return false; // Elemento não encontrado
    }
    int cmp = strcmp(elemento, no->elemento);
    if (cmp == 0) {
        return true; // Elemento encontrado
    } else if (cmp < 0) {
        printf("esq ");
        return pesquisar(no->esq, elemento);
    } else {
        printf("dir ");
        return pesquisar(no->dir, elemento);
    }
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
    fgets(linha, sizeof(linha), arquivo); // Ignora cabeçalho

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

//Main ===========================================================
int main() {
    No* raiz = NULL;

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
            raiz = inserir(raiz, nome);
        }
    }

    verdade = true;
    char nome_pokemon[20];
    bool achei;

    while (verdade) {
        scanf("%s", nome_pokemon);
        if (strcmp(nome_pokemon, "FIM") == 0) {
            verdade = false;
        } else {
            printf("%s\n", nome_pokemon);
            printf("raiz ");
            achei = pesquisar(raiz, nome_pokemon);
            if(achei == true){
                printf("SIM\n");
            }else{
                printf("NAO\n");
            }
        }
    }
    return 0;
}
