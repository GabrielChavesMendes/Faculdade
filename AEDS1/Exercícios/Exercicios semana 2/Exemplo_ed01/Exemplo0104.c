/*
 Exemplo0100 - v1.3. - _01_ / _03_ / _2024_
 Author: ___Gabriel_Chaves_Mendes___

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0100 exemplo0100.c
 Windows: gcc -o exemplo0100 exemplo0100.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0100
 Windows: exemplo0100

 Saída:
        Exemplo0104 - Programa = v1.3
        Autor:  ___Gabriel_Chaves_Mendes___
        Opcoes:
        0 - Terminar
        1 - Method_01
        2 - Method_02
        3 - Method_03
        4 - Method_04
        Opcao = 4
        Opcao = 4
        EXEMPLO0104 - Programa - v1.3
        x = 0
        Entrar com um valor logico: 5
        x = 1
        Apertar ENTER para continuar.
        Opcoes:
        0 - Terminar
        1 - Method_01
        2 - Method_02
        3 - Method_03
        4 - Method_04
        Opcao = 4
        Opcao = 4
        EXEMPLO0104 - Programa - v1.3
        x = 0
        Entrar com um valor logico: 0
        x = 0
        Apertar ENTER para continuar.
        Opcoes:
        0 - Terminar
        1 - Method_01
        2 - Method_02
        3 - Method_03
        4 - Method_04
        Opcao = 0
        Opcao = 0
        Apertar ENTER para terminar.
*/

// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral
#include <stdbool.h> // para valores logicos
/*
 Method_01.
*/
void method_01 ( void )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 printf ( "\n%s\n", "Method_01 - Programa = v1.3" );
// mostrar valor inicial
 printf ( "\n%s%d\n", "x = ", x );
// OBS.: O formato para int -> %d (ou %i)
 printf ( "&%s%p\n" , "x = ", &x );
// OBS.: O formato para endereco -> %p)
// ler do teclado
 printf ( "Entrar com um valor inteiro: " );
 scanf ( "%d", &x );
// OBS.: Necessario indicar o endereco -> &
 getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
 printf ( "%s%i\n", "x = ", x );
// encerrar
 printf ( "\n\nApertar ENTER para continuar." );
 getchar( ); // aguardar por ENTER
} // end method_01 ( )


/**
 Method_02.
*/
void method_02 ( void )
{
// definir dado
 double x = 0.0; // definir variavel com valor inicial
// OBS.: Definir a parte fracionaria e' util
// identificar
 printf ( "\n%s\n", "Method_02 - Programa - v1.3" );
// mostrar valor inicial
 printf ( "\n%s%lf\n", "x = ", x );
// OBS.: O formato para double -> %lf
// ler do teclado
 printf ( "Entrar com um valor real: " );
 scanf ( "%lf", &x );
// OBS.: Necessario indicar o endereco -> &
 getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
 printf ( "%s%lf\n", "x = ", x );
// encerrar
 printf ( "\n\nApertar ENTER para continuar.\n" );
 getchar( ); // aguardar por ENTER
} // end method_02 ( )

/**
 Method_03.
*/
void method_03 ( void )
{
// definir dado
 char x = 'A'; // definir variavel com valor inicial
// OBS.: Indispensavel usar apostrofos
// identificar
 printf ( "\n%s\n", "Method_03 - Programa - v1.3" );
// mostrar valor inicial
 printf ( "\n%s%c\n", "x = ", x );
// OBS.: O formato para char -> %c
// ler do teclado
 printf ( "Entrar com um caractere: " );
 scanf ( "%c", &x );
// OBS.: Necessario indicar o endereco -> &
 getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
 printf ( "%s%c\n", "x = ", x );
// encerrar
 printf ( "\n\nApertar ENTER para continuar.\n" );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // end main( )

/**
 Method_04.
*/
void method_04 ( void )
{
// definir dado
 bool x = false; // definir variavel com valor inicial
// OBS.: Indispensavel usar minusculas
 int y = 0; // definir variavel auxiliar
// identificar
 printf ( "\n%s\n", "EXEMPLO0104 - Programa - v1.3" );
// mostrar valor inicial
 printf ( "\n%s%d\n", "x = ", x );
// OBS.: O formato para equivalente inteiro -> %d
// ler do teclado
 printf ( "Entrar com um valor logico: " );
 scanf ( "%d", &y );
// OBS.: Usar equivalente inteiro -> 0 = false
 getchar ( ); // OBS.: Limpar a entrada de dados
// garantir valor logico no intervalo [0:1]
 x = (y!=0);
// mostrar valor lido
 printf ( "%s%d\n", "x = ", x );
// encerrar
 printf ( "\n\nApertar ENTER para continuar.\n" );
 getchar( ); // aguardar por ENTER
} // end method_04 ( )


/*
 Funcao principal
*/
int main ( int argc, char* argv [ ] )
{
 int opcao = 0;
// identificar
 printf ( "%s\n", "Exemplo0104 - Programa = v1.3" );
 printf ( "%s\n", "Autor:  ___Gabriel_Chaves_Mendes___" );
 printf ( "\n" ); // mudar de linha
// acoes
// repetir
 do
 {
 // para mostrar opcoes
 printf ( "\n%s\n", "Opcoes:" );
 printf ( "\n%s" , "0 - Terminar" );
 printf ( "\n%s" , "1 - Method_01" );
 printf ( "\n%s" , "2 - Method_02" );
 printf ( "\n%s" , "3 - Method_03" );
 printf ( "\n%s" , "4 - Method_04" );
 printf ( "\n" );
 // ler a opcao do teclado
 printf ( "\n%s", "Opcao = " );
 scanf ( "%d", &opcao );
 getchar( ); // para limpar a entrada de dados
 // para mostrar a opcao lida
 printf ( "\n%s%d", "Opcao = ", opcao );
 // escolher acao dependente da opcao
 switch ( opcao )
 {
 case 0: // nao fazer nada
 break;
 case 1: // executar method_01
 method_01 ( );
 break;
 case 2: // executar method_02
 method_02 ( );
 break;
 case 3: // executar method_03
 method_03 ( );
 break;
 case 4: // executar method_04
 method_04 ( );
 break;
 default: // comportamento padrao
 printf ( "\nERRO: Opcao invalida.\n" );
 break;
 } // end switch
 }
 while ( opcao != 0 );
// encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )


/*
-Acrescentado o method_04 e da biblioteca stdboo.h- documentacao complementar
-Entrada e saida de um valor booleano(verdadeiro ou falso(0 ou 1)) pelo method_04- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5
b.) -5
c.) 123456789
---------------------------------------------- historico
Versao Data Modificacao
 0.0 _01_/_03_ esboco
 0.1 _01_/_03_ esboco
 0.2 _01_/_03_ mudanca de versao
 0.3 _01_/_03_ mudanca de versao
 0.4 _01_/_03_ mudanca de versao
---------------------------------------------- testes
Versao Teste
0.0 00. ( _OK_ ) identificacao de programa
0.1 01. ( _OK_ ) identificacao de programa
leitura e exibicao de inteiro
0.2 02. ( _OK_ ) identificacao de programa
leitura e exibicao de real
0.3 03. ( _OK_ ) identificacao de programa
leitura e exibicao de caractere
0.4 04. ( _OK_ ) identificacao de programa
leitura e exibicao de valor bool
*/
