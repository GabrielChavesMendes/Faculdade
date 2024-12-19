/**
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Exercicio pratico: ed13_+_EXTRAS
  *
  * Matricula: 1453522  Nome: Gabriel_Chaves_Mendes
  * Versao:  1.0                Data: 28/05/2024
  *
  * Dados:
  * - Feito na IDE CodeBlocks
  *
  * Resultados(SAIDAS):
    * - Exercício 1311:
        Opcao:
        1
        Executando o Metodo 1311.
        Escreva um nome: Gabriel
        Nome: Gabriel

    * - Exercício 1312:
        Opcao:
        2
        Executando o Metodo 1312.
        Escreva agora o numero do telefone: (31)98911-0304
        Numero: (31)98911-0304

    * - Exercício 1313:
        Opcao:
        3
        Executando o Metodo 1313.
        Escreva agora o numero do telefone: 3198911-0304
        Numero valido.
        Numero: 3198911-0304

    * - Exercício 1314:
        Opcao:
        4
        Executando o Metodo 1314.
        Arquivo aberto!
        Escreva um nome: Gabriel
        Escreva agora o numero do telefone: 3198911-0304
        Numero valido.
        Arquivo aberto para leitura
        O nome no arquivo e: Gabriel
        O telefone no arquivo e: 3198911-0304

    * - Exercício 1315:
        Opcao:
        5
        Executando o Metodo 1315.
        Arquivo aberto para adicionar!
        Escreva um nome: Arthur
        Escreva agora o numero do telefone: 3199857-1435
        Numero valido.
        NO ARQUIVO:
        Nome:
        Gabriel
        Numero:
        3198911-0304

        Nome:
        Arthur
        Numero:
        3199857-1435

    * - Exercício 1316:
        Opcao:
        6
        Executando o Metodo 1316.
        Escreva um nome: Joao
        Nome: Joao
        Escreva agora o numero do telefone: 3199815-1685
        Numero valido.
        Numero: 3199815-1685
        Escreva um segundo numero do telefone: 3198963-2270
        Numero valido.
        Segundo Numero: 3198963-2270

    * - Exercício 1317:
        Opcao:
        7
        Executando o Metodo 1317.
        Arquivo aberto para leitura
        Usuario 1 tem 1 telefone!
        Usuario 2 tem 2 telefone!

    * - Exercício 1318:
        Opcao:
        8
        Executando o Metodo 1318.
        Arquivo aberto para leitura
        Voce quer adicionar outro numero para Gabriel? (sim/nao)
        sim
        Escreva um segundo numero do telefone: 3198915-2085
        Numero valido.
        Segundo Numero: 3198915-2085
        Voce quer adicionar outro numero para Arthur? (sim/nao)
        nao
        No arquvio:
            Nome:
            Gabriel
            Numero:
            3198911-0304
            Segundo Numero: 3198915-2085

            Nome:
            Arthur
            Numero:
            3199857-1435
            3197423-9950

    * - Exercício 1319:
        Opcao:
        9
        Executando o Metodo 1319.
        Arquivo aberto para leitura
        Deseja trocar o segundo telefone de Gabriel? (sim/nao)
        sim
        Escreva um segundo numero do telefone: 3199897-1453
        Numero valido.
        Segundo Numero atualizado: 3199897-1453
        Erro!
        Arthur possui apenas um numero.
        No arquivo:
            Nome:
            Gabriel
            Numero:
            3198911-0304
            Segundo Numero: 3199897-1453

            Nome:
            Arthur
            Numero:
            3199857-1435

    * - Exercício 1320:
        Opcao:
        10
        Executando o Metodo 1320.
        Arquivo aberto para leitura
        Deseja excluir o segundo telefone de Gabriel? (sim/nao)
        sim
        Segundo Numero excluido.
        Erro!
        Arthur possui apenas um numero.
        No arquivo:
            Nome:
            Gabriel
            Numero:
            3198911-0304


            Nome:
            Arthur
            Numero:
            3199857-1435

    * - Exercício 13E1:
        Opcao:
        11
        Executando o Metodo 13E1.
        Arquivo aberto para leitura
        O arquivo ainda possui 2 contatos!
        Deseja adicionar outro?  (sim/nao)
        sim
        Arquivo aberto para adicionar!
        Escreva um nome: Luiza
        Escreva agora o numero do telefone: 3198955-5741
        Numero valido.
        No arquvio:
            Nome:
            Gabriel
            Numero:
            3198911-0304

            Nome:
            Arthur
            Numero:
            3199857-1435

            Nome:
            Luiza
            Numero:
            3198955-5741

    * - Exercício 13E2:
        Opcao:
        12
        Executando o Metodo 13E2.
        Arquivo aberto para leitura
        Conteudo na matriz dentro_arquivo:
        Nome:
        Gabriel
        Nome:
        Arthur
        Nome:
        Yasmin
        Conteudo na matriz enderecos:
        Endereco Residencial:
        Rua Alameda, 94
        Endereco Profissional:
        Rua Comendador, 115
        Endereco Residencial:
        Rua Igarape, 88
        Endereco Profissional:
        Av Contorno, 725
        Endereco Residencial:
        Rua Esmeraldas, 120
        Endereco Profissional:
        Av Coronel Paixao, 1470

    */



//BIBLIOTECAS
#include <bits/stdc++.h>

using namespace std;

//------------------METODOS-----------------------//

class Cadeia {
private:
    string name;
    string telefone;

    int Numero_Valido(string numero) {
        int cont = 0;
        int cont2 = numero.length();

        for (char c : numero) {
            if ((c >= '0' && c <= '9') || c == '-') {
                cont++;
            }
        }

        if (cont == cont2) {
            return 0;
        } else {
            return 1;
        }
    }

    string guardar_name;
    string guardar_fone;
    string segundo_telefone;

    int quantidade;

    int Quantidade_Telefone(string numero) {
        int cont = 0;
        for (char c : numero) {
            if ((c >= '0' && c <= '9') || c == '-') {
                cont++;
            }
        }
        if (cont >= 8) {
            return 1;
        } else {
            return 0;
        }
    }

    string residencia;
    string profissao;


public:
    Cadeia(string nome) : name(nome), telefone("") {}

    // Métodos GET e SET
    string getNome() {
        return name;
    }

    void setNome_1311(string nome) {
        cout << "Escreva um nome: ";
        cin >> nome;
        this->name = nome;
    }

//--------------------------------------------------//

    string getNumero() {
        return telefone;
    }

    void setNumero_1312_1313() {
        cout << "Escreva agora o numero do telefone: ";
        cin >> telefone;

        if (Numero_Valido(telefone) == 0) {
            cout << "Numero valido." << endl;
        } else {
            cout << "Numero invalido." << endl;
        }
    }

//--------------------------------------------------//

    void Pegar_Info_1314(const char *name){

        string nome;
        string fone;

        ifstream  arquivo(name);
        if(arquivo.is_open()){
            cout << "Arquivo aberto para leitura" << endl;

            string linha;

            getline(arquivo, linha);

            getline(arquivo, nome);
            setGuarda_Nome(nome);

            getline(arquivo, linha);

            getline(arquivo, fone);
            setGuarda_Fone(fone);
        }

        cout << "O nome no arquivo e: " << getGuarda_Nome() << endl;
        cout << "O telefone no arquivo e: " << getGuarda_Fone() << endl;
    }

//--------------------------------------------------//

    void Add_Info_1315(const char *name){

        ofstream arquivo(name, ios::app);
        if(arquivo.is_open()){

            cout << "Arquivo aberto para adicionar!" << endl;

            arquivo << endl;

            setNome_1311(name);
            string nome_cadeia = getNome();
            arquivo << "Nome: " << endl << nome_cadeia << endl;

            setNumero_1312_1313();
            string telefone = getNumero();
            arquivo << "Numero: " << endl << telefone << endl;

            string residencial;
            setResidencia_13E2(residencial);
            arquivo << "Endereco Residencial: " << endl << getResidencia() << endl;

            string profissional;
            setProfissao_13E2(profissional);
            arquivo << "Endereco Profissional: " << endl << getProfissao() << endl;
        }
        arquivo.close();
    }

//--------------------------------------------------//

    void Quantidade_Numeros_1317(const char *name){

        int indice = 0;

        ifstream  arquivo(name);
        if(arquivo.is_open()){
            cout << "Arquivo aberto para leitura" << endl;

            string linha;

            while(!arquivo.eof()){
                int cont = 0;
                while(getline(arquivo, linha) && linha != ""){
                    if(Quantidade_Telefone(linha)){
                        cont++;
                        setQuantidade(cont);
                    }
                }
                cout << "Usuario " << indice + 1 << " tem " << getQuantidade() << " telefone!" << endl;
                indice++;
            }
        }
        arquivo.close();
    }

//--------------------------------------------------//

    void Segundo_Numero_1318(const char *name){

        string linha;
        int numero_linhas = 0;

        ifstream arquivo(name);

        while (getline(arquivo, linha)) {
            numero_linhas++; //NUMEROS DE LINHAS DENTRO DO ARQUVIO
        }

        arquivo.close();

        string* dentro_arquivo = new string[numero_linhas];

        ifstream arquivo_novo(name);

        if (arquivo_novo.is_open()) {
            cout << "Arquivo aberto para leitura" << endl;

            int i = 0;

            while (getline(arquivo_novo, linha)) {
                dentro_arquivo[i++] = linha; //PREENCHENDO A MATRIZ COM O CONTEUDO DO ARQUIVO
            }

            arquivo_novo.close();
        }

        for (int i = 0; i < numero_linhas; ++i) {

            if (dentro_arquivo[i].find("Nome:") != string::npos) { // .find PROCURA CERTA STRING NA MATRIZ E RETORNA A POSICAO DELA
                                                                   // string::npos RETORNA -1, OU SEJA, A STRING NAO FOI ACHADA
                int cont = 0;
                int j = i + 1;

                // WHILE PARA CONTINUAR CONTANDO QUANTOS NUMEROS O USARIO TEM ATE ENCONTRAR UMA LINHA VAZIA OU UMA STRING "Nome:"
                while (j < numero_linhas && !dentro_arquivo[j].empty() && dentro_arquivo[j].find("Nome:") == string::npos) { // .empty VERIFICA SE A STRING TA VAZIA

                    if (Quantidade_Telefone(dentro_arquivo[j])) {
                        cont++;
                    }
                    j++;
                }

                setQuantidade(cont);

                if (getQuantidade() == 1) {

                    string adcionar;

                    cout << "Voce quer adicionar outro numero para " << dentro_arquivo[i + 1] << "? (sim/nao)" << endl;
                    cin >> adcionar;

                    if (adcionar == "sim") {

                        setNumero_Segundo_1316();

                        string telefone_segundo = getNumero_Segundo();

                        //AUMENTA O TAMANHO DA MATRIZ PARA ADICIONAR OUTRO NUMERO
                        string* nova_matriz_conteudo = new string[numero_linhas + 2];

                        for (int k = 0; k < j; ++k) {
                            nova_matriz_conteudo[k] = dentro_arquivo[k];
                        }

                        nova_matriz_conteudo[j] = "Segundo Numero: " + telefone_segundo;

                        for (int k = j + 1; k <= numero_linhas; ++k) {
                            nova_matriz_conteudo[k] = dentro_arquivo[k - 1];
                        }

                        delete[] dentro_arquivo;

                        dentro_arquivo = nova_matriz_conteudo;
                        numero_linhas++;

                        cout << "Segundo Numero: " << telefone_segundo << endl;
                    }
                }
            }
        }

        // REESCREVE NO ARQUIVO O CONTEUDO QUE ESTA NA MATRIZ
        ofstream arquivo_reescrever(name, ios::out | ios::trunc);

        if (arquivo_reescrever.is_open()) {

            for (int i = 0; i < numero_linhas; ++i) {
                arquivo_reescrever << dentro_arquivo[i] << endl;
            }

            arquivo_reescrever.close();
        }
        delete[] dentro_arquivo;
    }

//--------------------------------------------------//

    void Alterar_Numero_1319(const char *name){

        string linha;
        int numero_linhas = 0;

        ifstream arquivo(name);

        while (getline(arquivo, linha)) {
            numero_linhas++;
        }

        arquivo.close();

        string* dentro_arquivo = new string[numero_linhas];

        ifstream arquivo_novo(name);

        if (arquivo_novo.is_open()) {
            cout << "Arquivo aberto para leitura" << endl;

            int i = 0;

            while (getline(arquivo_novo, linha)) {
                dentro_arquivo[i++] = linha;
            }

            arquivo_novo.close();
        }

        for (int i = 0; i < numero_linhas; ++i) {

            if (dentro_arquivo[i].find("Nome:") != string::npos) {
                int cont = 0;
                int j = i + 1;

                while (j < numero_linhas && !dentro_arquivo[j].empty() && dentro_arquivo[j].find("Nome:") == string::npos) {
                    if (Quantidade_Telefone(dentro_arquivo[j])) {
                        cont++;
                    }
                    j++;
                }

                // SE POSSUIR 2 NUMEROS
                if (cont == 2) {
                    string adicionar;
                    cout << "Deseja trocar o segundo telefone de " <<  dentro_arquivo[i + 1] << "? (sim/nao)" << endl;
                    cin >> adicionar;

                    if(adicionar == "sim") {
                        setNumero_Segundo_1316();
                        string telefone_segundo = getNumero_Segundo();

                        // ATUALIZA O SEGUNDO NUMERO DA MATRIZ
                        for(int k = i + 1; k < numero_linhas; ++k) {
                            if (dentro_arquivo[k].find("Segundo Numero:") != string::npos) {
                                dentro_arquivo[k] = "Segundo Numero: " + telefone_segundo;
                            }
                        }
                        cout << "Segundo Numero atualizado: " << telefone_segundo << endl;
                    }
                }
                // SE TIVER APENAS 1 NUMERO SITUACAO DE ERRO
                else if (cont == 1){
                    erro();
                    cout << dentro_arquivo[i + 1] << " possui apenas um numero." << endl;
                }
            }
        }

        ofstream arquivo_reescrever(name, ios::out | ios::trunc);

        if (arquivo_reescrever.is_open()) {

            for (int i = 0; i < numero_linhas; ++i) {
                arquivo_reescrever << dentro_arquivo[i] << endl;
            }

            arquivo_reescrever.close();
        }
        delete[] dentro_arquivo;
    }

//--------------------------------------------------//

    void Excluir_Segundo_Numero_1320(const char *name){

        string linha;
        int numero_linhas = 0;

        ifstream arquivo(name);

        while (getline(arquivo, linha)) {
            numero_linhas++;
        }

        arquivo.close();

        string* dentro_arquivo = new string[numero_linhas];

        ifstream arquivo_novo(name);

        if (arquivo_novo.is_open()) {
            cout << "Arquivo aberto para leitura" << endl;

            int i = 0;

            while (getline(arquivo_novo, linha)) {
                dentro_arquivo[i++] = linha;
            }

            arquivo_novo.close();
        }

        for (int i = 0; i < numero_linhas; ++i) {

            if (dentro_arquivo[i].find("Nome:") != string::npos) {
                int cont = 0;
                int j = i + 1;

                while (j < numero_linhas && !dentro_arquivo[j].empty() && dentro_arquivo[j].find("Nome:") == string::npos) {
                    if (Quantidade_Telefone(dentro_arquivo[j])) {
                        cont++;
                    }
                    j++;
                }

                // SE POSSUIR 2 NUMEROS
                if (cont == 2) {
                    string excluir;
                    cout << "Deseja excluir o segundo telefone de " <<  dentro_arquivo[i + 1] << "? (sim/nao)" << endl;
                    cin >> excluir;

                    if(excluir == "sim") {
                        // EXCLUI O SEGUNDO NUMERO
                        bool segundo_numero_encontrado = false;

                        for(int k = i + 1; k < numero_linhas; ++k) {
                            if (dentro_arquivo[k].find("Segundo Numero:") != string::npos) {
                                dentro_arquivo[k] = ""; // DEFINE A LINHA DA MATRIZ COMO VAZIA
                                segundo_numero_encontrado = true;
                            }
                        }
                        if (segundo_numero_encontrado) {
                            cout << "Segundo Numero excluido." << endl;
                        } else {
                            cout << "Segundo Numero nao encontrado." << endl;
                        }
                    }
                }
                // SE TIVER APENAS 1 NUMERO, SITUACAO DE ERRO
                else if (cont == 1){
                    erro();
                    cout << dentro_arquivo[i + 1] << " possui apenas um numero." << endl;
                }
            }
        }

        ofstream arquivo_reescrever(name, ios::out | ios::trunc);

        if (arquivo_reescrever.is_open()) {

            for (int i = 0; i < numero_linhas; ++i) {
                arquivo_reescrever << dentro_arquivo[i] << endl;
            }

            arquivo_reescrever.close();
        }
        delete[] dentro_arquivo;
    }

//--------------------------------------------------//

    void Verificar_Quantidade_Contatos_Add_13E1(const char *name){

        string linha;
        string resposta;
        int numero_linha = 0;
        int cont = 0;

        ifstream arquivo(name);

        if(arquivo.is_open()){

            while(getline(arquivo, linha)){
                numero_linha++; //CONTAR QUANTIDADE LINHAS DENTRO DO ARQUIVO
            }
        }

        arquivo.close();

        string* dentro_arquivo = new string[numero_linha]; //MATRIZ DINAMICA

        ifstream arquivo_novo(name);

        if (arquivo_novo.is_open()) {
            cout << "Arquivo aberto para leitura" << endl;

            int i = 0;

            while (getline(arquivo_novo, linha)) {
                dentro_arquivo[i++] = linha; //ALOCA DENTRO DA MATRIZ OS CONTEUDOS DENTRO DO ARQUIVO
            }

            arquivo_novo.close();
        }

        for (int i = 0; i < numero_linha; ++i) {
            if (dentro_arquivo[i].find("Nome:") != string::npos) { //SE NA MATRIZ ACHAR A STRING "Nome:" RETORNA A POSICAO DELA
                int j = i + 1;
                bool contatoEncontrado = false;

                while (j < numero_linha && !dentro_arquivo[j].empty() && dentro_arquivo[j].find("Nome:") == string::npos) {
                    //SE NA MATRIZ NAO FOR VAZIO E ACHAR A STRING "Nome:" RETORNA A POSICAO DELA
                    if (dentro_arquivo[j].find("Nome:") == string::npos) {
                    contatoEncontrado = true; // SE ENCONTRAR A STRING "Nome:" A VARIAVEL SE TORNA TRUE
                    }
                    j++;
                }
                if (contatoEncontrado) {
                    cont++; // ACRESCENTA SEMPRE QUE contatoEncotrado FOR TRUE
                    setQuantidade(cont);
                }
            }
        }

        if(getQuantidade() < 10){

            cout << "O arquivo ainda possui " << getQuantidade() << " contatos!" << endl;
            cout << "Deseja adicionar outro?  (sim/nao)" << endl;
            cin >> resposta;

            if(resposta == "sim"){
                Add_Info_1315(name);
            }
        }else if(getQuantidade() >= 10){
            cout << "Numero de contatos atingido!" << endl;
        }
    }

//--------------------------------------------------//

    void Endereco_13E2(const char *name){
        string linha;
        int numero_linha = 0;
        int endereco_index = 0;

        ifstream arquivo(name);

        if(arquivo.is_open()){
            while(getline(arquivo, linha)){
                numero_linha++;
            }
        }

        arquivo.close();

        string* dentro_arquivo = new string[numero_linha];
        string* enderecos = new string[numero_linha];

        ifstream arquivo_novo(name);

        if (arquivo_novo.is_open()) {
            cout << "Arquivo aberto para leitura" << endl;

            int i = 0;

            while (getline(arquivo_novo, linha)) {
                dentro_arquivo[i++] = linha;

                if (linha.find("Endereco Residencial:") != string::npos || linha.find("Endereco Profissional:") != string::npos) {
                    enderecos[endereco_index++] = linha;
                    getline(arquivo_novo, linha);
                    enderecos[endereco_index++] = linha;
                }
            }

            arquivo_novo.close();
        }

        cout << "Conteudo na matriz dentro_arquivo: " << endl;
        for (int i = 0; i < numero_linha; ++i) {
            if (dentro_arquivo[i].find("Nome:") != string::npos) {
                cout << dentro_arquivo[i] << endl;
                cout << dentro_arquivo[i+1] << endl;
                i++;
            }
        }

        cout << "Conteudo na matriz enderecos: " << endl;
        for (int i = 0; i < endereco_index; ++i) {
            cout << enderecos[i] << endl;
        }

        delete[] dentro_arquivo;
        delete[] enderecos;
    }

//--------------------------------------------------//

    void Criar_Arquivo(void){

        string name;

        ofstream arquivo("DADOS.TXT");
        if(arquivo.is_open()){
            cout << "Arquivo aberto!" << endl;

            setNome_1311(name);
            string nome_cadeia = getNome();
            arquivo << "Nome: " << endl << nome_cadeia << endl;

            setNumero_1312_1313();
            string telefone = getNumero();
            arquivo << "Numero: " << endl << telefone << endl;
        }

        arquivo.close();
    }

//-------------------GET E SET-------------------------//

    string getGuarda_Nome() {
        return guardar_name;
    }

    void setGuarda_Nome(string guarda_name) {
        this->guardar_name = guarda_name;
    }

    string getGuarda_Fone() {
        return guardar_fone;
    }

    void setGuarda_Fone(string guarda_fone) {
        this->guardar_fone = guarda_fone;
    }

//--------------------------------------------------//

    string getNumero_Segundo() {
            return segundo_telefone;
    }

    void setNumero_Segundo_1316() {
        cout << "Escreva um segundo numero do telefone: ";
        cin >> segundo_telefone;

        if (Numero_Valido(segundo_telefone) == 0) {
            cout << "Numero valido." << endl;
        } else {
            cout << "Numero invalido." << endl;
        }
    }

    void setGuardar_Segundo_Numero_1318(string segundo_numero){
        this->segundo_telefone = segundo_numero;
    }

//--------------------------------------------------//

    int getQuantidade() {
        return quantidade;
    }

    void setQuantidade(int quantos) {
        this->quantidade = quantos;
    }

//---------------------ERROR------------------------//

    void erro(void){
        cout << "Erro!" << endl;
    }

//---------------------GET E SET(ENDERECO)----------------------//

    string getResidencia() {
            return residencia;
        }

    void setResidencia_13E2(string &residencial) {
        cout << "Escreva o endereco residencial: ";
        cin.ignore(); // Ignora o newline deixado pelo cin anterior
        getline(cin, residencial);
        this->residencia = residencial;
    }

    string getProfissao() {
            return profissao;
        }

    void setProfissao_13E2(string &profissional) {
        cout << "Escreva o endereco profissional: ";
        getline(cin, profissional);
        this->profissao = profissional;
    }

};

//-----------------PROCEDIMENTOS-----------------//

void procedimento1311(void){

    string name;
    Cadeia cadeia(name);

    cadeia.setNome_1311(name);
    string nome_cadeia = cadeia.getNome();
    cout << "Nome: " << nome_cadeia << endl;
}

//--------------------------------------------------//

void procedimento1312(void) {
    Cadeia cadeia("");

    cadeia.setNumero_1312_1313();
    string telefone = cadeia.getNumero();
    cout << "Numero: " << telefone << endl;
}

//--------------------------------------------------//

void procedimento1314(void) {

    Cadeia cadeia("");

    cadeia.Criar_Arquivo();

    cadeia.Pegar_Info_1314("DADOS.TXT");
}

//--------------------------------------------------//

void procedimento1315(void) {

    Cadeia cadeia("");

    cadeia.Add_Info_1315("DADOS.TXT");
}

//--------------------------------------------------//

void procedimento1316(void) {

    string name;

    Cadeia cadeia("");

    //NOME
    cadeia.setNome_1311(name);
    string nome_cadeia = cadeia.getNome();
    cout << "Nome: " << nome_cadeia << endl;

    //PRIMEIRO NUMERO
    cadeia.setNumero_1312_1313();
    string telefone = cadeia.getNumero();
    cout << "Numero: " << telefone << endl;

    //SEGUNDO NUMERO
    cadeia.setNumero_Segundo_1316();
    string telefone_dois = cadeia.getNumero_Segundo();
    cout << "Segundo Numero: " << telefone_dois << endl;
}

//--------------------------------------------------//

void procedimento1317(void){

    Cadeia cadeia("");

    cadeia.Quantidade_Numeros_1317("DADOS.TXT");
}

//--------------------------------------------------//

void procedimento1318(void){

    Cadeia cadeia("");

    cadeia.Segundo_Numero_1318("DADOS.TXT");
}

//--------------------------------------------------//

void procedimento1319(void){

    Cadeia cadeia("");

    cadeia.Alterar_Numero_1319("DADOS.TXT");
}

//--------------------------------------------------//

void procedimento1320(void){

    Cadeia cadeia("");

    cadeia.Excluir_Segundo_Numero_1320("DADOS.TXT");
}

//--------------------------------------------------//

void procedimento13E1(void){

    Cadeia cadeia("");

    cadeia.Verificar_Quantidade_Contatos_Add_13E1("DADOS.TXT");
}

//--------------------------------------------------//

void procedimento13E2(void){

    Cadeia cadeia("");

    cadeia.Endereco_13E2("DADOS.TXT");
}

//--------------------------------------------------//

int main()
{
    int opcao;

   do{
    cout << "Menu:\n" << endl;
    cout << "1- Metodo 1311;\n"
            "2- Metodo 1312;\n"
            "3- Metodo 1313;\n"
            "4- Metodo 1314;\n"
            "5- Metodo 1315;\n"
            "6- Metodo 1316;\n"
            "7- Metodo 1317;\n"
            "8- Metodo 1318;\n"
            "9- Metodo 1319;\n"
            "10- Metodo 1320;\n"
            "11- Metodo 13E1_EXTRA1;\n"
            "12- Metodo 13E2_EXTRA2;\n"
            "Opcao: " << endl;


    cin >> opcao;

    switch(opcao){
        case 0:
            break;

        case 1:
            cout << "Executando o Metodo 1311.\n";
            procedimento1311();
            break;

        case 2:
            cout << "Executando o Metodo 1312.\n";
            procedimento1312();
            break;

        case 3:
            cout << "Executando o Metodo 1313.\n";
            procedimento1312();
            break;

        case 4:
            cout << "Executando o Metodo 1314.\n";
            procedimento1314();
            break;

        case 5:
            cout << "Executando o Metodo 1315.\n";
            procedimento1315();
            break;

        case 6:
            cout << "Executando o Metodo 1316.\n";
            procedimento1316();
            break;

        case 7:
            cout << "Executando o Metodo 1317.\n";
            procedimento1317();
            break;

        case 8:
            cout << "Executando o Metodo 1318.\n";
            procedimento1318();
            break;

        case 9:
            cout << "Executando o Metodo 1319.\n";
            procedimento1319();
            break;

        case 10:
            cout << "Executando o Metodo 1320.\n";
            procedimento1320();
            break;

        case 11:
            cout << "Executando o Metodo 13E1.\n";
            procedimento13E1();
            break;

        case 12:
            cout << "Executando o Metodo 13E2.\n";
            procedimento13E2();
            break;
        default:
            cout << "Opcao invalida. Escolha uma opcao de 1 a 12.\n";
            break;
    }

      cout << "\n";
    }while(opcao != 0);

return 0;
}
