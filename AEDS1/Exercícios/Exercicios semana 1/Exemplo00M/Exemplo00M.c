/* Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico_Extra2: aed1_ed00
  *
  * Matricula: 1453522  Nome: Gabriel_Chaves_Mendes
  * Versao:  1.0                Data: 24/02/2024
  *
  * Dados:
  * - Feito na IDE CodeBlocks
  *
  * Resultados(SAIDAS):
  * -Metodo 1:
        Metodo 1
        Aperte 'Enter' para continuar

  * -Metodo 2:
        Metodo 2
        Aperte 'Enter' para continuar

  * -Metodo 3:
        Metodo 3
        Aperte 'Enter' para continuar

    * -Metodo 4:
        Metodo 4
        Aperte 'Enter' para continuar

  * -Metodo 5:
        Metodo 5
        Aperte 'Enter' para continuar

  * -Metodo 6:
        Metodo 6
        Aperte 'Enter' para continuar

  * -Metodo 7:
        Metodo 7
        Aperte 'Enter' para continuar

  * -Metodo 8:
        Metodo 8
        Aperte 'Enter' para continuar

  * -Metodo 9:
        Metodo 9
        Aperte 'Enter' para continuar

  * -Metodo 10:
        Metodo 10
        Aperte 'Enter' para continuar
**/



#include <stdio.h>

// Protótipos dos métodos
void metodo1();
void metodo2();
void metodo3();
void metodo4();
void metodo5();
void metodo6();
void metodo7();
void metodo8();
void metodo9();
void metodo10();

//Funcao principal
int main() {
    int opcao;

    do {
        printf("Menu:\n"
               "1) Metodo 1;\n"
               "2) Metodo 2;\n"
               "3) Metodo 3;\n"
               "4) Metodo 4;\n"
               "5) Metodo 5;\n"
               "6) Metodo 6;\n"
               "7) Metodo 7;\n"
               "8) Metodo 8;\n"
               "9) Metodo 9;\n"
               "10) Metodo 10;\n"
               "Escolha 0 para sair do programa;\n"
               "Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) { //chamando os metodos em um switch/case
            case 0:
                break;
            case 1:
                metodo1();
                break;
            case 2:
                metodo2();
                break;
            case 3:
                metodo3();
                break;
            case 4:
                metodo4();
                break;
            case 5:
                metodo5();
                break;
            case 6:
                metodo6();
                break;
            case 7:
                metodo7();
                break;
            case 8:
                metodo8();
                break;
            case 9:
                metodo9();
                break;
            case 10:
                metodo10();
                break;
            default:
                printf("Numero invalido\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

// Implementação dos métodos vazios
void metodo1() {
        printf("Metodo 1\n"); // Código do método 1
        getchar(); // Espera pela tecla "Enter"
        printf("Aperte 'Enter' para continuar");
        getchar(); // Espera pela tecla "Enter"
}

void metodo2() {
        printf("Metodo 2\n"); // Código do método 2
        getchar(); // Espera pela tecla "Enter"
        printf("Aperte 'Enter' para continuar");
        getchar(); // Espera pela tecla "Enter"
}

void metodo3() {
        printf("Metodo 3\n"); // Código do método 3
        getchar(); // Espera pela tecla "Enter"
        printf("Aperte 'Enter' para continuar");
        getchar(); // Espera pela tecla "Enter"
}

void metodo4() {
        printf("Metodo 4\n"); // Código do método 4
        getchar(); // Espera pela tecla "Enter"
        printf("Aperte 'Enter' para continuar");
        getchar(); // Espera pela tecla "Enter"
}

void metodo5() {
        printf("Metodo 5\n"); // Código do método 5
        getchar(); // Espera pela tecla "Enter"
        printf("Aperte 'Enter' para continuar");
        getchar(); // Espera pela tecla "Enter"
}

void metodo6() {
        printf("Metodo 6\n"); // Código do método 6
        getchar(); // Espera pela tecla "Enter"
        printf("Aperte 'Enter' para continuar");
        getchar(); // Espera pela tecla "Enter"
}

void metodo7() {
        printf("Metodo 7\n"); // Código do método 7
        getchar(); // Espera pela tecla "Enter"
        printf("Aperte 'Enter' para continuar");
        getchar(); // Espera pela tecla "Enter"
}

void metodo8() {
        printf("Metodo 8\n"); // Código do método 8
        getchar(); // Espera pela tecla "Enter"
        printf("Aperte 'Enter' para continuar");
        getchar(); // Espera pela tecla "Enter"
}

void metodo9() {
        printf("Metodo 9\n"); // Código do método 9
        getchar(); // Espera pela tecla "Enter"
        printf("Aperte 'Enter' para continuar");
        getchar(); // Espera pela tecla "Enter"
}

void metodo10() {
        printf("Metodo 10\n"); // Código do método 10
        getchar(); // Espera pela tecla "Enter"
        printf("Aperte 'Enter' para continuar");
        getchar(); // Espera pela tecla "Enter"
}
