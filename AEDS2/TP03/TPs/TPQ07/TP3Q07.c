#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//STRUCT PARA ARMAZENAR POKEMON ================================================
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

//STRUCT PARA ARMAZENAR INFORMAÇÕES =============================================
typedef struct {
    int valor;
    int id_removidos;
    int cont_removidos;
    int soma;
} Armazenar;

//TIPO CELULA ===================================================================
typedef struct Celula {
    int elemento;         // Elemento inserido na celula.
    struct Celula* prox;  // Aponta a celula prox.
} Celula;

Celula* novaCelula(int elemento) {
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->elemento = elemento;
    nova->prox = NULL;
    return nova;
}

// FILA CIRCULAR ===============================================================
Celula* primeiro;
Celula* ultimo;
int tamanho = 0;
const int MAX_SIZE = 5;  // Tamanho máximo da fila circular

//Inicializa a fila com a célula cabeça.
void inicializarFila() {
    primeiro = novaCelula(-1);  // Célula cabeça
    ultimo = primeiro;
}

//Remove elemento da fila circular
int remover() {
    if (tamanho == 0) {
        printf("Erro ao remover: Fila vazia!\n");
        exit(1);
    }
    Celula* tmp = primeiro->prox;
    int resp = tmp->elemento;
    primeiro->prox = tmp->prox;
    free(tmp);
    tamanho--;

    if (tamanho == 0) {
        ultimo = primeiro;
    }

    return resp;
}

//Insere elemento na fila circula
int inserir(int x) {
    int removido = -1;
    if (tamanho == MAX_SIZE) {
        removido = remover();  // Remove o mais antigo se a fila estiver cheia
    }
    ultimo->prox = novaCelula(x);
    ultimo = ultimo->prox;
    ultimo->prox = primeiro->prox;  // Ligação circular
    tamanho++;

    return removido;
}

//IMPRIMI OS POKEMONS REMOVIDOS
void imprimir_removidos(int n, Pokemon *p) {
    printf("(R) %s\n", p->name);
}

//ACHA OS IDS DOS POKEMONS REMOVIDOS QUE FORAM ARMAZENADOS EM UM ARRAY NA STRUCT ARMAZENAR
void Ids_removidos(Armazenar armazena) {
    Pokemon *p = (Pokemon *)malloc(sizeof(Pokemon));

    char linha[400];
    char name[200];
    char nomes[100][100];
    int id, j = 0;

    FILE* arquivo = fopen("/tmp/pokemon.csv", "r");

    int n = 0;

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

        if (p->id ==  armazena.id_removidos) {
            imprimir_removidos(n, p);
            n++;
            break;
        }
    }

    fclose(arquivo);
    free(p);
}

//FUNÇÕES PARA IMPRIMIR POKEMONS

 void imprimir_media(int media) {
    printf("M\u00E9dia: %d\n", media);
}

//PEGA AS INFORMAÇÕES DE CADA POKEMON PARA IMPRIMIR A MEDIA DOS INSERIDOS
 void Media_pokemon(int id, int removido) {

     if(removido != -1){
        FILE* arquivo = fopen("/tmp/pokemon.csv", "r");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        char linha[400];
        Pokemon p;
        Armazenar armazena;
        fgets(linha, sizeof(linha), arquivo); // Ignora cabeçalho

        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            char* linhaCopy = linha;
            char* parte;

            parte = strsep(&linhaCopy, ",");
            p.id = atoi(parte);

            if (p.id == removido) {
                parte = strsep(&linhaCopy, ",");
                p.generation = atoi(parte);

                parte = strsep(&linhaCopy, ",");
                strcpy(p.name, parte);

                parte = strsep(&linhaCopy, ",");
                strcpy(p.description, parte);

                parte = strsep(&linhaCopy, ",");
                strcpy(p.types, parte);

                parte = strsep(&linhaCopy, "\"");
                if (parte != NULL && strlen(parte) > 0 && strcmp(parte, ",") != 0) {
                    parte[strlen(parte) - 1] = '\0';
                    strcat(p.types, "', '");
                    strcat(p.types, parte);
                }

                parte = strsep(&linhaCopy, "\"");
                strcpy(p.abilities, parte);

                while (*linhaCopy != '\0') {
                    parte = strsep(&linhaCopy, ",");
                    parte = strsep(&linhaCopy, ",");
                    if (parte) {
                        p.weight = atof(parte);
                    }
                    parte = strsep(&linhaCopy, ",");
                    if (parte) {
                        p.height = atof(parte);
                    }
                    break;
                }

                parte = strsep(&linhaCopy, ",");
                p.captureRate = atoi(parte);

                armazena.soma = armazena.soma - p.captureRate;

                break;
            }
        }
        fclose(arquivo);

        arquivo = fopen("/tmp/pokemon.csv", "r");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

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
                strcpy(p.name, parte);

                parte = strsep(&linhaCopy, ",");
                strcpy(p.description, parte);

                parte = strsep(&linhaCopy, ",");
                strcpy(p.types, parte);

                parte = strsep(&linhaCopy, "\"");
                if (parte != NULL && strlen(parte) > 0 && strcmp(parte, ",") != 0) {
                    parte[strlen(parte) - 1] = '\0';
                    strcat(p.types, "', '");
                    strcat(p.types, parte);
                }

                parte = strsep(&linhaCopy, "\"");
                strcpy(p.abilities, parte);

                while (*linhaCopy != '\0') {
                    parte = strsep(&linhaCopy, ",");
                    parte = strsep(&linhaCopy, ",");
                    if (parte) {
                        p.weight = atof(parte);
                    }
                    parte = strsep(&linhaCopy, ",");
                    if (parte) {
                        p.height = atof(parte);
                    }
                    break;
                }

                parte = strsep(&linhaCopy, ",");
                p.captureRate = atoi(parte);

                armazena.soma = armazena.soma + p.captureRate;
                int media = (int) round((double) armazena.soma / 5);

                imprimir_media(media);
                break;
            }
        }
        fclose(arquivo);

     }else{
        FILE* arquivo = fopen("/tmp/pokemon.csv", "r");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        char linha[400];
        Pokemon p;
        Armazenar armazena;
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
                strcpy(p.name, parte);

                parte = strsep(&linhaCopy, ",");
                strcpy(p.description, parte);

                parte = strsep(&linhaCopy, ",");
                strcpy(p.types, parte);

                parte = strsep(&linhaCopy, "\"");
                if (parte != NULL && strlen(parte) > 0 && strcmp(parte, ",") != 0) {
                    parte[strlen(parte) - 1] = '\0';
                    strcat(p.types, "', '");
                    strcat(p.types, parte);
                }

                parte = strsep(&linhaCopy, "\"");
                strcpy(p.abilities, parte);

                while (*linhaCopy != '\0') {
                    parte = strsep(&linhaCopy, ",");
                    parte = strsep(&linhaCopy, ",");
                    if (parte) {
                        p.weight = atof(parte);
                    }
                    parte = strsep(&linhaCopy, ",");
                    if (parte) {
                        p.height = atof(parte);
                    }
                    break;
                }

                parte = strsep(&linhaCopy, ",");
                p.captureRate = atoi(parte);

                armazena.soma = armazena.soma + p.captureRate;
                armazena.cont_removidos++;
                int media = (int) round((double) armazena.soma / armazena.cont_removidos);

                imprimir_media(media);
                break;
            }
        }
        fclose(arquivo);
     }
}

//FUNÇÕES PARA IMPRIMIR POKEMONS

 void imprimir(int n, Pokemon *p) {
    printf("[%d] [#%d -> %s: %s - ['%s'] - %s - %.1fkg - %.1fm - %d%% - %s - %d gen] - %s\n", n,
           p->id, p->name, p->description, p->types, p->abilities, p->weight, p->height, p->captureRate, p->isLegendary ? "true" : "false", p->generation, p->captureDate);
}

//PEGA AS INFORMAÇÕES DE CADA POKEMON ACHADO E ARMAZENA NA STRUCT POKEMON
 void BuscarPokemon(int id, int n) {

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
            strcpy(p.name, parte);

            parte = strsep(&linhaCopy, ",");
            strcpy(p.description, parte);

            parte = strsep(&linhaCopy, ",");
            strcpy(p.types, parte);

            parte = strsep(&linhaCopy, "\"");
            if (parte != NULL && strlen(parte) > 0 && strcmp(parte, ",") != 0) {
                parte[strlen(parte) - 1] = '\0';
                strcat(p.types, "', '");
                strcat(p.types, parte);
            }

            parte = strsep(&linhaCopy, "\"");
            strcpy(p.abilities, parte);

            while (*linhaCopy != '\0') {
                parte = strsep(&linhaCopy, ",");
                parte = strsep(&linhaCopy, ",");
                if (parte) {
                    p.weight = atof(parte);
                }
                parte = strsep(&linhaCopy, ",");
                if (parte) {
                    p.height = atof(parte);
                }
                break;
            }

            parte = strsep(&linhaCopy, ",");
            p.captureRate = atoi(parte);

            parte = strsep(&linhaCopy, ",");
            int lendario = atoi(parte);
            p.isLegendary = (lendario == 1);

            parte = strsep(&linhaCopy, "\n");
            strcpy(p.captureDate, parte);

            imprimir(n, &p);
            break;
        }
    }
    fclose(arquivo);
}

//Mostra os elementos separados por espacos.
void mostrar(int *cont) {
    if (tamanho == 0) {
        printf("Fila vazia!\n");
        return;
    }

    Celula* i = primeiro->prox;
    for (int count = 0; count < tamanho; count++) {
        BuscarPokemon(i->elemento, (*cont)++);
        i = i->prox;
    }
}

int main(void){
    inicializarFila();

    char num[4];
    int valor;
    bool verdade = true;
    int removido;

    Armazenar armazena;

    armazena.cont_removidos = 0;

    while(verdade){
        scanf("%s", num);
        if(strcmp(num, "FIM") == 0){
            verdade = false;
        }else{
            valor = atoi(num);
            removido = inserir(valor);

            Media_pokemon(valor, removido);

        }
    }

    int quant;
    scanf("%d", &quant);

    armazena.valor = quant;

    char comandos[3];
    int entrada;
    int j = 0;

    for(int i = 0; i < armazena.valor; i++){
        scanf("%s", comandos);

        if(strcmp(comandos, "I") == 0){
            scanf("%d", &entrada);
            removido = inserir(entrada);
            Media_pokemon(entrada, removido);

        }else if(strcmp(comandos, "R") == 0){
            armazena.cont_removidos--;
            armazena.id_removidos = remover();
            Ids_removidos(armazena);
            j++;
        }
    }

    int cont = 0;
    printf("\n");
    mostrar(&cont);

    return 0;
}
