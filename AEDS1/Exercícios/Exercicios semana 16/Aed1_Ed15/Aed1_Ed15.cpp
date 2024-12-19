/**
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico: ed14_+_EXTRAS
  *
  * Matricula: 1453522  Nome: Gabriel_Chaves_Mendes
  * Versao:  1.0                Data: 08/06/2024
  *
  * Dados:
  * - Feito na IDE CodeBlocks
  *
  * Resultados(SAIDAS):
    * - Exercício 1511:
        Opcao:
        1
        Executando o Metodo 1511.
        Escreva uma palavra: MG_T
        Agora o que deseja adicionar: V
        Cadeia antes de adicionar o caractere: MG_T
        Cadeia apos adicionar caractere final: MG_TV

    * - Exercício 1512:
        Opcao:
        2
        Executando o Metodo 1512.
        Escreva uma palavra: Puc_Minas
        Cadeia antes de remover o caractere do final: Puc_Minas
        Cadeia apos remover o caractere no final: Puc_Mina

    * - Exercício 1513:
        Opcao:
        3
        Executando o Metodo 1513.
        Escreva uma palavra: UC_Minas
        Agora o que deseja adicionar: P
        Cadeia antes de adicionar o caractere no inicio: UC_Minas
        Cadeia apos adicionar um caractere no inicio: PUC_Minas

    * - Exercício 1514:
        Opcao:
        4
        Executando o Metodo 1514.
        Escreva uma palavra: PUC_Minas
        Cadeia original: PUC_Minas
        Cadeia apos remover caractere no inicio: UC_Minas

    * - Exercício 1515:
        Opcao:
        5
        Executando o Metodo 1515.
        Escreva uma palavra: PUC_inas
        Agora o que deseja adicionar: M
        Cadeia apos inserir caractere: PUC_Minas

    * - Exercício 1516:
        Opcao:
        6
        Executando o Metodo 1516.
        Escreva uma palavra: PUC_Minas
        Cadeia apos remover: PUC_inas

    * - Exercício 1517:
        Opcao:
        7
        Executando o Metodo 1517.
        Escreva uma palavra: PucMinas
        Agora o que deseja adicionar: _
        Em qual posicao quer adicionar o caracter: 3
        Cadeia original: PucMinas
        Cadeia apos inserir o caractere: Puc_Minas

    * - Exercício 1518:
        Opcao:
        8
        Executando o Metodo 1518.
        Escreva uma palavra: Puc_Minas
        Em qual posicao quer remover o caracter: 3
        Cadeia original: Puc_Minas
        Cadeia apos remover: PucMinas

    * - Exercício 1519:
        Opcao:
        9
        Executando o Metodo 1519.
        Escreva uma palavra: Puc_Minas
        Agora o caractere que deseja procurar: _
        Primeira ocorrÛncia de '_': _Minas

    * - Exercício 1520:
        Opcao:
        10
        Executando o Metodo 1520.
        Escreva uma palavra: Puc_Minas
        Agora o delimitador: c
        Parte antes do delimitador: Pu
        Parte apos o delimitador: _Minas

    * - Exercício 15E1:
        Opcao:
        11
        Executando o Metodo 15E1_EXTRA1.
        Escreva uma palavra: Puc_Minas
        Escreva um prefixo: P
        Prefixo encontrado: P

    * - Exercício 15E2:
        Opcao:
        12
        Executando o Metodo 15E2_EXTRA2.
        Escreva uma palavra: Puc_Minas
        Escreva um sufixo: s
        Sufixo encontrado: s
    */



//BIBLIOTECAS
#include <bits/stdc++.h>

using namespace std;

//------------------METODOS-----------------------//

char* Adicionar_No_Final(char* cadeia, char caractere) {

    int tamanho = strlen(cadeia);
    char* novaCadeia = new char[tamanho + 2];

    strcpy(novaCadeia, cadeia);

    novaCadeia[tamanho] = caractere;
    novaCadeia[tamanho + 1] = '\0';

    return novaCadeia;
}

//--------------------------------------------------//

char* Remover_Caractere(char* cadeia) {

    int tamanho = strlen(cadeia);

    if (tamanho == 0)
        return cadeia;

    char* novaCadeia = new char[tamanho];

    strncpy(novaCadeia, cadeia, tamanho - 1);

    novaCadeia[tamanho - 1] = '\0';

    delete[] cadeia;
    return novaCadeia;
}

//--------------------------------------------------//

char* Adicionar_No_Inicio(char caractere, char* cadeia) {

    int tamanho = strlen(cadeia);
    char* novaCadeia = new char[tamanho + 2];

    novaCadeia[0] = caractere;

    strcpy(novaCadeia + 1, cadeia);

    return novaCadeia;
}

//--------------------------------------------------//

char* Remover_Caractere_Inicio(char* cadeia) {

    int tamanho = strlen(cadeia);

    if (tamanho <= 1)
        return cadeia;

    char* novaCadeia = new char[tamanho];

    strcpy(novaCadeia, cadeia + 1);

    delete[] cadeia;
    return novaCadeia;
}

//--------------------------------------------------//

char* Inserir_Caractere_Meio(char* cadeia, char caracteres) {

    int tamanho = strlen(cadeia);

    if (tamanho < 2)
        return cadeia;

    int meio = tamanho / 2;
    char* novaCadeia = new char[tamanho + 2];

    strncpy(novaCadeia, cadeia, meio);

    novaCadeia[meio] = caracteres;

    strcpy(novaCadeia + meio + 1, cadeia + meio);

    return novaCadeia;
}

//--------------------------------------------------//

char* Remover_Caractere_Meio(char* cadeia) {

    int tamanho = strlen(cadeia);

    if (tamanho < 2)
        return cadeia;

    int meio = tamanho / 2;

    char* novaCadeia = new char[tamanho];

    strcpy(novaCadeia, cadeia);
    strcpy(novaCadeia + meio, cadeia + meio + 1);

    return novaCadeia;
}

//--------------------------------------------------//

char* Inserir_Caractere_Posicao(char* cadeia, char caracteres, int indice) {

    int tamanho = strlen(cadeia);

    if (indice < 0 || indice > tamanho)
        return cadeia;

    char* novaCadeia = new char[tamanho + 2];

    strncpy(novaCadeia, cadeia, indice);

    novaCadeia[indice] = caracteres;

    strcpy(novaCadeia + indice + 1, cadeia + indice);

    return novaCadeia;
}

//--------------------------------------------------//

char* Remover_Caractere_Posicao(char* cadeia, int indice) {

    int tamanho = strlen(cadeia);

    if (indice < 0 || indice >= tamanho)
        return cadeia;

    char* novaCadeia = new char[tamanho];

    strncpy(novaCadeia, cadeia, indice);
    strcpy(novaCadeia + indice, cadeia + indice + 1);

    return novaCadeia;
}

//--------------------------------------------------//

char* Ocorrencia(char* cadeia, char caracteres) {

    while (*cadeia != '\0') {
        if (*cadeia == caracteres)
            return cadeia;
        cadeia++;
    }

    return nullptr;
}

//--------------------------------------------------//

char* Delimitador(char* caracteres, char delimitador) {

    while (*caracteres != '\0') {
        if (*caracteres == delimitador) {
            *caracteres = '\0';
            return caracteres+ 1;
        }
        caracteres++;
    }

    return nullptr;
}

//--------------------------------------------------//

char* Prefixo(char* prefixo, char* caracteres) {
    while (*prefixo && *caracteres && *prefixo == *caracteres) {
        prefixo++;
        caracteres++;
    }
    return (*prefixo == '\0') ? caracteres : nullptr;
}

//--------------------------------------------------//

char* Sufixo(char* caracteres, char* sufixo) {
    int tamanho = strlen(caracteres);
    int tamanho_sufixo = strlen(sufixo);

    if (tamanho_sufixo > tamanho) {
        return nullptr;
    }

    char* inicio = caracteres + tamanho - tamanho_sufixo;

    while (*inicio && *sufixo && *inicio == *sufixo) {
        inicio++;
        sufixo++;
    }

    return (*sufixo == '\0') ? inicio : nullptr;
}

//------------------PROCEDIMENTOS-----------------------//

void procedimento1511(void){

    char* cadeia = new char[10];
    char add;

    cout << "Escreva uma palavra: ";
    cin >> cadeia;

    cout << "Agora o que deseja adicionar: ";
    cin >> add;

    cout << "Cadeia antes de adicionar o caractere: " << cadeia << endl;

    cadeia = Adicionar_No_Final(cadeia, add);

    cout << "Cadeia apos adicionar caractere final: " << cadeia << endl;

    delete[] cadeia;
}

//--------------------------------------------------//

void procedimento1512(void){

    char* cadeia = new char[10];

    cout << "Escreva uma palavra: ";
    cin >> cadeia;

    cout << "Cadeia antes de remover o caractere do final: " << cadeia << endl;

    cadeia = Remover_Caractere(cadeia);

    cout << "Cadeia apos remover o caractere no final: " << cadeia << endl;
}

//--------------------------------------------------//

void procedimento1513(void){

    char* cadeia = new char[10];
    char add;

    cout << "Escreva uma palavra: ";
    cin >> cadeia;

    cout << "Agora o que deseja adicionar: ";
    cin >> add;

    cout << "Cadeia antes de adicionar o caractere no inicio: " << cadeia << endl;

    cadeia = Adicionar_No_Inicio(add, cadeia);

    cout << "Cadeia apos adicionar um caractere no inicio: " << cadeia << endl;
}

//--------------------------------------------------//

void procedimento1514(void){

    char* cadeia = new char[10];

    cout << "Escreva uma palavra: ";
    cin >> cadeia;

    cout << "Cadeia original: " << cadeia << endl;

    cadeia = Remover_Caractere_Inicio(cadeia);

    cout << "Cadeia apos remover caractere no inicio: " << cadeia << endl;
}

//--------------------------------------------------//

void procedimento1515(void){

    char* cadeia = new char[10];
    char add;

    cout << "Escreva uma palavra: ";
    cin >> cadeia;

    cout << "Agora o que deseja adicionar: ";
    cin >> add;

    cadeia = Inserir_Caractere_Meio(cadeia, add);

    cout << "Cadeia apos inserir caractere: " << cadeia << endl;
}

//--------------------------------------------------//

void procedimento1516(void){

    char* cadeia = new char[10];

    cout << "Escreva uma palavra: ";
    cin >> cadeia;

    cadeia = Remover_Caractere_Meio(cadeia);

    cout << "Cadeia apos remover: " << cadeia << endl;
}

//--------------------------------------------------//

void procedimento1517(void){

    char* cadeia = new char[10];
    char add;
    int posicao;

    cout << "Escreva uma palavra: ";
    cin >> cadeia;

    cout << "Agora o que deseja adicionar: ";
    cin >> add;

    cout << "Em qual posicao quer adicionar o caracter: ";
    cin >> posicao;

    cout << "Cadeia original: " << cadeia << endl;

    cadeia = Inserir_Caractere_Posicao(cadeia, add, posicao);

    cout << "Cadeia apos inserir o caractere: " << cadeia << endl;

}

//--------------------------------------------------//

void procedimento1518(void){

    char* cadeia = new char[10];
    int posicao;

    cout << "Escreva uma palavra: ";
    cin >> cadeia;

    cout << "Em qual posicao quer remover o caracter: ";
    cin >> posicao;

    cout << "Cadeia original: " << cadeia << endl;

    cadeia = Remover_Caractere_Posicao(cadeia, posicao);

    cout << "Cadeia apos remover: " << cadeia << endl;

}

//--------------------------------------------------//

void procedimento1519(void){

    char* cadeia = new char[10];
    char c;

    cout << "Escreva uma palavra: ";
    cin >> cadeia;

    cout << "Agora o caractere que deseja procurar: ";
    cin >> c;

    char* result = Ocorrencia(cadeia, c);

    if (result != nullptr) {
        cout << "Primeira ocorrencia de '" << c << "': " << result << endl;
    } else {
        cout << "'" << c << "' não encontrado" << endl;
    }

    delete[] cadeia;
}

//--------------------------------------------------//

void procedimento1520(void){

    char* cadeia = new char[10];
    char delimitador;

    cout << "Escreva uma palavra: ";
    cin >> cadeia;

    cout << "Agora o delimitador: ";
    cin >> delimitador;

    char* resultado = Delimitador(cadeia, delimitador);

    cout << "Parte antes do delimitador: " << cadeia << "\n";

    if (resultado != nullptr) {
        cout << "Parte apos o delimitador: " << resultado << "\n";
    } else {
        cout << "Delimitador não encontrado.\n";
    }

    delete[] cadeia;
}

//--------------------------------------------------//

void procedimento15E1(void){

    char* cadeia = new char[10];
    char* prefixo = new char[10];

    cout << "Escreva uma palavra: ";
    cin >> cadeia;

    cout << "Escreva um prefixo: ";
    cin >> prefixo;

    char* resultado = Prefixo(prefixo, cadeia);

    if (resultado != nullptr) {
        cout << "Prefixo encontrado: " << prefixo << "\n";
    } else {
        cout << "Prefixo nao encontrado.\n";
    }

    delete[] cadeia;
    delete[] prefixo;
}

//--------------------------------------------------//

void procedimento15E2(void){

    char* cadeia = new char[10];
    char* sufixo= new char[10];

    cout << "Escreva uma palavra: ";
    cin >> cadeia;

    cout << "Escreva um sufixo: ";
    cin >> sufixo;

    char* resultado = Sufixo(cadeia, sufixo);

    if (resultado != nullptr) {
        cout << "Sufixo encontrado: " << sufixo << "\n";
    } else {
        cout << "Sufixo nao encontrado.\n";
    }

    delete[] cadeia;
    delete[] sufixo;
}

//--------------------------------------------------//

int main()
{
    int opcao;

    do{
        cout << "Menu:\n" << endl;
        cout << "1- Metodo 1511;\n"
                "2- Metodo 1512;\n"
                "3- Metodo 1513;\n"
                "4- Metodo 1514;\n"
                "5- Metodo 1515;\n"
                "6- Metodo 1516;\n"
                "7- Metodo 1517;\n"
                "8- Metodo 1518;\n"
                "9- Metodo 1519;\n"
                "10- Metodo 1520;\n"
                "11- Metodo 15E1_EXTRA1;\n"
                "12- Metodo 15E2_EXTRA2;\n"
                "Opcao: " << endl;

        cin >> opcao;

        switch(opcao){
            case 0:
                break;

            case 1:
                cout << "Executando o Metodo 1511.\n";
                procedimento1511();
                break;

            case 2:
                cout << "Executando o Metodo 1512.\n";
                procedimento1512();
                break;

            case 3:
                cout << "Executando o Metodo 1513.\n";
                procedimento1513();
                break;

            case 4:
                cout << "Executando o Metodo 1514.\n";
                procedimento1514();
                break;

            case 5:
                cout << "Executando o Metodo 1515.\n";
                procedimento1515();
                break;

            case 6:
                cout << "Executando o Metodo 1516.\n";
                procedimento1516();
                break;

            case 7:
                cout << "Executando o Metodo 1517.\n";
                procedimento1517();
                break;

            case 8:
                cout << "Executando o Metodo 1518.\n";
                procedimento1518();
                break;

            case 9:
                cout << "Executando o Metodo 1519.\n";
                procedimento1519();
                break;

            case 10:
                cout << "Executando o Metodo 1520.\n";
                procedimento1520();
                break;

            case 11:
                cout << "Executando o Metodo 15E1_EXTRA1.\n";
                procedimento15E1();
                break;

            case 12:
                cout << "Executando o Metodo 15E2_EXTRA2.\n";
                procedimento15E2();
                break;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    } while(opcao != 0);

return 0;
}
