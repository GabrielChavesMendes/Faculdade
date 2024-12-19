#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {

  char frase[300];
  bool verdade = false;
  int cont = 0;

  while (!verdade){ // Enquanto for diferente de true continua o loop

    fgets(frase, 300, stdin);
    frase[strcspn(frase, "\n")] = 0; //Encontra o caracter de nova linha

    int tam = strlen(frase);
    char frase_inversa[tam + 1];
    cont = 0;

     // Inverte a frase
    for (int i = 0; i < tam; i++){
      frase_inversa[i] = frase[tam - i - 1];
    }
      
    frase_inversa[tam] = '\0'; // Adiciona o caractere nulo ao final

    if (frase[0] == 'F' && frase[1] == 'I' && frase[2] == 'M'){ // Indice de parada
      verdade = true;
    }else{
      for(int i = 0; i < tam; i++){
        if(frase[i] == frase_inversa[i]){
          cont++;
        }
      }

      if(cont == tam){
        printf("SIM\n");
      }else{
        printf("NAO\n");
      }
    }
    cont = 0;
  }
  
 return 0;
}
