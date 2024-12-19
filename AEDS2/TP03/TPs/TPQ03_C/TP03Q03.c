#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
typedef struct{
    int valor;
    int ids_removidos[20];
}Armazenar;

//TIPO CELULA ===================================================================
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

//PILHA PROPRIAMENTE DITA =======================================================
Celula* topo; // Sem celula cabeca


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

//METODOS PARA INSERIR NA PILHA
void inserir(int x) {

   Celula* tmp = novaCelula(x); //Cria um ponteiro temporario que insere o valor no topo da pilha
   tmp->prox = topo; //Altera o ponteiro para o novo topo (NULL)
   topo = tmp; //Agora o ponteiro topo apontar para o ultimo valor inserido
   tmp = NULL; //E o ponteiro tmp aponta para NULL
}

int remover() {

   int resp = topo->elemento; //Pega o ultimo elemento da pilha que está sendo apontado para topo
   Celula* tmp = topo; //Tmp apontar para o ultimo valor da pilha
   topo = topo->prox; //Agora topo aponta para o proximo valor
   tmp->prox = NULL; //Tmp passa a valer NULL
   free(tmp); //Libera ponteiro
   tmp = NULL;
   return resp; //Retorna o valor removido
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

//PERCORRE A PILHA INVERSAMENTE DE FORMA RECURSIVA CHAMANDO A FUNÇÃO PARA IMPRIMIR OS POKEMONS DA PILHA
void mostrar(Celula* celula, int *cont) {
    if (celula == NULL) {
        return;
    }
    mostrar(celula->prox, cont);
    BuscarPokemon(celula->elemento, (*cont)++);
}


//IMPRIMI OS POKEMONS REMOVIDOS
void imprimir_removidos(int n, Pokemon *p) {
    printf("(R) %s\n", p->name);
}

//ACHA OS IDS DOS POKEMONS REMOVIDOS QUE FORAM ARMAZENADOS EM UM ARRAY NA STRUCT ARMAZENAR
void Ids_removidos(int tam, Armazenar armazena) {
    Pokemon *p = (Pokemon *)malloc(sizeof(Pokemon));

    char linha[400];
    char name[200];
    char nomes[100][100];
    int id, j = 0;

    FILE* arquivo = fopen("/tmp/pokemon.csv", "r");

    int n = 0;

    fgets(linha, sizeof(linha), arquivo); // Ignora cabe alho

    for (int i = 0; i < tam; i++) {
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

            if (p->id ==  armazena.ids_removidos[i]) {
                imprimir_removidos(n, p);
                n++;
                break;
            }
        }
    }
    fclose(arquivo);
    free(p);
}

int main(void){

    char num[4];
    int valor;
    bool verdade = true;

    while(verdade){
        scanf("%s", num);
        if(strcmp(num, "FIM") == 0){
            verdade = false;
        }else{
            valor = atoi(num);
            inserir(valor);
        }
    }

    Armazenar armazena;

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
            inserir(entrada);

        }else if(strcmp(comandos, "R") == 0){
            armazena.ids_removidos[j] = remover();
            j++;
        }
    }

    Ids_removidos(j, armazena);

    int cont = 0;
    mostrar(topo, &cont);

    return 0;
}
