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
    int x   = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_01" );
 // repetir certo numero de vezes
    x = 5;                   // valor inicial
    while ( x > 0 )          // teste
    {
     // mostrar valor
        printf ( "\n%d", x );
        x = x - 1;           // variacao
    } // end while
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
    int x   = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_02" );
 // repetir certo numero de vezes
    //  inicial teste variacao
    for ( x=5;  x>0;  x=x-1  )
    {
     // mostrar valor
        printf ( "\n%d", x );
    } // end for
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
    int x   = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_03" );
 // repetir certo numero de vezes
    x = 1;                   // valor inicial
    while ( x <= 5 )         // teste
    {
     // mostrar valor
        printf ( "\n%d", x );
        x = x + 1;           // variacao
    } // end if
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
    int x   = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_04" );
 // repetir certo numero de vezes
    //  inicial teste variacao
    for ( x=1;  x<=5; x=x+1  )
    {
     // mostrar valor
        printf ( "\n%d", x );
    } // end for
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
    int x   = 0;
    int y1  = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_05" );
 // repetir certo numero de vezes
    //  inicial teste variacao
    for ( x=0;  x<5;  x=x+1  )
    {
     // constante
        y1 = 5;
     // mostrar valores
        printf ( "\n%d\t%d", 
                     x, y1 );
    } // end for
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
    int x   = 0;
    int y1  = 0;
    int y2  = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_06" );
 // repetir certo numero de vezes
    //  inicial teste variacao
    for ( x=0;  x<5;  x=x+1  )
    {
     // constante
        y1 = 5;
     // identidade
        y2 = x;
     // mostrar valores
        printf ( "\n%d\t%d\t%d", 
                     x, y1, y2 );
    } // end for
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
    int x   = 0;
    int y1  = 0;
    int y2  = 0;
    int y3  = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_07" );
 // repetir certo numero de vezes
    //  inicial teste variacao
    for ( x=0;  x<5;  x=x+1  )
    {
     // constante
        y1 = 5;
     // identidade
        y2 = x;
     // par
        y3 = 2*x;
     // mostrar valores
        printf ( "\n%d\t%d\t%d\t%d",
                     x, y1, y2, y3 );
    } // end for
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
    int x   = 0;
    int y1  = 0;
    int y2  = 0;
    int y3  = 0;
    int y4  = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_08" );
 // repetir certo numero de vezes
    //  inicial teste variacao
    for ( x=0;  x<5;  x=x+1  )
    {
     // constante
        y1 = 5;
     // identidade
        y2 = x;
     // par
        y3 = 2*x;
     // impar
        y4 = 2*x+1;
     // mostrar valores
        printf ( "\n%d\t%d\t%d\t%d\t%d",
                     x, y1, y2, y3, y4 );
    } // end for
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_08 ( )

/**
  * Metodo_09.
  */
void metodo_09 ( void )
{
 // definir dados e resultados
    int x   = 0;
    int y1  = 0;
    int y2  = 0;
    int y3  = 0;
    int y4  = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_09" );
 // repetir certo numero de vezes
    //  inicial teste variacao
    for ( x=0;  x<5;  x=x+1  )
    {
     // constante
        y1 = -5;
     // identidade
        y2 = -x;
     // par
        y3 = -2*x;
     // impar
        y4 = -2*x-1;
     // mostrar valores
        printf ( "\n%2d\t%2d\t%2d\t%2d\t%2d",
                     x,   y1,  y2,  y3,  y4 );
    } // end for
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_09 ( )

/**
  * Metodo_10.
  */
void metodo_10 ( void )
{
 // definir dados e resultados
    int x   = 0;
    int n   = 0;
    int y1  = 0;
    int y2  = 0;
    int y3  = 0;
    int y4  = 0;
    int y5  = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_10" );
 // ler a quantidade de vezes
    printf ( "\nQuantos valores? " );
    scanf  ( "%d", &n ); getchar ( );
 // repetir certo numero de vezes
    //  inicial teste variacao
    for ( x=0;  x<n;  x=x+1  )
    {
     // constante
        y1 = 5;
     // identidade
        y2 = x;
     // par
        y3 = 2*x;
     // impar
        y4 = 2*x+1;
     // invertida
        y5 = n-x-1;
     // mostrar valores
        printf ( "\n%d\t%d\t%d\t%d\t%d\t%d",
                     x, y1, y2, y3, y4, y5 );
    } // end for
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_10 ( )

/**
  * Metodo_11.
  */
void metodo_11 ( void )
{
 // definir dados e resultados
    int x   = 0;
    int m   = 0;
    int n   = 0;
    int y1  = 0;
    int y2  = 0;
    int y3  = 0;
    int y4  = 0;
    int y5  = 0;
    int y6  = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_11" );
 // ler a quantidade de vezes
    printf ( "\nQuantos valores? " );
    scanf  ( "%d", &n ); getchar ( );
    m = n-1;
 // repetir certo numero de vezes
    //  inicial teste variacao
    for ( x=0;  x<n;  x=x+1  )
    {
     // constante
        y1 = 5;
     // identidade
        y2 = x;
     // par
        y3 = 2*x;
     // impar
        y4 = 2*x+1;
     // invertida
        y5 = n-x-1;
     // invertida
        y6 = m-x;
     // mostrar valores
        printf ( "\n%d\t%d\t%d\t%d\t%d\t%d\t%d",
                     x, y1, y2, y3, y4, y5, y6 );
    } // end for
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_11 ( )

/**
  * Metodo_12.
  */
void metodo_12 ( void )
{
 // definir dados e resultados
    int x   = 0;
    int m   = 0;
    int n   = 0;
    int p   = 0;
    int y1  = 0;
    int y2  = 0;
    int y3  = 0;
    int y4  = 0;
    int y5  = 0;
    int y6  = 0;
    int y7  = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_12" );
 // ler a quantidade de vezes
    printf ( "\nQuantos valores? " );
    scanf  ( "%d", &n ); getchar ( );
    m = n-1;
    p = 2*m;
 // repetir certo numero de vezes
    //  inicial teste variacao
    for ( x=0;  x<n;  x=x+1  )
    {
     // constante
        y1 = 5;
     // identidade
        y2 = x;
     // par
        y3 = 2*x;
     // impar
        y4 = 2*x+1;
     // invertida
        y5 = n-x-1;
     // invertida
        y6 = m-x;
     // par invertida
        y7 = p-2*x;
     // mostrar valores
        printf ( "\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",
                     x, y1, y2, y3, y4, y5, y6, y7 );
    } // end for
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_12 ( )

/**
  * Metodo_13.
  */
void metodo_13 ( void )
{
 // definir dados e resultados
    int x   = 0;
    int m   = 0;
    int n   = 0;
    int p   = 0;
    int q   = 0;
    int y1  = 0;
    int y2  = 0;
    int y3  = 0;
    int y4  = 0;
    int y5  = 0;
    int y6  = 0;
    int y7  = 0;
    int y8  = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_13" );
 // ler a quantidade de vezes
    printf ( "\nQuantos valores? " );
    scanf  ( "%d", &n ); getchar ( );
    m = n-1;
    p = 2*m;
    q = 2*m+1;
 // repetir certo numero de vezes
    //  inicial teste variacao
    for ( x=0;  x<n;  x=x+1  )
    {
     // constante
        y1 = 5;
     // identidade
        y2 = x;
     // par
        y3 = 2*x;
     // impar
        y4 = 2*x+1;
     // invertida
        y5 = n-x-1;
     // invertida
        y6 = m-x;
     // par invertida
        y7 = p-2*x;
     // impar invertida
        y8 = q-2*x;
     // mostrar valores
        printf ( "\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",
                     x, y1, y2, y3, y4, y5, y6, y7, y8 );
    } // end for
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_13 ( )

/**
  * Metodo_14.
  */
void metodo_14 ( void )
{
 // definir dados e resultados
    int x   = 0;
    int m   = 0;
    int n   = 0;
    int p   = 0;
    int q   = 0;
    int y1  = 0;
    int y2  = 0;
    int y3  = 0;
    int y4  = 0;
    int y5  = 0;
    int y6  = 0;
    int y7  = 0;
    int y8  = 0;
    int y9  = 0;
 // identificar
    printf ( "\n%s\n", "Metodo_14" );
 // ler a quantidade de vezes
    printf ( "\nQuantos valores? " );
    scanf  ( "%d", &n ); getchar ( );
    m = n-1;
    p = 2*m;
    q = 2*m+1;
 // repetir certo numero de vezes
    //  inicial teste variacao
    for ( x=0;  x<n;  x=x+1  )
    {
     // constante
        y1 = 5;
     // identidade
        y2 = x;
     // par
        y3 = 2*x;
     // impar
        y4 = 2*x+1;
     // invertida
        y5 = n-x-1;
     // invertida
        y6 = m-x;
     // par invertida
        y7 = p-2*x;
     // impar invertida
        y8 = q-2*x;
     // quadratica
        y9 = x*x;
     // mostrar valores
        printf ( "\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",
                     x, y1, y2, y3, y4, y5, y6, y7, y8, y9 );
    } // end for
 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_14 ( )

/**
  * Metodo_15.
  */
void metodo_15 ( void )
{
 // definir dados e resultados
 // OBS.: APENAS PARA VALOR INICIAL 
 //       E' POSSIVEL ATRIBUIR DIRETAMENTE
    char s1 [80] = ""     ; // area inicialmente vazia
    char s2 [80] = "fGhIJ"; // area com valor inicial
    char s3 [  ] = "KlMnO";
    char s4 [  ] = {'p','Q','r','s','T','\0'};
    int  x      = 0 ;

 // identificar
    printf ( "\n%s\n", "Metodo_15" );
 // determinar valor inicial
 // OBS.: PARA ATRIBUIR E' NECESSARIO USAR strcpy( )
    strcpy ( s1, "AbCdE" ); // s1 = "AbCdE";
 // mostrar valores
    printf ( "\ns1 = %s (%d)", s1, strlen(s1) );
    printf ( "\n" );
    printf ( "\ns2 = %s (%d)", s2, strlen(s2) );
    printf ( "\n" );
    printf ( "\ns3 = %s (%d)", s3, strlen(s3) );
    printf ( "\n" );
    printf ( "\ns4 = %s (%d)", s4, strlen(s4) );
    printf ( "\n" );
 // mostrar cada simbolo
    for ( x=0; x<=strlen(s1); x=x+1 )
    {
    	printf ( "\n%d %c %d", x, s1[x], s1[x] );
    } // end for
    printf ( "\n" );

    for ( x=0; x<=strlen(s2); x=x+1 )
    {
    	printf ( "\n%d %c %d", x, s2[x], s2[x] );
    } // end for
    printf ( "\n" );

    for ( x=0; x<=strlen(s3); x=x+1 )
    {
    	printf ( "\n%d %c %d", x, s3[x], s3[x] );
    } // end for
    printf ( "\n" );

 // alterar valor
    strcpy ( s2, "0123456789" );
    strcat ( s2, s1 );
    //strcpy ( s3, "0123456789" );

 // mostrar valor
    printf ( "\ns1 = %s (%d)", s1, strlen(s1) );
    printf ( "\n" );
    printf ( "\ns2 = %s (%d)", s2, strlen(s2) );
    printf ( "\n" );
    printf ( "\ns3 = %s (%d)", s3, strlen(s3) );
    printf ( "\n" );
    printf ( "\ns4 = %s (%d)", s4, strlen(s4) );
    printf ( "\n" );

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_15 ( )

/**
  * Metodo_16.
  */
void metodo_16 ( void )
{
 // definir dados e resultados
    char *s1 = NULL; // nao existe dado algum

 // identificar
    printf ( "\n%s\n", "Metodo_16" );
 // solicitar reserva de espaco para guardar 80 caracteres
    s1 = calloc (80, sizeof(char)); // char s1 [80];

 // confirmar a reserva
    if ( s1 != NULL )
    {
     // atribuir valor
        strcpy ( s1, "AbCdE" );
     // mostrar  valor
        printf ( "\ns1 = %s (%d)", s1, strlen(s1) );
        printf ( "\n" );
    } // end if

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_16 ( )

/**
  * Metodo_17.
  */
void metodo_17 ( void )
{
 // definir dados e resultados
    char s1 [80] = "";
    int  x      =  0 ;
    int  y      =  0 ;
    char c      = '0';

 // identificar
    printf ( "\n%s\n", "Metodo_17" );
 // atribuir valor
    strcpy ( s1, "AbCdE" ); // s = "AbCdE";
 // mostrar valor
    printf ( "\ns1 = %s (%d)", s1, strlen(s1) );
    printf ( "\n" );
 // repetir para cada simbolo
    for ( x=0; x<=strlen(s1); x=x+1 )
    {
     // separar um simbolo em certa posicao
        c = s1 [x];
     // testar simbolo
    	if ( 'A' <= c && c <= 'Z' )
    	{
    	 // mostrar simbolo
            printf ( "\n%d %c %d", x, c, c );
    	 // contar mais um letra maiuscula
            y = y + 1;
    	} // end if
    } // end for
 // mostrar o total de maiusculas
    printf ( "\nmaiusculas = %d\n", y );

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_17 ( )

/**
  * Metodo_18.
  */
void metodo_18 ( void )
{
 // definir dados e resultados
    char s1 [80] = "";
    int  x      =  0 ;
    char c      = '0';
    int  y      =  0 ;

 // identificar
    printf ( "\n%s\n", "Metodo_18" );
 // atribuir valor inicial
    strcpy ( s1, "AbCdE" ); // s = "AbCdE";
 // mostrar  valor
    printf ( "\ns1 = %s (%d)", s1, strlen(s1) );
    printf ( "\n" );
 // repetir para cada simbolo
    for ( x=0; x<=strlen(s1); x=x+1 )
    {
     // separar um simbolo em certa posicao
        c = s1 [x];
     // testar simbolo
    	if ( 'a' <= c && c <= 'z' )
    	{
    	 // mostrar simbolo
            printf ( "\n%d %c %d", x, c, c );
    	 // contar mais uma minuscula
            y = y + 1;
    	} // end if
    } // end for
 // mostrar o total de minusculas
    printf ( "\nminusculas = %d\n", y );

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_18 ( )

/**
  * Metodo_19.
  */
void metodo_19 ( void )
{
 // definir dados e resultados
    char s1 [80] = "";
    int  x      =  0 ;
    char c      = '0';
    int  y      =  0 ;
    int  tamanho =  0 ;

 // identificar
    printf ( "\n%s\n", "Metodo_19" );
 // atribuir valor inicial
    strcpy ( s1, "AbCdE" ); // s = "AbCdE";
 // mostrar  valor
    printf ( "\ns1 = %s (%d)", s1, strlen(s1) );
    printf ( "\n" );
 // guardar o tamanho
    tamanho = strlen(s1);
 // repetir para cada simbolo
    x = 0;
    while ( x < tamanho )
    {
     // separar um simbolo em certa posicao
        c = s1 [x];
     // testar simbolo
    	if ( ('A' <= c && c <= 'Z') ||
             ('a' <= c && c <= 'z') )
    	{
    	 // mostrar valor
            printf ( "\n%d %c %d", x, c, c );
	 // contar mais uma letra
            y = y + 1;
    	} // end if
    	x = x + 1;
    } // end for
 // mostrar o total de letras
    printf ( "\nletras = %d\n", y );

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_19 ( )

/**
  * Metodo_20.
  */
void metodo_20 ( void )
{
 // definir dados e resultados
    char s1 [80] =  "";
    int  x       =  0 ;
    char c       = '0';
    int  y       =  0 ;
    int  tamanho =  0 ;
    bool letra   = false;

 // identificar
    printf ( "\n%s\n", "Metodo_20" );
 // atribuir valor inicial
    strcpy ( s1, "4b(d&" ); // s = "AbCdE";
 // mostrar  valor
    printf ( "\ns1 = %s (%d)", s1, strlen(s1) );
    printf ( "\n" );
 // guardar o tamanho
    tamanho = strlen(s1);
 // repetir para cada simbolo
    x = 0;
    while ( x < tamanho )
    {
     // printf ( "\n%d %c %d", x, s1[x], s1[x] );
     // separar um simbolo em certa posicao
        c = s1 [x];
     // testar simbolo
        letra = ('A' <= c && c <= 'Z') ||
                ('a' <= c && c <= 'z') ;
    	if ( letra  )
    	{
    	 // mostrar simbolo
            printf ( "\n%d %c %d", x, c, c );
    	 // contar mais uma letra
            y = y + 1;
    	} // end if
    	x = x + 1;
    } // end while
 // mostrar o total de letras
    printf ( "\nletras = %d\n", y );

 // encerrar
    printf ( "\n%s\n", "Apertar ENTER para continuar." );
    getchar( );
} // fim metodo_20 ( )

// -------------------------- definicao do metodo_ principal

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
        printf ( "%s\n", " 1 - metodo_ 01   2 - metodo_ 02" );
        printf ( "%s\n", " 3 - metodo_ 03   4 - metodo_ 04" );
        printf ( "%s\n", " 5 - metodo_ 05   6 - metodo_ 06" );
        printf ( "%s\n", " 7 - metodo_ 07   8 - metodo_ 08" );
        printf ( "%s\n", " 9 - metodo_ 09  10 - metodo_ 10" );
        printf ( "%s\n", "11 - metodo_ 11  12 - metodo_ 12" );
        printf ( "%s\n", "13 - metodo_ 13  14 - metodo_ 14" );
        printf ( "%s\n", "15 - metodo_ 15  16 - metodo_ 16" );
        printf ( "%s\n", "17 - metodo_ 17  18 - metodo_ 18" );
        printf ( "%s\n", "19 - metodo_ 19  20 - metodo_ 20" );
        printf ( "%s\n", "" );        // para saltar linha

     // ler opcao
        printf ( "%s", "Qual a sua opcao? " );
        scanf  ( "%d", &opcao ); getchar ( );
        printf ( "%d",  opcao );

     // escolher acao
        switch ( opcao )
        {
           case  0:                break;
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
           case 11: metodo_11 ( ); break;
           case 12: metodo_12 ( ); break;
           case 13: metodo_13 ( ); break;
           case 14: metodo_14 ( ); break;
           case 15: metodo_15 ( ); break;
           case 16: metodo_16 ( ); break;
           case 17: metodo_17 ( ); break;
           case 18: metodo_18 ( ); break;
           case 19: metodo_19 ( ); break;
           case 20: metodo_20 ( ); break;
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
