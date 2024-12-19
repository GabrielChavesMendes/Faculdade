/*
 Exemplo1000 - v1.8. - _11_ / _05_ / _2024_
 Author: ___Gabriel_Chaves_Mendes___

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo1000 exemplo1000.c
 Windows: gcc -o exemplo1000 exemplo1000.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo1000
 Windows: exemplo1000

    * Exemplo1000_v0.0
        Entrar com uma opcao: 1
        Method_01 - v0.0
        Autor: ________________________

         0: 1
         1: 2
         2: 3
         3: 4
         4: 5

        Apertar ENTER para continuar

    * Exemplo1000_v1.0
        Entrar com uma opcao: 2
        Method_02 - v1.0
        Autor: ________________________


        length = 5
        0 : 1
        1 : 2
        2 : 3
        3 : 4
        4 : 5

         0: 1
         1: 2
         2: 3
         3: 4
         4: 5

        Apertar ENTER para continuar

    * Exemplo1000_v1.1
        Entrar com uma opcao: 3
        Method_03 - v1,1
        Autor: ________________________


        length = 5
        0 : 5
        1 : 4
        2 : 3
        3 : 2
        4 : 1

         0: 5
         1: 4
         2: 3
         3: 2
         4: 1

        Apertar ENTER para continuar

    * Exemplo1000_v1.2
        Entrar com uma opcao: 4
        Method_04 - v1.2
        Autor: ________________________


         0: 5
         1: 4
         2: 3
         3: 2
         4: 1

        Apertar ENTER para continuar

    * Exemplo1000_v1.3
        Entrar com uma opcao: 5
        Method_05 - v1.3
        Autor: ________________________


        Original
         0: 5
         1: 4
         2: 3
         3: 2
         4: 1

        Copia
         0: 5
         1: 4
         2: 3
         3: 2
         4: 1

        Apertar ENTER para continuar

    * Exemplo1000_v1.4
        Entrar com uma opcao: 6
        Method_06 - v1.4
        Autor: ________________________

          1       2       3
          3       4       5
          6       7       8

        Apertar ENTER para continuar

    * Exemplo1000_v1.5
        Entrar com uma opcao: 7
        Method_07 - v1.5
        Autor: ________________________


        rows = 3

        columns = 3
        0, 0 : 1
        0, 1 : 2
        0, 2 : 3

        1, 0 : 4
        1, 1 : 5
        1, 2 : 6

        2, 0 : 7
        2, 1 : 8
        2, 2 : 9


          1       2       3
          4       5       6
          7       8       9

        Apertar ENTER para continuar

    * Exemplo1000_v1.6
        Entrar com uma opcao: 8
        Method_08 - v1.6
        Autor: ________________________


        rows = 3

        columns = 2
        0, 0 : 6
        0, 1 : 5

        1, 0 : 4
        1, 1 : 3

        2, 0 : 2
        2, 1 : 1


        Apertar ENTER para continuar

    * Exemplo1000_v1.7
        Entrar com uma opcao: 9
        Method_09 - v1.7
        Autor: ________________________


          6       5
          4       3
          2       1

        Apertar ENTER para continuar

    * Exemplo1000_v1.8
        Entrar com uma opcao: 10
        Method_10 - v1.8
        Autor: ________________________


        Original
          6       5
          4       3
          2       1

        Copia
          6       5
          4       3
          2       1

        Apertar ENTER para continuar

*/

// dependencias
#include <stdio.h>
#include "io.h" // bibliotecas e outras definicoes

/**
 Definicao de tipo arranjo com inteiros
 baseado em estrutura
*/
typedef
struct s_int_Array
{
 int length;
 ints data ;
 int ix ;
}
int_Array;
/**
 Definicao de referencia para arranjo com inteiros
 baseado em estrutura
*/
typedef int_Array* ref_int_Array;
/**
 new_int_Array - Reservar espaco para arranjo com inteiros
 @return referencia para arranjo com inteiros
 @param n - quantidade de datos
*/
ref_int_Array new_int_Array ( int n )
{
// reserva de espaco
 ref_int_Array tmpArray = (ref_int_Array) malloc (sizeof(int_Array));
// estabelecer valores padroes
 if ( tmpArray == NULL )
 {
 IO_printf ( "\nERRO: Falta espaco.\n" );
 }
 else
 {
 tmpArray->length = 0;
 tmpArray->data = NULL;
 tmpArray->ix = -1;
 if ( n>0 )
 {
 // guardar a quantidade de dados
 tmpArray->length = n;
 // reservar espaco para os dados
 tmpArray->data = (ints) malloc (n * sizeof(int));
 // definir indicador do primeiro elemento
 tmpArray->ix = 0;
 } // end if
 } // end if
// retornar referencia para espaco reservado
 return ( tmpArray );
} // end new_int_Array ( )
/**
 free_int_Array - Dispensar espaco para arranjo com inteiros
 @param tmpArray - referencia para grupo de valores inteiros
*/
void free_int_Array ( ref_int_Array tmpArray )
{
// testar se ha' dados, antes de reciclar o espaco
 if ( tmpArray != NULL )
 {
 if ( tmpArray->data != NULL )
 {
 free ( tmpArray->data );
 } // end if
 free ( tmpArray );
 } // fim se
} // end free_int_Array ( )
/**
 printIntArray - Mostrar arranjo com valores inteiros.
 @param array - grupo de valores inteiros
*/
void printIntArray ( int_Array array )
{
// mostrar valores no arranjo
 if ( array.data )
 {
 for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
 {
 // mostrar valor
 printf ( "%2d: %d\n", array.ix, array.data [ array.ix ] );
 } // end for
 } // end if
} // end printIntArray ( )
/**
 Method_01 - Mostrar certa quantidade de valores.
*/
void method_01 ( )
{
// definir dado
 int_Array array;
// montar arranjo em estrutura
 array. length = 5;
 array. data = (ints) malloc (array.length * sizeof(int));
// testar a existência de dados
 if ( array.data )
 {
 array. data [ 0 ] = 1;
 array. data [ 1 ] = 2;
 array. data [ 2 ] = 3;
 array. data [ 3 ] = 4;
 array. data [ 4 ] = 5;
 } // fim se

// identificar
 IO_id ( "Method_01 - v0.0" );
// executar o metodo auxiliar
 printIntArray ( array );
// reciclar o espaco
 if ( array.data )
 {
 free ( array.data );
 } // fim se
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )


//-----------------------------------------------//

/**
 IO_readintArray - Ler arranjo com valores inteiros.
 @return arranjo com valores lidos
*/
int_Array IO_readintArray ( )
{
// definir dados locais
 chars text = IO_new_chars ( STR_SIZE );
 static int_Array array;
// ler a quantidade de dados
 do
 {
 array.length = IO_readint ( "\nlength = " );
 }
 while ( array.length <= 0 );
// reservar espaco para armazenar
 array.data = IO_new_ints ( array.length );
// testar se ha' espaco
 if ( array.data == NULL )
 {
 array.length = 0; // nao ha' espaco
 }
 else
 {
 // ler e guardar valores em arranjo
 for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
 {
 // ler valor
 strcpy ( text, STR_EMPTY );
 array.data [ array.ix ]
 = IO_readint ( IO_concat (
 IO_concat ( text, IO_toString_d ( array.ix ) ), " : " ) );
 } // end for
 } // end if
// retornar arranjo
 return ( array );
} // end IO_readintArray ( )
/**
 Method_02.
*/
void method_02 ( )
{
// definir dados
 int_Array array;
// identificar
 IO_id ( "Method_02 - v1.0" );
// ler dados
 array = IO_readintArray ( );
// testar a existência de dados
 if ( array.data )
 {
 // mostrar dados
 IO_printf ( "\n" );
 printIntArray ( array );
 // reciclar o espaco
 free ( array.data );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

//-----------------------------------------------//

/**
 fprintIntArray - Gravar arranjo com valores inteiros.
 @param fileName - nome do arquivo
 @param array - grupo de valores inteiros
*/
void fprintIntArray ( chars fileName, int_Array array )
{
// definir dados locais
 FILE* arquivo = fopen ( fileName, "wt" );
// gravar quantidade de dados
 fprintf ( arquivo, "%d\n", array.length );
// gravar valores no arquivo, se existirem
 if ( array.data )
 {
 for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
 {
 // gravar valor
 fprintf ( arquivo, "%d\n", array.data [ array.ix ] );
 } // end for
 } // end if

// fechar arquivo
 fclose ( arquivo );
} // end fprintIntArray ( )
/**
 Method_03.
*/
void method_03 ( )
{
// definir dados
 int_Array array;
// identificar
 IO_id ( "Method_03 - v1,1" );
// ler dados
 array = IO_readintArray ( );
// testar a existência de dados
 if ( array.data )
 {
 // mostrar e gravar dados
 IO_printf ( "\n" );
 printIntArray ( array );
 fprintIntArray ( "ARRAY1.TXT", array );
 // reciclar o espaco
 free ( array.data );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )


//-----------------------------------------------//

/**
 freadArraySize - Ler tamanho do arranjo com valores inteiros.
 @return quantidade de valores lidos
 @param fileName - nome do arquivo
*/
int freadArraySize ( chars fileName )
{
// definir dados locais
 int n = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
// testar a existencia
 if ( arquivo )
 {
 // ler a quantidade de dados
 fscanf ( arquivo, "%d", &n );
 if ( n <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 n = 0;
 } // end if
 fclose ( arquivo );
 } // end if
// retornar dados lidos
 return ( n );
} // end freadArraySize ( )
/**
 fIO_readintArray - Ler arranjo com valores inteiros.
 @return arranjo com os valores lidos
 @param fileName - nome do arquivo
 @param array - grupo de valores inteiros
*/
int_Array fIO_readintArray ( chars fileName )
{
// definir dados locais
 int x = 0;
 int y = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
 static int_Array array;
// testar a existencia
 if ( arquivo )
 {
 // ler a quantidade de dados
 fscanf ( arquivo, "%d", &array.length );
 // testar se ha' dados
 if ( array.length <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 array.length = 0; // nao ha' dados
 }
 else
 {
 // reservar espaco
 array.data = IO_new_ints ( array.length );
 // testar a existência
 if ( array.data )
 {
 // ler e guardar valores em arranjo
 array.ix = 0;
 while ( ! feof ( arquivo ) &&
 array.ix < array.length )
 {
 // ler valor
 fscanf ( arquivo, "%d", &(array.data [ array.ix ]) );
 // passar ao proximo
 array.ix = array.ix + 1;
 } // end while
 } // end if
 } // end if
 } // end if
// retornar dados lidos
 return ( array );
} // end fIO_readintArray ( )
/**
 Method_04.
*/
void method_04 ( )
{
// definir dados
 int_Array array; // arranjo sem tamanho definido
// identificar
 IO_id ( "Method_04 - v1.2" );
// ler dados
 array = fIO_readintArray ( "ARRAY1.TXT" );
// testar a existência de dados
 if ( array.data )
 {
 // mostrar dados
 IO_printf ( "\n" );
 printIntArray ( array );
 // reciclar o espaco
 free ( array.data );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method04 ( )

//-----------------------------------------------//

/**
 copyIntArray - Copiar arranjo com valores inteiros.
 @return referencia para copia do arranjo
 @param fileName - nome do arquivo
 @param array - grupo de valores inteiros
*/
ref_int_Array copyIntArray ( int_Array array )
{
// definir dados locais
 int x = 0;
 int y = 0;
 ref_int_Array copy;
 if ( array.length <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 array.length = 0;
 }
 else
 {
 // reservar area
 copy = new_int_Array ( array.length );
 // testar se ha' descritor
 if ( copy )
 {
 copy->length = array.length;
 copy->data = IO_new_ints ( copy->length );
 // testar se ha' espaco e dados
 if ( copy->data == NULL || array.data == NULL )
 {
 printf ( "\nERRO: Falta espaco ou dados." );
 }
 else
 {
 // ler e copiar valores
 for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
 {
 // copiar valor
 copy->data [ array.ix ] = array.data [ array.ix ];
 } // end for
 } // end if
 } // end if
 } // end if
// retornar dados lidos
 return ( copy );
} // end copyIntArray ( )
/**
 Method_05.
*/
void method_05 ( )
{
// definir dados
 int_Array array; // arranjo sem tamanho definido
 ref_int_Array other; // referencia para arranjo sem tamanho definido
// identificar
 IO_id ( "Method_05 - v1.3" );
// ler dados
 array = fIO_readintArray ( "ARRAY1.TXT" );
// copiar dados
 other = copyIntArray ( array );
// testar a existência de dados
 if ( array.data )
 {
 // mostrar dados
 IO_printf ( "\nOriginal\n" );
 printIntArray ( array );
 // mostrar dados
 IO_printf ( "\nCopia\n" );
 printIntArray ( *other ); // dereferenciar a copia
 // reciclar os espacos
 free ( array.data );
 free ( other->data );
 free ( other );
 } // end if
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

//-----------------------------------------------//

/**
 Definicao de tipo arranjo bidimensional com inteiros baseado em estrutura
*/
typedef
struct s_int_Matrix
{
 int rows ;
 int columns;
 ints* data ;
 int ix, iy ;
}
int_Matrix;
/**
 Definicao de referencia para arranjo bidimensional com inteiros baseado em estrutura
*/
typedef int_Matrix* ref_int_Matrix;
/**
 new_int_Matrix - Reservar espaco para arranjo bidimensional com inteiros
 @return referencia para arranjo com inteiros
 @param rows - quantidade de dados
 @param columns - quantidade de dados
*/
ref_int_Matrix new_int_Matrix ( int rows, int columns )
{
// reserva de espaco
 ref_int_Matrix tmpMatrix = (ref_int_Matrix) malloc (sizeof(int_Matrix));
// estabelecer valores padroes
 if ( tmpMatrix != NULL )
 {
 tmpMatrix->rows = 0;
 tmpMatrix->columns = 0;
 tmpMatrix->data = NULL;
 // reservar espaco
 if ( rows>0 && columns>0 )
 {
 tmpMatrix->rows = rows;
 tmpMatrix->columns = columns;
 tmpMatrix->data = malloc (rows * sizeof(ints));
 if ( tmpMatrix->data )
 {
 for ( tmpMatrix->ix=0;
 tmpMatrix->ix<tmpMatrix->rows;
 tmpMatrix->ix=tmpMatrix->ix+1 )
 {
 tmpMatrix->data [ tmpMatrix->ix ] = (ints) malloc (columns * sizeof(int));
 } // end for
 } // end if
 } // end if
 tmpMatrix->ix = 0;
 tmpMatrix->iy = 0;
 } // end if
 return ( tmpMatrix );
} // end new_int_Matrix ( )
/**
 free_int_Matrix - Dispensar espaco para arranjo com inteiros
 @param tmpMatrix - referencia para grupo de valores inteiros
*/
void free_int_Matrix ( ref_int_Matrix matrix )
{
// testar se ha' dados
 if ( matrix != NULL )
 {
 if ( matrix->data != NULL )
 {
 for ( matrix->ix=0;
 matrix->ix<matrix->rows;
 matrix->ix=matrix->ix+1 )
 {
 free ( matrix->data [ matrix->ix ] );
 } // end for
 free ( matrix->data );
 } // end if
 free ( matrix );
 } // end if
} // end free_int_Matrix ( )
/**
 printIntMatrix - Mostrar matrix com valores inteiros.
 @param array - grupo de valores inteiros
*/
void printIntMatrix ( ref_int_Matrix matrix )
{
// testar a existencia
 if ( matrix != NULL && matrix->data != NULL )
 {
 // mostrar valores na matriz
 for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
 {
 for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
 {
 // mostrar valor
 printf ( "%3d\t", matrix->data [ matrix->ix ][ matrix->iy ] );
 } // end for
 printf ( "\n" );
 } // end for
 } // end if
} // end printIntArray ( )
/**
 Method_06.
*/
void method_06 ( )
{
// definir dado
 ref_int_Matrix matrix = new_int_Matrix ( 3, 3 );
 if ( matrix != NULL && matrix->data != NULL )
 {
 matrix->data [0][0] = 1; matrix->data [0][1] = 2; matrix->data [0][2] = 3;
 matrix->data [1][0] = 3; matrix->data [1][1] = 4; matrix->data [1][2] = 5;
 matrix->data [2][0] = 6; matrix->data [2][1] = 7; matrix->data [2][2] = 8;
 } // fim se
// identificar
 IO_id ( "Method_06 - v1.4" );
// executar o metodo auxiliar
 printIntMatrix ( matrix );
// reciclar espaco
 free_int_Matrix ( matrix );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

//-----------------------------------------------//

/**
 IO_readintMatrix - Ler arranjo bidimensional com valores inteiros.
 @return referencia para o grupo de valores inteiros
*/
ref_int_Matrix IO_readintMatrix ( )
{
// definir dados locais
 int rows = 0;
 int columns = 0;
 chars text = IO_new_chars ( STR_SIZE );
// ler a quantidade de dados
 do
 { rows = IO_readint ( "\nrows = " ); }
 while ( rows <= 0 );
 do
 { columns = IO_readint ( "\ncolumns = " ); }
 while ( columns <= 0 );
// reservar espaco para armazenar valores
 ref_int_Matrix matrix = new_int_Matrix ( rows, columns );
// testar se ha' espaco
 if ( matrix != NULL )
 {
 if ( matrix->data == NULL )
 {
 // nao ha' espaco
 matrix->rows = 0;
 matrix->columns = 0;
 matrix->ix = 0;
 matrix->iy = 0;
 }
 else
 {
 // ler e guardar valores na matriz
 for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
 {
 for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
 {
 // ler e guardar valor
 strcpy ( text, STR_EMPTY );
 matrix->data [ matrix->ix ][ matrix->iy ]
 = IO_readint ( IO_concat (
 IO_concat ( IO_concat ( text, IO_toString_d ( matrix->ix ) ), ", " ),
 IO_concat ( IO_concat ( text, IO_toString_d ( matrix->iy ) ), " : " ) ) );
 } // end for
 printf ( "\n" );
 } // end for
 } // end if
 } // end if
// retornar dados lidos
 return ( matrix );
} // end IO_readintMatrix ( )
/**
 Method_07.
*/
void method_07 ( )
{
// definir dados
 ref_int_Matrix matrix = NULL;
// identificar
 IO_id ( "Method_07 - v1.5" );
// ler dados
 matrix = IO_readintMatrix ( );
// mostrar dados
 IO_printf ( "\n" );
 printIntMatrix ( matrix );
// reciclar espaco
 free_int_Matrix ( matrix );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

//-----------------------------------------------//

/**
 fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
 @param fileName - nome do arquivo
 @param matrix - grupo de valores inteiros
*/
void fprintIntMatrix ( chars fileName, ref_int_Matrix matrix )
{
// definir dados locais
 FILE* arquivo = fopen ( fileName, "wt" );
// testar se ha' dados
 if ( matrix == NULL )
 {
 printf ( "\nERRO: Nao ha' dados." );
 }
 else
 {
 // gravar quantidade de dados
 fprintf ( arquivo, "%d\n", matrix->rows );
 fprintf ( arquivo, "%d\n", matrix->columns );

 if ( matrix->data != NULL )
 {
 // gravar valores no arquivo
 for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
 {
 for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
 {
 // gravar valor
 fprintf ( arquivo, "%d\n", matrix->data [ matrix->ix ][ matrix->iy ] );
 } // end for
 } // end for
 } // end if
 // fechar arquivo
 fclose ( arquivo );
 } // end if
} // end fprintIntMatrix ( )
/**
 Method_08.
*/
void method_08 ( )
{
// definir dados
 ref_int_Matrix matrix = NULL;
// identificar
 IO_id ( "Method_08 - v1.6" );
// ler dados
 matrix = IO_readintMatrix ( );
// gravar dados
 fprintIntMatrix( "MATRIX1.TXT", matrix );
// reciclar espaco
 free_int_Matrix ( matrix );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

//-----------------------------------------------//

/**
 freadintMatrix - Ler arranjo bidimensional com valores inteiros.
 @return referencia para o grupo de valores inteiros
 @param fileName - nome do arquivo
*/
ref_int_Matrix freadintMatrix ( chars fileName )
{
// definir dados locais
 ref_int_Matrix matrix = NULL;
 int rows = 0;
 int columns = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
 fscanf ( arquivo, "%d", &rows );
 fscanf ( arquivo, "%d", &columns );
 if ( rows <= 0 || columns <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 }
 else
 {
 // reservar espaco para armazenar
 matrix = new_int_Matrix ( rows, columns );
 // testar se ha' espaco
 if ( matrix != NULL && matrix->data == NULL )
 {
 // nao ha' espaco
 matrix->rows = 0;
 matrix->columns = 0;
 matrix->ix = 0;
 matrix->iy = 0;
 }
 else
 {
 // testar a existência
 if ( matrix != NULL )
 {
 // ler e guardar valores na matriz
 matrix->ix = 0;
 while ( ! feof ( arquivo ) && matrix->ix < matrix->rows )
 {
 matrix->iy = 0;
 while ( ! feof ( arquivo ) && matrix->iy < matrix->columns )
 {
 // guardar valor
 fscanf ( arquivo, "%d", &(matrix->data [ matrix->ix ][ matrix->iy ]) );
 // passar ao proximo
 matrix->iy = matrix->iy+1;
 } // end while
 // passar ao proximo
 matrix->ix = matrix->ix+1;
 } // end while
 matrix->ix = 0;
 matrix->iy = 0;
 } // end if
 } // end if
 } // end if
// retornar matriz lida
 return ( matrix );
} // end freadintMatrix ( )
/**
 Method_09.
*/
void method_09 ( )
{
// identificar
 IO_id ( "Method_09 - v1.7" );
// ler dados
 ref_int_Matrix matrix = freadintMatrix ( "MATRIX1.TXT" );
// mostrar dados
 IO_printf ( "\n" );
 printIntMatrix ( matrix );
// reciclar espaco
 free_int_Matrix ( matrix );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

//-----------------------------------------------//

/**
 copyIntMatrix - Copiar matriz com valores inteiros.
 @return referencia para o grupo de valores inteiros
*/
ref_int_Matrix copyIntMatrix ( ref_int_Matrix matrix )
{
// definir dados locais
 ref_int_Matrix copy = NULL;
 if ( matrix == NULL || matrix->data == NULL )
 {
 IO_printf ( "\nERRO: Faltam dados.\n" );
 }
 else
 {
 if ( matrix->rows <= 0 || matrix->columns <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 }
 else
 {
 // reservar espaco
 copy = new_int_Matrix ( matrix->rows, matrix->columns );
 // testar se ha' espaco e dados
 if ( copy == NULL || copy->data == NULL )
 {
 printf ( "\nERRO: Falta espaco." );
 }
 else
 {
 // copiar valores
 for ( copy->ix = 0; copy->ix < copy->rows; copy->ix = copy->ix + 1 )
 {
 for ( copy->iy = 0; copy->iy < copy->columns; copy->iy = copy->iy + 1 )
 {
 // copiar valor
 copy->data [ copy->ix ][ copy->iy ]
 = matrix->data [ copy->ix ][ copy->iy ];
 } // end for
 } // end for
 } // end if
 } // end if
 } // end if

// retornar copia
 return ( copy );
} // end copyIntMatrix ( )
/**
 Method_10.
*/
void method_10 ( )
{
// definir dados
 ref_int_Matrix matrix = NULL;
 ref_int_Matrix other = NULL;
// identificar
 IO_id ( "Method_10 - v1.8" );
// ler dados
 matrix = freadintMatrix ( "MATRIX1.TXT" );
// copiar dados
 other = copyIntMatrix ( matrix );
// mostrar dados
 IO_printf ( "\nOriginal\n" );
 printIntMatrix ( matrix );
// mostrar dados
 IO_printf ( "\nCopia\n" );
 printIntMatrix ( other );
// reciclar espaco
 free_int_Matrix ( matrix );
 free_int_Matrix ( other );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method10 ( )

//-----------------------------------------------//

/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( )
{
// definir dado
 int x = 0;
// repetir at  desejar parar
 do
 {
 // identificar
 IO_id ( "EXEMPLO1000 - Programa - v1.8" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0- parar" );
 IO_println ( "1- Mostrar certa quantidade de valores" );
 IO_println ( "2- Ler arranjo com valores inteiros" );
 IO_println ( "3- Gravar arranjo com valores inteiros" );
 IO_println ( "4- Ler tamanho do arranjo com valores inteiros" );
 IO_println ( "5- Copiar arranjo com valores inteiros" );
 IO_println ( "6- Definicao de tipo arranjo bidimensional com inteiros baseado em estrutura" );
 IO_println ( "7- Ler arranjo bidimensional com valores inteiros" );
 IO_println ( "8- Gravar arranjo bidimensional com valores inteiros" );
 IO_println ( "9- Ler arranjo bidimensional com valores inteiros" );
 IO_println ( "10- Copiar matriz com valores inteiros" );

 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 // testar valor
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
 IO_pause ( IO_concat ( "Valor diferente das opcoes [0,1,2,3,4,5,6,7,8,9,10] (",
 IO_concat ( IO_toString_d ( x ), ")" ) ) );
 } // end switch
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // end main ( )

/*
----------------------------------------------
----------------------------------------------
//ANOTACOES/ NOTAS/ OBSERVACOES:
- v0.0 Cria um array de tamanho 5 alocando 5 numeros -

- v1.0 Pede ao usuario digitar o tamanho do array desejado e alocar os numeros pela entrada de dados e mostra o array logo em seguida -

- v1.1 Pede ao usuario digitar o tamanho do array desejado e alocar os numeros pela entrada de dados -

- v1.2 Mostra o array criado no method3 -

- v1.3 Copia o array criado no method3 e mostra o array original e sua copia logo em seguida -

- v1.4 Cria uma matriz de tamanho 3x3 alocando os numeros dinamicamente -

- v1.5 Pede ao usuario quantas linhas e colunas tera a matriz e pede para ele alocar o numeros desejados, em seguida mostra a matriz criada -

- v1.6 Pede ao usuario quantas linhas e colunas tera a matriz e pede para ele alocar o numeros desejados -

- v1.7 Mostra a matriz criada no method8 -

- v1.8 Copia a matriz criada no mathod8 e mostra em seguida a original e sua copia -

----------------------------------------------
----------------------------------------------

----------------------------------------------
----------------------------------------------
Versao Data Modificacao
0.0 _11_/_05_ esboco e adicao do method_01
1.0 _11_/_05_ modificacao esboco e adicao do method_02
1.1 _11_/_05_ modificacao esboco e adicao do method_03
1.2 _11_/_05_ modificacao esboco e adicao do method_04
1.3 _11_/_05_ modificacao esboco e adicao do method_05
1.4 _11_/_05_ modificacao esboco e adicao do method_06
1.5 _11_/_05_ modificacao esboco e adicao do method_07
1.6 _11_/_05_ modificacao esboco e adicao do method_08
1.7 _11_/_05_ modificacao esboco e adicao do method_09
1.8 _11_/_05_ modificacao esboco e adicao do method_010

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

