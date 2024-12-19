/*
 Exemplo0000 - v0.0. - _21_ / _02_ / _2024_
 Author: _Gabriel_Chaves_Mendes__

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0000 exemplo0000.c
 Windows: gcc -o exemplo0000 exemplo0000.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0000
 Windows: exemplo0000
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dados / resultados
// identificar
 printf ( "%s\n", "Exemplo0000 - Programa = v0.0" );
 printf ( "%s\n", "Autor: Gabriel_Chaves_Mendes" );
 printf ( "\n" ); // mudar de linha
// acoes
// encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5
b.) -5
c.) 123456789
---------------------------------------------- historico
Versao Data Modificacao
 0.1 _21_/_02_ esboco
---------------------------------------------- testes
Versao Teste
0.0 01. ( OK ) identificacao de programa
leitura e exibicao de inteiro
*/
