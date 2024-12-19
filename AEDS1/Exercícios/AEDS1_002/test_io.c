// 999999_AED1
#include <stdio.h>
#include "io.h"

int method_01 ( void )
{
    int opcao = 0;
    printf ( "%s\n", "999999_AED1 - Method_01" );
    // acoes
    do
    {
       opcao = readint ( "Qual a opcao (int)? " );
       printf ( "%s%d", "opcao = ", opcao );
    }
    while ( opcao != 0 );
    printf ( "\n%s\n", "Apertar ENTER para terminar." );
    getchar( );
    return (0);
}

int method_02 ( void )
{
    double opcao = 0.0;
    printf ( "%s\n", "999999_AED1 - Method_02" );
    // acoes
    do
    {
       opcao = readdouble ( "Qual a opcao (double)? " );
       printf ( "%s%lf", "opcao = ", opcao );
    }
    while ( opcao != 0 );
    printf ( "\n%s\n", "Apertar ENTER para terminar." );
    getchar( );
    return (0);
}

int method_03 ( void )
{
    bool opcao = false;
    printf ( "%s\n", "999999_AED1 - Method_03" );
    // acoes
    do
    {
       opcao = readbool ( "Qual a opcao (bool)? " );
       printf ( "%s%d", "opcao = ", opcao );
    }
    while ( opcao ); // OBS.: teste = ( opcao != false )
    printf ( "\n%s\n", "Apertar ENTER para terminar." );
    getchar( );
    return (0);
}

int method_04 ( void )
{
    char opcao = '0';
    printf ( "%s\n", "999999_AED1 - Method_04" );
    // acoes
    do
    {
       opcao = readchar ( "Qual a opcao (char)? " );
       printf ( "%s%c (%d)", "opcao = ", opcao, opcao );
    }
    while ( opcao != '0' );
    printf ( "\n%s\n", "Apertar ENTER para terminar." );
    getchar( );
    return (0);
}

int main ( void )
{
 // testes
    printf ( "%s\n\n", "999999_AED1 - Leituras" );
    method_01 ( );
    method_02 ( );
    method_03 ( );
    method_04 ( );
    printf ( "\n%s\n", "Apertar ENTER para terminar." );
    getchar( );
    return (0);
}