#include <stdio.h>

int main(void){
    int num = 3;

    for (int c = 0; c < num; c++){

        int N;

        scanf("%d", &N);

        int inicio[N], fim[N], posicao[N];

        for (int i = 0; i < N; i++){
            scanf("%d", &inicio[i]);
        }

        for (int i = 0; i < N; i++){
            scanf("%d", &fim[i]);
        }

        for (int i = 0; i < N; i++){
            posicao[i] = -1;
            for (int j = 0; j < N; j++){
                if (inicio[i] == fim[j]){
                    posicao[i] = j;
                }
            }
        }

        int cont = 0;
        for (int i = 0; i < N; i++){
            for (int j = i + 1; j < N; j++){
                if (posicao[i] > posicao[j]){
                    cont++;
                }
            }
        }

        printf("%d\n", cont);
    }

    return 0;
}
