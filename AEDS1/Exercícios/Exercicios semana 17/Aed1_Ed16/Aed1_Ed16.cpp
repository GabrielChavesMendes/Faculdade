/**
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico: ed16_+_EXTRAS
  *
  * Matricula: 1453522  Nome: Gabriel_Chaves_Mendes
  * Versao:  1.0                Data: 18/06/2024
  *
  * Dados:
  * - Feito na IDE CodeBlocks
  *
  * Resultados(SAIDAS):
    * - Exercício 1611:
        Opcao:
        1
        Executando o Metodo 1611.
        Qual sera o tamanho do array: 5
        Arranjo inicial: 1  7  14  0  9
        Digite o valor a ser adicionado: 8
        Arranjo atualizado: 1  7  14  0  9  8

    * - Exercício 1612:
        Opcao:
        2
        Executando o Metodo 1612.
        Qual sera o tamanho do array: 5
        Arranjo inicial: 1  7  14  0  9
        Arranjo atualizado: 1  7  14  0

    * - Exercício 1613:
        Opcao:
        3
        Executando o Metodo 1613.
        Qual sera o tamanho do array: 5
        Arranjo inicial: 1  7  14  0  9
        Digite o valor a ser adicionado: 6
        Arranjo atualizado: 6  1  7  14  0  9

    * - Exercício 1614:
        Opcao:
        4
        Executando o Metodo 1614.
        Qual sera o tamanho do array: 5
        Arranjo inicial: 1  7  14  0  9
        Arranjo atualizado: 7  14  0  9

    * - Exercício 1615:
        Opcao:
        5
        Executando o Metodo 1615.
        Qual sera o tamanho do array: 5
        Arranjo inicial: 1  7  14  0  9
        Digite o valor a ser adicionado: 6
        Arranjo atualizado: 1  7  6  14  0  9

    * - Exercício 1616:
        Opcao:
        6
        Executando o Metodo 1616.
        Qual sera o tamanho do array: 5
        Arranjo inicial: 1  7  14  0  9
        Arranjo atualizado: 1  7  0  9

    * - Exercício 1617:
        Opcao:
        7
        Executando o Metodo 1617.
        Qual sera o tamanho do primeiro array: 5
        Arranjo 1: 1 7 14 0 9
        Qual sera o tamanho do segundo array: 5
        Arranjo 2: 4 18 18 2 4
        Primeiro array e menor que o segundo array

    * - Exercício 1618:
        Opcao:
        8
        Executando o Metodo 1618.
        Qual sera o tamanho do primeiro array: 5
        Arranjo 1: 1 7 14 0 9
        Qual sera o tamanho do segundo array: 5
        Arranjo 2: 4 18 18 2 4
        Arranjo unido:
        1 4 7 18 14 18 0 2 9 4

    * - Exercício 1619:
        Opcao:
        9
        Executando o Metodo 1619.
        Qual sera o tamanho do array: 5
        Arranjo: 1 7 14 0 9
        Qual valor deseja procurar no array: 14
        Valor 14 encontrado no array

    * - Exercício 1620:
        Opcao:
        10
        Executando o Metodo 1620.
        Qual sera o tamanho do array: 5
        Arranjo original: 1 7 14 0 9
        Qual a posicao inicial da subsequencia: 1
        Qual o tamanho da subsequencia: 3
        Subsequencia: 7 14 0

    * - Exercício 16E1:
        Opcao:
        11
        Executando o Metodo 16E1_EXTRA1.
        Qual sera o tamanho do primeiro array: 5
        Arranjo 1: 1 7 14 0 9
        Qual sera o tamanho do segundo array: 6
        Arranjo 2: 4 18 18 2 4 5
        Arranjo unido:
        1 4 7 18 14 18 0 2 9 4 5

    * - Exercício 16E2:
        Opcao:
        12
        Executando o Metodo 16E2_EXTRA2.
        Qual sera o tamanho do primeiro array: 4
        Arranjo 1: 1 7 14 0
        Qual sera o tamanho do segundo array: 5
        Arranjo 2: 9 4 18 18 2
        Arranjo unido:
        0 1 2 4 7 9 14 18 18
    */



//BIBLIOTECAS
#include <bits/stdc++.h>

using namespace std;

//------------------METODOS-----------------------//

int* Arranjo_Add_Final(int* arranjo, int& tam, int valor) {

    int* cadeia = new int[tam + 1]; //CRIA UM ARRANJO COM UM TAMANHO A MAIS

    //COPIA O QUE ESTAVA NO ANTIGO ARRANJO NO NOVO
    for (int i = 0; i < tam; ++i) {
        cadeia[i] = arranjo[i];
    }

    //ADICIONA O VALOR
    cadeia[tam] = valor;

    delete[] arranjo;

    ++tam;

    return cadeia;
}

void Imprimi_Arranjo(int* arranjo, int tam) {
    for (int i = 0; i < tam; ++i) {
        cout << arranjo[i] << "  ";
    }
    cout << endl;
}

//--------------------------------------------------//

int* Arranjo_Remove_Final(int* arranjo, int& tam) {

    int* cadeia = new int[tam - 1]; //CRIA UM ARRANJO COM UM TAMANHO A MENOS

    //COPIA O QUE ESTAVA NO ANTIGO ARRANJO NO NOVO ATE O PENULTIMO NUMERO
    for (int i = 0; i < tam; ++i) {
        cadeia[i] = arranjo[i];
    }

    delete[] arranjo;

    ++tam;

    return cadeia;
}

void Imprimi_Arranjo_Remove(int* arranjo, int tam) {
    for (int i = 0; i < tam-1; ++i) {
        cout << arranjo[i] << "  ";
    }
    cout << endl;
}

//--------------------------------------------------//

int* Arranjo_Add_Inicio(int* arranjo, int& tam, int valor) {

    int* cadeia = new int[tam + 1]; //CRIA UM ARRANJO COM UM TAMANHO A MAIS

    //COPIA O QUE ESTAVA NO ANTIGO ARRANJO NO NOVO DEIXANDO A PRIMEIRA POSICAO VAZIA
    for (int i = 1; i < tam+1; ++i) {
        cadeia[i] = arranjo[i-1];
    }

    //ADICIONA O VALOR NO INICIO
    cadeia[0] = valor;

    delete[] arranjo;

    ++tam;

    return cadeia;
}

void Imprimi_Arranjo_Inicio(int* arranjo, int tam) {
    for (int i = 0; i < tam; ++i) {
        cout << arranjo[i] << "  ";
    }
    cout << endl;
}

//--------------------------------------------------//

int* Arranjo_Remove_Inicio(int* arranjo, int& tam) {

    int* cadeia = new int[tam - 1]; //CRIA UM ARRANJO COM UM TAMANHO A MENOS

    //COPIA O QUE ESTAVA NO ANTIGO ARRANJO NO NOVO ATE O PENULTIMO NUMERO
    for (int i = 0; i < tam; ++i) {
        cadeia[i] = arranjo[i+1];
    }

    delete[] arranjo;

    ++tam;

    return cadeia;
}

void Imprimi_Arranjo_Remove_Inicio(int* arranjo, int tam) {
    for (int i = 0; i < tam-1; ++i) {
        cout << arranjo[i] << "  ";
    }
    cout << endl;
}

//--------------------------------------------------//

int* Arranjo_Add_Meio(int* arranjo, int& tam, int valor) {

    int* cadeia = new int[tam + 1]; // CRIA UM ARRANJO COM UM TAMANHO A MAIS

    int metade = tam / 2;

    // COPIA O QUE ESTAVA NO ANTIGO ARRANJO ATÉ A METADE DO NOVO
    for (int i = 0; i < metade; ++i) {
        cadeia[i] = arranjo[i];
    }

    // ADICIONA O VALOR NO MEIO
    cadeia[metade] = valor;

    // COPIA O RESTANTE DO ARRANJO ANTIGO APÓS A METADE
    for (int i = metade; i < tam; ++i) {
        cadeia[i + 1] = arranjo[i];
    }

    delete[] arranjo;

    ++tam;

    return cadeia;
}

void Imprimi_Arranjo_Meio(int* arranjo, int tam) {
    for (int i = 0; i < tam; ++i) {
        cout << arranjo[i] << "  ";
    }
    cout << endl;
}


//--------------------------------------------------//

int* Arranjo_Remove_Meio(int* arranjo, int& tam) {

    int* cadeia = new int[tam - 1]; // CRIA UM ARRANJO COM UM TAMANHO A MENOS

    int metade = tam / 2;

    // COPIA O QUE ESTAVA NO ANTIGO ARRANJO ATÉ A METADE DO NOVO
    for (int i = 0; i < metade; ++i) {
        cadeia[i] = arranjo[i];
    }

    metade++;

    // COPIA O RESTANTE DO ARRANJO ANTIGO APÓS A METADE
    for (int i = metade; i < tam; ++i) {
        cadeia[i-1] = arranjo[i];
    }

    delete[] arranjo;

    ++tam;

    return cadeia;
}

void Imprimi_Remove_Meio(int* arranjo, int tam) {
    for (int i = 0; i < tam-1; ++i) {
        cout << arranjo[i] << "  ";
    }
    cout << endl;
}

//--------------------------------------------------//

//STRUCT
typedef struct s_intArray{

    int length;
    int *data;

} intArray;

typedef intArray* ref_intArray;

//--------------------------------------------------//

int Compara_Arranjo(ref_intArray p, ref_intArray q){

    //p E q SAO PONTEIROS PARA STRUCT
    if (p->length != q->length) {
        return p->length - q->length;
    }

    for (int i = 0; i < p->length; i++){
        if (p->data[i] != q->data[i]){
            int resul = p->data[i] - q->data[i];
            return p->data[i] - q->data[i];
        }
    }

    return 0;
}

void Imprime_Arranjo_Compara(int* arranjo, int n){

    for (int i = 0; i < n; ++i) {
        cout << arranjo[i] << " ";
    }
    cout << endl;
}

//--------------------------------------------------//


int* Unir_Arranjo(ref_intArray p, ref_intArray q) {

    int tam = p->length + q->length;
    int *arranjo_unido = (int*)malloc(tam * sizeof(int));

    int i = 0, j = 0, k = 0;

    while (i < p->length && j < q->length) {
        arranjo_unido[k++] = p->data[i++];
        arranjo_unido[k++] = q->data[j++];
    }

    while (i < p->length) {
        arranjo_unido[k++] = p->data[i++];
    }

    while (j < q->length) {
        arranjo_unido[k++] = q->data[j++];
    }

    return arranjo_unido;
}

void Imprime_Arranjo_Unido(int* arranjo, int n, int m){
    for (int i = 0; i < n + m; ++i) {
        cout << arranjo[i] << " ";
    }
    cout << endl;
}

//--------------------------------------------------//

ref_intArray Ocorrencia(ref_intArray a, int x){

    for (int i = 0; i < a->length; ++i){
        if (a->data[i] == x) {
            return a; //RETORNA O PROPRIO ARRANJO COMO APONTADOR
        }
    }
    return nullptr;
}

void Imprime_Arranjo_Ocorrencia(int* arranjo, int tamanho){

    for (int i = 0; i < tamanho; ++i){
        cout << arranjo[i] << " ";
    }

    cout << endl;
}

//--------------------------------------------------//

ref_intArray Sequencia(ref_intArray a, int start, int size){

    if (start < 0 || start >= a->length || size <= 0 || start + size > a->length){
        return nullptr;
    }

    int* arranjo = new int[size];

    for (int i = 0; i < size; ++i){
        arranjo[i] = a->data[start + i];
    }

    intArray* arranjo_sequencia = new intArray;

    arranjo_sequencia->length = size;
    arranjo_sequencia->data = arranjo;

    return arranjo_sequencia;
}

void Imprime_Arranjo_Sequencia(int* arranjo, int tamanho){

    for (int i = 0; i < tamanho; ++i) {
        cout << arranjo[i] << " ";
    }

    cout << endl;
}

//--------------------------------------------------//

int* Unir_Arranjo_Crescente(ref_intArray p, ref_intArray q){

    int tam = p->length + q->length;
    int *arranjo_unido = (int*)malloc(tam * sizeof(int));

    int i = 0, j = 0, k = 0;

    //INTERCALA A UNIAO DOS ELEMENTOS
    while (i < p->length && j < q->length){
        if (p->data[i] <= q->data[j]) {
            arranjo_unido[k++] = p->data[i++];
        } else {
            arranjo_unido[k++] = q->data[j++];
        }
    }

    //SE OUVER NUMEROS FALTANDO COLOCA NO ARRANJO
    while (i < p->length){
        arranjo_unido[k++] = p->data[i++];
    }

    while (j < q->length){
        arranjo_unido[k++] = q->data[j++];
    }

    //ORDENA EM ORDEM CRESCENTE
    for (int i = 0; i < tam - 1; ++i){
        for (int j = 0; j < tam - i - 1; ++j){
            if (arranjo_unido[j] > arranjo_unido[j + 1]){
                int temp = arranjo_unido[j];
                arranjo_unido[j] = arranjo_unido[j + 1];
                arranjo_unido[j + 1] = temp;
            }
        }
    }

    return arranjo_unido;
}


//------------------PROCEDIMENTOS-----------------------//

void procedimento1611(void){

    int n;

    cout << "Qual sera o tamanho do array: ";
    cin >> n;

    int* arranjo = new int[n];

    for (int i = 0; i < n; ++i) {
        arranjo[i] = rand() % 20;
    }

    cout << "Arranjo inicial: ";
    Imprimi_Arranjo(arranjo, n);

    int num;

    cout << "Digite o valor a ser adicionado: ";
    cin >> num;

    //CHAMA A FUNCAO PRA ADICIONAR O NUMERO NO FINAL DO ARRANJO E RETORNAR ELE
    arranjo = Arranjo_Add_Final(arranjo, n, num);

    cout << "Arranjo atualizado: ";
    Imprimi_Arranjo(arranjo, n);

    delete[] arranjo;
}

//--------------------------------------------------//

void procedimento1612(void){

    int n;

    cout << "Qual sera o tamanho do array: ";
    cin >> n;

    int* arranjo = new int[n];

    for (int i = 0; i < n; ++i) {
        arranjo[i] = rand() % 20;
    }

    cout << "Arranjo inicial: ";
    Imprimi_Arranjo(arranjo, n);

    arranjo = Arranjo_Remove_Final(arranjo, n);

    cout << "Arranjo atualizado: ";
    Imprimi_Arranjo_Remove(arranjo, n-1);

    delete[] arranjo;
}

//--------------------------------------------------//

void procedimento1613(void){

    int n;

    cout << "Qual sera o tamanho do array: ";
    cin >> n;

    int* arranjo = new int[n];

    for (int i = 0; i < n; ++i) {
        arranjo[i] = rand() % 20;
    }

    cout << "Arranjo inicial: ";
    Imprimi_Arranjo_Inicio(arranjo, n);

    int num;

    cout << "Digite o valor a ser adicionado: ";
    cin >> num;

    //CHAMA A FUNCAO PRA ADICIONAR O NUMERO NO INICIO DO ARRANJO E RETORNAR ELE
    arranjo = Arranjo_Add_Inicio(arranjo, n, num);

    cout << "Arranjo atualizado: ";
    Imprimi_Arranjo_Inicio(arranjo, n);

    delete[] arranjo;
}

//--------------------------------------------------//

void procedimento1614(void){

    int n;

    cout << "Qual sera o tamanho do array: ";
    cin >> n;

    int* arranjo = new int[n];

    for (int i = 0; i < n; ++i) {
        arranjo[i] = rand() % 20;
    }

    cout << "Arranjo inicial: ";
    Imprimi_Arranjo(arranjo, n);

    arranjo = Arranjo_Remove_Inicio(arranjo, n);

    cout << "Arranjo atualizado: ";
    Imprimi_Arranjo_Remove_Inicio(arranjo, n-1);

    delete[] arranjo;
}

//--------------------------------------------------//

void procedimento1615(void){

    int n;

    cout << "Qual sera o tamanho do array: ";
    cin >> n;

    int* arranjo = new int[n];

    for (int i = 0; i < n; ++i) {
        arranjo[i] = rand() % 20;
    }

    cout << "Arranjo inicial: ";
    Imprimi_Arranjo_Meio(arranjo, n);

    int num;

    cout << "Digite o valor a ser adicionado: ";
    cin >> num;

    // CHAMA A FUNÇÃO PARA ADICIONAR O NÚMERO NO MEIO DO ARRANJO E RETORNAR ELE
    arranjo = Arranjo_Add_Meio(arranjo, n, num);

    cout << "Arranjo atualizado: ";
    Imprimi_Arranjo_Meio(arranjo, n);

    delete[] arranjo;
}

//--------------------------------------------------//

void procedimento1616(void){

    int n;

    cout << "Qual sera o tamanho do array: ";
    cin >> n;

    int* arranjo = new int[n];

    for (int i = 0; i < n; ++i) {
        arranjo[i] = rand() % 20;
    }

    cout << "Arranjo inicial: ";
    Imprimi_Arranjo(arranjo, n);

    arranjo = Arranjo_Remove_Meio(arranjo, n);

    cout << "Arranjo atualizado: ";
    Imprimi_Remove_Meio(arranjo, n-1);

    delete[] arranjo;
}

//--------------------------------------------------//

void procedimento1617(void){

    int n;

    cout << "Qual sera o tamanho do primeiro array: ";
    cin >> n;

    int* arranjo1 = new int[n];

    for (int i = 0; i < n; ++i) {
        arranjo1[i] = rand() % 20;
    }

    cout << "Arranjo 1: ";
    Imprime_Arranjo_Compara(arranjo1, n);

    int m;

    cout << "Qual sera o tamanho do segundo array: ";
    cin >> m;

    int* arranjo2 = new int[m];

    for (int i = 0; i < m; ++i) {
        arranjo2[i] = rand() % 20;
    }

    cout << "Arranjo 2: ";
    Imprime_Arranjo_Compara(arranjo2, m);

    //CRIA VARIAVEIS QUE ARMAZENAM OS DADOS DOS ARRANJOS E SEUS TAMANHOS
    intArray array1 = {n, arranjo1};
    intArray array2 = {m, arranjo2};

    //CRIA REFERENCIAS PARA CADA ARRANJO
    ref_intArray refArray1 = &array1;
    ref_intArray refArray2 = &array2;

    int result = Compara_Arranjo(refArray1, refArray2);

    if (result == 0) {
        cout << "Arrays sao iguais" << endl;
    } else if (result < 0) {
        cout << "Primeiro array e menor que o segundo array" << endl;
    } else {
        cout << "Primeiro array e maior que o segundo array" << endl;
    }

    delete[] arranjo1;
    delete[] arranjo2;

}

//--------------------------------------------------//

void procedimento1618(void){

    int n;

    cout << "Qual sera o tamanho do primeiro array: ";
    cin >> n;

    int* arranjo1 = new int[n];

    for (int i = 0; i < n; ++i) {
        arranjo1[i] = rand() % 20;
    }

    cout << "Arranjo 1: ";
    Imprime_Arranjo_Compara(arranjo1, n);

    int m;

    cout << "Qual sera o tamanho do segundo array: ";
    cin >> m;

    int* arranjo2 = new int[m];

    for (int i = 0; i < m; ++i) {
        arranjo2[i] = rand() % 20;
    }

    cout << "Arranjo 2: ";
    Imprime_Arranjo_Compara(arranjo2, m);

    // CRIA VARIAVEIS QUE ARMAZENAM OS DADOS DOS ARRANJOS E SEUS TAMANHOS
    intArray array1 = {n, arranjo1};
    intArray array2 = {m, arranjo2};

    // CRIA REFERENCIAS PARA CADA ARRANJO
    ref_intArray refArray1 = &array1;
    ref_intArray refArray2 = &array2;

    int *arranjo_result = Unir_Arranjo(refArray1, refArray2);

    cout << "Arranjo unido:" << endl;

    Imprime_Arranjo_Unido(arranjo_result, n, m);

    delete[] arranjo1;
    delete[] arranjo2;
    free(arranjo_result);
}

//--------------------------------------------------//

void procedimento1619(void){

    int n;

    cout << "Qual sera o tamanho do array: ";
    cin >> n;

    int* arranjo1 = new int[n];

    for (int i = 0; i < n; ++i) {
        arranjo1[i] = rand() % 20;
    }

    cout << "Arranjo: ";
    Imprime_Arranjo_Ocorrencia(arranjo1, n);

    intArray array1 = {n, arranjo1};
    ref_intArray refArray1 = &array1;

    int valor;
    cout << "Qual valor deseja procurar no array: ";
    cin >> valor;

    ref_intArray resultado = Ocorrencia(refArray1, valor);

    if (resultado != nullptr) {
        cout << "Valor " << valor << " encontrado no array" << endl;
    } else {
        cout << "Valor " << valor << " nao encontrado no array" << endl;
    }

    delete[] arranjo1;

}

//--------------------------------------------------//

void procedimento1620(void){

 int n;

    cout << "Qual sera o tamanho do array: ";
    cin >> n;

    int* arranjo = new int[n];

    for (int i = 0; i < n; ++i){
        arranjo[i] = rand() % 20;
    }

    cout << "Arranjo original: ";
    Imprime_Arranjo_Sequencia(arranjo, n);

    int start, tam;

    cout << "Qual a posicao inicial da subsequencia: ";
    cin >> start;

    cout << "Qual o tamanho da subsequencia: ";
    cin >> tam;

    intArray arranjo_novo = {n, arranjo};
    ref_intArray refArray = &arranjo_novo;

    ref_intArray arranjo_sequencia = Sequencia(refArray, start, tam);

    if (arranjo_sequencia != nullptr){
        cout << "Subsequencia: ";
        Imprime_Arranjo_Sequencia(arranjo_sequencia->data, arranjo_sequencia->length);
    } else {
        cout << "Parametros invalidos para a subsequencia" << endl;
    }

    delete[] arranjo;

    if (arranjo_sequencia != nullptr) {
        delete[] arranjo_sequencia->data;
        delete arranjo_sequencia;
    }
}

//--------------------------------------------------//

void procedimento16E1(void){

    procedimento1618();
    //FOI FEITO O MESMO PROCEDIMENTO NO 1618()

}

//--------------------------------------------------//

void procedimento16E2(void){

    int n;

    cout << "Qual sera o tamanho do primeiro array: ";
    cin >> n;

    int* arranjo1 = new int[n];

    for (int i = 0; i < n; ++i) {
        arranjo1[i] = rand() % 20;
    }

    cout << "Arranjo 1: ";
    Imprime_Arranjo_Compara(arranjo1, n);

    int m;

    cout << "Qual sera o tamanho do segundo array: ";
    cin >> m;

    int* arranjo2 = new int[m];

    for (int i = 0; i < m; ++i) {
        arranjo2[i] = rand() % 20;
    }

    cout << "Arranjo 2: ";
    Imprime_Arranjo_Compara(arranjo2, m);

    intArray array1 = {n, arranjo1};
    intArray array2 = {m, arranjo2};

    ref_intArray refArray1 = &array1;
    ref_intArray refArray2 = &array2;

    int *arranjo_result = Unir_Arranjo_Crescente(refArray1, refArray2);

    cout << "Arranjo unido:" << endl;

    Imprime_Arranjo_Unido(arranjo_result, n, m);

    delete[] arranjo1;
    delete[] arranjo2;
    free(arranjo_result);

}

//--------------------------------------------------//

int main()
{
    int opcao;

    do{
        cout << "Menu:\n" << endl;
        cout << "1- Metodo 1611;\n"
                "2- Metodo 1612;\n"
                "3- Metodo 1613;\n"
                "4- Metodo 1614;\n"
                "5- Metodo 1615;\n"
                "6- Metodo 1616;\n"
                "7- Metodo 1617;\n"
                "8- Metodo 1618;\n"
                "9- Metodo 1619;\n"
                "10- Metodo 1620;\n"
                "11- Metodo 16E1_EXTRA1;\n"
                "12- Metodo 16E2_EXTRA2;\n"
                "Opcao: " << endl;

        cin >> opcao;

        switch(opcao){
            case 0:
                break;

            case 1:
                cout << "Executando o Metodo 1611.\n";
                procedimento1611();
                break;

            case 2:
                cout << "Executando o Metodo 1612.\n";
                procedimento1612();
                break;

            case 3:
                cout << "Executando o Metodo 1613.\n";
                procedimento1613();
                break;

            case 4:
                cout << "Executando o Metodo 1614.\n";
                procedimento1614();
                break;

            case 5:
                cout << "Executando o Metodo 1615.\n";
                procedimento1615();
                break;

            case 6:
                cout << "Executando o Metodo 1616.\n";
                procedimento1616();
                break;

            case 7:
                cout << "Executando o Metodo 1617.\n";
                procedimento1617();
                break;

            case 8:
                cout << "Executando o Metodo 1618.\n";
                procedimento1618();
                break;

            case 9:
                cout << "Executando o Metodo 1619.\n";
                procedimento1619();
                break;

            case 10:
                cout << "Executando o Metodo 1620.\n";
                procedimento1620();
                break;

            case 11:
                cout << "Executando o Metodo 16E1_EXTRA1.\n";
                procedimento16E1();
                break;

            case 12:
                cout << "Executando o Metodo 16E2_EXTRA2.\n";
                procedimento16E2();
                break;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    } while(opcao != 0);

return 0;
}
