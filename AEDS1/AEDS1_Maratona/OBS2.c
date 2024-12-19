#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;

    // Leitura do número de casas (N) e encomendas (M)
    scanf("%d %d", &N, &M);

    // Alocação dinâmica de memória para armazenar os números das casas e encomendas
    int *casas = (int *)malloc(N * sizeof(int));
    int *encomendas = (int *)malloc(M * sizeof(int));

    // Leitura dos números das casas
    for (int i = 0; i < N; i++) {
        scanf("%d", &casas[i]);
    }

    // Leitura dos números das encomendas
    for (int j = 0; j < M; j++) {
        scanf("%d", &encomendas[j]);
    }

    // Calcular o tempo total
    int tempoTotal = 0;
    for (int i = 0; i < N; i++) { //Loop para pegar a primeira CASA (N) e COMPARAR com as ENCOMENDAS (M)
            for(int j = 0; j < M; j++){
                if(casas[i] == encomendas[j]){ //Se casas[i] for igual a encomenda[j], irá somar a variável tempoTotal com a posição j
                    tempoTotal = tempoTotal + (j);
                }
            }
    }

    // Imprime o tempo total
    printf("%d\n", tempoTotal);

    // Libera a memória alocada dinamicamente
    free(casas);
    free(encomendas);

    return 0;
}
