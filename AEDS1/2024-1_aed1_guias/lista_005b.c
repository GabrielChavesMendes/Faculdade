/**
  * ------------------------- Documentacao preliminar
  * Pontificia Universidade Catolica de Minas Gerais
  * Curso de Ciencia da Computacao
  * Algoritmos e Estruturas de Dados I
  *
  * Trabalho pratico: lista 00
  *
  * Objetivo:
  * Modelo de programa para a disciplina AED I
  * Sugestao para montar um trabalho pratico
  *
  * Autor:   Matricula: 999999  Nome: xxx yyy zzz
  * Versao:  1.0                Data: 01/mm/20aa
  *
  * Dados:
  * - opcao de execucao escolhida pelo usuario
  *
  * Resultados:
  * - execucao de um teste de cada vez a escolha do usuario
  *
  * Condicoes:
  * - so' aceitara' as opcoes oferecidas.
  *
  * Arquivos:
  *
  * - lista_00.c
  * - lista_00     ( no Linux   )
  * - lista_00.exe ( no Windows )
  *
  * Forma de compilacao:
  * - acionar o compilador no modo console 
  *   (terminal/janela de comandos):
  *
  *   Linux  : gcc -o ./lista_03 ./lista_03.c
  *   Windows: gcc -o   lista_03   lista_03.c
  *
  * Forma de uso:
  * - acionar o programa   no modo console 
  *   (terminal/janela de comandos):
  *
  *   Linux  :  ./lista_03
  *   Windows:    lista_03
  *
  * Referencias:
  * - Exemplos mostrados em sala de aula
  * - Apostila: Fundamentos de Programacao - Notas de aulas
  *
  */

// --------------------------- classes nativas
//                             ou auxiliares

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// --------------------------- definicao de classe

/**
  * Modelo para definir exemplo de um programa.
  * Obs.: E' recomendado ter o nome do programa
  *       sem espacos em branco, acentos ou cedilha.
  */

// --------------------------- tratamento de erro

// --------------------------- definicao de constantes

// --------------------------- definicao de armazenadores globais

// --------------------------- definicao de prototipos

// --------------------------- definicao de metodos

/**
  * Metodo_01.
  */
void metodo_01 ( void )
{
 // definir dados e resultados
    int lado1    = 10;
    int lado2    =  2;
    int area     =  1;

 // identificar
    printf ( "\n%s\n", "Metodo_01" );
 // ler dados
    do
    {
     // ler dados do teclado
        printf( "Qual o primeiro lado? "  );
        scanf ( "%i", &lado1 ); getchar ( );
        printf( "Qual o segundo  lado? "  );
        scanf ( "%i", &lado2 ); getchar ( );
     // testar se lados positivos
        if ( lado1 <= 0 && lado2 <= 0 )
        {
         // mostrar erro
            printf ( "%s\n", "ERRO: Dado(s) invalido(s)." );
        } // end if
     //
    }// repetir enquanto nao houver dados validos
    while ( lado1 <= 0 || lado2 <= 0 );

 // calcular a area
    area     = lado1 * lado2;
 // mostrar  a area
    printf ( "%s %d", "area = ", area );

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_01 ( )

/**
  * Metodo_02.
  */
void metodo_02 ( void )
{
 // definir dados e resultados
    int  lado1    = 10 ;
    int  lado2    =  2 ;
    int  area     =  1 ;
    char opcao    = '0';

 // identificar
    printf ( "\n%s\n", "Metodo_02" );
 // repetir  (teste no fim)
    do
    {
     // ler dados
        do
        {
         // ler dados do teclado
            printf( "Qual o primeiro lado? "  );
            scanf ( "%i", &lado1 ); getchar ( );
            printf( "Qual o segundo  lado? "  );
            scanf ( "%i", &lado2 ); getchar ( );
         // testar se lados positivos
            if ( lado1 <= 0 && lado2 <= 0 )
            {
             // mostrar erro
                printf ( "%s\n", "ERRO: Dado(s) invalido(s)." );
            } // end if
        }// repetir enquanto nao houver dados validos
        while ( lado1 <= 0 || lado2 <= 0 );

     // calcular a area
        area     = lado1 * lado2;
     // mostrar  a area
        printf ( "%s %d", "area = ", area );

     // ler opcao para continuar
        printf ( "\n%s", "Quer repetir [S]? " );
        scanf  ( "%c", &opcao );    getchar ( );
    }
    while ( opcao == 'S' );

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_02 ( )

/**
  * Metodo_03.
  */
void metodo_03 ( void )
{
 // definir dados e resultados
    int  lado1    = 10 ;
    int  lado2    =  2 ;
    int  area     =  1 ;
    char opcao    = '0';

 // identificar
    printf ( "\n%s\n", "Metodo_03" );
 // repetir  (teste no fim)
    do
    {
     // ler dados
        do
        {
         // ler dados do teclado
            printf( "Qual o primeiro lado? "  );
            scanf ( "%i", &lado1 ); getchar ( );
            printf( "Qual o segundo  lado? "  );
            scanf ( "%i", &lado2 ); getchar ( );
         // testar se lados positivos
            if ( lado1 <= 0 && lado2 <= 0 )
            {
             // mostrar erro
                printf ( "%s\n", "ERRO: Dado(s) invalido(s)." );
            } // end if
        }// repetir enquanto nao houver dados validos
        while ( lado1 <= 0 || lado2 <= 0 );

     // calcular a area
        area     = lado1 * lado2;
     // mostrar  a area
        printf ( "%s %d", "area = ", area );

     // ler opcao para continuar
        printf ( "\n%s", "Quer repetir [S,s]? " );
        scanf  ( "%c", &opcao );    getchar ( );
    }
    while ( opcao == 'S' || opcao == 's' );

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_03 ( )

/**
  * Metodo_04.
  */
void metodo_04 ( void )
{
 // definir dados e resultados
    int  lado1    = 10 ;
    int  lado2    =  2 ;
    int  area     =  1 ;
    char opcao    = 'S';

 // identificar
    printf ( "\n%s\n", "Metodo_04" );
 // repetir  (teste no inicio)
    while ( opcao == 'S' || opcao == 's' )
    {
     // ler dados
        do
        {
         // ler dados do teclado
            printf( "Qual o primeiro lado? "  );
            scanf ( "%i", &lado1 ); getchar ( );
            printf( "Qual o segundo  lado? "  );
            scanf ( "%i", &lado2 ); getchar ( );
         // testar se lados positivos
            if ( lado1 <= 0 && lado2 <= 0 )
            {
             // mostrar erro
                printf ( "%s\n", "ERRO: Dado(s) invalido(s)." );
            } // end if
        }// repetir enquanto nao houver dados validos
        while ( lado1 <= 0 || lado2 <= 0 );

     // calcular a area
        area     = lado1 * lado2;
     // mostrar  a area
        printf ( "%s %d", "area = ", area );

     // ler opcao para continuar
        printf ( "\n%s", "Quer repetir [S,s]? " );
        scanf  ( "%c", &opcao );    getchar ( );
    }// end while

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_04 ( )

/**
  * Metodo_05.
  */
void metodo_05 ( void )
{
 // definir dados e resultados
    int  lado1    = 10 ;
    int  lado2    =  2 ;
    int  area     =  1 ;
    char opcao    = 'S';

 // identificar
    printf ( "\n%s\n", "Metodo_05" );
 // repetir  (teste no inicio)
    while (  opcao == 'S' || opcao == 's'  )
    {
     // ler dados do teclado
        printf( "Qual o primeiro lado? "  );
        scanf ( "%i", &lado1 ); getchar ( );
        printf( "Qual o segundo  lado? "  );
        scanf ( "%i", &lado2 ); getchar ( );
     // testar se lados positivos
        if ( lado1 <= 0 && lado2 <= 0 )
        {
         // mostrar erro
            printf ( "%s\n", "ERRO: Dado(s) invalido(s)." );
        }
        else
        {
         // calcular a area
            area     = lado1 * lado2;
         // mostrar  a area
            printf ( "%s %d", "area = ", area );
        }// end if
     // ler opcao para continuar
        printf ( "\n%s", "Quer repetir [S,s]? " );
        scanf  ( "%c", &opcao );    getchar ( );
    }// end while

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_05 ( )

/**
  * Metodo_06.
  */
void metodo_06 ( void )
{
 // definir dados e resultados
    int  lado1    = 10 ;
    int  lado2    =  2 ;
    int  area     =  1 ;
    char opcao    = 'S';
    bool teste    = false;

 // identificar
    printf ( "\n%s\n", "Metodo_06" );
 // repetir  (teste no inicio)
    while (   opcao == 'S' || opcao == 's'   )
    {
     // ler dados do teclado
        printf( "Qual o primeiro lado? "  );
        scanf ( "%i", &lado1 ); getchar ( );
        printf( "Qual o segundo  lado? "  );
        scanf ( "%i", &lado2 ); getchar ( );
     // testar se lados positivos
        teste = (lado1 <= 0 && lado2 <= 0);
        if ( teste )
        {
         // mostrar erro
            printf ( "%s\n", "ERRO: Dado(s) invalido(s)." );
        }
        else
        {
         // calcular a area
            area     = lado1 * lado2;
         // mostrar  a area
            printf ( "%s %d", "area = ", area );
        }// end if
     // ler opcao para continuar
        printf ( "\n%s", "Quer repetir [S,s]? " );
        scanf  ( "%c", &opcao );    getchar ( );
    }// end while

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_06 ( )

/**
  * Metodo_07.
  */
void metodo_07 ( void )
{
 // definir dados e resultados
    int  lado1    = 10 ;
    int  lado2    =  2 ;
    int  area     =  1 ;
    char opcao    = 'S';
    bool teste    = false;

 // identificar
    printf ( "\n%s\n", "Metodo_07" );
 // repetir  (teste no inicio)
    teste =  (opcao == 'S' || opcao == 's');
    while (  teste  )
    {
     // ler dados do teclado
        printf( "Qual o primeiro lado? "  );
        scanf ( "%i", &lado1 ); getchar ( );
        printf( "Qual o segundo  lado? "  );
        scanf ( "%i", &lado2 ); getchar ( );
     // testar se lados positivos
        teste = (lado1 <= 0 && lado2 <= 0);
        if (  teste  )
        {
         // mostrar erro
            printf ( "%s\n", "ERRO: Dado(s) invalido(s)." );
        }
        else
        {
         // calcular a area
            area     = lado1 * lado2;
         // mostrar  a area
            printf ( "%s %d", "area = ", area );
        }// end if
     // ler opcao para continuar
        printf ( "\n%s", "Quer repetir [S,s]? " );
        scanf  ( "%c", &opcao );    getchar ( );
        teste =  (opcao == 'S' || opcao == 's');
    }// end while

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_07 ( )

/**
  * Metodo_08.
  */
void metodo_08 ( void )
{
 // definir dados e resultados
    int  lado1    = 10 ;
    int  lado2    =  2 ;
    int  area     =  1 ;
    char opcao    = 'S';
    bool teste    = false;
    bool teste1   = false;
    bool teste2   = false;

 // identificar
    printf ( "\n%s\n", "Metodo_08" );
 // repetir  (teste no inicio)
    teste  = ( opcao == 'S' || opcao == 's' );
    while  ( teste )
    {
     // ler dados do teclado
        printf( "Qual o primeiro lado? "  );
        scanf ( "%i", &lado1 ); getchar ( );
        printf( "Qual o segundo  lado? "  );
        scanf ( "%i", &lado2 ); getchar ( );
     // testar se lados positivos
        teste = (lado1 <= 0 && lado2 <= 0);
        if ( teste )
        {
         // mostrar erro
            printf ( "%s\n", "ERRO: Dado(s) invalido(s)." );
        }
        else
        {
         // calcular a area
            area     = lado1 * lado2;
         // mostrar  a area
            printf ( "%s %d", "area = ", area );
        }// end if
     // ler opcao para continuar
        do
        {
          printf ( "\n%s", "Quer repetir [S,s,N,n]? " );
          scanf  ( "%c", &opcao );    getchar ( );
          teste1 = ( opcao == 'S' || opcao == 's' );
          teste2 = ( opcao == 'N' || opcao == 'n' );
        }
        while ( ! teste1 && ! teste2 );
        teste  = teste1;
    }// end while

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_08 ( )

/**
  * Funcao para ler opcao valida (S|N).
  */
bool repetir1 ( void )
{
 // definir dados locais
    bool teste  = false;
    bool teste1 = false;
    bool teste2 = false;
    char opcao  = '0';
 // ler opcao valida
    do
    {
     // ler opcao
        printf ( "\n%s", "Quer repetir [S,s,N,n]? " );
        scanf  ( "%c", &opcao ); getchar ( );
        teste1 = ( opcao == 'S' || opcao == 's' );
        teste2 = ( opcao == 'N' || opcao == 'n' );
    }
    while ( ! teste1 && !teste2 );
    teste = teste1;
    return ( teste );
} // end repetir1 ( )

/**
  * Metodo_09.
  */
void metodo_09 ( void )
{
 // definir dados e resultados
    int  lado1    = 10 ;
    int  lado2    =  2 ;
    int  area     =  1 ;
    char opcao    = 'S';
    bool teste    = false;

 // identificar
    printf ( "\n%s\n", "Metodo_08" );
 // repetir  (teste no inicio)
    teste  = ( opcao == 'S' || opcao == 's' );
    while  ( teste )
    {
     // ler dados do teclado
        printf( "Qual o primeiro lado? "  );
        scanf ( "%i", &lado1 ); getchar ( );
        printf( "Qual o segundo  lado? "  );
        scanf ( "%i", &lado2 ); getchar ( );
     // testar se lados positivos
        teste = (lado1 <= 0 && lado2 <= 0);
        if ( teste )
        {
         // mostrar erro
            printf ( "%s\n", "ERRO: Dado(s) invalido(s)." );
        }
        else
        {
         // calcular a area
            area     = lado1 * lado2;
         // mostrar  a area
            printf ( "%s %d", "area = ", area );
        }// end if
     // ler opcao para continuar
        teste  = repetir1 ( );
    }// end while

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_09 ( )

/**
  * Funcao para ler opcao valida (S|N).
  */
bool repetir2 ( char *texto )
{
 // definir dados locais
    bool teste  = false;
    bool teste1 = false;
    bool teste2 = false;
    char opcao  = '0';
 // ler opcao para continuar
    do
    {
      printf ( "\n%s", texto  );
      scanf  ( "%c"  , &opcao ); getchar ( );
      teste1 = ( opcao == 'S' || opcao == 's' );
      teste2 = ( opcao == 'N' || opcao == 'n' );
    }
    while ( ! (teste1 || teste2) );
    teste = teste1;
    return ( teste );
} // end repetir2 ( )

/**
  * Funcao para ler valor inteiro positivo.
  */
int ler_positivo ( char *texto )
{
 // definir dados locais
    int valor = -1;
 // repetir enquanto negativo
    while ( valor < 0 )
    {
     // ler dado
        printf( "\n%s", texto  );
        scanf ( "%i"  , &valor ); getchar ( );
     // testar o lado
        if ( valor < 0 )
        {
         // mostrar erro
            printf ( "%s\n", "ERRO: Dado invalido." );
        } // end if
    } // end while
    return ( valor );
} // end ler_positivo ( )

/**
  * Metodo_10.
  */
void metodo_10 ( void )
{
 // definir dados e resultados
    int  lado1    = 10 ;
    int  lado2    =  2 ;
    int  area     =  1 ;
    char opcao    = 'S';
    bool teste    = false;

 // identificar
    printf ( "\n%s\n", "Metodo_10" );
 // repetir  (teste no inicio)
    teste  = repetir2 ( "Quer executar [S,s,N,n]? " );
    while  ( teste )
    {
     // ler dados do teclado
        lado1 = ler_positivo( "Qual o primeiro lado? "  );
        lado2 = ler_positivo( "Qual o segundo  lado? "  );
     // calcular a area
        area     = lado1 * lado2;
     // mostrar  a area
        printf ( "%s %d", "area = ", area );
     // ler opcao para repetir
        teste  = repetir2 ( "Quer repetir [S,s,N,n]? " );
    }// end while

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // end method_10 ( )

// --------------------------- definicao do metodo principal

int main ( void )
{
 // definir dados/resultados
    int opcao = 0;

 // repetir ate' desejar parar
    do
    {
     // identificar
        printf ( "\n" );             // para saltar linha
        printf ( "%s\n", "Lista_00 - v.0.0 - 01/mm/20aa"       );
        printf ( "%s\n", "Matricula: 999999 Nome: xxx yyy zzz" );

     // mostrar opcoes
        printf ( "%s\n", "Opcoes:"         );
        printf ( "%s\n", " 0 - parar"      );
        printf ( "%s\n", " 1 - metodo 01   2 - metodo 02" );
        printf ( "%s\n", " 3 - metodo 03   4 - metodo 04" );
        printf ( "%s\n", " 5 - metodo 05   6 - metodo 06" );
        printf ( "%s\n", " 7 - metodo 07   8 - metodo 08" );
        printf ( "%s\n", " 9 - metodo 09  10 - metodo 10" );
        printf ( "%s\n", "" );        // para saltar linha

     // ler opcao
        printf ( "%s", "Qual a sua opcao? " );
        scanf  ( "%d", &opcao ); getchar ( );
        printf ( "%d",  opcao );

     // escolher acao
        switch ( opcao )
        {
           case  0:               break;
           case  1: metodo_01 ( ); break;
           case  2: metodo_02 ( ); break;
           case  3: metodo_03 ( ); break;
           case  4: metodo_04 ( ); break;
           case  5: metodo_05 ( ); break;
           case  6: metodo_06 ( ); break;
           case  7: metodo_07 ( ); break;
           case  8: metodo_08 ( ); break;
           case  9: metodo_09 ( ); break;
           case 10: metodo_10 ( ); break;
           default:
                    printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
              break;
        } // fim escolher
    }
    while ( opcao != 0 );

 // encerrar execucao
    printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
    getchar( );

} // end main ( )


/*
------------------------------ documentacao complementar

------------------------------ notas / observacoes / comentarios

------------------------------ previsao de testes

------------------------------ historico

Versao	Data                   Modificacao
  0.1	__/__                  esboco

 ----------------------------- testes

Versao	Teste
  0.1	01. ( OK )             identificacao de programa

*/
