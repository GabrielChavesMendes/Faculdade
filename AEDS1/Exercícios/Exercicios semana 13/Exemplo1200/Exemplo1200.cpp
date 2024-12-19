/*
 Exemplo1100 - v1.8. - _26_ / _05_ / _2024_
 Author: ___Gabriel_Chaves_Mendes___

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo1200 exemplo1200.c
 Windows: gcc -o exemplo1200 exemplo1200.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo1200
 Windows: exemplo1200

    * Exemplo1200_v0.0
        Entrar com uma opcao: 1

        Method_01 - v0.0


        1       2
        3       4


        Apertar ENTER para continuar

    * Exemplo1200_v1.0
        Entrar com uma opcao: 2

        Method_02 - v1.0

         0,  0 : 1
         0,  1 : 3
         1,  0 : 5
         1,  1 : 7


        1       3
        5       7


        Apertar ENTER para continuar

    * Exemplo1200_v1.1
        Entrar com uma opcao: 3

        Method_03 - v1.1

         0,  0 : 2
         0,  1 : 4
         1,  0 : 6
         1,  1 : 8


        2       4
        6       8


        Apertar ENTER para continuar

    * Exemplo1200_v1.2
        Entrar com uma opcao: 4

        Method_04 - v1.2

        2       4
        6       8


        Apertar ENTER para continuar

    * Exemplo1200_v1.3
        Entrar com uma opcao: 5

        Method_05 - v1.3

        Original


        2       4
        6       8


        Copia


        2       4
        6       8


        Apertar ENTER para continuar

    * Exemplo1200_v1.4
        Entrar com uma opcao: 6

        Method_06 - v1.4

        0       0
        0       0

        Zeros = 1

        2       4
        6       8

        Zeros = 0

        Apertar ENTER para continuar

    * Exemplo1200_v1.5
        Entrar com uma opcao: 7

        Method_07 - v1.5

        Matrix_1

        2       4
        6       8


        Matrix_2

        2       4
        6       8

        Diferentes = 0

        Matrix_1

        2       4
        6       8


        Matrix_2

        -1      4
        6       8

        Diferentes = 1

        Apertar ENTER para continuar

    * Exemplo1200_v1.6
        Entrar com uma opcao: 8

        Method_08 - v1.6

        Matrix_1

        2       4
        6       8


        Matrix_2

        2       4
        6       8


        Matrix_3

        0       0
        0       0


        Apertar ENTER para continuar

    * Exemplo1200_v1.7
        Entrar com uma opcao: 9

        Method_09 - v1.7

        Matrix_1

        1       0
        0       1


        Matrix_2

        2       4
        6       8


        Matrix_3

        2       4
        6       8


        Apertar ENTER para continuar

    * Exemplo1200_v1.8
        Entrar com uma opcao: 10

        Method_10 - v1.8

        Matrix

        2       4
        6       8


        Matrix

        -2      -4
        -6      -8


        Apertar ENTER para continuar
*/

/*
 Exemplo1200 - v0.0. - __ / __ / _____
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
#include "mymatrix.hpp"
using namespace std;
// ----------------------------------------------- metodos

/**
 Method_01 - Mostrar certa quantidade de valores.
*/
void method_01 ( )
{
// definir dados
 Matrix <int> int_matrix ( 2, 2, 0 );
 int_matrix.set ( 0, 0, 1 ); int_matrix.set ( 0, 1, 2 );
 int_matrix.set ( 1, 0, 3 ); int_matrix.set ( 1, 1, 4 );
// identificar
 cout << "\nMethod_01 - v0.0\n" << endl;
// mostrar dados
 int_matrix.print ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )


/**
 Method_02.
*/
void method_02 ( )
{
// definir dados
 Matrix <int> matrix ( 2, 2, 0 );
// identificar
 cout << endl << "Method_02 - v1.0" << endl;
// ler dados
 matrix.read ( );
// mostrar dados
 matrix.print ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )


/**
 Method_03.
*/
void method_03 ( )
{
// definir dados
 Matrix <int> matrix ( 2, 2, 0 );
// identificar
 cout << endl << "Method_03 - v1.1" << endl;
// ler dados
 matrix.read ( );
// mostrar dados
 matrix.print ( );
// gravar dados
 matrix.fprint( "MATRIX1.TXT" );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )


/**
 Method_04.
*/
void method_04 ( )
{
// definir dados
 Matrix <int> matrix ( 1, 1, 0 );
// identificar
 cout << endl << "Method_04 - v1.2" << endl;
// ler dados
 matrix.fread ( "MATRIX1.TXT" );
// mostrar dados
 matrix.print ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )


/**
 Method_05.
*/
void method_05 ( )
{
// definir dados
 Matrix <int> int_matrix1 ( 1, 1, 0 );
 Matrix <int> int_matrix2 ( 1, 1, 0 );
// identificar
 cout << endl << "Method_05 - v1.3" << endl;
// ler dados
 int_matrix1.fread ( "MATRIX1.TXT" );
// mostrar dados
 cout << "\nOriginal\n" << endl;
 int_matrix1.print ( );
// copiar dados
 int_matrix2 = int_matrix1;
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_matrix2.print ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )


/**
 Method_06.
*/
void method_06 ( )
{
// definir dados
 Matrix <int> int_matrix ( 2, 2, 0 );
 int_matrix.set ( 0, 0, 0 ); int_matrix.set ( 0, 1, 0 );
 int_matrix.set ( 1, 0, 0 ); int_matrix.set ( 1, 1, 0 );
// identificar
 cout << endl << "Method_06 - v1.4" << endl;
// mostrar dados
 int_matrix.print ( );
// testar condicao
 cout << "Zeros = " << int_matrix.isZeros ( ) << endl;
// ler dados
 int_matrix.fread ( "MATRIX1.TXT" );
// mostrar dados
 int_matrix.print ( );
// testar condicao
 cout << "Zeros = " << int_matrix.isZeros ( ) << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )


/**
 Method_07.
*/
void method_07 ( )
{
// definir dados
 Matrix <int> int_matrix1 ( 1, 1, 0 );
 Matrix <int> int_matrix2 ( 1, 1, 0 );
// identificar
 cout << endl << "Method_07 - v1.5" << endl;
// ler dados
 int_matrix1.fread ( "MATRIX1.TXT" );
// mostrar dados
 cout << "\nMatrix_1\n";
 int_matrix1.print ( );
// copiar dados
 int_matrix2 = int_matrix1;
// mostrar dados
 cout << "\nMatrix_2\n";
 int_matrix2.print ( );
// testar condicao
 cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl;
// alterar dados
 int_matrix2.set ( 0, 0, (-1) );
// mostrar dados
 cout << "\nMatrix_1\n";
 int_matrix1.print ( );
// mostrar dados
 cout << "\nMatrix_2\n";
 int_matrix2.print ( );
// testar condicao
 cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )


/**
 Method_08.
*/
void method_08 ( )
{
// definir dados
 Matrix <int> int_matrix1 ( 1, 1, 0 );
 Matrix <int> int_matrix2 ( 1, 1, 0 );
 Matrix <int> int_matrix3 ( 1, 1, 0 );
// identificar
 cout << endl << "Method_08 - v1.6" << endl;
// ler dados
 int_matrix1.fread ( "MATRIX1.TXT" );
// mostrar dados
 cout << "\nMatrix_1\n";
 int_matrix1.print ( );
// copiar dados
 int_matrix2 = int_matrix1;
// mostrar dados
 cout << "\nMatrix_2\n";
 int_matrix2.print ( );
// operar dados
 int_matrix3 = int_matrix1 - int_matrix2;
// mostrar dados
 cout << "\nMatrix_3\n";
 int_matrix3.print ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )



/**
 Method_09.
*/
void method_09 ( )
{
// definir dados
 Matrix <int> int_matrix1 ( 2, 2, 0 );
 int_matrix1.set ( 0, 0, 1 );
 int_matrix1.set ( 0, 1, 0 );
 int_matrix1.set ( 1, 0, 0 );
 int_matrix1.set ( 1, 1, 1 );
 Matrix <int> int_matrix2 ( 1, 1, 0 );
 Matrix <int> int_matrix3 ( 1, 1, 0 );
// identificar
 cout << endl << "Method_09 - v1.7" << endl;
// ler dados
 int_matrix2.fread ( "MATRIX1.TXT" );
// mostrar dados
 cout << "\nMatrix_1\n";
 int_matrix1.print ( );
// mostrar dados
 cout << "\nMatrix_2\n";
 int_matrix2.print ( );
// operar dados
 int_matrix3 = int_matrix1 * int_matrix2;
// mostrar dados
 cout << "\nMatrix_3\n";
 int_matrix3.print ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )


/**
 Method_10.
*/
void method_10 ( )
{
// definir dados
 Matrix <int> int_matrix ( 3, 3, 0 );
 int x = 0;
 int y = 0;
// identificar
 cout << endl << "Method_10 - v1.8" << endl;
// ler dados
 int_matrix.fread ( "MATRIX1.TXT" );
// mostrar dados
 cout << "\nMatrix\n";
 int_matrix.print ( );
// operar dados
 for ( int x = 0; x < int_matrix.getRows ( ); x=x+1 )
 {
 for ( int y = 0; y < int_matrix.getColumns ( ); y=y+1 )
 {
 int_matrix.set ( x, y, int_matrix.get ( x, y ) * (-1) );
 } // end for
 } // end for
// mostrar dados
 cout << "\nMatrix\n";
 int_matrix.print ( );
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
 cout << "EXEMPLO1200 - Programa - v0.0\n " << endl;
 // mostrar opcoes
 cout << "Opcoes " << endl;
 cout << " 0 - parar " << endl;
 cout << " 1 - Mostrar certa quantidade de valores " << endl;
 cout << " 2 - Alocar dados inteiros em uma matriz" << endl;
 cout << " 3 - Alocar dados inteiros de uma matriz em um arquivo" << endl;
 cout << " 4 - Apresentar dados presente em um arquivo" << endl;
 cout << " 5 - Copiar os dados presente em um arquivo" << endl;
 cout << " 6 - Quantidade de zeros uma matriz" << endl;
 cout << " 7 - Matrizes diferentes" << endl;
 cout << " 8 - Subtração de matrizes" << endl;
 cout << " 9 - Multiplicação matriz identidade" << endl;
 cout << "10 - Matriz negativa" << endl;
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
- v0.0 Alocou dinamicamente numeros inteiros em uma matriz -

- v1.0 Pediu ao usuario alocar 5 numeros inteiros em uma matriz -

- v1.1 Pediu ao usuario alocar 5 numeros inteiros em uma matriz e imprimiu a matriz em um arquivo -

- v1.2 Apresenta no terminal a matriz alocada no arquivo -

- v1.3 Copia os dados da matriz alocada no arquivo em outra matriz -

- v1.4 Conferiu a quantidade de zeros em uma matriz -

- v1.5 Conferiu se a matriz do arquivo era diferente de outra matriz -

- v1.6 Subtraiu duas matrizes diferentes e imprimiu a matriz resultante -

- v1.7 Multiplicou a matriz do arquivo por uma matriz identidade de mesmo tamanho -

- v1.8 Pegou a matriz do arquivo e criou uma matriz semelhante porem com os valores negativos -

----------------------------------------------
----------------------------------------------

----------------------------------------------
----------------------------------------------
Versao Data Modificacao
0.0 _26_/_05_ esboco e adicao do method_01
1.0 _26_/_05_ modificacao esboco e adicao do method_02
1.1 _26_/_05_ modificacao esboco e adicao do method_03
1.2 _26_/_05_ modificacao esboco e adicao do method_04
1.3 _26_/_05_ modificacao esboco e adicao do method_05
1.4 _26_/_05_ modificacao esboco e adicao do method_06
1.5 _26_/_05_ modificacao esboco e adicao do method_07
1.6 _26_/_05_ modificacao esboco e adicao do method_08
1.7 _26_/_05_ modificacao esboco e adicao do method_09
1.8 _26_/_05_ modificacao esboco e adicao do method_010

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

