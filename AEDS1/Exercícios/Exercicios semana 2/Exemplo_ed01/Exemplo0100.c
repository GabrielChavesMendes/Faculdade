/*
 Exemplo0100 - v0.0. - _01_ / _03_ / _2024_
 Author: ___Gabriel_Chaves_Mendes___

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0100 exemplo0100.c
 Windows: gcc -o exemplo0100 exemplo0100.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0100
 Windows: exemplo0100

 Saída:
        Exemplo0100 - Programa = v0.0
        Autor: ___Gabriel_Chaves_Mendes___
        Opcoes:
        0 - Terminar
        1 - Method_01
        Opcao = 1
        Opcao = 1Method_01
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
/**
 Method_01.
*/
void method_01 ( void )
{
 // identificar
 printf ( "%s\n", "Method_01" );
 // encerrar
 printf ( "\nApertar ENTER para continuar.\n" );
 getchar ( );
} // end method_01 ( )
/*
 Funcao principal
*/
int main ( int argc, char* argv [ ] )
{
 int opcao = 0;
// identificar
 printf ( "%s\n", "Exemplo0100 - Programa = v0.0" );
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
------Foi encontrado 2 erros no codigo-------- documentacao complementar
------1) Falta do ; ao declarar a variavel---- notas / observacoes / comentarios
--2) linha 61 tinha um . antes do comentario-- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.0 _01_/_03_ esboco
---------------------------------------------- testes
Versao Teste
0.0 00. ( _OK_ ) identificacao de programa
*/
