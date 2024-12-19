#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;

    // Leitura do n�mero de casas (N) e encomendas (M)
    scanf("%d %d", &N, &M);

    // Aloca��o din�mica de mem�ria para armazenar os n�meros das casas e encomendas
    int *casas = (int *)malloc(N * sizeof(int));
    int *encomendas = (int *)malloc(M * sizeof(int));

    // Leitura dos n�meros das casas
    for (int i = 0; i < N; i++) {
        scanf("%d", &casas[i]);
    }

    // Leitura dos n�meros das encomendas
    for (int j = 0; j < M; j++) {
        scanf("%d", &encomendas[j]);
    }

    // Calcular o tempo total
    int tempoTotal = 0;
    for (int i = 0; i < N; i++) { //Loop para pegar a primeira CASA (N) e COMPARAR com as ENCOMENDAS (M)
            for(int j = 0; j < M; j++){
                if(casas[i] == encomendas[j]){ //Se casas[i] for igual a encomenda[j], ir� somar a vari�vel tempoTotal com a posi��o j
                    tempoTotal = tempoTotal + (j);
                }
            }
    }

    // Imprime o tempo total
    printf("%d\n", tempoTotal);

    // Libera a mem�ria alocada dinamicamente
    free(casas);
    free(encomendas);

    return 0;
}
