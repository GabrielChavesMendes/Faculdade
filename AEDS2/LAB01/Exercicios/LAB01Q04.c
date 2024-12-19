#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int Quantidade_Maiusculo(char *frase, int index){

    int tam = strlen(frase);
    int cont = 0;

    /*
    funcao recrusivs

    analisa letra por letra da frase por meio da variavel index que percorre a string
    sempre que a funcao chama a si propria e acrescenta +1 no index, acresentando em +1
    a variavel cont sempre que encontrar uma letra dentro do intervalo entre as letras A e Z
    */

    if(index >= tam){
        return 0;
    }else if(frase[index] >= 'A' && frase[index] <= 'Z'){
        cont++;
        return cont + Quantidade_Maiusculo(frase, index + 1);
    }else{
        return Quantidade_Maiusculo(frase, index + 1);
    }
}

int main(void){

    char frase[70];
    bool verdade = false;
    int index = 0;

    while(!verdade){

        fgets(frase, 70, stdin);

        if(frase[0] == 'F' && frase[1] == 'I' && frase[2] == 'M'){
            verdade = true;
        }else{
            int quantidade = Quantidade_Maiusculo(frase, index);

            printf("%d\n", quantidade);
        }

    }

    return 0;
}
