/**
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico: ed11_+_EXTRAS
  *
  * Matricula: 1453522  Nome: Gabriel_Chaves_Mendes
  * Versao:  1.0                Data: 13/05/2024
  *
  * Dados:
  * - Feito na IDE CodeBlocks
  *
  * Resultados(SAIDAS):
    * - Exercício 1111:
        Opcao:
        1
        Executando o Metodo 1111.
        Digite o minimo: 1
        Digite o maximo: 100
        Qual sera o tamanho do vetor: 10
        [42]
        [68]
        [35]
        [1]
        [70]
        [25]
        [79]
        [59]
        [63]
        [65]
        Arquivo aberto com sucesso!
        No arquvio:
        10
        [42]
        [68]
        [35]
        [1]
        [70]
        [25]
        [79]
        [59]
        [63]
        [65]

    * - Exercício 1112:
        Opcao:
        2
        Executando o Metodo 1112.
        Arquivo aberto com sucesso!
        O maior valor par no arquivo e: 70

    * - Exercício 1113:
       Opcao:
        3
        Executando o Metodo 1113.
        Arquivo aberto com sucesso!
        O menor valor impar dentro do arquivo e: 1

    * - Exercício 1114:
        Opcao:
        4
        Executando o Metodo 1114.
        Digite o intervalo minimo: 2
        Digite o intervalo maximo: 6
        Arquivo aberto com sucesso!
        68 + 35 + 1 + 70 + 25
        A soma do intervalo entre 2 e 6 e: 199

    * - Exercício 1115:
        Opcao:
        5
        Executando o Metodo 1115.
        Digite o intervalo minimo: 2
        Digite o intervalo maximo: 6
        Arquivo aberto com sucesso!
        68 + 35 + 1 + 70 + 25
        A media da soma dos numeros do intervalo entre 2 e 6 e: 39.80

    * - Exercício 1116:
        Opcao:
        6
        Executando o Metodo 1116.
        Arquivo aberto com sucesso!
        O vetor nao tem valores negativos!

    * - Exercício 1117:
        Opcao:
        7
        Executando o Metodo 1117.
        Arquivo aberto com sucesso!
        O arranjo esta desordenado!

    * - Exercício 1118:
        Opcao:
        8
        Executando o Metodo 1118.
        Escreva a posicao inicial em que o numero sera procurado: 2
        Escreva a posicao final em que o numero sera procurado: 6
        Qual numero esta procurando: 40
        Arquivo aberto com sucesso!
        O valor 40 nao foi encontrado!

        Opcao:
        8
        Executando o Metodo 1118.
        Escreva a posicao inicial em que o numero sera procurado: 2
        Escreva a posicao final em que o numero sera procurado: 6
        Qual numero esta procurando: 70
        Arquivo aberto com sucesso!
        O valor 70 foi encontrado!

    * - Exercício 1119:
        Opcao:
        9
        Executando o Metodo 1119.
        Escreva a posicao inicial em que a comecara a contagem: 2
        Escreva a posicao final em que a contagem terminara: 6
        Digite uma constante: 5
        Arquivo aberto com sucesso!
        Novo vetor criado dentro dos intervalos [2 : 6]
        [340]
        [175]
        [5]
        [350]
        [125]

    * - Exercício 1120:
        Opcao:
        10
        Executando o Metodo 1120.
        Arquivo aberto com sucesso!
        Vetor em ordem decrescente:
        [79]
        [70]
        [68]
        [65]
        [63]
        [59]
        [42]
        [35]
        [25]
        [1]

    * - Exercício 11E1:
        Opcao:
        11
        Executando o Metodo 11E1.
        Qual sera o limite minimo: 1
        Qual sera o limite maximo: 150
        Qual sera o tamanho do vetor: 10
        Qual sera o tamanho do vetor: 10
        Primiro vetor
        [42]
        [18]
        [35]
        [101]
        [120]
        [125]
        [79]
        [109]
        [113]
        [15]
        Arquivo aberto com sucesso!
        Segundo vetor
        [6]
        [96]
        [32]
        [28]
        [62]
        [42]
        [146]
        [93]
        [28]
        [37]
        Arquivo aberto com sucesso!
        Os vetores sao diferente em 10 posicoes!

    * - Exercício 11E2:
        Opcao:
        12
        Executando o Metodo 11E2.
        Arquivo aberto com sucesso!
        Arquivo aberto com sucesso!
        O vetor resultante da subtracao dos outros 2 vetores e:
        [36]
        [-78]
        [3]
        [73]
        [58]
        [83]
        [-67]
        [16]
        [85]
        [-22]
    */



//BIBLIOTECAS
#include <bits/stdc++.h>

using namespace std;

//------------------METODOS-----------------------//

class Vetor{

    private:
        int N;
        int numeros;
        int limite_maximo;
        int limite_minimo;
        char colchete_a;
        char colchete_f;


    public:
        Vetor(int Numero, int valores, int Maximo, int Minimo){ //CONTRUTOR COM PARAMETROS
            N = Numero;
            numeros = valores;
            limite_maximo = Maximo;
            limite_minimo = Minimo;
        }

        Vetor() : N(0), numeros(0), limite_maximo(0), limite_minimo(0){} //CONSTRUTOR PADRAO SEM PARAMETROS

        void setN(int Numero){
            N = Numero;
        }
        int getN()const{
            return N;
        }

        void setNumeros(int Valores){
            numeros = Valores;
        }
        int getNumeros()const{
            return numeros;
        }

        void setLimite_Maximo(int Maximo){
            limite_maximo = Maximo;
        }
        int getLimite_Maximo()const{
            return limite_maximo;
        }

        void setLimite_Minimo(int Minimo){
            limite_minimo = Minimo;
        }
        int getLimite_Minimo()const{
            return limite_minimo;
        }

        void setColchete_A(char colcheteA){
            colchete_a = colcheteA;
        }
        char getColchete_A()const{
            return colchete_a;
        }

        void setColchete_F(char colcheteF){
            colchete_f = colcheteF;
        }
        char getColchete_F()const{
            return colchete_f;
        }

        int Quantidade(){
            cout << "Qual sera o tamanho do vetor: ";
            cin >> numeros;
            return numeros;
        }

        int numero_aleatorio(int limite_maximo, int limite_minimo) {
            return limite_minimo + rand() % (limite_maximo - limite_minimo + 1);
        }

        void Abrir_arquivo_escrita(const char *name, int vetor[], int tamanho){ //PROCEDIMENTO QUE ABRE O ARQUIVO PARA ESCRITA
            ofstream arquivo(name);
            if(arquivo.is_open()){
                cout << "Arquivo aberto com sucesso!" << endl;
                arquivo << tamanho << endl;
                for(int i = 0; i < tamanho; i++){
                    arquivo << "[" << vetor[i] << "]" << endl;
                }
            }else{
                cout << "Arquivo nao foi aberto!" << endl;
            }
            arquivo.close();
        }

        int Abrir_arquivo_leitura(const char *name){ //FUNCAO QUE ABRE ARQUIVO PARA LEITURA E RETORNA O TAMANHO
            ifstream arquivo(name);
            if(arquivo.is_open()){
                char linha[100];
                int cont = 0;
                cout << "Arquivo aberto com sucesso!" << endl;
                arquivo.getline(linha, sizeof(linha)); //PULA A PRIMEIRA LINHA PORQUE O ARRANJO COMECA NA SEGUNDA
                while(arquivo.getline(linha, sizeof(linha))){
                    cont++;
                }
                return cont;
            }else{
                cout << "Arquivo nao foi aberto!" << endl;
            }
            arquivo.close();
        }
};

void procedimento1111(void){

    int numero, valores, maximo, minimo;

    cout << "Digite o minimo: ";
    cin >> minimo;
    cout << "Digite o maximo: ";
    cin >> maximo;

    Vetor vetor(numero, valores, maximo, minimo);

    int tamanho = vetor.Quantidade();
    int vetor1[tamanho];

    for(int i = 0; i < tamanho; i++){
        vetor1[i] = vetor.numero_aleatorio(maximo, minimo);
        cout << "[" << vetor1[i] << "]" << endl;
    }

    vetor.Abrir_arquivo_escrita("DADOS.TXT", vetor1, tamanho);
}

//--------------------------------------------------//

int Maior_Par(char const *name, int tamanho){

    char linha[100];
    int atual = 0, maior = 0;
    char colchete_a, colchete_f; //VARIAVEIS PARA LER OS COLCHETES DENTRO DO ARQUIVO

    ifstream arquivo(name);
    if(arquivo.is_open()){
        arquivo.getline(linha, sizeof(linha)); //PULA A PRIMEIRA LINHA
        arquivo >> colchete_a >> maior >> colchete_f; //LE A SEGUNDA LINHA E ATRIBUI O PRIMEIRO VALOR A VARIAVEL MAIOR
        while(arquivo >>  colchete_a >> atual >> colchete_f){
            if(atual > maior && atual % 2 == 0){
                maior = atual;
            }
        }
    }
    arquivo.close();
    return maior;
}

void procedimento1112(void){

    Vetor vetor;

    int tamanho = vetor.Abrir_arquivo_leitura("DADOS.TXT"); //CHAMA FUNCAO PARA ABRIR ARQUIVO COMO LEITURA E RETORNA O TAMANHO DO ARRANJO

    int maior_par = Maior_Par("DADOS.TXT", tamanho);

    cout << "O maior valor par no arquivo e: " << maior_par << endl;
}

//--------------------------------------------------//

int Menor_Impar(char const *name, int tamanho){

    char linha[100];
    int cont = 0;
    int atual = 0, menor = 0;
    int numeros;
    char colchete_a, colchete_f;

    ifstream arquivo(name);
    if(arquivo.is_open()){
        arquivo.getline(linha, sizeof(linha)); //PULA A PRIMEIRA LINHA
        arquivo >> colchete_a >> menor >> colchete_f; //LE A SEGUNDA LINHA E ATRIBUI O PRIMEIRO VALOR A VARIAVEL MAIOR
        while(arquivo >>  colchete_a >> atual >> colchete_f){
            if(atual < menor && atual % 2 != 0){
                menor = atual;
            }
        }
    }
    arquivo.close();

    return menor;
}

void procedimento1113(void){

    Vetor vetor;

    int tamanho = vetor.Abrir_arquivo_leitura("DADOS.TXT");

    int menor = Menor_Impar("DADOS.TXT", tamanho);

    cout << "O menor valor impar dentro do arquivo e: " << menor << endl;
}

//--------------------------------------------------//

int Soma_Intervalo(const char *name, int tamanho, int minimo, int maximo){

    char linha[100];
    int soma = 0;
    int numeros;
    char colchete_a, colchete_f;

    ifstream arquivo(name);
    if(arquivo.is_open()){
        arquivo.getline(linha, sizeof(linha)); //PULA A PRIMEIRA LINHA
        for(int i = 0; i < tamanho; i++){
            arquivo >> colchete_a >> numeros >> colchete_f;
            if(i >= minimo - 1 && i < maximo){
                cout << numeros;
                if(i < maximo - 1){
                    cout << " + ";
                }
                soma = soma + numeros;
            }
        }
    }
    arquivo.close();

    return soma;
}

void procedimento1114(void){

    int numero, valores, maximo, minimo;

    cout << "Digite o intervalo minimo: ";
    cin >> minimo;
    cout << "Digite o intervalo maximo: ";
    cin >> maximo;

    Vetor vetor(numero, valores, maximo, minimo);

    int tamanho = vetor.Abrir_arquivo_leitura("DADOS.TXT");

    int soma = Soma_Intervalo("DADOS.TXT", tamanho, minimo, maximo);

    cout << "\nA soma do intervalo entre " << minimo << " e " << maximo << " e: " << soma << endl;
}

//--------------------------------------------------//

double Media_Intervalo(const char *name, int tamanho, int minimo, int maximo){

    char linha[100];
    int soma = 0, cont = 0;
    int numeros;
    double media = 0;
    char colchete_a, colchete_f;

    ifstream arquivo(name);
    if(arquivo.is_open()){
        arquivo.getline(linha, sizeof(linha)); //PULA A PRIMEIRA LINHA
        for(int i = 0; i < tamanho; i++){
            arquivo >> colchete_a >> numeros >> colchete_f;
            if(i >= minimo - 1 && i < maximo){
                cout << numeros;
                if(i < maximo - 1){
                    cout << " + ";
                }
                soma = soma + numeros;
                cont++;
            }
        }
    }
    media = (double)soma / cont;

    arquivo.close();

    return media;
}

void procedimento1115(void){

    int numero, valores, maximo, minimo;

    cout << "Digite o intervalo minimo: ";
    cin >> minimo;
    cout << "Digite o intervalo maximo: ";
    cin >> maximo;

    Vetor vetor(numero, valores, maximo, minimo);

    int tamanho = vetor.Abrir_arquivo_leitura("DADOS.TXT");

    double media = Media_Intervalo("DADOS.TXT", tamanho, minimo, maximo);

    cout << "\nA media da soma dos numeros do intervalo entre " << minimo << " e " << maximo << " e: " << fixed << setprecision(2) << media << endl;
}

//--------------------------------------------------//


int Valor_Negativo(const char *name, int tamanho){

    char linha[100];
    int cont = 0;
    int valor;
    char colchete_a, colchete_f;

    ifstream arquivo(name);
    if(arquivo.is_open()){
        arquivo.getline(linha, sizeof(linha));
        for(int i = 0; i < tamanho; i++){
            arquivo >> colchete_a >> valor >> colchete_f;
            if(valor < 0){
                cont++;
            }
        }
    }

    return cont;
}

void procedimento1116(void){

    Vetor vetor;

    int tamanho = vetor.Abrir_arquivo_leitura("DADOS.TXT");

    int quantidade = Valor_Negativo("DADOS.TXT", tamanho);

    if(quantidade == tamanho){
        cout << "O vetor tem apenas valores negativos!" << endl;
    }else if(quantidade < tamanho && quantidade > 0){
        cout << "O vetor tem " << quantidade << " numeros negativos" << endl;
    }else if(quantidade == 0){
        cout << "O vetor nao tem valores negativos!" << endl;
    }
}

//--------------------------------------------------//

bool Ordenado_Crescente(const char *name, int tamanho){

    char linha[100];
    int cont = 0, cont2 = 0;
    int vetor[tamanho], numero;
    bool ordem = false;
    char colchete_a, colchete_f;

    ifstream arquivo(name);
    if(arquivo.is_open()){
        arquivo.getline(linha, sizeof(linha));
        for(int i = 0; i < tamanho; i++){
            arquivo >> colchete_a >> numero >> colchete_f;
            vetor[i] = numero;
        }
        for(int i = 0; i < tamanho - 1; i++){
            if(vetor[i] < vetor[i+1]){
                cont++;
            }
            cont2++;
        }
    }

    if(cont == tamanho - 1){
        return true;
    }else{
        return false;
    }
}


void procedimento1117(void){

    Vetor vetor;

    int tamanho = vetor.Abrir_arquivo_leitura("DADOS.TXT");
    bool resultado = Ordenado_Crescente("DADOS.TXT", tamanho);

    if(resultado == true){
        cout << "O arranjo esta em ordem crescente!" << endl;
    }else if(resultado == false){
        cout << "O arranjo esta desordenado!" << endl;
    }
}

//--------------------------------------------------//

bool Achar_Numero(const char *name, int tamanho, int valor, int minimo, int maximo){

    char linha[100];
    char colchete_a, colchete_f;
    int numero;
    bool achei = false;

    ifstream arquivo(name);
    if(arquivo.is_open()){
        arquivo.getline(linha, sizeof(linha));
        for(int i = 0; i < tamanho; i++){
            arquivo >> colchete_a >> numero >> colchete_f;
            if(i >= minimo - 1 && i <= maximo){
                if(numero == valor){
                    achei = true;
                }
            }
        }
    }
    arquivo.close();

    return achei;
}

void procedimento1118(void){

    int minimo, maximo, valor;

    cout << "Escreva a posicao inicial em que o numero sera procurado: ";
    cin >> minimo;

    cout << "Escreva a posicao final em que o numero sera procurado: ";
    cin >> maximo;

    cout << "Qual numero esta procurando: ";
    cin >> valor;

    Vetor vetor;

    int tamanho = vetor.Abrir_arquivo_leitura("DADOS.TXT");

    bool achar = Achar_Numero("DADOS.TXT", tamanho, valor, minimo, maximo);

    if(achar == true){
        cout << "O valor " << valor << " foi encontrado!" << endl;
    }else if(achar == false){
        cout << "O valor " << valor << " nao foi encontrado!" << endl;
    }
}

//--------------------------------------------------//

int *Multiplica_vetor(const char *name, int tamanho, const int constante, int minimo, int maximo){

    char linha[100];
    int *vetor = new int[maximo - minimo + 1]; //NEW INT = ALOCACAO DINAMICA
    int numero;
    char colchete_a, colchete_f;

    ifstream arquivo(name);
    if(arquivo.is_open()){
        arquivo.getline(linha, sizeof(linha));
        for(int i = 0; i < tamanho; i++){
            arquivo >> colchete_a >> numero >> colchete_f;
            if(i >= minimo - 1 && i <= maximo - 1){
                vetor[i - (minimo - 1)] = numero * constante;
            }
        }
    }
    return vetor;
}


void procedimento1119(void){

    int minimo, maximo, constante;

    cout << "Escreva a posicao inicial em que a comecara a contagem: ";
    cin >> minimo;

    cout << "Escreva a posicao final em que a contagem terminara: ";
    cin >> maximo;

    cout << "Digite uma constante: ";
    cin >> constante;

    Vetor vetor;

    int tamanho = vetor.Abrir_arquivo_leitura("DADOS.TXT");

    int *vetor1 = Multiplica_vetor("DADOS.TXT", tamanho, constante, minimo, maximo);

    cout << "Novo vetor criado dentro dos intervalos [" << minimo << " : " << maximo << "]" << endl;

    for(int i = 0; i <= maximo - minimo; i++){
        cout << "[" << vetor1[i] << "]" << endl;
    }
}

//--------------------------------------------------//

int *Vetor_Decrescente(const char *name, int tamanho){

    char linha[100];
    char colchete_a, colchete_f;
    int numero, num2, atual = 0;
    int *vetor = new int [tamanho];

    ifstream arquivo(name);
    if(arquivo.is_open()){
        arquivo.getline(linha, sizeof(linha));
        for(int i = 0; i < tamanho; i++){
            arquivo >> colchete_a >> numero >> colchete_f;
            vetor[i] = numero;
        }
    }
    arquivo.close();

    for(int i = 0; i < tamanho; i++){
        for(int j = i + 1; j < tamanho; j++){
            if(vetor[i] < vetor[j]){
                //TROCANDO O NUMERO NA POSICAO i COM O NUMERO NA POSICAO j
                int controle = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = controle;
            }
        }
    }
    return vetor;
}

void procedimento1120(void){

    Vetor vetor;

    int tamanho = vetor.Abrir_arquivo_leitura("DADOS.TXT");

    int *vetor1 = Vetor_Decrescente("DADOS.TXT", tamanho);

    cout << "Vetor em ordem decrescente:" << endl;

    for(int i = 0; i < tamanho; i++){
        cout << "[" << vetor1[i] << "]" << endl;
    }

    delete[] vetor1;
}

//--------------------------------------------------//

int Vetores_Diferente(const char *name1, const char *name2, int tamanho1, int tamanho2){

    char linha[100];
    char colchete_a, colchete_f;
    int numero, numero2, cont = 0;
    int *vetor1 = new int [tamanho1];
    int *vetor2 = new int [tamanho2];

    ifstream arquivo(name1);
    ifstream arquivo2(name2);
    if(arquivo.is_open() && arquivo.is_open()){
        arquivo.getline(linha, sizeof(linha));
        arquivo2.getline(linha, sizeof(linha));

        for(int i = 0; i < tamanho1; i++){
            arquivo >> colchete_a >> numero >> colchete_f;
            vetor1[i] = numero;
        }

        for(int i = 0; i < tamanho2; i++){
            arquivo2 >> colchete_a >> numero >> colchete_f;
            vetor2[i] = numero;
        }
    }

    for(int i = 0; i < tamanho1; i++){
        if(vetor1[i] != vetor2[i]){
            cont++;
        }
    }

    arquivo.close();
    arquivo2.close();

    return cont;
}

void procedimento11E1(void){

    Vetor vetor;

    int limite_min, limite_max;

    cout << "Qual sera o limite minimo: ";
    cin >> limite_min;

    cout << "Qual sera o limite maximo: ";
    cin >> limite_max;

    int tamanho1 = vetor.Quantidade();
    int tamanho2 = vetor.Quantidade();

    int *vetor1 = new int [tamanho1];
    int *vetor2 = new int [tamanho2];

    cout << "Primiro vetor" << endl;

    for(int i = 0; i < tamanho1; i++){
            vetor1[i] = vetor.numero_aleatorio(limite_max, limite_min);
            cout << "[" << vetor1[i] << "]" << endl;
        }

    vetor.Abrir_arquivo_escrita("DADOS2.TXT", vetor1, tamanho1);

    cout << "\nSegundo vetor" << endl;

    for(int i = 0; i < tamanho2; i++){
        vetor2[i] = vetor.numero_aleatorio(limite_max, limite_min);
        cout << "[" << vetor2[i] << "]" << endl;
    }

    vetor.Abrir_arquivo_escrita("DADOS3.TXT", vetor2, tamanho2);

    int diferente = Vetores_Diferente("DADOS2.TXT", "DADOS3.TXT", tamanho1, tamanho2);

    if(diferente > 0){
        cout << "Os vetores sao diferente em " << diferente << " posicoes!" << endl;
    }else if(diferente == 0){
        cout << "Os vetores sao iguais!" << endl;
    }
}

//--------------------------------------------------//

int *Vetor_Subtracao(const char *name1, const char *name2, int tamanho1, int tamanho2){

    char linha[100];
    char colchete_a, colchete_f;
    int numero;

    int *vetor = new int[tamanho1];
    int *vetor2 = new int[tamanho2];
    int *vetor_resultado = new int[tamanho1];

    ifstream arquivo(name1);
    ifstream arquivo2(name2);

    if(arquivo.is_open() && arquivo2.is_open()){
        arquivo.getline(linha, sizeof(linha));
        arquivo2.getline(linha, sizeof(linha));

        for(int i = 0; i < tamanho1; i++){
            arquivo >> colchete_a >> numero >> colchete_f;
            vetor[i] = numero;
        }

       for(int i = 0; i < tamanho2; i++){
            arquivo2 >> colchete_a >> numero >> colchete_f;
            vetor2[i] = numero;
        }

        arquivo.close();
        arquivo2.close();
    }

    for(int i = 0; i < tamanho1; i++){
        vetor_resultado[i] = vetor[i] - vetor2[i];
    }

    delete[] vetor;
    delete[] vetor2;

    return vetor_resultado;
}

void procedimento11E2(void){

    Vetor vetor;

    int tamanho1 = vetor.Abrir_arquivo_leitura("DADOS2.TXT");
    int tamanho2 = vetor.Abrir_arquivo_leitura("DADOS3.TXT");

    if(tamanho1 == tamanho2){
        int *vetor1 = Vetor_Subtracao("DADOS2.TXT", "DADOS3.TXT", tamanho1, tamanho2);
        cout << "O vetor resultante da subtracao dos outros 2 vetores e: " << endl;
        for(int i = 0; i < tamanho1; i++){
            cout << "[" << vetor1[i] << "]" << endl;
        }
    }else{
        cout << "Os arranjos tem tamanhos diferentes!" << endl;
    }

}


//--------------------------------------------------//

int main()
{
    int opcao;

   do{
    cout << "Menu:\n" << endl;
    cout << "1- Metodo 1111;\n"
            "2- Metodo 1112;\n"
            "3- Metodo 1113;\n"
            "4- Metodo 1114;\n"
            "5- Metodo 1115;\n"
            "6- Metodo 1116;\n"
            "7- Metodo 1117;\n"
            "8- Metodo 1118;\n"
            "9- Metodo 1119;\n"
            "10- Metodo 1120;\n"
            "11- Metodo 11E1_EXTRA1;\n"
            "12- Metodo 11E2_EXTRA2;\n"
            "Opcao: " << endl;

    cin >> opcao;

    switch(opcao){
        case 0:
            break;

        case 1:
            cout << "Executando o Metodo 1111.\n";
            procedimento1111();
            break;

        case 2:
            cout << "Executando o Metodo 1112.\n";
            procedimento1112();
            break;

        case 3:
            cout << "Executando o Metodo 1113.\n";
            procedimento1113();
            break;

        case 4:
            cout << "Executando o Metodo 1114.\n";
            procedimento1114();
            break;

        case 5:
            cout << "Executando o Metodo 1115.\n";
            procedimento1115();
            break;

        case 6:
            cout << "Executando o Metodo 1116.\n";
            procedimento1116();
            break;

        case 7:
            cout << "Executando o Metodo 1117.\n";
            procedimento1117();
            break;

        case 8:
            cout << "Executando o Metodo 1118.\n";
            procedimento1118();
            break;

        case 9:
            cout << "Executando o Metodo 1119.\n";
            procedimento1119();
            break;

        case 10:
            cout << "Executando o Metodo 1120.\n";
            procedimento1120();
            break;

        case 11:
            cout << "Executando o Metodo 11E1.\n";
            procedimento11E1();
            break;

        case 12:
            cout << "Executando o Metodo 11E2.\n";
            procedimento11E2();
            break;

        default:
            cout << "Opcao invalida. Escolha uma opcao de 1 a 12.\n";
            break;
    }

      cout << "\n";
    }while(opcao != 0);

return 0;
}
