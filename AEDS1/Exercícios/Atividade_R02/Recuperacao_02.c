/**
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico: R02_Recuperacao02
  *
  * Matricula: 1453522  Nome: Gabriel_Chaves_Mendes
  * Versao:  1.0                Data: 16/06/2024
  *
  * Dados:
  * - Feito na IDE CodeBlocks
  *
  * Resultados(SAIDAS):
  * - Exercício 1:
        Opcao: 1
        Executando o Exercicio 1.
        Quantos numeros voce quer na cadeia: 5
        41      67      34      0       69
        A cadeia nao esta em ordem decrescente

        Cadeia em ordem decrescnete:
        69      67      41      34      0

  * - Exercício 2:
        Opcao: 2
        Executando o Exercicio 2.
        69      67      41      34      0
        Cadeia invertida:
        0       34      41      67      69
        No arquivo:
        0	34	41	67	69

  * - Exercício 3:
        Opcao: 3
        Executando o Exercicio 3.
        69      67      41      34      0
        A mediana e: 41

  * - Exercício 4:
        Opcao: 4
        Executando o Exercicio 4.
        41      65      35      0       70
        41      67      34      0       69
        41      0
        No arquivo:
        41	0

  * - Exercício 5:
        Opcao: 5
        Executando o Exercicio 5.
        1       0       0       1       1
        19

  * - Exercício 6:
        Opcao: 6
        Executando o Exercicio 6.
        41      67      34      0
        69      24      78      58
        62      64      5       45
        81      27      61      91
        Linhas: 4
        Colunas: 4

        1       2       0       0
        3       4       5       0
        0       6       7       8
        0       0       9       10

  * - Exercício 7:
        Opcao: 7
        Executando o Exercicio 7.
        Linhas: 4
        Colunas: 4

        0       0       10      9
        0       8       7       6
        5       4       3       2
        0       0       0       0

  * - Exercício 8:
        Opcao: 8
        Executando o Exercicio 8.
        1       1       1       1
        1       2       4       8
        1       3       9       27
        1       4       16      64

  * - Exercício 9:
        Opcao: 9
        Executando o Exercicio 9.
        1       1       1       1
        1       2       3       4
        1       4       9       16
        1       8       27      64

  * - Exercício 10:
        Opcao: 10
        Executando o Exercicio 10.
        A soma dos valores do preco do arroz e: 73.40
        A media dos valores e: 14.68

        O supermercado 1 (Supermercado BH) esta abaixo da media
        O supermercado 3 (Supermercado Apoio) esta abaixo da media
        O supermercado 5 (Supermercado Carreful) esta abaixo da media
*/



//BIBLIOTECAS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


//--------METODOS AUXILIARES--------//



//------------------METODOS-----------------------//

void Arquivo_Vetor(void){

    FILE *arquivo = fopen("DADOS.TXT", "w");
    int n, cont = 0;
    int temp;

    printf("Quantos numeros voce quer na cadeia: ");
    scanf("%d", &n);

    int *cadeia = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        cadeia[i] = rand() % 100;
        printf("%d\t", cadeia[i]);
        fprintf(arquivo, "%d\t", cadeia[i]);
        if(cadeia[i] > cadeia[i+1]){
            cont++;
        }
    }

    FILE *arquivo2 = fopen("DECRESCENTE.TXT", "w");

    if(cont == n - 1){
        printf("\nA cadeia esta em ordem decrescente\n");
    }else{
        printf("\nA cadeia nao esta em ordem decrescente\n");

        cont = 0;
        while(cont != 5){
            for(int i = 0; i < n; i++){
                if(cadeia[i] < cadeia[i+1]){
                    temp = cadeia[i];
                    cadeia[i] = cadeia[i+1];
                    cadeia[i+1] = temp;
                }
            }
            cont++;
        }

        printf("\nCadeia em ordem decrescnete:\n");
        for(int i = 0; i < n; i++){
            printf("%d\t", cadeia[i]);
            fprintf(arquivo2, "%d\t", cadeia[i]);
        }
    }

    fclose(arquivo);
    fclose(arquivo2);
    free(cadeia);
}

void exercicios1(void){

    Arquivo_Vetor();
}

//--------------------------------------------------//

void Inverter(int *cadeia, int cont){

    FILE *arquivo2 = fopen("IVERTIDOS.TXT", "w");

    printf("\nCadeia invertida:\n");
    for(int i = cont-1; i >= 0; i--){
        printf("%d\t", cadeia[i]);
        fprintf(arquivo2, "%d\t", cadeia[i]);
    }

    fclose(arquivo2);
}

void exercicios2(void){

    FILE *arquivo = fopen("DECRESCENTE.TXT", "r");
    int n, cont = 0;
    int temp;


    while(fscanf(arquivo, "%d", &n) == 1){
        cont++;
    }

    int *cadeia = malloc(cont * sizeof(int));

    rewind(arquivo);

    for(int i = 0; i < cont; i++){
        fscanf(arquivo, "%d", &n);
        cadeia[i] = n;
        printf("%d\t", cadeia[i]);
    }

    Inverter(cadeia, cont);

    free(cadeia);
    fclose(arquivo);
}

//--------------------------------------------------//

void Mediana(int *cadeia, int cont){

    int mediana;

    if(cont % 2 != 0){
        for(int i = 0; i < cont/2 + 1; i++){
            if(i == cont/2){
                mediana = cadeia[i];
                printf("\nA mediana e: %d", mediana);
            }
        }
    }else{
        for(int i = 0; i < cont/2; i++){
            if(i == cont/2){
                mediana = (cadeia[i] + cadeia[i+1]) / 2;
                printf("\nA mediana e: %d", mediana);
            }
        }
    }
}

void exercicios3(void){

    FILE *arquivo = fopen("DECRESCENTE.TXT", "r");
    int n, cont = 0;
    int temp;


    while(fscanf(arquivo, "%d", &n) == 1){
        cont++;
    }

    int *cadeia = malloc(cont * sizeof(int));

    rewind(arquivo);

    for(int i = 0; i < cont; i++){
        fscanf(arquivo, "%d", &n);
        cadeia[i] = n;
        printf("%d\t", cadeia[i]);
    }

    Mediana(cadeia, cont);

    free(cadeia);
    fclose(arquivo);
}

//--------------------------------------------------//

void Dados_Novo(void){

    FILE *arquivo = fopen("DADOS2.TXT", "r");
    int n, cont = 0;
    int temp;

    while(fscanf(arquivo, "%d", &n) == 1){
        cont++;
    }

    int *cadeia = malloc(cont * sizeof(int));

    rewind(arquivo);

    for(int i = 0; i < cont; i++){
        fscanf(arquivo, "%d", &n);
        cadeia[i] = n;
        printf("%d\t", cadeia[i]);
    }

    FILE *arquivo2 = fopen("DADOS.TXT", "r");

    cont = 0;

    while(fscanf(arquivo2, "%d", &n) == 1){
        cont++;
    }

    int *cadeia2 = malloc(cont * sizeof(int));

    rewind(arquivo2);

    printf("\n");

    for(int i = 0; i < cont; i++){
        fscanf(arquivo2, "%d", &n);
        cadeia2[i] = n;
        printf("%d\t", cadeia2[i]);
    }

    FILE *arquivo3 = fopen("FILTRADOS.TXT", "w");

    int tam = cont;
    cont = 0;

    for(int i = 0; i < tam; i++){
        if(cadeia[i] == cadeia2[i]){
            cont++;
        }
    }

    int *cadeia3 = malloc(cont * sizeof(int));

    printf("\n");

    for(int i = 0; i < tam; i++){
        if(cadeia[i] == cadeia2[i]){
            cadeia3[i] = cadeia[i];
            printf("%d\t", cadeia3[i]);
            fprintf(arquivo3, "%d\t", cadeia3[i]);
        }
    }


    fclose(arquivo);
    free(cadeia);
    fclose(arquivo2);
    free(cadeia2);
    fclose(arquivo3);
    free(cadeia3);
}


void exercicios4(void){

    Dados_Novo();

}

//--------------------------------------------------//

void Binario(void){

  FILE *arquivo = fopen("BINARIO.TXT", "r");

  int n, soma;
  int cont = 0;
  int potencia = 0;

  while(fscanf(arquivo, "%d\n", &n) == 1){
    cont++;
  }

  rewind(arquivo);

  int *cadeia = malloc(cont * sizeof(int));

  for(int i = 0; i < cont; i++){
    fscanf(arquivo, "%d", &n);
    cadeia[i] = n;
    printf("%d\t", cadeia[i]);
  }

  for(int i = cont-1; i >= 0; i--){
      soma = soma + cadeia[i] * pow(2, potencia);
      potencia++;
  }

  printf("\n%d", soma);

  fclose(arquivo);
}

void exercicios5(void){

    Binario();
}

//--------------------------------------------------//

void Matriz(void){

    FILE *arquivo = fopen("MATRIZ1.TXT", "w");

    int matriz[4][4];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            matriz[i][j] = rand() % 100;
            fprintf(arquivo, "%d\t", matriz[i][j]);
            printf("%d\t", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
        printf("\n");
    }

    fclose(arquivo);

    FILE *arquivo2 = fopen("MATRIZ1.TXT", "r");

    char linha[100];
    int cont = 0;
    int n;

    while(fgets(linha, sizeof(linha), arquivo2)){
        cont++;
    }
    printf("Linhas: %d\n", cont);

    int cont2 = 0;
    rewind(arquivo2);

    while(fscanf(arquivo2, "%d", &n) == 1){
        cont2++;
    }

    printf("Colunas: %d", cont2/cont);

    fclose(arquivo2);
}

void MatrizPadrao(void){

    FILE *arquivo = fopen("MATRIZ2.TXT", "w");

    int matriz[4][4];
    int num = 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                matriz[i][j] = num;
                num = num + 1;
            } else if (i == j - 1) {
                matriz[i][j] = num;
                num = num + 1;
            } else if (j == i - 1) {
                matriz[i][j] = num;
                num = num + 1;
            } else {
                matriz[i][j] = 0;
            }
            printf("%d\t", matriz[i][j]);
            fprintf(arquivo, "%d\t", matriz[i][j]);
        }
        printf("\n");
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

void exercicios6(void){

    Matriz();

    printf("\n\n");

    MatrizPadrao();

}

//--------------------------------------------------//

int Linhas(const char *name){

    FILE *arquivo = fopen(name, "r");

    char linha[100];
    int cont = 0;
    int n;

    while(fgets(linha, sizeof(linha), arquivo)){
        cont++;
    }
    printf("Linhas: %d\n", cont);

    fclose(arquivo);

    return cont;
}

int Colunas(const char *name, int linhas){

    FILE *arquivo = fopen(name, "r");

    int cont2 = 0;
    int n;

    while(fscanf(arquivo, "%d", &n) == 1){
        cont2++;
    }

    fclose(arquivo);

    printf("Colunas: %d", cont2/linhas);
}

void MatrizPadrao_Secundaria(void){

    FILE *arquivo = fopen("MATRIZ2_2.TXT", "w");

    int matriz[4][4];
    int num = 10;

   for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 0 && j >= 2) {
                matriz[i][j] = num;
                num = num - 1;
            } else if (i == 1 && j >= 1) {
                matriz[i][j] = num;
                num = num - 1;
            } else if (i == 2 && j >= 0) {
                matriz[i][j] = num;
                num = num - 1;
            } else {
                matriz[i][j] = 0;
            }
            printf("%d\t", matriz[i][j]);
            fprintf(arquivo, "%d\t", matriz[i][j]);
        }
        printf("\n");
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

void exercicios7(void){

    int linhas = Linhas("MATRIZ1.TXT");
    int colunas = Colunas("MATRIZ1.TXT", linhas);

    printf("\n\n");

    MatrizPadrao_Secundaria();
}

//--------------------------------------------------//

void Matriz_Linha_Potencia(void){

    int matriz[4][4];

    FILE *arquivo = fopen("MATRIZ3.TXT", "w");

    int pot = 0;
    int num = 1;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            matriz[i][j] = pow(num, pot);
            pot++;
            printf("%d\t", matriz[i][j]);
            fprintf(arquivo, "%d\t", matriz[i][j]);
        }
        pot = 0;
        num++;
        printf("\n");
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
}

void exercicios8(void){

    Matriz_Linha_Potencia();
}

//--------------------------------------------------//

void Matriz_Coluna_Potencia(void){

    int matriz[4][4];

    FILE *arquivo = fopen("MATRIZ4.TXT", "w");

    int pot = 0;
    int num = 1;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            matriz[i][j] = pow(num, pot);
            pot++;
        }
        pot = 0;
        num++;
    }

    for(int j = 0; j < 4; j++){
        for(int i = 0; i < 4; i++){
            printf("%d\t", matriz[i][j]);
            fprintf(arquivo, "%d\t", matriz[i][j]);
        }
        printf("\n");
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

void exercicios9(void){

    Matriz_Coluna_Potencia();
}

//--------------------------------------------------//

typedef struct{

    int N;
    char nome[100];
    int codigo;
    double valores;
    double soma;
    double media;
    char linha[10];

}Supermercado;

void Supermercados(const char *name, Supermercado *mercado){

    FILE *arquivo = fopen(name, "r");
    double soma_total = 0.0;

    fscanf(arquivo, "%d", &mercado->N); // LE QUANTIDADE DE SUPERMERCADOS

    fgetc(arquivo); //LE LINHA NOVA

    for(int i = 0; i < mercado->N; i++){

        fscanf(arquivo, "%d", &mercado[i].codigo); //LE O CODIGO DO SUPERMERCADO
        fgetc(arquivo); //LE LINHA NOVA

        fgets(mercado[i].nome, sizeof(mercado[i].nome), arquivo); //LE O NOME DO SUPERMERCADO
        mercado[i].nome[strcspn(mercado[i].nome, "\n")] = '\0'; //SUBSTITUI /n

        fgets(mercado[i].linha, sizeof(mercado[i].linha), arquivo); //LE O NOME DO PRODUTO

        fscanf(arquivo, "%lf", &mercado[i].valores); //GUARDA OS VALORES DOS PRODUTOS
        fgetc(arquivo); //LE LINHA NOVA

        soma_total = soma_total + mercado[i].valores; //SOMA OS VALORES
    }

    mercado->soma = soma_total; //ATRIBUI A VARIAVEL DA STRUCT
    printf("A soma dos valores do preco do arroz e: %.2lf\n", mercado->soma);

    mercado->media = soma_total / mercado->N; //ACHA MEDIA DOS VALORES
    printf("A media dos valores e: %.2lf", mercado->media);

    int *super = malloc(mercado->N * sizeof(int));

    printf("\n\n");

    for(int i = 0; i < mercado->N; i++){

        fscanf(arquivo, "%d", &mercado[i].codigo);
        fgetc(arquivo);

        fgets(mercado[i].nome, sizeof(mercado[i].nome), arquivo);
        mercado[i].nome[strcspn(mercado[i].nome, "\n")] = '\0';

        fgets(mercado[i].linha, sizeof(mercado[i].linha), arquivo);

        fscanf(arquivo, "%lf", &mercado[i].valores);
        fgetc(arquivo);

        if(mercado[i].valores < mercado->media){ //SE O VALOR DO PRODUTO FOR MENOR QUE A MEDIA
            super[i] = i+1; //COLOCA NO VETOR
            printf("O supermercado %d (%s) esta abaixo da media\n", super[i], mercado[i].nome);
        }
    }

    fclose(arquivo);
    free(super);
}

void exercicios10(void){

    Supermercado mercado[10];

    Supermercados("DADOS3.TXT", mercado);
}

//--------------------------------------------------//

int main()
{
    int opcao;
    char linha[60];

   do{
    printf("Menu:\n");
     printf("1- Metodo 1;\n"
            "2- Metodo 2;\n"
            "3- Metodo 3;\n"
            "4- Metodo 4;\n"
            "5- Metodo 5;\n"
            "6- Metodo 6;\n"
            "7- Metodo 7;\n"
            "8- Metodo 8;\n"
            "9- Metodo 9;\n"
            "10- Metodo 10;\n"
            "Digite 0 para sair do programa\n\n"
            "Opcao: ");
     scanf("%d", &opcao);

    switch(opcao){
        case 0:
            break;

        case 1:
            printf("Executando o Exercicio 1.\n");
            exercicios1();
            break;

        case 2:
            printf("Executando o Exercicio 2.\n");
            exercicios2();
            break;

        case 3:
            printf("Executando o Exercicio 3.\n");
            exercicios3();
            break;

        case 4:
            printf("Executando o Exercicio 4.\n");
            exercicios4();
            break;

        case 5:
            printf("Executando o Exercicio 5.\n");
            exercicios5();
            break;

        case 6:
            printf("Executando o Exercicio 6.\n");
            exercicios6();
            break;

        case 7:
            printf("Executando o Exercicio 7.\n");
            exercicios7();
            break;

        case 8:
            printf("Executando o Exercicio 8.\n");
            exercicios8();
            break;

        case 9:
            printf("Executando o Exercicio 9.\n");
            exercicios9();
            break;

        case 10:
            printf("Executando o Exercicio 10.\n");
            exercicios10();
            break;

        default:
            printf("Opcao invalida. Escolha uma opcao de 1 a 10.\n");
            break;
    }

      printf("\n");
    }while(opcao != 0);

return 0;
}
