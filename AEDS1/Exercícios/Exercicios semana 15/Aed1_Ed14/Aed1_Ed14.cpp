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
    * - Exercício 1411:
        Opcao:
        1
        Executando o Metodo 1411.
        Digite um valor inteiro: 10
        Valor inteiro: 10
        Opcao:
        1
        Executando o Metodo 1411.
        Digite um valor inteiro: -15
        Valor inteiro: -15
        Opcao:
        1
        Executando o Metodo 1411.
        Digite um valor inteiro: A15
        Entrada de inteiro invalida.

    * - Exercício 1412:
        Opcao:
        2
        Executando o Metodo 1412.
        Digite um valor real: 15.25
        Valor real: 15.25
        Opcao:
        2
        Executando o Metodo 1412.
        Digite um valor real: -5.25
        Valor real: -5.25
        Opcao:
        2
        Executando o Metodo 1412.
        Digite um valor real: A2.5
        Entrada de valor real invalida.

    * - Exercício 1413:
        Opcao:
        3
        Executando o Metodo 1413.
        Digite um valor booleano: true
        Valor booleano: true
        Opcao:
        3
        Executando o Metodo 1413.
        Digite um valor booleano: T
        Valor booleano: true
        Opcao:
        3
        Executando o Metodo 1413.
        Digite um valor booleano: 1
        Valor booleano: true
        Opcao:
        3
        Executando o Metodo 1413.
        Digite um valor booleano: false
        Valor booleano: false
        Opcao:
        3
        Executando o Metodo 1413.
        Digite um valor booleano: F
        Valor booleano: false
        Opcao:
        3
        Executando o Metodo 1413.
        Digite um valor booleano: 0
        Valor booleano: false

    * - Exercício 1414:
        Opcao:
        4
        Executando o Metodo 1414.
        Digite um texto: 3 pratos de trigo para 3 tigres tristes
        Digite um parametro para verificar se esta contido no texto: 3
        O parametro esta contido no texto.
        Opcao:
        4
        Executando o Metodo 1414.
        Digite um texto: 3 pratos de trigo para 3 tigres tristes
        Digite um parametro para verificar se esta contido no texto: t
        O parametro esta contido no texto.
        Opcao:
        4
        Executando o Metodo 1414.
        Digite um texto: 3 pratos de trigo para 3 tigres tristes
        Digite um parametro para verificar se esta contido no texto: 4
        O parametro nao esta contido no texto.

    * - Exercício 1415:
        Opcao:
        5
        Executando o Metodo 1415.
        Digite um texto para converter para maiusculas: gabriel
        Texto em maiusculas: GABRIEL

    * - Exercício 1416:
        Opcao:
        6
        Executando o Metodo 1416.
        Digite um texto para converter para minusculas: GABRIEL
        Texto em minusculas: gabriel

    * - Exercício 1417:
        Opcao:
        7
        Executando o Metodo 1417.
        Digite um texto: PUC_Minas
        Digite o caractere a ser substituido: U
        Digite o novo caractere: u
        Texto apos substituicao: PuC_Minas

    * - Exercício 1418:
        Opcao:
        8
        Executando o Metodo 1418.
        Digite um texto para codificar: PUC_Minas
        Digite o valor do deslocamento para a cifra de Cesar: 5
        Texto cifrado: ZH_Rnsfx

    * - Exercício 1419:
        Opcao:
        9
        Executando o Metodo 1419.
        Digite o texto para decodificar: UZH_Rnsfx
        Digite o valor do deslocamento utilizado na cifra de Cesar: 5
        Texto decifrado: UC_Minas

    * - Exercício 1420:
        Opcao:
        10
        Executando o Metodo 1420.
        Digite um texto para separar: PUC Minas
        Numero de sequencias separadas: 2
        PUC
        Minas

    * - Exercício 14E1:
        Opcao:
        11
        Executando o Metodo 14E1.
        Digite um texto para fragmentar: Puc_Minas
        Digite o delimitador: _
        Numero de fragmentos separados: 2
        Puc
        Minas

    * - Exercício 14E2:
        Opcao:
        12
        Executando o Metodo 14E2.
        Digite um texto para inverter: Puc_Minas
        Texto invertido: saniM_cuP
    */



//BIBLIOTECAS
#include <bits/stdc++.h>

using namespace std;

//------------------METODOS-----------------------//

int ObterInteiro(const string& entrada) {

    if (entrada.empty()) return -1;

    int sinal = 1;
    size_t inicio = 0;

    if (entrada[0] == '-') {
        sinal = -1;
        inicio = 1;
    } else if (entrada[0] == '+') {
        inicio = 1;
    }

    int resultado = 0;

    for (size_t i = inicio; i < entrada.size(); ++i) {
        if (!isdigit(entrada[i])) {
            return -1;
        }
        resultado = resultado * 10 + (entrada[i] - '0');
    }

    return sinal * resultado;
}

//--------------------------------------------------//

double ObterReal(const string& entrada) {

    if (entrada.empty()) return 0.0;

    int sinal = 1;
    size_t inicio = 0;

    if (entrada[0] == '-') {
        sinal = -1;
        inicio = 1;
    } else if (entrada[0] == '+') {
        inicio = 1;
    }

    double resultado = 0.0;
    double fracao = 0.0;
    double divisor = 10.0;
    bool pontoDecimal = false;

    for (size_t i = inicio; i < entrada.size(); ++i) {
        if (entrada[i] == '.') {
            if (pontoDecimal) return 0.0;
            pontoDecimal = true;
        } else if (isdigit(entrada[i])) {
            if (pontoDecimal) {
                fracao += (entrada[i] - '0') / divisor;
                divisor *= 10.0;
            } else {
                resultado = resultado * 10.0 + (entrada[i] - '0');
            }
        } else {
            return 0.0;
        }
    }

    return sinal * (resultado + fracao);
}

//--------------------------------------------------//

bool ObterBooleano(const string& entrada) {

    string entradaMinuscula = entrada;

    transform(entradaMinuscula.begin(), entradaMinuscula.end(), entradaMinuscula.begin(), ::tolower);

    if(entradaMinuscula == "true" || entradaMinuscula == "t" || entradaMinuscula == "1") {
        return true;

    }else if (entradaMinuscula == "false" || entradaMinuscula == "f" || entradaMinuscula == "0") {
        return false;
    }

    return false;
}

//--------------------------------------------------//

bool Contem(const string& texto, const string& parametro) {

    if (texto.find(parametro) != string::npos) {
        return true;
    }

    return false;
}

//--------------------------------------------------//

string Converter_Maiusculas(string texto) {

    for (size_t i = 0; i < texto.size(); ++i) {
        if (islower(texto[i])) {
            texto[i] = toupper(texto[i]);
        }
    }

    return texto;
}

//--------------------------------------------------//

string Converter_Minusculas(string texto) {

    for (size_t i = 0; i < texto.size(); ++i) {
        if (isupper(texto[i])) {
            texto[i] = tolower(texto[i]);
        }
    }

    return texto;
}

//--------------------------------------------------//

string Ocorrencia(string texto, char original, char novo) {

    for (size_t i = 0; i < texto.size(); ++i) {
        if (texto[i] == original) {
            texto[i] = novo;
        }
    }

    return texto;
}

//--------------------------------------------------//

string Codificar_Cezar(string texto, int shift) {

    for (size_t i = 0; i < texto.size(); ++i) {
        if (isalpha(texto[i])) {
            char base = islower(texto[i]) ? 'a' : 'A';
            texto[i] = ((texto[i] - base + shift) % 26 + 26) % 26 + base;
        }
    }

    return texto;
}

//--------------------------------------------------//

string Decodificar(string texto, int shift) {
    return Codificar_Cezar(texto, 26 - shift);
}

//--------------------------------------------------//

int Separar_Caracteres(const string& texto, string*& sequencias) {

    size_t inicio = 0, fim = 0;
    int quantidade = 0;

    while ((fim = texto.find(' ', inicio)) != string::npos) {
        if (fim != inicio) {
            sequencias[quantidade] = texto.substr(inicio, fim - inicio);
            quantidade++;
        }
        inicio = fim + 1;
    }

    if (inicio < texto.size()) {
        sequencias[quantidade] = texto.substr(inicio);
        quantidade++;
    }

    return quantidade;
}

//--------------------------------------------------//

int Fragmentar(const string& texto, char delimitador, string*& sequencias) {

    size_t inicio = 0, fim = 0;
    int quantidade = 0;

    while ((fim = texto.find(delimitador, inicio)) != string::npos) {
        if (fim != inicio) {
            sequencias[quantidade] = texto.substr(inicio, fim - inicio);
            quantidade++;
        }
        inicio = fim + 1;
    }

    if (inicio < texto.size()) {
        sequencias[quantidade] = texto.substr(inicio);
        quantidade++;
    }

    return quantidade;
}

//--------------------------------------------------//

string Inverter_Ordem(const string& texto) {
    string textoInvertido = texto;
    size_t n = texto.size();
    for (size_t i = 0; i < n / 2; ++i) {
        swap(textoInvertido[i], textoInvertido[n - i - 1]);
    }
    return textoInvertido;
}

//------------------PROCEDIMENTOS-----------------------//

void procedimento1411(void){

    string entrada;

    cout << "Digite um valor inteiro: ";
    cin >> entrada;

    int valorInteiro = ObterInteiro(entrada);

    if(valorInteiro != -1) {
        cout << "Valor inteiro: " << valorInteiro << endl;
    }else {
        cout << "Entrada de inteiro invalida." << endl;
    }

}

void procedimento1412(void){

    string entrada;

    cout << "Digite um valor real: ";
    cin >> entrada;

    double valorReal = ObterReal(entrada);

    if(valorReal != 0.0 || entrada == "0" || entrada == "0.0") {
        cout << "Valor real: " << valorReal << endl;
    }else {
        cout << "Entrada de valor real invalida." << endl;
    }

}

void procedimento1413(void){

    string entrada;

    cout << "Digite um valor booleano: ";
    cin >> entrada;

    bool valorBooleano = ObterBooleano(entrada);

    cout << "Valor booleano: " << (valorBooleano ? "true" : "false") << endl;

}

void procedimento1414(void){

    string texto, parametro;

    cout << "Digite um texto: ";
    cin.ignore();

    getline(cin, texto);

    cout << "Digite um parametro para verificar se esta contido no texto: ";

    getline(cin, parametro);

    if(Contem(texto, parametro)) {
        cout << "O parametro esta contido no texto." << endl;
    }else {
        cout << "O parametro nao esta contido no texto." << endl;
    }

}

void procedimento1415(void){

    string texto;

    cout << "Digite um texto para converter para maiusculas: ";

    cin.ignore();
    getline(cin, texto);

    cout << "Texto em maiusculas: " << Converter_Maiusculas(texto) << endl;
}

void procedimento1416(void){

    string texto;

    cout << "Digite um texto para converter para minusculas: ";

    cin.ignore();
    getline(cin, texto);

    cout << "Texto em minusculas: " << Converter_Minusculas(texto) << endl;
}

void procedimento1417(void){

    string texto;
    char original, novo;

    cout << "Digite um texto: ";

    cin.ignore();
    getline(cin, texto);

    cout << "Digite o caractere a ser substituido: ";
    cin >> original;

    cout << "Digite o novo caractere: ";
    cin >> novo;

    cout << "Texto apos substituicao: " << Ocorrencia(texto, original, novo) << endl;
}

void procedimento1418(void){

    string texto;
    int shift;

    cout << "Digite um texto para codificar: ";
    cin.ignore();

    cin.ignore();
    getline(cin, texto);

    cout << "Digite o valor do deslocamento para a cifra de Cesar: ";
    cin >> shift;

    cout << "Texto cifrado: " << Codificar_Cezar(texto, shift) << endl;
}

void procedimento1419(void){

    string texto;
    int shift;

    cout << "Digite o texto para decodificar: ";
    cin.ignore();

    cin.ignore();
    getline(cin, texto);

    cout << "Digite o valor do deslocamento utilizado na cifra de Cesar: ";
    cin >> shift;

    cout << "Texto decifrado: " << Decodificar(texto, shift) << endl;
}

void procedimento1420(void){

    string texto;
    string* sequencias = nullptr;

    cout << "Digite um texto para separar: ";

    cin.ignore();
    getline(cin, texto);

    sequencias = new string[texto.size()];

    int quantidade = Separar_Caracteres(texto, sequencias);

    cout << "Numero de sequencias separadas: " << quantidade << endl;

    for(int i = 0; i < quantidade; ++i) {
        cout << sequencias[i] << endl;
    }

    delete[] sequencias;
}

void procedimento14E1(void){

    string texto;
    char delimitador;
    string* sequencias = nullptr;

    cout << "Digite um texto para fragmentar: ";

    cin.ignore();
    getline(cin, texto);

    cout << "Digite o delimitador: ";
    cin >> delimitador;

    sequencias = new string[texto.size()];

    int quantidade = Fragmentar(texto, delimitador, sequencias);

    cout << "Numero de fragmentos separados: " << quantidade << endl;

    for (int i = 0; i < quantidade; ++i) {
        cout << sequencias[i] << endl;
    }

    delete[] sequencias;
}

void procedimento14E2(void){

    string texto;

    cout << "Digite um texto para inverter: ";

    cin.ignore();
    getline(cin, texto);

    cout << "Texto invertido: " << Inverter_Ordem(texto) << endl;
}

//--------------------------------------------------//

int main()
{
    int opcao;

    do{
        cout << "Menu:\n" << endl;
        cout << "1- Metodo 1411;\n"
                "2- Metodo 1412;\n"
                "3- Metodo 1413;\n"
                "4- Metodo 1414;\n"
                "5- Metodo 1415;\n"
                "6- Metodo 1416;\n"
                "7- Metodo 1417;\n"
                "8- Metodo 1418;\n"
                "9- Metodo 1419;\n"
                "10- Metodo 1420;\n"
                "11- Metodo 14E1_EXTRA1;\n"
                "12- Metodo 14E2_EXTRA2;\n"
                "Opcao: " << endl;

        cin >> opcao;

        switch(opcao){
            case 0:
                break;

            case 1:
                cout << "Executando o Metodo 1411.\n";
                procedimento1411();
                break;

            case 2:
                cout << "Executando o Metodo 1412.\n";
                procedimento1412();
                break;

            case 3:
                cout << "Executando o Metodo 1413.\n";
                procedimento1413();
                break;

            case 4:
                cout << "Executando o Metodo 1414.\n";
                procedimento1414();
                break;

            case 5:
                cout << "Executando o Metodo 1415.\n";
                procedimento1415();
                break;

            case 6:
                cout << "Executando o Metodo 1416.\n";
                procedimento1416();
                break;

            case 7:
                cout << "Executando o Metodo 1417.\n";
                procedimento1417();
                break;

            case 8:
                cout << "Executando o Metodo 1418.\n";
                procedimento1418();
                break;

            case 9:
                cout << "Executando o Metodo 1419.\n";
                procedimento1419();
                break;

            case 10:
                cout << "Executando o Metodo 1420.\n";
                procedimento1420();
                break;

            case 11:
                cout << "Executando o Metodo 14E1.\n";
                procedimento14E1();
                break;

            case 12:
                cout << "Executando o Metodo 14E2.\n";
                procedimento14E2();
                break;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    } while(opcao != 0);

return 0;
}
