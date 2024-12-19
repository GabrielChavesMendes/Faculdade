/**
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico: ed12_+_EXTRAS
  *
  * Matricula: 1453522  Nome: Gabriel_Chaves_Mendes
  * Versao:  1.0                Data: 22/05/2024
  *
  * Dados:
  * - Feito na IDE CodeBlocks
  *
  * Resultados(SAIDAS):
    * - Exercício 1211:
        Opcao:
        1
        Executando o Metodo 1211.
        Qual sera a quantidade de linhas: 3
        Qual sera a quantidade de colunas: 3
        O arquivo foi aberto!
        41      67      34
        0       69      24
        78      58      62
        No arquivo:
        41      67      34
        0       69      24
        78      58      62

    * - Exercício 1212:
        Opcao:
        2
        Executando o Metodo 1212.
        Qual sera o valor da constante: 5
        Arquivo aberto!
        Matriz do arquivo:
        41      67      34
        0       69      24
        78      58      62
        Matriz nova:
        205     335     170
        0       345     120
        390     290     310

    * - Exercício 1213:
        Opcao:
        3
        Executando o Metodo 1213.
        Arquivo aberto!
        Matriz do arquivo:
        41      67      34
        0       69      24
        78      58      62
        Nao e uma matriz identidade

    * - Exercício 1214:
        Opcao:
        4
        Executando o Metodo 1214.
        Qual sera a quantidade de linhas: 3
        Qual sera a quantidade de colunas: 3
        O arquivo foi aberto!
        Arquivo aberto!
        Matriz do arquivo DADOS.TXT:
        41      67      34
        0       69      24
        78      58      62
        Arquivo aberto!
        Matriz do arquivo DADOS2.TXT:
        41      67      34
        0       69      24
        78      58      62
        As matrizes sao iguais

        NOVA TENTATIVA:
        Opcao:
        4
        Executando o Metodo 1214.
        Qual sera a quantidade de linhas: 3
        Qual sera a quantidade de colunas: 3
        O arquivo foi aberto!
        Arquivo aberto!
        Matriz do arquivo DADOS.TXT:
        41      67      34
        0       69      24
        78      58      62
        Arquivo aberto!
        Matriz do arquivo DADOS2.TXT:
        64      5       45
        81      27      61
        91      95      42
        As matrizes sao diferentes

    * - Exercício 1215:
        Opcao:
        5
        Executando o Metodo 1215.
        Arquivo aberto!
        Matriz do arquivo DADOS.TXT:
        41      67      34
        0       69      24
        78      58      62
        Arquivo aberto!
        Matriz do arquivo DADOS2.TXT:
        64      5       45
        81      27      61
        91      95      42
        Matriz resultante da soma de duas outras matrizes:
        105     72      79
        81      96      85
        169     153     104

    * - Exercício 1216:
        Opcao:
        6
        Executando o Metodo 1216.
        Qual sera o valor da constante: 2
        Arquivo aberto!
        Matriz do arquivo:
        41      67      34
        0       69      24
        78      58      62

        Matriz com a sua primeira linha alterada:
        41      205     82
        0       69      24
        78      58      62

    * - Exercício 1217:
        Opcao:
        7
        Executando o Metodo 1217.
        Qual sera o valor da constante: 3
        Arquivo aberto!
        Matriz do arquivo:
        41      67      34
        0       69      24
        78      58      62

        Matriz com a sua primeira linha alterada:
        41      -140    -38
        0       69      24
        78      58      62

    * - Exercício 1218:
        Opcao:
        8
        Executando o Metodo 1218.
        Qual valor deseja encontrar na matriz: 50
        Arquivo aberto!
        O numero 50 nao foi encontrado!
        Opcao:
        8
        Executando o Metodo 1218.
        Qual valor deseja encontrar na matriz: 69
        Arquivo aberto!
        O numero 69 foi encontrado na linha: 2

    * - Exercício 1219:
        Opcao:
        9
        Executando o Metodo 1219.
        Qual valor deseja encontrar na matriz: 50
        Arquivo aberto!
        O numero 50 nao foi encontrado!
        Opcao:
        9
        Executando o Metodo 1219.
        Qual valor deseja encontrar na matriz: 24
        Arquivo aberto!
        O numero 24 foi encontrado na coluna: 3

    * - Exercício 1220:
        Opcao:
        10
        Executando o Metodo 1220.
        Arquivo aberto!
        Matriz do arquivo:
        41      67      34
        0       69      24
        78      58      62
        A matriz transposta e:
        41      0       78
        67      69      58
        34      24      62

    * - Exercício 12E1:
        Opcao:
        11
        Executando o Metodo 12E1.
        Arquivo aberto!
        A matriz nao segue o padrao!

    * - Exercício 12E2:
        Opcao:
        12
        Executando o Metodo 12E2.
        Qual sera a quantidade de linhas: 3
        Qual sera a quantidade de colunas: 3
        O arquivo foi aberto!
        9       6       3
        8       5       2
        7       4       1
        Matriz do arquivo:
        9       6       3
        8       5       2
        7       4       1
    */



//BIBLIOTECAS
#include <bits/stdc++.h>

using namespace std;

//------------------METODOS-----------------------//

class Matriz{

private:
    int M;
    int N;
    int constante;
    bool identidade;
    int somatorio;
    int achar;

public:

    Matriz(int linhas, int colunas): M(linhas), N(colunas){} //CONSTRUTOR
    Matriz(int linhas, int colunas, int valorConstante) : M(linhas), N(colunas), constante(valorConstante) {} //NOVO CONTRUTOR
    Matriz(bool identico) : identidade(identico) {}
    Matriz(int soma) : somatorio(soma) {}

    //GETS E SETS PARA ACESSAR E ALTERAR O VALORES PRIVADOS
    int getLinhas();
    void setLinhas(int linhas);

    int getColunas();
    void setColunas(int colunas);

    int getConstante();
    void setConstante(int numero);

    bool getIdentidade();
    void setIdentidade(int identico);

    int getSoma();
    void setSoma(int soma);

    int getAchar();
    void setAchar(int achei);

};

//------METODOS GET E SET------//
int Matriz::getColunas(){
    return N;
}

void Matriz::setColunas(int colunas){
    N = colunas;
}

int Matriz::getLinhas(){
    return M;
}

void Matriz::setLinhas(int linhas){
    M = linhas;
}

int Matriz::getConstante(){
    return constante;
}

void Matriz::setConstante(int numero){
    constante = numero;
}

bool Matriz::getIdentidade(){
    return identidade;
}

void Matriz::setIdentidade(int identico){
    if(identico == 1){
        identidade = true;
    }else if(identico == 0){
        identidade = false;
    }
}

int Matriz::getSoma(){
    return somatorio;
}

void Matriz::setSoma(int soma){
    somatorio = soma;
}

int Matriz::getAchar(){
    return achar;
}

void Matriz::setAchar(int achei){
    achar = achei;
}

//--------------------------------------------------//

int LinhasMatriz(const char *name){

    string linha;
    int cont = 0;

    ifstream arquivo(name);
    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            cont++;
        }
    }
    arquivo.close();

    return cont;
}

int ColunasMatriz(const char *name, int linhas){

    int cont = 0, cont2 = 0;
    int valor;

    ifstream arquivo(name);
    if(arquivo.is_open()){
        while(arquivo >> valor){
            cont++;
        }
    }
    arquivo.close();

    return cont / linhas;
}

int MatrizIdentidade(const char *name, int linha, int coluna){

    int cont = 0, cont2 = 0;
    int **matriz1 = new int*[linha];
    int identico;
    Matriz matriz(false);

    ifstream arquivo(name);
        if(arquivo.is_open()){
            cout << "Arquivo aberto!" << endl;

            cout << "Matriz do arquivo:" << endl;

            for(int i = 0; i < linha; i++){
                matriz1[i] = new int[coluna];
                for(int j = 0; j < coluna; j++){
                    arquivo >> matriz1[i][j];
                    cout << matriz1[i][j] << "\t";
                }
                cout << endl;
            }
        }

        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                if(i == j){
                    if(matriz1[i][j] == 1){
                        cont++;
                    }
                }else if(i != j){
                    if(matriz1[i][j] == 0){
                        cont2++;
                    }
                }
            }
        }

        for(int i = 0; i < linha; i++) {
            delete[] matriz1[i];
        }
        delete[] matriz1;

        arquivo.close();

        if(cont + cont2 == linha * coluna){
            identico = 1;
            return identico;
        }else{
            identico = 0;
            return identico;
        }
}

int MatrizesIguais(const char *name, const char *name2, int linha, int coluna){

    int cont = 0;
    int **matriz1 = new int*[linha];
    int **matriz2 = new int*[linha];
    int identico;
    int linha_1 = LinhasMatriz(name);
    int coluna_1 = ColunasMatriz(name, linha_1);
    Matriz matriz(false);

    ifstream arquivo(name);
        if(arquivo.is_open()){
            cout << "Arquivo aberto!" << endl;

            cout << "Matriz do arquivo DADOS.TXT:" << endl;

            for(int i = 0; i < linha_1; i++){
                matriz1[i] = new int[coluna_1];
                for(int j = 0; j < coluna_1; j++){
                    arquivo >> matriz1[i][j];
                    cout << matriz1[i][j] << "\t";
                }
                cout << endl;
            }
        }

    ifstream arquivo2(name2);
        if(arquivo2.is_open()){
            cout << "Arquivo aberto!" << endl;

            cout << "Matriz do arquivo DADOS2.TXT:" << endl;

            for(int i = 0; i < linha; i++){
                matriz2[i] = new int[coluna];
                for(int j = 0; j < coluna; j++){
                    arquivo2 >> matriz2[i][j];
                    cout << matriz2[i][j] << "\t";
                }
                cout << endl;
            }
        }

    if(linha == linha_1 && coluna == coluna_1){
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                if(matriz1[i][j] == matriz2[i][j]){
                    cont++;
                }
            }
        }

        if(cont == linha * coluna){
            identico = 1;
            return identico;
        }else{
            identico = 0;
            return identico;
        }
    }else{
        cout << "As matrizes tem dimensoes diferentes!" << endl;
        return 0;
    }

    for(int i = 0; i < linha; i++) {
        delete[] matriz1[i];
    }
    delete[] matriz1;

    for(int i = 0; i < linha; i++) {
        delete[] matriz2[i];
    }
    delete[] matriz2;

}

int SomaMatriz(const char *name, const char *name2){

    int linha_1 = LinhasMatriz(name);
    int coluna_1 = ColunasMatriz(name, linha_1);
    int linha_2 = LinhasMatriz(name2);
    int coluna_2 = ColunasMatriz(name2, linha_2);
    int **matriz1 = new int*[linha_1];
    int **matriz2 = new int*[linha_2];
    int soma = 0;

    Matriz matriz(0);

    ifstream arquivo(name);
        if(arquivo.is_open()){
            cout << "Arquivo aberto!" << endl;

            cout << "Matriz do arquivo DADOS.TXT:" << endl;

            for(int i = 0; i < linha_1; i++){
                matriz1[i] = new int[coluna_1];
                for(int j = 0; j < coluna_1; j++){
                    arquivo >> matriz1[i][j];
                    cout << matriz1[i][j] << "\t";
                }
                cout << endl;
            }
        }

    ifstream arquivo2(name2);
        if(arquivo2.is_open()){
            cout << "Arquivo aberto!" << endl;

            cout << "Matriz do arquivo DADOS2.TXT:" << endl;

            for(int i = 0; i < linha_2; i++){
                matriz2[i] = new int[coluna_2];
                for(int j = 0; j < coluna_2; j++){
                    arquivo2 >> matriz2[i][j];
                    cout << matriz2[i][j] << "\t";
                }
                cout << endl;
            }
        }

    int **matriz3 = new int*[linha_1];

    if(linha_1 == linha_2 && coluna_1 == coluna_2){
        cout << "Matriz resultante da soma de duas outras matrizes:" << endl;
        for(int i = 0; i < linha_1; i++){
            matriz3[i] = new int[coluna_1];
            for(int j = 0; j < coluna_1; j++){
                soma = matriz1[i][j] + matriz2[i][j];
                matriz.setSoma(soma);
                matriz3[i][j] = matriz.getSoma();
                cout << matriz3[i][j] << "\t";
            }
            cout << endl;
        }
    }else{
        cout << "As matrizes nao possuem dimensoes iguais!" << endl;
    }
}

int AcharNaLinha(const char *name, int valor){

    int linha = LinhasMatriz("DADOS.TXT");
    int coluna = ColunasMatriz("DADOS.TXT", linha);
    int **matriz1 = new int*[linha];
    int achei, cont = 1;

    Matriz matriz(0);

    ifstream arquivo(name);
    if(arquivo.is_open()){
        cout << "Arquivo aberto!" << endl;
        for(int i = 0; i < linha; i++){
            matriz1[i] = new int[coluna];
            for(int j = 0; j < coluna; j++){
                arquivo >> matriz1[i][j];
            }
        }
    }

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            if(matriz1[i][j] == valor){
                matriz.setAchar(cont);
            }
        }
        cont++;
    }

    return matriz.getAchar();
}

int AcharNaColuna(const char *name, int valor){

    int linha = LinhasMatriz("DADOS.TXT");
    int coluna = ColunasMatriz("DADOS.TXT", linha);
    int **matriz1 = new int*[linha];
    int achei, cont = 1;

    Matriz matriz(0);

    ifstream arquivo(name);
    if(arquivo.is_open()){
        cout << "Arquivo aberto!" << endl;
        for(int i = 0; i < linha; i++){
            matriz1[i] = new int[coluna];
            for(int j = 0; j < coluna; j++){
                arquivo >> matriz1[i][j];
            }
        }
    }

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            if(matriz1[i][j] == valor){
                matriz.setAchar(cont);
            }
            cont++;
        }
        cont = 1;
    }

    return matriz.getAchar();
}

int MatrizPadrao(const char *name, int linha, int coluna){

    int total = linha * coluna;
    int elementos = 1;
    int **matriz1 = new int*[linha];
    int achei, cont = 0;

    Matriz matriz(0);

    ifstream arquivo(name);
    if(arquivo.is_open()){
        cout << "Arquivo aberto!" << endl;
        for(int i = 0; i < linha; i++){
            matriz1[i] = new int[coluna];
            for(int j = 0; j < coluna; j++){
                arquivo >> matriz1[i][j];
            }
        }
    }

    for (int j = 0; j < coluna; ++j) {
        for (int i = 0; i < linha; ++i) {
            if (matriz1[i][j] == elementos) {
                cont++;
            }
            elementos++;
        }
    }

    for (int i = 0; i < linha; ++i) {
        delete[] matriz1[i];
    }
    delete[] matriz1;

    if(cont == total){
        achei = 1;
        matriz.setAchar(achei);
        return matriz.getAchar();
    }else{
        achei = 0;
        matriz.setAchar(achei);
        return matriz.getAchar();
    }
}

void MatrizPadraoInversa(const char *name, int linha, int coluna){

    ifstream arquivo(name);
    if(arquivo.is_open()){
        cout << "Matriz do arquivo:" << endl;
        int valor;
        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
                arquivo >> valor;
                cout << valor << "\t";
            }
            cout << endl;
        }
    }
    arquivo.close();
}

//-----------------PROCEDIMENTOS-----------------//

void procedimento1211(void){

    Matriz matriz(0, 0); //INICIALIZA A MATRIZ COM 0 LINHAS E 0 COLUNAS

    cout << "Qual sera a quantidade de linhas: ";
    int M;
    cin >> M;
    matriz.setLinhas(M);

    cout << "Qual sera a quantidade de colunas: ";
    int N;
    cin >> N;
    matriz.setColunas(N);

    ofstream arquivo("DADOS.TXT");
    if(arquivo.is_open()){
        cout << "O arquivo foi aberto!" << endl;
        int **matriz1 = new int*[M];

        for(int i = 0; i < M; i++){
            matriz1[i] = new int[N];
            for(int j = 0; j < N; j++){
                matriz1[i][j] = rand() % 100;
                cout << matriz1[i][j] << "\t";
                arquivo << matriz1[i][j] << "\t";
            }
            cout << endl;
            arquivo << endl;
        }
    }
}

//--------------------------------------------------//

void procedimento1212(void){

    int linha = LinhasMatriz("DADOS.TXT");
    int coluna = ColunasMatriz("DADOS.TXT", linha);
    int constante;
    int **matriz1 = new int*[linha];

    cout << "Qual sera o valor da constante: ";
    cin >> constante;

    Matriz matriz(linha, coluna, constante);

    matriz.setConstante(constante);

    ifstream arquivo("DADOS.TXT");
    if(arquivo.is_open()){
        cout << "Arquivo aberto!" << endl;

        cout << "Matriz do arquivo:" << endl;

        for(int i = 0; i < linha; i++){
            matriz1[i] = new int[coluna];
            for(int j = 0; j < coluna; j++){
                arquivo >> matriz1[i][j];
                cout << matriz1[i][j] << "\t";
            }
            cout << endl;
        }
    }

    cout << "Matriz nova:" << endl;

    int  **matriz2 = new int*[linha];
    for(int i = 0; i < linha; i++){
        matriz2[i] = new int[coluna];
        for(int j = 0; j < coluna; j++){
            matriz2[i][j] = matriz1[i][j] * matriz.getConstante();
            cout << matriz2[i][j] << "\t";
        }
        cout << endl;
    }

    arquivo.close();

    for(int i = 0; i < linha; i++) {
        delete[] matriz1[i];
    }
    delete[] matriz1;

    for(int i = 0; i < linha; i++) {
        delete[] matriz2[i];
    }
    delete[] matriz2;
}

//--------------------------------------------------//

void procedimento1213(void){

    int linha = LinhasMatriz("DADOS.TXT");
    int coluna = ColunasMatriz("DADOS.TXT", linha);

    Matriz matriz(linha, coluna);

    int identico = MatrizIdentidade("DADOS.TXT", matriz.getLinhas(), matriz.getColunas());

    matriz.setIdentidade(identico);

    if(matriz.getIdentidade() == true){
        cout << "E uma matriz identidade" << endl;
    }else if(matriz.getIdentidade() == false){
        cout << "Nao e uma matriz identidade" << endl;
    }
}

//--------------------------------------------------//

void procedimento1214(void){

    Matriz matriz(0, 0);

    cout << "Qual sera a quantidade de linhas: ";
    int M;
    cin >> M;
    matriz.setLinhas(M);

    cout << "Qual sera a quantidade de colunas: ";
    int N;
    cin >> N;
    matriz.setColunas(N);

    int **matriz1 = new int*[M];

    ofstream arquivo("DADOS2.TXT");
    if(arquivo.is_open()){
        cout << "O arquivo foi aberto!" << endl;

        for(int i = 0; i < M; i++){
            matriz1[i] = new int[N];
            for(int j = 0; j < N; j++){
                matriz1[i][j] = rand() % 100;
                arquivo << matriz1[i][j] << "\t";
            }
            arquivo << endl;
        }
    }

    arquivo.close();

    for(int i = 0; i < M; i++) {
        delete[] matriz1[i];
    }
    delete[] matriz1;

    int identico = MatrizesIguais("DADOS.TXT", "DADOS2.TXT", M, N);

    matriz.setIdentidade(identico);

    if(matriz.getIdentidade() == true){
        cout << "As matrizes sao iguais" << endl;
    }else if(matriz.getIdentidade() == false){
        cout << "As matrizes sao diferentes" << endl;
    }
}

//--------------------------------------------------//

void procedimento1215(void){

    SomaMatriz("DADOS.TXT", "DADOS2.TXT");

}

//--------------------------------------------------//

void procedimento1216(void){

    int linha = LinhasMatriz("DADOS.TXT");
    int coluna = ColunasMatriz("DADOS.TXT", linha);
    int constante;
    int **matriz1 = new int*[linha];

    cout << "Qual sera o valor da constante: ";
    cin >> constante;

    Matriz matriz(linha, coluna, constante);

    matriz.setConstante(constante);

    ifstream arquivo("DADOS.TXT");
    if(arquivo.is_open()){
        cout << "Arquivo aberto!" << endl;

        cout << "Matriz do arquivo:" << endl;

        for(int i = 0; i < linha; i++){
            matriz1[i] = new int[coluna];
            for(int j = 0; j < coluna; j++){
                arquivo >> matriz1[i][j];
                cout << matriz1[i][j] << "\t";
            }
            cout << endl;
        }
    }

    for(int i = 0; i < 1; i++){
        for(int j = 0; j < coluna; j++){
            matriz1[i][j] = matriz1[i][j] + matriz1[i+1][j] * matriz.getConstante();
        }
    }

    cout << endl;
    cout << "Matriz com a sua primeira linha alterada:" << endl;

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            cout << matriz1[i][j] << "\t";
        }
        cout << endl;
    }
}

//--------------------------------------------------//

void procedimento1217(void){

    int linha = LinhasMatriz("DADOS.TXT");
    int coluna = ColunasMatriz("DADOS.TXT", linha);
    int constante;
    int **matriz1 = new int*[linha];

    cout << "Qual sera o valor da constante: ";
    cin >> constante;

    Matriz matriz(linha, coluna, constante);

    matriz.setConstante(constante);

    ifstream arquivo("DADOS.TXT");
    if(arquivo.is_open()){
        cout << "Arquivo aberto!" << endl;

        cout << "Matriz do arquivo:" << endl;

        for(int i = 0; i < linha; i++){
            matriz1[i] = new int[coluna];
            for(int j = 0; j < coluna; j++){
                arquivo >> matriz1[i][j];
                cout << matriz1[i][j] << "\t";
            }
            cout << endl;
        }
    }

    for(int i = 0; i < 1; i++){
        for(int j = 0; j < coluna; j++){
            matriz1[i][j] = matriz1[i][j] - matriz1[i+1][j] * matriz.getConstante();
        }
    }

    cout << endl;
    cout << "Matriz com a sua primeira linha alterada:" << endl;

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            cout << matriz1[i][j] << "\t";
        }
        cout << endl;
    }
}

//--------------------------------------------------//

void procedimento1218(void){

    int numero;

    cout << "Qual valor deseja encontrar na matriz: ";
    cin >> numero;

    int achei = AcharNaLinha("DADOS.TXT", numero);

    if(achei != 0){
        cout << "O numero " << numero << " foi encontrado na linha: " << achei << endl;
    }else{
        cout << "O numero " << numero << " nao foi encontrado!" << endl;
    }
}

//--------------------------------------------------//

void procedimento1219(void){

    int numero;

    cout << "Qual valor deseja encontrar na matriz: ";
    cin >> numero;

    int achei = AcharNaColuna("DADOS.TXT", numero);

    if(achei != 0){
        cout << "O numero " << numero << " foi encontrado na coluna: " << achei << endl;
    }else{
        cout << "O numero " << numero << " nao foi encontrado!" << endl;
    }
}

//--------------------------------------------------//

void procedimento1220(void){

    int linha = LinhasMatriz("DADOS.TXT");
    int coluna = ColunasMatriz("DADOS.TXT", linha);
    int **matriz1 = new int*[linha];
    int **matriz2 = new int*[coluna];

    ifstream arquivo("DADOS.TXT");
    if(arquivo.is_open()){
        cout << "Arquivo aberto!" << endl;

        cout << "Matriz do arquivo:" << endl;

        for(int i = 0; i < linha; i++){
            matriz1[i] = new int[coluna];
            for(int j = 0; j < coluna; j++){
                arquivo >> matriz1[i][j];
                cout << matriz1[i][j] << "\t";
            }
            cout << endl;
        }
    }

    arquivo.close();

    int cont = 0;
    int cont2 = 0;

    cout << "A matriz transposta e: " << endl;

    for(int i = 0; i < linha; i++){
        matriz2[i] = new int[linha];
        for(int j = 0; j < coluna; j++){
            matriz2[i][j] = matriz1[cont][cont2];
            cont++;
            cout << matriz2[i][j] << "\t";
        }
        cont = 0;
        cont2++;
        cout << endl;
    }
}

//--------------------------------------------------//

void procedimento12E1(void){

    int linha = LinhasMatriz("DADOS.TXT");
    int coluna = ColunasMatriz("DADOS.TXT", linha);

    Matriz matriz(0);

    int achar = MatrizPadrao("DADOS.TXT", linha, coluna);

    matriz.setIdentidade(achar);

    if(matriz.getIdentidade() == true){
        cout << "A matriz segue o padrao!" << endl;
    }else if(matriz.getIdentidade() == false){
        cout << "A matriz nao segue o padrao!" << endl;
    }
}

//--------------------------------------------------//

void procedimento12E2(void){

    Matriz matriz(0, 0);

    int M, N;
    do {
        cout << "Qual sera a quantidade de linhas: ";
        cin >> M;
        matriz.setLinhas(M);

        cout << "Qual sera a quantidade de colunas: ";
        cin >> N;
        matriz.setColunas(N);
    } while (M != N);

    int **matriz1 = new int*[M];
    for (int i = 0; i < M; ++i) {
        matriz1[i] = new int[N];
    }

    int total = M * N;

    ofstream arquivo("DADOS3.TXT");
    if (arquivo.is_open()) {
        cout << "O arquivo foi aberto!" << endl;

        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) {
                matriz1[i][j] = total;
                total--;
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cout << matriz1[i][j] << "\t";
                arquivo << matriz1[i][j] << "\t";
            }
            cout << endl;
            arquivo << endl;
        }

        arquivo.close();
    }

    for (int i = 0; i < M; i++) {
        delete[] matriz1[i];
    }
    delete[] matriz1;

    MatrizPadraoInversa("DADOS3.TXT", M, N);
}

//--------------------------------------------------//

int main()
{
    int opcao;

   do{
    cout << "Menu:\n" << endl;
    cout << "1- Metodo 1211;\n"
            "2- Metodo 1212;\n"
            "3- Metodo 1213;\n"
            "4- Metodo 1214;\n"
            "5- Metodo 1215;\n"
            "6- Metodo 1216;\n"
            "7- Metodo 1217;\n"
            "8- Metodo 1218;\n"
            "9- Metodo 1219;\n"
            "10- Metodo 1220;\n"
            "11- Metodo 12E1_EXTRA1;\n"
            "12- Metodo 12E2_EXTRA2;\n"
            "Opcao: " << endl;

    cin >> opcao;

    switch(opcao){
        case 0:
            break;

       case 1:
            cout << "Executando o Metodo 1211.\n";
            procedimento1211();
            break;

        case 2:
            cout << "Executando o Metodo 1212.\n";
            procedimento1212();
            break;

        case 3:
            cout << "Executando o Metodo 1213.\n";
            procedimento1213();
            break;

        case 4:
            cout << "Executando o Metodo 1214.\n";
            procedimento1214();
            break;

        case 5:
            cout << "Executando o Metodo 1215.\n";
            procedimento1215();
            break;

        case 6:
            cout << "Executando o Metodo 1216.\n";
            procedimento1216();
            break;

        case 7:
            cout << "Executando o Metodo 1217.\n";
            procedimento1217();
            break;

        case 8:
            cout << "Executando o Metodo 1218.\n";
            procedimento1218();
            break;

        case 9:
            cout << "Executando o Metodo 1219.\n";
            procedimento1219();
            break;

        case 10:
            cout << "Executando o Metodo 1220.\n";
            procedimento1220();
            break;

        case 11:
            cout << "Executando o Metodo 12E1.\n";
            procedimento12E1();
            break;

        case 12:
            cout << "Executando o Metodo 12E2.\n";
            procedimento12E2();
            break;

        default:
            cout << "Opcao invalida. Escolha uma opcao de 1 a 12.\n";
            break;
    }

      cout << "\n";
    }while(opcao != 0);

return 0;
}
