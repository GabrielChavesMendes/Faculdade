/*
 Exemplo1400 - v1.8. - _09_ / _06_ / _2024_
 Author: ___Gabriel_Chaves_Mendes___

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo1400 exemplo1400.c
 Windows: gcc -o exemplo1400 exemplo1400.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo1400
 Windows: exemplo1400

    * Exemplo1400_v0.0
        EXEMPLO1400 - Programa - v0.0

        Opcoes
         0 - parar
         1 - testar definicoes

        Entrar com uma opcao: 1

        Method_01 - v0.0


        Apertar ENTER para continuar

*/

/*
 Exemplo1400 - v0.0. - __ / __ / _____
 Author: _____________________________
*/
// ----------------------------------------------- preparacao
// dependencias
#include <iostream>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo
// outras dependencias
void pause ( std::string text )
{
 std::string dummy;
 std::cin.clear ( );
 std::cout << std::endl << text;
 std::cin.ignore( );
 std::getline(std::cin, dummy);
 std::cout << std::endl << std::endl;
} // end pause ( )
// ----------------------------------------------- classes
#include "Erro.hpp" // classe para tratar erros
class MyString : public Erro
{
 public:
 /**
 * Funcao para obter mensagem
 * relativa ao código de erro.
 * @return mensagem sobre o erro
 */
 std::string getErroMsg ( )
 {
 return ( NO_ERROR ); // COMPLETAR A DEFINICAO
 } // end getErroMsg ( )
}; // end classe MyString
// ----------------------------------------------- definicoes globais
using namespace std;
// ----------------------------------------------- metodos

/**
 Method_00 - nao faz nada.
*/
void method_00 ( )
{
// nao faz nada
} // end method_00 ( )

// ----------------------------------------------- //

/**
 Method_01 - Testar definicoes da classe.
*/
void method_01 ( )
{
// definir dados
 MyString *s = new MyString ( );
// identificar
 cout << "\nMethod_01 - v0.0\n" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

// ----------------------------------------------- acao principal

/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( int argc, char** argv )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// repetir at  desejar parar
 do
 {
 // identificar
 cout << "EXEMPLO1400 - Programa - v0.0\n " << endl;
 // mostrar opcoes
 cout << "Opcoes " << endl;
 cout << " 0 - parar " << endl;
 cout << " 1 - testar definicoes" << endl;

 // ler do teclado
 cout << endl << "Entrar com uma opcao: ";
 cin >> x;
 // escolher acao
 switch ( x )
 {
 case 0: break;
 case 1: method_01 ( ); break;
 default:
 cout << endl << "ERRO: Valor invalido." << endl;
 } // end switch
 }
 while ( x != 0 );
// encerrar
 pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // end main ( )

/*
----------------------------------------------
----------------------------------------------
//ANOTACOES/ NOTAS/ OBSERVACOES:
- v0.0 Testar as definicoes da classe e da biblioteca Erro.hpp -
----------------------------------------------
----------------------------------------------

----------------------------------------------
----------------------------------------------
Versao Data Modificacao
0.0 _09_/_06_ esboco e adicao do method_01

----------------------------------------------
----------------------------------------------

---------------------------------------------- testes

----------------------------------------------
----------------------------------------------
Versao Teste
0.0 00. ( _OK_ ) identificacao de programa
----------------------------------------------
*/

