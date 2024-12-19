/*
 Exemplo1300 - v1.8. - _01_ / _06_ / _2024_
 Author: ___Gabriel_Chaves_Mendes___

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo1300 exemplo1300.c
 Windows: gcc -o exemplo1300 exemplo1300.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo1300
 Windows: exemplo1300

    * Exemplo1300_v0.0
        Entrar com uma opcao: 1

        Method_01 - v0.0


        Apertar ENTER para continuar

    * Exemplo1300_v1.0
        Entrar com uma opcao: 2

        Method_02 - v1.0

        pessoa1 - { Pessoa_01, 111 }
        pessoa3 - { Pessoa_03, 333 }

        Apertar ENTER para continuar

    * Exemplo1300_v1.1
        Entrar com uma opcao: 3

        Method_03 - v1.1

        pessoa1 - { Pessoa_01, 111 }
        pessoa3 - { Pessoa_03, 333 }

        Apertar ENTER para continuar

    * Exemplo1300_v1.2
        Entrar com uma opcao: 4

        Method_04 - v1.2

        pessoa1 - { Pessoa_01, 111 }
        pessoa3 - { Pessoa_03, 333 }

        Apertar ENTER para continuar

    * Exemplo1300_v1.3
        Entrar com uma opcao: 5

        Method_05 - v1.3

        pessoa1 - { Pessoa_01, 111 } (0)
        pessoa3 - { , 333 } (1)

        Apertar ENTER para continuar

    * Exemplo1300_v1.4
        Entrar com uma opcao: 6

        Method_06 - v1.4

        pessoa1 - { Pessoa_01, 111 }
        pessoa3 tem erro (1)

        Apertar ENTER para continuar

    * Exemplo1300_v1.5
        Entrar com uma opcao: 7

        Method_07 - v1.5

        pessoa1 - { Pessoa_01, 111 }
        pessoa3 tem erro (1)

        Apertar ENTER para continuar

    * Exemplo1300_v1.6
        Entrar com uma opcao: 8

        EXEMPLO1308 - Method_08 - v1.6

        pessoa2 - { Pessoa_01, 111 }
        pessoa2 - { , 333 }

        Apertar ENTER para continuar

    * Exemplo1300_v1.7
        Entrar com uma opcao: 9

        Method_09 - v1.7

        0 : { Pessoa_1, 111 }
        1 : { Pessoa_2, 222 }
        2 : { Pessoa_3, 333 }

        Apertar ENTER para continuar

    * Exemplo1300_v1.8
        Entrar com uma opcao: 10

        Method_10 - v1.8

        0 : { Pessoa_1, 111 }
        1 : { Pessoa_2, 222 }
        2 : { Pessoa_3, 333 }

        Apertar ENTER para continuar
*/

/*
 Exemplo1300 - v0.0. - __ / __ / _____
 Author: ________________________
*/
// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres
// ----------------------------------------------- definicoes globais
void pause ( std::string text )
{
 std::string dummy;
 std::cin.clear ( );
 std::cout << std::endl << text;
 std::cin.ignore( );
 std::getline(std::cin, dummy);
 std::cout << std::endl << std::endl;
} // end pause ( )
// ----------------------------------------------- classes / pacotes
#include "Erro.hpp"
using namespace std;
// ----------------------------------------------- metodos

/*
 Exemplo1300 - v0.0. - __ / __ / _____
 Author: ________________________
*/
// ----------------------------------------------- classes
#include "Contato.hpp" // classe para tratar dados de pessoas
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
/**
 Method_01 - Testar definicoes da classe.
*/
void method_01 ( )
{
// definir dados
 Contato pessoa1;
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( );
// identificar
 cout << "\nMethod_01 - v0.0\n" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

// ----------------------------------------------- //

/**
 Method_02 - Testar atribuicoes.
*/
void method_02 ( )
{
// definir dados
 Contato pessoa1;
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( );
// identificar
 cout << "\nMethod_02 - v1.0\n" << endl;
// testar atribuicoes
 pessoa1.setNome ( "Pessoa_01" );
 pessoa1.setFone ( "111" );
 pessoa3->setNome ( "Pessoa_03" );
 pessoa3->setFone ( "333" );
 cout << "pessoa1 - { " << pessoa1.getNome ( ) << ", " << pessoa1.getFone ( ) << " }" << endl;
 cout << "pessoa3 - { " << pessoa3->getNome ( ) << ", " << pessoa3->getFone ( ) << " }" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

// ----------------------------------------------- //

/**
 Method_03 - Testar recuperacao de dados.
*/
void method_03 ( )
{
// definir dados
 Contato pessoa1;
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( );
// identificar
 cout << "\nMethod_03 - v1.1\n" << endl;
// testar atribuicoes
 pessoa1.setNome ( "Pessoa_01" );
 pessoa1.setFone ( "111" );
 pessoa3->setNome ( "Pessoa_03" );
 pessoa3->setFone ( "333" );
 cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
 cout << "pessoa3 - " << pessoa3->toString ( ) << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

// ----------------------------------------------- //

/**
 Method_04 - Testar construtor alternativo.
*/
void method_04 ( )
{
// definir dados
 Contato pessoa1 ( "Pessoa_01", "111" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "Pessoa_03", "333" );
// identificar
 cout << "\nMethod_04 - v1.2\n" << endl;
// testar atribuicoes
 cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
 cout << "pessoa3 - " << pessoa3->toString ( ) << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

// ----------------------------------------------- //

/**
 Method_05 - Testar construtor alternativo.
*/
void method_05 ( )
{
// definir dados
 Contato pessoa1 ( "Pessoa_01", "111" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "", "333" );
// identificar
 cout << "\nMethod_05 - v1.3\n" << endl;
// testar atribuicoes
 cout << "pessoa1 - " << pessoa1.toString ( ) << " (" << pessoa1.getErro( ) << ")" << endl;
 cout << "pessoa3 - " << pessoa3->toString ( ) << " (" << pessoa3->getErro( ) << ")" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

// ----------------------------------------------- //

/**
 Method_06 - Testar construtor alternativo.
*/
void method_06 ( )
{
// definir dados
 Contato pessoa1 ( "Pessoa_01", "111" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "", "333" );
// identificar
 cout << "\nMethod_06 - v1.4\n" << endl;
// testar atribuicoes
 if ( ! pessoa1.hasErro( ) )
 cout << "pessoa1 - " << pessoa1.toString( ) << endl;
 else
 cout << "pessoa1 tem erro (" << pessoa1.getErro( ) << ")" << endl;
 if ( ! pessoa3->hasErro( ) )
 cout << "pessoa3 - " << pessoa3->toString( ) << endl;
 else
 cout << "pessoa3 tem erro (" << pessoa3->getErro( ) << ")" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

// ----------------------------------------------- //

/**
 Method_07 - Testar atribuicoes e tratamento de erro.
*/
void method_07 ( )
{
// definir dados
 Contato pessoa1 ( "Pessoa_01", "111" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "", "333" );
// identificar
 cout << "\nMethod_07 - v1.5\n" << endl;
// testar atribuicoes
 pessoa2 = &pessoa1; // copiar endereco de objeto
 if ( ! pessoa2->hasErro( ) )
 cout << "pessoa1 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa1 tem erro (" << pessoa2->getErro( ) << ")" << endl;
 pessoa2 = pessoa3; // vincular-se a outro objeto
 if ( ! pessoa2->hasErro( ) )
 cout << "pessoa3 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa3 tem erro (" << pessoa2->getErro( ) << ")" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

// ----------------------------------------------- //

/**
 Method_08 - Testar atribuicoes e tratamento de erro.
*/
void method_08 ( )
{
// definir dados
 Contato pessoa1 ( "Pessoa_01", "111" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "", "333" );
 ref_Contato pessoa4 = nullptr;
// identificar
 cout << "\nEXEMPLO1308 - Method_08 - v1.6\n" << endl;
// testar atribuicoes
 pessoa2 = new Contato ( pessoa1 );
 if ( pessoa2 )
 cout << "pessoa2 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa2 tem erro (" << pessoa2->getErro( ) << ")" << endl;
 if ( pessoa3 ) // o teste de existencia deve ser feito previamente
 {
 pessoa2 = new Contato ( *pessoa3 );
 if ( pessoa2 )
 cout << "pessoa2 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa2 tem erro (" << pessoa3->getErro( ) << ")" << endl;
 } // end if
 if ( pessoa4 ) // o teste de existencia deve ser feito previamente
 {
 pessoa2 = new Contato ( *pessoa4 );
 if ( pessoa2 )
 cout << "pessoa2 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa2 tem erro (" << pessoa4->getErro( ) << ")" << endl;
 } // end if
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

// ----------------------------------------------- //

/**
 Method_09 - Testar arranjo de objetos (1).
*/
void method_09 ( )
{
// definir dados
 Contato pessoa [ 3 ];
 int x = 0;
// identificar
 cout << "\nMethod_09 - v1.7\n" << endl;
// testar atribuicoes
 pessoa [ 0 ].setNome ( "Pessoa_1" );
 pessoa [ 0 ].setFone ( "111" );
 pessoa [ 1 ].setNome ( "Pessoa_2" );
 pessoa [ 1 ].setFone ( "222" );
 pessoa [ 2 ].setNome ( "Pessoa_3" );
 pessoa [ 2 ].setFone ( "333" );
 for ( x=0; x < 3; x=x+1 )
 {
 cout << x << " : " << pessoa[ x ].toString( ) << endl;
 } // end for
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

// ----------------------------------------------- //

/**
 Method_10 - Testar arranjo de referencias para objetos (2).
*/
void method_10 ( )
{
// definir dados
 Contato *pessoa [ 3 ];
 int x = 0;
// identificar
 cout << "\nMethod_10 - v1.8\n" << endl;
// testar atribuicoes
 pessoa [ 0 ] = new Contato ( "Pessoa_1", "111" );
 pessoa [ 1 ] = new Contato ( "Pessoa_2", "222" );
 pessoa [ 2 ] = new Contato ( "Pessoa_3", "333" );
 for ( x=0; x < 3; x=x+1 )
 {
 cout << x << " : " << pessoa[ x ]->toString( ) << endl;
 } // end for
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

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
 cout << "EXEMPLO1300 - Programa - v0.0\n " << endl;
 // mostrar opcoes
 cout << "Opcoes " << endl;
 cout << " 0 - parar " << endl;
 cout << " 1 - Testar definicoes da classe " << endl;
 cout << " 2 - Testar atribuicoes" << endl;
 cout << " 3 - Testar recuperacao de dados" << endl;
 cout << " 4 - Testar construtor alternativo" << endl;
 cout << " 5 - Testar construtor alternativo" << endl;
 cout << " 6 - Testar construtor alternativo" << endl;
 cout << " 7 - Testar atribuicoes e tratamento de erro" << endl;
 cout << " 8 - Testar atribuicoes e tratamento de erro" << endl;
 cout << " 9 - Testar arranjo de objetos (1)" << endl;
 cout << "10 - Testar arranjo de referencias para objetos (2)" << endl;
 // ler do teclado
 cout << endl << "Entrar com uma opcao: ";
 cin >> x;
 // escolher acao
 switch ( x )
 {
 case 0: break;
 case 1: method_01 ( ); break;
 case 2: method_02 ( ); break;
 case 3: method_03 ( ); break;
 case 4: method_04 ( ); break;
 case 5: method_05 ( ); break;
 case 6: method_06 ( ); break;
 case 7: method_07 ( ); break;
 case 8: method_08 ( ); break;
 case 9: method_09 ( ); break;
 case 10: method_10 ( ); break;
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
- v0.0 Testa as definicoes da classe prsente em Contato.hpp -

- v1.0 Testa as atribuicoes feitas dentro da classe -

- v1.1 Recupera os dados atribuidos -

- v1.2 Testa o construtor dentro da classe presente em Contato.hpp -

- v1.3 Testa o construtor dentro da classe presente em Contato.hpp -

- v1.4 Testa o construtor dentro da classe presente em Contato.hpp -

- v1.5 Testa as atribuicoes deitas dentro da classe faz o tratamento de erro retornando falso ou verdadeiro -

- v1.6 Testa as atribuicoes deitas dentro da classe faz o tratamento de erro retornando falso ou verdadeiro -

- v1.7 Testa a alocacao dos dados em um arranjo -

- v1.8 Testa a alocacao dos dados em um arranjo mas com referencia a objetos -

----------------------------------------------
----------------------------------------------

----------------------------------------------
----------------------------------------------
Versao Data Modificacao
0.0 _01_/_06_ esboco e adicao do method_01
1.0 _01_/_06_ modificacao esboco e adicao do method_02
1.1 _01_/_06_ modificacao esboco e adicao do method_03
1.2 _01_/_06_ modificacao esboco e adicao do method_04
1.3 _01_/_06_ modificacao esboco e adicao do method_05
1.4 _01_/_06_ modificacao esboco e adicao do method_06
1.5 _01_/_06_ modificacao esboco e adicao do method_07
1.6 _01_/_06_ modificacao esboco e adicao do method_08
1.7 _01_/_06_ modificacao esboco e adicao do method_09
1.8 _01_/_06_ modificacao esboco e adicao do method_010

----------------------------------------------
----------------------------------------------

---------------------------------------------- testes

----------------------------------------------
----------------------------------------------
Versao Teste
0.0 00. ( _OK_ ) identificacao de programa
1.0 00. ( _OK_ ) identificacao e alteracao do programa
1.1 00. ( _OK_ ) identificacao e alteracao do programa
1.2 00. ( _OK_ ) identificacao e alteracao do programa
1.3 00. ( _OK_ ) identificacao e alteracao do programa
1.4 00. ( _OK_ ) identificacao e alteracao do programa
1.5 00. ( _OK_ ) identificacao e alteracao do programa
1.6 00. ( _OK_ ) identificacao e alteracao do programa
1.7 00. ( _OK_ ) identificacao e alteracao do programa
1.8 00. ( _OK_ ) identificacao e alteracao do programa
----------------------------------------------
----------------------------------------------
*/

