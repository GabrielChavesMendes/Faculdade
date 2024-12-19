/*
 Exemplo0100 - v1.0. - _01_ / _03_ / _2024_
 Author: ___Gabriel_Chaves_Mendes___

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0100 exemplo0100.c
 Windows: gcc -o exemplo0100 exemplo0100.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0100
 Windows: exemplo0100

 Saída:
        Exemplo0101 - Programa = v1.0
        Autor: ___Gabriel_Chaves_Mendes___
        Opcoes:
        0 - Terminar
        1 - Method_01
        Opcao = 1
        Opcao = 1
        Method_01 - Programa = v1.0
        x = 0
        &x = 000000000061FDDC
        Entrar com um valor inteiro: 5
        x = 5
        Apertar ENTER para continuar.
        Opcoes:
        0 - Terminar
        1 - Method_01
        Opcao = 0
        Opcao = 0
        Apertar ENTER para terminar.
*/

// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral
/*
 Method_01.
*/
void method_01 ( void )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 printf ( "\n%s\n", "Method_01 - Programa = v1.0" );
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

/*
 Funcao principal
*/
int main ( int argc, char* argv [ ] )
{
 int opcao = 0;
// identificar
 printf ( "%s\n", "Exemplo0101 - Programa = v1.0" );
 printf ( "%s\n", "Autor: ___Gabriel_Chaves_Mendes___" );
 printf ( "\n" ); // mudar de linha
// acoes
// repetir
 do
 {
 // para mostrar opcoes
 printf ( "\n%s\n", "Opcoes:" );
 printf ( "\n%s" , "0 - Terminar" );
 printf ( "\n%s" , "1 - Method_01" );
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
-Mudanca no method_01, com saida e entrada de dados- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5
b.) -5
c.) 123456789
---------------------------------------------- historico
Versao Data Modificacao
 0.1 _01_/_03_ esboco
---------------------------------------------- testes
Versao Teste
0.0 00. ( _OK_ ) identificacao de programa
0.1 01. ( _OK_ ) identificacao de programa
leitura e exibicao de inteiro
*/
