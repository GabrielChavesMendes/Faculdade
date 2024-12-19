#include <stdio.h>
#include <stdlib.h>

void Vetor_Aleatorio(void){

    int tam;

    FILE *arquivo = fopen("VETOR.TXT", "w");

    printf("Qual sera o tamanho do vetor: ");
    scanf("%d", &tam);

    int *vetor = malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
        vetor[i] = rand() % 100;
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    free(vetor);
    fclose(arquivo);
}

void Vetor_Crescente(const char *name){

    FILE *arquivo = fopen(name, "r");
    FILE *arquivo2 = fopen("VETOR_CRESCENTE", "w");

    int num;
    int cont = 0;

    while(fscanf(arquivo, "%d", &num) == 1) {
        cont++;
    }
    rewind(arquivo);

    int *vetor = malloc(cont * sizeof(int));
    int i = 0;

    while(fscanf(arquivo, "%d", &num) == 1){
        vetor[i] = num;
        i++;
    }

    fclose(arquivo);

    for(int i = 0; i < cont; i++){
        printf("%d\t", vetor[i]);
    }

    int temp;

    for(int i = 0; i < cont - 1; i++){
        for(int j = 0; j < cont - i - 1; j++){ //VAI DESCONSIDERANDO OS ULTIMOS NUMEROS PORQUE ELE EMPURRA OS MAIORES PARA O FINAL
            if(vetor[j] > vetor[j + 1]){
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    printf("\n");

    for(int i = 0; i < cont; i++){
        printf("%d\t", vetor[i]);
        fprintf(arquivo2, "%d\t", vetor[i]);
    }
    fclose(arquivo2);
    free(vetor);
}

void Vetor_Decrescente(const char *name){

    FILE *arquivo = fopen(name, "r");
    FILE *arquivo2 = fopen("VETOR_DECRESCENTE", "w");

    int num;
    int cont = 0;

    while(fscanf(arquivo, "%d", &num) == 1) {
        cont++;
    }
    rewind(arquivo);

    int *vetor = malloc(cont * sizeof(int));
    int i = 0;

    while(fscanf(arquivo, "%d", &num) == 1){
        vetor[i] = num;
        i++;
    }

    fclose(arquivo);

    for(int i = 0; i < cont; i++){
        printf("%d\t", vetor[i]);
    }

    int temp;

    for(int i = 0; i < cont - 1; i++){
        for(int j = 0; j < cont - i - 1; j++){ //VAI DESCONSIDERANDO OS ULTIMOS NUMEROS PORQUE ELE EMPURRA OS MENORES PARA O FINAL
            if(vetor[j] < vetor[j + 1]){
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    printf("\n");

    for(int i = 0; i < cont; i++){
        printf("%d\t", vetor[i]);
        fprintf(arquivo2, "%d\t", vetor[i]);
    }
    fclose(arquivo2);
    free(vetor);
}


void Matriz_Aleatoria(void){

    int M, N;

    FILE *arquivo = fopen("MATRIZ.TXT", "w");

    printf("Quantas linhas tera a matriz: ");
    scanf("%d", &M);

    printf("Quantas colunas tera a matriz: ");
    scanf("%d", &N);

    int **matriz = (int **)malloc(M * sizeof(int *)); //ALOCAÇÃO DINAMICA DE MATRIZ PARA AS LINHAS

    for (int i = 0; i < M; i++) {
        matriz[i] = (int *)malloc(N * sizeof(int)); //ALOCAÇÃO DINAMICA DE MATRIZ PARA AS COLUNAS
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            matriz[i][j] = rand() % 100;
            printf("%d\t", matriz[i][j]);
            fprintf(arquivo, "%d\t", matriz[i][j]);
        }
        printf("\n");
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    free(matriz);
}

int Linhas(const char *name){

    FILE *arquivo = fopen(name, "r");

    char linha[100];
    int cont = 0;

    while(fgets(linha, sizeof(linha), arquivo)){
        cont++;
    }

    fclose(arquivo);

    return cont;
}

int Colunas(const char *name, int linhas){

    FILE *arquivo = fopen(name, "r");

    int num, cont = 0;

    while(fscanf(arquivo, "%d", &num) == 1){ // = 1 PORQUE TEM UMA VARIAVEL RECEBENDO
        cont++;
    }

    fclose(arquivo);

    return cont / linhas;
}

void Diagonais(const char *name, int linhas, int colunas){

    FILE *arquivo = fopen(name, "r");
    FILE *arquivo2 = fopen("DIAGONAIS.TXT", "w");

    int **matriz = (int **)malloc(linhas * sizeof(int*));

    for(int i = 0; i < linhas; i++){
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }

    //DIAGONAL PRINCIPAL
    printf("DIAGONAL PRINCIPAL:\n");
    fprintf(arquivo2, "DIAGONAL PRINCIPAL:\n");
    for(int i = 0; i < linhas; i++){
        for(int j = i; j <= i; j++){
            printf("%d", matriz[i][j]);
            fprintf(arquivo2, "%d", matriz[i][j]);
        }
        fprintf(arquivo2, "\n");
        printf("\n");
        for(int k = 0; k < i+1; k++){
            printf("\t");
            fprintf(arquivo2, "\t");
        }
    }

    //DIAGONAL SECUNDARIA
    printf("DIAGONAL SECUNDARIA:\n");
    fprintf(arquivo2, "\n\nDIAGONAL SECUNDARIA:\n");
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(i + j == linhas - 1){ //PORQUE A SOMA DOS INDICES NA DIAGONAL SECUNDARIA É IGUAL A 2, OU SEJA, (0,2), (1,1) E (2,0)

                for(int k = 0; k < j; k++){
                    printf("\t");
                    fprintf(arquivo2, "\t");
                }

                printf("%d", matriz[i][j]);
                fprintf(arquivo2, "%d", matriz[i][j]);
            }
        }
        fprintf(arquivo2, "\n");
        printf("\n");

    }
    fclose(arquivo);
    fclose(arquivo2);
    free(matriz);
}

void Acima_Abaixo_Diagona_Principal(const char *name, int linha, int coluna){

    FILE *arquivo = fopen(name, "r");
    FILE *arquivo2 = fopen("ACIMA_ABAIXO_DIAGONAI_PRINCIPAL.TXT", "w");

    int **matriz = (int**)malloc(linha * sizeof(int*));

    for(int i = 0; i < linha; i++){
        matriz[i] = (int*)malloc(linha * sizeof(int));
    }

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }

    //ACIMA DA DIAGONAL PRINCIPAL
    printf("ACIMA DA DIAGONAL PRINCIPAL:\n");
    fprintf(arquivo2, "ACIMA DA DIAGONAL PRINCIPAL:\n");
    for(int i = 0; i < linha; i++){
        for(int j = i; j < coluna; j++){
            printf("%d\t", matriz[i][j]);
            fprintf(arquivo2, "%d\t", matriz[i][j]);
        }
        printf("\n");
        fprintf(arquivo2, "\n");
        for(int k = 0; k < i+1; k++){
            printf("\t");
            fprintf(arquivo2, "\t");
        }
    }

    //ABAIXO DA DIAGONAL PRINCIPAL
    printf("\n\nABAIXO DA MATRIZ PRINCIPAL:\n");
    fprintf(arquivo2, "\n\nABAIXO DA MATRIZ PRINCIPAL:\n");
    for(int i = 0; i < linha; i++){
        for(int j = 0; j <= i; j++){
            printf("%d\t", matriz[i][j]);
            fprintf(arquivo2, "%d\t", matriz[i][j]);
        }
        printf("\n");
        fprintf(arquivo2, "\n");
    }

    fclose(arquivo);
    fclose(arquivo2);
    free(matriz);
}

int main(void) {

    int escolha;

    printf("1- Criar vetor aleatorio e colocar em arquivo");
    printf("\n2- Ordenar vetor(crescente)");
    printf("\n3- Ordenar vetor(decrescente)");
    printf("\n4- Criar matriz aleatoria e colocar em arquivo");
    printf("\n5- Diagona principal e secundaria");
    printf("\n6- Acima e abaixo da Diagona principal");
    printf("\n7- Acima e abaixo da Diagona secundaria");
    printf("\nQual atividade voce deseja: ");
    scanf("%d", &escolha);

    int linhas;
    int colunas;

    switch(escolha){
        case 0:
            break;

        case 1:
            Vetor_Aleatorio();
            break;

        case 2:
            Vetor_Crescente("VETOR.TXT");
            break;

        case 3:
            Vetor_Decrescente("VETOR.TXT");

        case 4:
            Matriz_Aleatoria();

        case 5:
            linhas = Linhas("MATRIZ.TXT");
            colunas = Colunas("MATRIZ.TXT", linhas);
            Diagonais("MATRIZ.TXT", linhas, colunas);

        case 6:
            linhas = Linhas("MATRIZ.TXT");
            colunas = Colunas("MATRIZ.TXT", linhas);
            Acima_Abaixo_Diagona_Principal("MATRIZ.TXT", linhas, colunas);
    }


    return 0;
}
