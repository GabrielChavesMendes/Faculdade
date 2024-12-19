#include <bits/stdc++.h>

using namespace std;

//--------------------- CLASSE ---------------------//

class Treino{

    private:
        //ATRIBUTOS PRIVADOS
        int N;
        int linhas;
        int colunas;
        int contador;
        double soma_total;
        string nome;
        bool verdade;

    public:
        //CONSTRUTOR
        Treino(int N = 0, int linhas = 0, int colunas = 0, int contador = 0, double soma_total = 0.0, string nome = "")
        : N(N), linhas(linhas), colunas(colunas), contador(contador), soma_total(soma_total), nome(nome){}

        //FUNCOES GETTERS E SETTER
        void setN(int numeros){
            N = numeros;
        }

        int getN(){
            return N;
        }

        void setLinhas(int linha){
            linhas = linha;
        }

        int getLinhas(){
            return linhas;
        }

        void setColunas(int coluna){
            colunas = coluna;
        }

        int getColunas(){
            return colunas;
        }

        void setContador(int cont){
            contador = cont;
        }

        int getContador(){
            return contador;
        }

        void setSoma(double soma){
            soma_total = soma;
        }

        double getSoma(){
            return soma_total;
        }

        void setNome(string caracter){
            nome = caracter;
        }

        string getNome(){
            return nome;
        }

        void setVerdade(bool falso){
            verdade = falso;
        }

        bool getVerdade(){
            if(verdade == 1){
                return true;
            }else if( verdade == 0){
                return false;
            }
        }
};


void exercicio01(void){

    Treino treinos; //INICIALIZANDO A CLASSE

    string nome;
    int tam;
    int n;

    ofstream arquivo ("VETOR.TXT"); //ABRIR ARQUIVO PARA ESCRITA
    if(arquivo.is_open()){

        cout << "Qual sera o tamanho do vetor: ";
        cin >> tam;

        treinos.setLinhas(tam); //PASSANDO O VALOR DA VARIAVEL tam PARA O ATRIBUTO PRIVADO POR MEIO DE SET

        int* vetor = new int[treinos.getLinhas()]; //ALOCACAO DINAMICA DE VETOR

        for(int i = 0; i < treinos.getLinhas(); i++){
            vetor[i] = rand() % 100;
            cout << vetor[i] << "\t"; //IMPRIMINDO NO TERMINAL
            arquivo << vetor[i] << "\t"; //IMPRIMINDO NO ARQUIVO
        }
        delete[] vetor;
        cout << endl;
    }

    arquivo.close();
}

//--------------------------------------------------//

int Quantidade_Elementos(const string name){ // FUNCAO PARA RETORNAR A QUANTIDADE DE ELEMENTOS EM UM VETOR NO ARQUIVO

    Treino treinos;

    treinos.setNome(name);

    int cont = 0, n;

    ifstream arquivo(treinos.getNome()); //ABRIR ARQUIVO PARA LEITURA
    if(arquivo.is_open()){
        while(arquivo >> n){ //ATRIBUI O VALOR DO ARQUIVO A VARIAVEL n
            cont++; //E VAI CONTANDO
        }
        treinos.setContador(cont);
        arquivo.close();
    }

    return treinos.getContador(); //RETORNA O VALOR COM GET
}

void exercicio02(void){

    Treino treinos;

    treinos.setContador(Quantidade_Elementos("VETOR.TXT"));

    cout << "A quantidade de elementos e: " << treinos.getContador() << endl;
}

//--------------------------------------------------//

int *Vetor_Invertido(const string nome){ //FUNCAO PONTEIRO QUE RETORNA UM PONTEIRO PARA O VETOR INVERTIDO

    Treino treinos;

    treinos.setContador(Quantidade_Elementos("VETOR.TXT"));
    treinos.setNome(nome);

    int n;
    int* vetor_invertido = new int[treinos.getContador()];

    ifstream arquivo(treinos.getNome());
    if(arquivo.is_open()){
        for(int i = treinos.getContador() - 1; i >= 0; i--){
            arquivo >> n;
            treinos.setN(n);
            vetor_invertido[i] = treinos.getN();
        }
        arquivo.close();
    }

    return vetor_invertido;
}

void exercicio03(void){

    Treino treinos;

    treinos.setContador(Quantidade_Elementos("VETOR.TXT"));

    int* vetor_invertido = Vetor_Invertido("VETOR.TXT");

    ofstream arquivo2("VETOR_INVERTIDO.TXT");
    if(arquivo2.is_open()){
        for(int i = 0; i < treinos.getContador(); i++){
           cout << vetor_invertido[i] << "\t";
           arquivo2 << vetor_invertido[i] << "\t";
        }
        cout << endl;
    }
    arquivo2.close();
}

//--------------------------------------------------//

int *Vetor_Crescente(const string name){

    Treino treinos;

    treinos.setContador(Quantidade_Elementos("VETOR.TXT"));
    treinos.setNome(name);

    int n, cont = 0, temp;
    int* vetor_crescente = new int[treinos.getContador()];

    ifstream arquivo(treinos.getNome());
    if(arquivo.is_open()){
        for(int i = 0; i < treinos.getContador(); i++){
            arquivo >> n;
            vetor_crescente[i] = n;
        }

        while(cont != treinos.getContador()){
            for(int i = 0; i < treinos.getContador()-1; i++){
                if(vetor_crescente[i] > vetor_crescente[i+1]){
                    temp = vetor_crescente[i];
                    vetor_crescente[i] = vetor_crescente[i+1];
                    vetor_crescente[i+1] = temp;
                }
            }
            cont++;
        }
        arquivo.close();
    }

    return vetor_crescente;
}

void exercicio04(void){

    Treino treinos;

    treinos.setContador(Quantidade_Elementos("VETOR.TXT"));

    int* vetor_crescente = Vetor_Crescente("VETOR.TXT");

    ofstream arquivo2("VETOR_CRESCENTE.TXT");
    if(arquivo2.is_open()){
        for(int i = 0; i < treinos.getContador(); i++){
           cout << vetor_crescente[i] << "\t";
           arquivo2 << vetor_crescente[i] << "\t";
        }
        cout << endl;
    }
    arquivo2.close();
}

//--------------------------------------------------//

int *Vetor_Decrescente(const string name){

    Treino treinos;

    treinos.setContador(Quantidade_Elementos("VETOR.TXT"));
    treinos.setNome(name);

    int n, cont = 0, temp;
    int* vetor_decrescente = new int[treinos.getContador()];

    ifstream arquivo(treinos.getNome());
    if(arquivo.is_open()){
        for(int i = 0; i < treinos.getContador(); i++){
            arquivo >> n;
            vetor_decrescente[i] = n;
        }

        while(cont != treinos.getContador()){
            for(int i = 0; i < treinos.getContador(); i++){
                if(vetor_decrescente[i] < vetor_decrescente[i+1]){
                    temp = vetor_decrescente[i];
                    vetor_decrescente[i] = vetor_decrescente[i+1];
                    vetor_decrescente[i+1] = temp;
                }
            }
            cont++;
        }
        arquivo.close();
    }
    return vetor_decrescente;
}

void exercicio05(void){

    Treino treinos;

    treinos.setContador(Quantidade_Elementos("VETOR.TXT"));

    int* vetor_decrescente = Vetor_Decrescente("VETOR.TXT");

    ofstream arquivo2("VETOR_DECRESCENTE.TXT");
    if(arquivo2.is_open()){
        for(int i = 0; i < treinos.getContador(); i++){
           cout << vetor_decrescente[i] << "\t";
           arquivo2 << vetor_decrescente[i] << "\t";
        }
        cout << endl;
    }
    arquivo2.close();
}

//--------------------------------------------------//

int Vetor_Compara(const string name, int tam2, int *vetor2){

    Treino treinos;

    treinos.setContador(Quantidade_Elementos("VETOR.TXT"));
    treinos.setNome(name);

    int n, cont = 0;
    int* vetor1 = new int[treinos.getContador()];

    ifstream arquivo(treinos.getNome());
    if(arquivo.is_open()){

        if(tam2 == treinos.getContador()){
            for(int i = 0; i < tam2; i++){
                arquivo >> n;
                vetor1[i] = n;
                if(vetor1[i] == vetor2[i]){
                    cont++;
                }
            }
        }else{
            return cont;
        }
    }
    return cont;
}

void exercicio06(void){

    Treino treinos;

    string nome;
    int tam;
    int n;

    ofstream arquivo ("VETOR2.TXT");
        if (arquivo.is_open()) {

        cout << "Qual sera o tamanho do novo vetor: ";
        cin >> tam;

        treinos.setLinhas(tam);

        int* vetor = new int[treinos.getLinhas()];

        cout << "Novo vetor:" << endl;

        for (int i = 0; i < treinos.getLinhas(); i++) {
            vetor[i] = rand() % 100;
            cout << vetor[i] << "\t";
            arquivo << vetor[i] << "\t";
        }
        cout << endl;
        arquivo.close();

        int resultado = Vetor_Compara("VETOR.TXT", treinos.getLinhas(), vetor);

        if (resultado == tam) {
            cout << "Os vetores sao iguais!" << endl;
        } else if (resultado < tam && resultado > 0) {
            cout << "Os vetores sao diferentes!" << endl;
        } else if (resultado == 0) {
            cout << "Os vetores tem tamanhos diferentes!" << endl;
        }

        delete[] vetor;
    }
}

//--------------------------------------------------//

double Media_Vetor(const string name){

    Treino treinos;

    treinos.setContador(Quantidade_Elementos("VETOR.TXT"));
    treinos.setNome(name);

    int n, soma = 0;
    int* vetor = new int[treinos.getContador()];

    ifstream arquivo(treinos.getNome());
    if(arquivo.is_open()){
        for(int i = 0; i < treinos.getContador(); i++){
            arquivo >> n;
            vetor[i] = n;
            soma = soma + vetor[i];
            treinos.setSoma(soma);
        }
    }

    double media = treinos.getSoma() / treinos.getContador();

    arquivo.close();
    delete[] vetor;

    return media;
}

double Mediana_Vetor(const string name){

    Treino treinos;

    treinos.setContador(Quantidade_Elementos("VETOR.TXT"));
    treinos.setNome(name);

    int n;
    double soma = 0;
    int media = treinos.getContador() / 2;
    int* vetor = new int[treinos.getContador()];

    ifstream arquivo(treinos.getNome());;
    if(arquivo.is_open()){
        for(int i = 0; i < treinos.getContador(); i++){
            arquivo >> n;
            vetor[i] = n;
        }

        if(media%2 != 0){
            for(int i = media; i > media+1; i++){
                soma = soma + vetor[i];
                treinos.setSoma(soma);
            }
            return treinos.getSoma() / 2;
        }else if(media%2 == 0){
          return vetor[media];
        }
    }
    arquivo.close();
}

void exercicio07(void){

    double media = Media_Vetor("VETOR.TXT");
    int mediana = Mediana_Vetor("VETOR.TXT");

    ofstream arquivo("MEDIA_MEDIANA_VETOR.TXT");
    if(arquivo.is_open()){
        cout << fixed << setprecision(2) << "A media do vetor e: " << media << endl;
        arquivo << fixed << setprecision(2) << "A media do vetor e: " << media << endl;

        cout << fixed << setprecision(2) << "A mediana do vetor e: " << mediana << endl;
        arquivo << fixed << setprecision(2) << "A mediana do vetor e: " << mediana << endl;
    }

    arquivo.close();
}

//--------------------------------------------------//

int* Vetor_Intersecao(const string& name, const string& name2, int& tam_intersecao) {
    int cont1 = Quantidade_Elementos(name);
    int cont2 = Quantidade_Elementos(name2);

    int* vetor1 = new int[cont1];
    int* vetor2 = new int[cont2];

    ifstream arquivo1(name);
    for (int i = 0; i < cont1; i++) {
        arquivo1 >> vetor1[i];
    }
    arquivo1.close();

    ifstream arquivo2(name2);
    for (int i = 0; i < cont2; i++) {
        arquivo2 >> vetor2[i];
    }
    arquivo2.close();

    int* temp_intersecao = new int[cont1 < cont2 ? cont1 : cont2];
    tam_intersecao = 0;

    for (int i = 0; i < cont1; i++) {
        bool achou = false;
        for (int j = 0; j < cont2; j++) {
            if (vetor1[i] == vetor2[j]) {
                achou = true;
            }
        }
        if (achou) {
            bool ja_presente = false;
            for (int k = 0; k < tam_intersecao; k++) {
                if (temp_intersecao[k] == vetor1[i]) {
                    ja_presente = true;
                }
            }
            if (!ja_presente) {
                temp_intersecao[tam_intersecao] = vetor1[i];
                tam_intersecao++;
            }
        }
    }

    int* vetor_intersecao = new int[tam_intersecao];
    for (int i = 0; i < tam_intersecao; i++) {
        vetor_intersecao[i] = temp_intersecao[i];
    }

    delete[] vetor1;
    delete[] vetor2;
    delete[] temp_intersecao;

    return vetor_intersecao;
}

void exercicio08(){

    int tam_intersecao = 0;
    int* vetor_intersecao = Vetor_Intersecao("VETOR.TXT", "VETOR2.TXT", tam_intersecao);

    for (int i = 0; i < tam_intersecao; i++) {
        cout << vetor_intersecao[i] << "\t";
    }
    cout << endl;

    delete[] vetor_intersecao;
}

//--------------------------------------------------//

int main()
{
    int opcao;

    do{
        cout << "Menu:\n" << endl;
        cout << "1- Exercicio 01;\n"
                "2- Exercicio 02;\n"
                "3- Exercicio 03;\n"
                "4- Exercicio 04;\n"
                "5- Exercicio 05;\n"
                "6- Exercicio 06;\n"
                "7- Exercicio 07;\n"
                "8- Exercicio 08;\n"
                "9- Exercicio 09;\n"
                "10- Exercicio 10;\n"
                "11- Exercicio 11;\n"
                "12- Exercicio 12;\n"
                "Opcao: " << endl;

        cin >> opcao;

        switch(opcao){
            case 0:
                break;

            case 1:
                    cout << "Executando o Exercicio 01.\n";
                    exercicio01();
                    break;

                case 2:
                    cout << "Executando o Exercicio 02.\n";
                    exercicio02();
                    break;

                case 3:
                    cout << "Executando o Exercicio 03.\n";
                    exercicio03();
                    break;

                case 4:
                    cout << "Executando o Exercicio 04.\n";
                    exercicio04();
                    break;

                case 5:
                    cout << "Executando o Exercicio 05.\n";
                    exercicio05();
                    break;

                case 6:
                    cout << "Executando o Exercicio 06.\n";
                    exercicio06();
                    break;

                case 7:
                    cout << "Executando o Exercicio 07.\n";
                    exercicio07();
                    break;

                case 8:
                    cout << "Executando o Exercicio 08.\n";
                    exercicio08();
                    break;

                case 9:
                    cout << "Executando o Exercicio 09.\n";
                    //exercicio09();
                    break;

                case 10:
                    cout << "Executando o Exercicio 10.\n";
                    //exercicio10();
                    break;

                case 11:
                    cout << "Executando o Exercicio 11.\n";
                    //exercicio11();
                    break;

                case 12:
                    cout << "Executando o Exercicio 12.\n";
                    //exercicio12();
                    break;

                default:
                    cout << "Opcao invalida. Tente novamente.\n";
                    break;
            }
    } while(opcao != 0);

return 0;
}
