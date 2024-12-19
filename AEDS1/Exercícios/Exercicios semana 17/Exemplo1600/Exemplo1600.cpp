/*
 Exemplo1500 - v1.8. - _20_ / _06_ / _2024_
 Author: ___Gabriel_Chaves_Mendes___

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo1600 exemplo1600.c
 Windows: gcc -o exemplo1600 exemplo1600.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo1600
 Windows: exemplo1600

    * Exemplo1600_v0.0
        EXEMPLO1600 - Programa - v0.0

        Opcoes
         0 - parar
         1 - testar definicoes

        Entrar com uma opcao: 1

        Method_01 - v0.0

        Apertar ENTER para continuar
*/

/*
 Exemplo1600 - v0.0. - __ / __ / _____
 Author: _____________________________
*/
// ----------------------------------------------- preparacao

// dependências

#include <iostream>

// ----------------------------------------------- definicoes globais

using namespace std;

// ----------------------------------------------- metodos
/**


 Method_00 - nao faz nada.
*/
void method_00 ( )
{
// nao faz nada
} // end method_00 ( )
/**
 Method_01 - Testar definicoes da classe.
*/


void method_01 ( )
{
// definir dados
// identificar
 cout << "\nMethod_01 - v0.0\n" << endl;
// encerrar
 cout << "Apertar ENTER para continuar" << endl;
 cin.ignore(); // espera o usuário pressionar Enter
 cin.get();    // espera o usuário pressionar Enter novamente, se necessário
} // end method_01 ( )


// ----------------------------------------------- acao principal


/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( int argc, char** argv )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
 do
 {
 // identificar
 cout << "EXEMPLO1600 - Programa - v0.0\n " << endl;
 // mostrar opcoes
 cout << "Opcoes " << endl;
 cout << " 0 - parar " << endl;
 cout << " 1 - testar definicoes " << endl;
 // ler do teclado
 cout << endl << "Entrar com uma opcao: ";
 cin >> x;
 // escolher acao
 switch ( x )
 {
 case 0:
 method_00 ( );
 break;
 case 1:
 method_01 ( );
 break;
 default:
 cout << endl << "ERRO: Valor invalido." << endl;
 } // end switch
 }
 while ( x != 0 );
// encerrar
 cout << "Apertar ENTER para continuar" << endl;
 cin.ignore(); // espera o usuário pressionar Enter
 cin.get();    // espera o usuário pressionar Enter novamente, se necessário
 return ( 0 );
} // end main ( )

/*
----------------------------------------------
----------------------------------------------
//ANOTACOES/ NOTAS/ OBSERVACOES:
- v0.0 Testar as definicoes dos metodos-
----------------------------------------------
----------------------------------------------

----------------------------------------------
----------------------------------------------
Versao Data Modificacao
0.0 _20_/_06_ esboco e adicao do method_01

----------------------------------------------
----------------------------------------------

---------------------------------------------- testes

----------------------------------------------
----------------------------------------------
Versao Teste
0.0 00. ( _OK_ ) identificacao de programa
----------------------------------------------
*/

