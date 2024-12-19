/*
 Exemplo0002 - v0.0. - _21_ / _02_ / _2024_
 Author: _Gabriel_Chaves_Mendes__

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0002 exemplo0002.c
 Windows: gcc -o exemplo0002 exemplo0002.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0002
 Windows: exemplo0002
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral

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
 printf ( "%s\n", "Exemplo0002 - Programa = v0.0" );
 printf ( "%s\n", "Autor: Gabriel_Chaves_Mendes" );
 printf ( "\n" ); // mudar de linha
// acoes
// ler a opcao do teclado
 printf ( "\n%s", "Opcao = " );
 scanf ( "%d", &opcao );
 getchar( ); // para limpar a entrada de dados
// para mostrar a opcao lida
 printf ( "\n%s%d", "Opcao = ", opcao );
// encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )

/*
-Entrada e saída de dados com o uso do scanf-- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5
b.) -5
c.) 123456789
---------------------------------------------- historico
Versao Data Modificacao
 0.1 _21_/_02_/ esboco
 0.2 _21_/_02_/ mudanca de versao
 0.3 _21_/_02_/ adicição de um scanf
---------------------------------------------- testes
Versao Teste
0.0 01. ( OK ) identificacao de programa
0.1 01. ( OK ) identificacao de programa
0.2 01. ( OK ) identificacao de programa
leitura e exibicao de inteiro
*/
