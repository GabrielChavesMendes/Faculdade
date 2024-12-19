#include <bits/stdc++.h>

using namespace std;

class Desafio{

private:
    int termo_ini;
    int termo_final;
    int termo;
    int indice;
    string arquivo;

public:
    //CONSTRUTOR
    Desafio(){
        termo_ini = 0;
        termo_final = 0;
        termo = 0;
        indice = 0;
        arquivo = "";
    }

    Desafio(int termo_i, int termo_f, int ter, int ind, string name){
        this->termo_ini = termo_i;
        this->termo_final = termo_f;
        this->termo = ter;
        this->indice = ind;
        this->arquivo = name;
    }

    //GET E SET
    void setTermo_I(int ter_i){
        termo_ini = ter_i;
    }

    int getTermo_I(){
        return termo_ini;
    }

    void setTermo_F(int ter_f){
        termo_final = ter_f;
    }

    int getTermo_F(){
        return termo_final;
    }

    void setTermo(int ter){
        termo = ter;
    }

    int getTermo(){
        return termo;
    }

    void setIndice(int ind){
        indice = ind;
    }

    int getIndice(){
        return indice;
    }

    void setArquivo(string name){
        arquivo = name;
    }

    string getArquivo(){
        return arquivo;
    }
};

//SOMATORIO
int Somatorio(int ini, int fim, int termo){

    if(ini > fim){
        return 0;
    }

    int somatorio = pow(ini, termo);

    return somatorio + Somatorio(ini + 1, fim, termo);
}

//FATORIAL
int Fatorial(int termo){

    if(termo == 0 || termo == 1){
        return 1;
    }

    return termo * Fatorial(termo - 1);
}

int main(void){

    Desafio desafios;

    int n, ini, fim;

    cout << "Escreva o termo inicial: ";
    cin >> ini;
    desafios.setTermo_I(ini);

    cout << endl << "Escreva o termo final: ";
    cin >> fim;
    desafios.setTermo_F(fim);

    cout << endl << "Agora indique o termo a ser usado: ";
    cin >> n;
    desafios.setTermo(n);

    string name;

    cout << "Digite o nome do arquivo: ";
    cin >> name;
    desafios.setArquivo(name);

    ofstream arquivo(desafios.getArquivo());
    if(arquivo.is_open()){
        int somatorio = Somatorio(desafios.getTermo_I(), desafios.getTermo_F(), desafios.getTermo());

        cout << endl << somatorio;
        arquivo << "O somatorio e: " << somatorio << endl;

        int fatorial = Fatorial(desafios.getTermo_F());

        cout << endl << fatorial;
        arquivo << "O fatorial e: " << fatorial << endl;
    }

    arquivo.close();

return 0;
}
