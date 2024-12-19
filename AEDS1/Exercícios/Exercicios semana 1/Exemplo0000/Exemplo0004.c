/*
 Exemplo0004 - v0.0. - _21_ / _02_ / _2024_
 Author: _Gabriel_Chaves_Mendes__

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0004 exemplo0004.c
 Windows: gcc -o exemplo0004 exemplo0004.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0004
 Windows: exemplo0004
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral

/**
 Metodo 01.
*/
void method_01 ( void )
{
 // identificar
 printf ( "%s\n", " Metodo 01" );
 // encerrar
 printf ( "\nApertar ENTER para continuar.\n" );
 getchar ( );
} // end method_01 ( )

/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dados / resultados
 int opcao = 0;
// identificar
 printf ( "%s\n", "Exemplo0004 - Programa = v0.0" );
 printf ( "%s\n", "Autor: Gabriel_Chaves_Mendes" );
 printf ( "\n" ); // mudar de linha
// acoes
// para mostrar opcoes
 printf ( "\n%s\n", "Opcoes:" );
 printf ( "\n%s" , "0 - Terminar" );
 printf ( "\n%s" , "1 - Metodo 01" );
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
 case 1: // executar metodo 01
 method_01 ( );
 break;
 default: // comportamento padrao
 printf ( "\nERRO: Opcao invalida.\n" );
 break;
 } // end switch
// encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )

/*
-No exemplo 2: Entrada e saída de dados com o uso do scanf- documentacao complementar
-No exemplo 3: Implementação do Switch-Case- notas / observacoes / comentarios
-No exemplo 4: Foi implementado um procedimento sem retorno referenciado ao case 1- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5
b.) -5
c.) 123456789
---------------------------------------------- historico
Versao Data Modificacao
 0.1 _21_/_02_/ esboco
 0.2 _21_/_02_/ mudanca de versao
 0.3 _21_/_02_/ adicição de um scanf
 0.4 _21_/_02_/ adicao de um switch case
 0.5 _21_/_02_/ adicao de um procedimento
---------------------------------------------- testes
Versao Teste
0.0 01. ( OK ) identificacao de programa
0.1 01. ( OK ) identificacao de programa
0.2 01. ( OK ) identificacao de programa
leitura e exibicao de inteiro
0.3 03. ( OK ) identificacao de programa
leitura e exibicao mediante escolha
0.4 04. ( OK ) identificacao de programa
leitura e exibicao mediante escolha
*/
