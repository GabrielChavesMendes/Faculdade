#include <stdio.h>

int main() {
    // Leitura da entrada
    int N;
    scanf("%d", &N);

    int dados[N][6];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            scanf("%d", &dados[i][j]);
        }
    }

    // Inicialização das variáveis para armazenar a soma máxima
    int somaMax = 0;

    // Loop para cada dado
    for (int i = 0; i < N; i++) {
        // Considerando que a soma dos opostos é 7
        int somaLado = 7;

        // Loop para cada lado do dado
        for (int j = 0; j < 6; j++) {
            // Encontrando o valor máximo do par oposto
            int oposto = dados[i][j];
            if (dados[i][(j + 3) % 6] > oposto) {
                oposto = dados[i][(j + 3) % 6];
            }

            // Atualizando a somaLado
            somaLado += oposto;
        }

        // Atualizando a soma máxima se necessário
        if (somaLado > somaMax) {
            somaMax = somaLado;
        }
    }

    // Impressão do resultado
    printf("%d\n", somaMax);

    return 0;
}
