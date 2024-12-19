#include <stdio.h>
#include <stdbool.h>

/**
   Funcao para ler valor inteiro do teclado.
   @return valor lido
   @param  texto - mensagem a ser exibida antes da leitura
*/
int readint ( char *texto )
{
 // dado local
    int x=0;
    printf ( "\n%s", texto );
    scanf  ( "%d"  , &x ); getchar( );
    return ( x );
}

/**
   Funcao para ler valor real do teclado.
   @return valor lido
   @param  texto - mensagem a ser exibida antes da leitura
*/
double readdouble ( char *texto )
{
 // dado local
    double x=0;
    printf ( "\n%s", texto );
    scanf  ( "%lf"  , &x ); getchar( );
    return ( x );
}

/**
   Funcao para ler valor logico do teclado.
   @return valor lido
   @param  texto - mensagem a ser exibida antes da leitura
*/
bool readbool ( char *texto )
{
 // dado local
    int x=0;
    printf ( "\n%s", texto );
    scanf  ( "%d"  , &x ); getchar( );
    return ( x!=0 );
}

/**
   Funcao para ler caractere do teclado.
   @return valor lido
   @param  texto - mensagem a ser exibida antes da leitura
*/
char readchar ( char *texto )
{
 // dado local
    char x='0';
    char y='0';
    printf ( "\n%s", texto );
    scanf  ( "%c"  , &x );
    do { y = getchar( ); } while ( y != '\n' );
    return ( x );
}
