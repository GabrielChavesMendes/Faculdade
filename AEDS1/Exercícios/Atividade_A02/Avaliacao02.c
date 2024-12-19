/**
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico: A02_Avaliacao02
  *
  * Matricula: 1453522  Nome: Gabriel_Chaves_Mendes
  * Versao:  1.0                Data: 11/06/2024
  *
  * Dados:
  * - Feito na IDE CodeBlocks
  *
  * Resultados(SAIDAS):
  * - Questao 1:
        Opcao: 1
        Executando a Questao 1.
        2
        a) -1
        b) 0
        c) 1
        d) 2 (CORRETA)
        e)OUTRA (JUSTIFICATIVA)

  * - Questao 2:
        Opcao: 2
        Executando a Questao 2.
        [bqbubebi]
        a) "aqauaeai"
        b) "auaeaiaj"
        c) "bqbubebi" (CORRETA)
        d) "bubebibj"
        e)OUTRA (JUSTIFICATIVA)

  * - Questao 3:
        Opcao: 3
        Executando a Questao 3.
            Weiss
            Grun
        a) Blau Grun
        b) Weiss Grun (CORRETA)
        c) Blue Weiss
        d) White Weiss
        e)OUTRA (JUSTIFICATIVA)

  * - Questao 4:
        Opcao: 4
        Executando a Questao 4.
        [castanhola]
        [cstanhola]
        [cstnhola]
        [cstnhla]
        a) "cstnhlada" (CORRETA)
        b) "cstnholada"
        c) "cstanholada"
        d) "castanholada"
        e)OUTRA (JUSTIFICATIVA)

  * - Questao 5:
        Opcao: 5
        Executando a Questao 5.
        [parde]
        [pedra]
        a) "perda" "pedra"
        b) "perda" "padre"
        c) "padre" "pedra"
        d) "padre" "perda"
        e)OUTRA (JUSTIFICATIVA) (CORRETA) ("parde" "pedra")

  * - Questao 6:
        Opcao: 6
        Executando a Questao 6.
        Vetor:
        1       2       3       4       5       6       7       8       9
        A       B       C       D       E       F       G       H       I
        J       K       L       M       N       O       P       Q       R
        S       T       U       V       W       X       Y       Z
        Escreva um nome: Gabriel
        7 + 1 + 2 + 9 + 9 + 5 + 3 + 36
        Soma dos digitos: 9

  * - Questao 7:
        Opcao: 7
        Executando a Questao 7.
        O professor que fara aniversario primeiro e o de indice 2

  * - Questao 8:
        Opcao: 8
        Executando a Questao 8.
        No arquivo RESULTADO.TXT:
        7
        83
        19
        65
        91
        21
        89
        3
        75
        99
        58
        42
        34
        12
        78
        46
        56
        30
        24
        68
*/



//BIBLIOTECAS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//----------------QUESTOES FECHADAS----------------//

int q_01(int m, int n, int a[]){

    int x = 0;

    if(0 < m && m < n - 1 && a[m-1] - a[m] > 0 && a[m] - a[m+1] < 0){
        x = 1;
    }

    if(0 < m && m < n)
    if(x >= 0){
        x = x + q_01(m  - 1, n, a);
    }else{
        x = -m;
    }

    return(x);
}

void questao1(void){

    int array[] = {7,9,6,8,3,5};
    int n = 6;

    printf("%d\n", q_01(n-1, n, array));
}


//--------------------------------------------------//

void q_02(char *p, char *q){

    char *r = calloc(strlen(p) * strlen(q) + 1, sizeof(char));

    int k = 0;

    for(int x = 0; x < strlen(p); x++){
        for(int y = 0; y < strlen(q); y++){
            if(x == strlen(p) / 2){
                r[k] = p[x];
                r[k + 1] = q[y];
                k = k + 2;
                if(k > 6){
                    y = strlen(q);
                    x = strlen(p);
                }
            }
        }
    }
    printf("[%s]\n", r);
}

void questao2(void){

    char *p = "goiabada";
    char *q = "queijo";

    q_02(p, q);
}

//--------------------------------------------------//

void q_03(int a, int b, int c, char m[][3][7]){

    for(int x = 0; x < a; x++){
        for(int y = 0; y < b; y++){
            if('A' < m[x][0][0] && m[x][0][0] < 'Z'){
                printf("%8s", m[x][2]);
                y = b;
            }
            printf("\n");
        }
    }
}

void questao3(void){

    char m [][3][7] = {{{"Azul" }, {"Blue" }, {"Blau "}},
                      {{"Branco"}, {"White"}, {"Weiss"}},
                      {{"Verde"}, {"Green"}, {"Grun" }}};

    q_03(3, 3, 7, m);
}

//--------------------------------------------------//

void q_04(char *p){

    int x = 0;

    for(int y = 0; y < strlen(p); y = y + 1){
        if(y < strlen(p) - 1 && p[y] == 'a' || p[y] == 'o'){
            for(int z = y; z < strlen(p); z = z + 1){
                p[z] = p[z+1];
            }
            printf("[%s]\n", p);
        }
    }
}

void questao4(void){

    char p[] = "acastanhola";

    q_04(p);
}

//--------------------------------------------------//

char* q_05(int x, int y, char *p){

    char c = '_';

    if(0 <= x && x < strlen(p) && 0 <= y && y < strlen(p)){
        c = p[x];
        p[x] = p[y];
        p[y] = c;
    }
    return(p);
}

void questao5(void){

    char p[] = "pedra";

    char *q = q_05(1, 4, q_05(2, 3, p));
    printf("[%s]\n", q);

    char *r = q_05(2, 3, q_05(1, 4, p));
    printf("[%s]\n", r);
}

//-----------------QUESTOES ABERTAS-----------------//

void Tabela_Arquivo(void){

   char matriz[3][9] = {
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'},
        {'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'},
        {'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'}
    };

    int vetor[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Vetor:\n");
    for (int i = 0; i < 9; i++) {
        printf("%d\t", vetor[i]);
    }

    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c\t", matriz[i][j]);
        }
        printf("\n");
    }

    char nome[15];
    int soma = 0;

    printf("Escreva um nome: ");

    getchar();
    fgets(nome, sizeof(nome), stdin);

    int j = 0, k = 0;

    for (int i = 0; nome[i] != '\0'; i++) {
        char letra_nome = nome[i];
        if ((letra_nome >= 'A' && letra_nome <= 'Z') || (letra_nome >= 'a' && letra_nome <= 'z')) {
            if (letra_nome >= 'a' && letra_nome <= 'z') {
                letra_nome = letra_nome - 'a' + 'A';
            }
            int encontrou = 0;
            for (int j = 0; j < 3 && !encontrou; j++) {
                for (int k = 0; k < 9 && !encontrou; k++) {
                    if (letra_nome == matriz[j][k]) {
                        soma += vetor[j * 9 + k];
                        printf("%d + ", vetor[j * 9 + k]);
                        encontrou = 1;
                    }
                }
            }
        }
    }


    printf("%d", soma);

    if(soma == 11 || soma == 22){
        printf("\nA soma e: %d", soma);
    }else{
        int soma_digitos = 0;
        while (soma > 0) {
            soma_digitos += soma % 10;
            soma /= 10;
        }
        printf("\nSoma dos digitos: %d\n", soma_digitos);
    }

}

void questao6(void){

    Tabela_Arquivo();
}

//--------------------------------------------------//

struct Datas {

    int dias[3];

    struct Data {

        int dia, mes, ano;

    } data[3];
};

int dias_no_mes(int mes) {

    switch (mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            return 28;

        default:
            return 0;
    }
}

int Dias_Aniversario(struct Data data) {

    int dias_ano = 365;

    int dias_mes_ate_hoje = 0;

    for (int mes = 1; mes < data.mes; ++mes) {
        dias_mes_ate_hoje += dias_no_mes(mes);
    }

    int dias_totais_ate_hoje = (data.ano - 1) * dias_ano + dias_mes_ate_hoje + data.dia;
    int dias_ate_proximo = dias_ano - (dias_totais_ate_hoje % dias_ano);

    return dias_ate_proximo;
}


void questao7(void){

    struct Datas dias_vividos = { { 9876, 8967, 6789 }, { { 1, 1, 1980 }, { 15, 5, 1975 }, { 10, 10, 1985 } } };

    int menor_dias_restantes = Dias_Aniversario(dias_vividos.data[0]);
    int indice_menor = 0;

    for (int i = 1; i < 3; ++i) {
        int dias_restantes = Dias_Aniversario(dias_vividos.data[i]);

        if (dias_restantes < menor_dias_restantes) {
            menor_dias_restantes = dias_restantes;
            indice_menor = i;
        }
    }

    printf("O professor que fara aniversario primeiro e o de indice %d\n", indice_menor);
}

//--------------------------------------------------//

void arquivo(void){

    FILE *arquivo = fopen("DADOS.TXT", "r");
    FILE *arquivo2 = fopen("PAR.TXT", "w");
    FILE *arquivo3 = fopen("IMPAR.TXT", "w");

    int cont = 0;
    int n;

    while(fscanf(arquivo, "%d", &n) == 1){
        if(n % 2 == 0){
            fprintf(arquivo2, "%d\n", n);
        }else if(n % 2 != 0){
            fprintf(arquivo3, "%d\n", n);
        }
    }


    fclose(arquivo);
    fclose(arquivo2);
    fclose(arquivo3);

    FILE *arquivo4= fopen("RESULTADOS.TXT", "w");
    FILE *arquivo5 = fopen("PAR.TXT", "r");
    FILE *arquivo6 = fopen("IMPAR.TXT", "r");

    while(fscanf(arquivo6, "%d", &n) == 1){
        fprintf(arquivo4, "%d\n", n);
    }

    while(fscanf(arquivo5, "%d", &n) == 1){
        fprintf(arquivo4, "%d\n", n);
    }

    fclose(arquivo4);
    fclose(arquivo5);
    fclose(arquivo6);

}

void questao8(void){

    arquivo();
}

//--------------------------------------------------//

int main()
{
    int opcao;
    char linha[60];

   do{
    printf("Menu:\n");
    printf("1- Questao 1;\n"
            "2- Questao 2;\n"
            "3- Questao 3;\n"
            "4- Questao 4;\n"
            "5- Questao 5;\n"
            "6- Questao 6;\n"
            "7- Questao 7;\n"
            "8- Questao 8;\n"
            "Digite 0 para sair do programa\n\n"
            "Opcao: ");
     scanf("%d", &opcao);

    switch(opcao){
        case 0:
            break;

        case 1:
            printf("Executando a Questao 1.\n");
            questao1();
            break;

        case 2:
            printf("Executando a Questao 2.\n");
            questao2();
            break;

        case 3:
            printf("Executando a Questao 3.\n");
            questao3();
            break;

        case 4:
            printf("Executando a Questao 4.\n");
            questao4();
            break;

        case 5:
            printf("Executando a Questao 5.\n");
            questao5();
            break;

        case 6:
            printf("Executando a Questao 6.\n");
            questao6();
            break;

        case 7:
            printf("Executando a Questao 7.\n");
            questao7();
            break;

        case 8:
            printf("Executando a Questao 8.\n");
            questao8();
            break;

        default:
            printf("Opcao invalida. Escolha uma opcao de 1 a 8.\n");
            break;
    }

      printf("\n");
    }while(opcao != 0);

return 0;
}
