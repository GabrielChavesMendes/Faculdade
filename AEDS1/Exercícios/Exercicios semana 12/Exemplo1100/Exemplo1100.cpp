/*
 Exemplo1100 - v1.8. - _17_ / _05_ / _2024_
 Author: ___Gabriel_Chaves_Mendes___

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo1100 exemplo1100.c
 Windows: gcc -o exemplo1100 exemplo1100.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo1100
 Windows: exemplo1100

    * Exemplo0800_v0.0
        Method_01 - v0.0


          0 :         1
          1 :         2
          2 :         3
          3 :         4
          4 :         5

    * Exemplo0800_v1.0
        Method_02 - v1.0

          0 : 1
          1 : 2
          2 : 3
          3 : 4
          4 : 5


          0 :         1
          1 :         2
          2 :         3
          3 :         4
          4 :         5


Apertar ENTER para continuar

    * Exemplo0800_v1.1
        Method_03 - v1.1

          0 : 5
          1 : 4
          2 : 3
          3 : 2
          4 : 1


        Apertar ENTER para continuar

    * Exemplo0800_v1.2
        Method_04 - v1.2

          0 :         5
          1 :         4
          2 :         3
          3 :         2
          4 :         1
        Apertar ENTER para continuar

    * Exemplo0800_v1.3
        Method_05 - v1.3

        Copia


          0 :         1
          1 :         2
          2 :         3
          3 :         4
          4 :         5
        Apertar ENTER para continuar

    * Exemplo0800_v1.4
        Method_06 - v1.4

        Original


          0 :         5
          1 :         4
          2 :         3
          3 :         2
          4 :         1


        Copia


          0 :         5
          1 :         4
          2 :         3
          3 :         2
          4 :         1


        Apertar ENTER para continuar

    * Exemplo0800_v1.5
        Method_07 - v1.5

        Original


          0 :         5
          1 :         4
          2 :         3
          3 :         2
          4 :         1


        Copia


          0 :         5
          1 :         4
          2 :         3
          3 :         2
          4 :         1


        Apertar ENTER para continuar

    * Exemplo0800_v1.6
        Method_08 - v1.6

        Array_1
          0 :         1
          1 :         2
          2 :         3

        Array_2
          0 :         1
          1 :         2
          2 :         3

        Igualdade = 1

        Array_1

          0 :         1
          1 :         2
          2 :         3

        Array_2

          0 :        -1
          1 :         2
          2 :         3

        Igualdade = 0

        Apertar ENTER para continuar

    * Exemplo0800_v1.7
        EXEMPLO1110 - Method_09 - v1.7

        Original

          0 :         5
          1 :         4
          2 :         3
          3 :         2
          4 :         1

        Copia

          0 :         5
          1 :         4
          2 :         3
          3 :         2
          4 :         1

        Soma

          0 :        10
          1 :         8
          2 :         6
          3 :         4
          4 :         2


        Apertar ENTER para continuar

    * Exemplo0800_v1.8
        Method_10 - v1.8

        Acesso externo

          0 : 1
          1 : 2
          2 : 3
          3 : 4
          4 : 5

        Fora dos limites:
        [-1]: 1875945840

        [5]:

        ERROR: Invalid position.

        5

        Apertar ENTER para continuar
*/

/*
 Exemplo1100 - v0.0. - __ / __ / _____
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
#include "myarray.hpp"
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
 Method_01 - Mostrar certa quantidade de valores.
*/
void method_01 ( )
{
// definir dados
 Array <int> int_array ( 5, 0 );
 int_array.set ( 0, 1 );
 int_array.set ( 1, 2 );
 int_array.set ( 2, 3 );
 int_array.set ( 3, 4 );
 int_array.set ( 4, 5 );
// identificar
 cout << "\nMethod_01 - v0.0\n" << endl;
// mostrar dados
 int_array.print ( );
// reciclar espaco
 int_array.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )



/**
 Method_02.
*/
void method_02 ( )
{
// definir dados
 Array <int> int_array ( 5, 0 );
// identificar
 cout << endl << "Method_02 - v1.0" << endl;
// ler dados
 int_array.read ( );
// mostrar dados
 int_array.print ( );
// reciclar espaco
 int_array.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )



/**
 Method_03.
*/
void method_03 ( )
{
// definir dados
 Array <int> int_array ( 5, 0 );
// identificar
 cout << endl << "Method_03 - v1.1" << endl;
// ler dados
 int_array.read ( );
// mostrar dados
 int_array.fprint ( "INT_ARRAY1.TXT" );
// reciclar espaco
 int_array.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )



/**
 Method_04.
*/
void method_04 ( )
{
// definir dados
 Array <int> int_array ( 5, 0 );
// identificar
 cout << endl << "Method_04 - v1.2" << endl;
// ler dados
 int_array.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
 int_array.print ( );
// reciclar espaco
 int_array.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )




/**
 Method_05.
*/
void method_05 ( )
{
// definir dados
 int other [ ] = { 1, 2, 3, 4, 5 };
 Array <int> int_array ( 5, other );
// identificar
 cout << endl << "Method_05 - v1.3" << endl;
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_array.print ( );
// reciclar espaco
 int_array.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )




/**
 Method_06.
*/
void method_06 ( )
{
// definir dados
 Array <int> int_array1 ( 1, 0 );
// identificar
 cout << endl << "Method_06 - v1.4" << endl;
// ler dados
 int_array1.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
 cout << "\nOriginal\n" << endl;
 int_array1.print ( );
// criar copia
 Array <int> int_array2 ( int_array1 );
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_array2.print ( );
// reciclar espaco
 int_array1.free ( );
 int_array2.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )





/**
 Method_07.
*/
void method_07 ( )
{
// definir dados
 Array <int> int_array1 ( 1, 0 );
 Array <int> int_array2 ( 1, 0 );
// identificar
 cout << endl << "Method_07 - v1.5" << endl;
// ler dados
 int_array1.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
 cout << "\nOriginal\n" << endl;
 int_array1.print ( );
// copiar dados
 int_array2 = int_array1;
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_array2.print ( );
// reciclar espaco
 int_array1.free ( );
 int_array2.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )





/**
 Method_08.
*/
void method_08 ( )
{
// definir dados
 int other [ ] = { 1, 2, 3 };
 Array <int> int_array1 ( 3, other );
 Array <int> int_array2 ( 3, other );
 int x;
// identificar
 cout << endl << "Method_08 - v1.6" << endl;
// mostrar dados
 cout << endl;
 cout << "Array_1";
 int_array1.print ( );
// mostrar dados
 cout << "Array_2";
 int_array2.print ( );
// mostrar comparacao
 cout << "Igualdade = " << (int_array1==int_array2) << endl;
// alterar dado
 int_array2.set ( 0, (-1) );
// mostrar dados
 cout << endl;
 cout << "Array_1" << endl;
 int_array1.print ( );

 cout << "Array_2" << endl;
 int_array2.print ( );
// mostrar comparacao
 cout << "Igualdade = " << (int_array1==int_array2) << endl;
// reciclar espaco
 int_array1.free ( );
 int_array2.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )





/**
 Method_09.
*/
void method_09 ( )
{
// definir dados
 Array <int> int_array1 ( 1, 0 );
 Array <int> int_array2 ( 1, 0 );
 Array <int> int_array3 ( 1, 0 );
// identificar
 cout << endl << "EXEMPLO1110 - Method_09 - v1.7" << endl;
// ler dados
 int_array1.fread ( "INT_ARRAY1.TXT" );
// copiar dados
 int_array2 = int_array1;
// somar dados
 int_array3 = int_array2 + int_array1;
// mostrar dados
 cout << endl;
 cout << "Original" << endl;
 int_array1.print ( );
// mostrar dados
 cout << "Copia" << endl;
 int_array2.print ( );
// mostrar dados
 cout << "Soma" << endl;
 int_array3.print ( );
// reciclar espaco
 int_array1.free ( );
 int_array2.free ( );
 int_array3.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )



/**
 Method_10.
*/
void method_10 ( )
{
// definir dados
 int other [ ] = { 1, 2, 3, 4, 5 };
 Array <int> int_array ( 5, other );
 int x;
// identificar
 cout << endl << "Method_10 - v1.8" << endl;
// mostrar dados
 cout << "\nAcesso externo" << endl;
 for ( x=0; x<int_array.getLength( ); x=x+1 )
 {
 cout << endl << setw( 3 ) << x << " : " << int_array [ x ];
 } // fim repetir
 cout << endl << "\nFora dos limites:";
 cout << endl << "[-1]: " << int_array.get(-1) << endl;
 cout << endl << "[" << int_array.getLength( ) << "]: "
 << int_array [ int_array.getLength( ) ] << endl;
// reciclar espaco
 int_array.free ( );
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
// repetir até desejar parar
 do
 {
 // identificar
 cout << "EXEMPLO1101 - Programa - v0.0\n " << endl;
 // mostrar opcoes
 cout << "Opcoes " << endl;
 cout << " 0 - parar " << endl;
 cout << " 1 - mostrar dados inteiros em arranjo " << endl;
 cout << " 2 - alocar dados inteiros em um arranjo" << endl;
 cout << " 3 - alocar dados inteiros de um arranjo em um arquivo" << endl;
 cout << " 4 - apresentar dados presente em um arquivo" << endl;
 cout << " 5 - copiar os dados presente em um arquivo" << endl;
 cout << " 6 - apresentar os dados originais e sua copia" << endl;
 cout << " 7 - apresentar os dados originais e sua copia" << endl;
 cout << " 8 - testar igualdade de arranjos" << endl;
 cout << " 9 - soma entre arranjos" << endl;
 cout << "10 - dentro ou fora do limite" << endl;
 // ler do teclado
 cout << endl << "Entrar com uma opcao: ";
 cin >> x;
 // escolher acao
 switch ( x )
 {
 case 0: method_00 ( ); break;
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
- v0.0 Alocou dinamicamente numeros inteiros em um arranjo -

- v1.0 Pediu ao usuario alocar 5 numeros inteiros em um arranjo -

- v1.1 Pediu ao usuario alocar 5 numeros inteiros em um arranjo e imprimiu o arranjo em um arquivo -

- v1.2 Apresenta no terminal o arranjo alocado no arquivo -

- v1.3 Copia os dados do arranjo alocano no arquivo em outro arranjo -

- v1.4 Apresenta no terminal o arranjo alocado original e sua copia -

- v1.5 Apresenta no terminal o arranjo alocado original e sua copia -

- v1.6 Cria 2 arranjos diferente e testa posicao por posicao e retorna 1 caso sejam iguais e 0 caso sejam diferentes -

- v1.7 Faz a soma entre o arranjo alocado no arquivo e sua copia e aloca os resultados da soma em outro vetor -

- v1.8 Confere se os valores do arranjo estao dentro ou fora dos limites -

----------------------------------------------
----------------------------------------------

----------------------------------------------
----------------------------------------------
Versao Data Modificacao
0.0 _17_/_05_ esboco e adicao do method_01
1.0 _17_/_05_ modificacao esboco e adicao do method_02
1.1 _17_/_05_ modificacao esboco e adicao do method_03
1.2 _17_/_05_ modificacao esboco e adicao do method_04
1.3 _17_/_05_ modificacao esboco e adicao do method_05
1.4 _17_/_05_ modificacao esboco e adicao do method_06
1.5 _17_/_05_ modificacao esboco e adicao do method_07
1.6 _17_/_05_ modificacao esboco e adicao do method_08
1.7 _17_/_05_ modificacao esboco e adicao do method_09
1.8 _17_/_05_ modificacao esboco e adicao do method_010

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

