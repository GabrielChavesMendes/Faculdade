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


}

//--------------------------------------------------//



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
                    //exercicio02();
                    break;

                case 3:
                    cout << "Executando o Exercicio 03.\n";
                    //exercicio03();
                    break;

                case 4:
                    cout << "Executando o Exercicio 04.\n";
                    //exercicio04();
                    break;

                case 5:
                    cout << "Executando o Exercicio 05.\n";
                    //exercicio05();
                    break;

                case 6:
                    cout << "Executando o Exercicio 06.\n";
                    //exercicio06();
                    break;

                case 7:
                    cout << "Executando o Exercicio 07.\n";
                    //exercicio07();
                    break;

                case 8:
                    cout << "Executando o Exercicio 08.\n";
                    //exercicio08();
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
