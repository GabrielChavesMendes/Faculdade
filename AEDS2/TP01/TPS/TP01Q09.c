#include <stdio.h>

int main(void){

    int x;

    scanf("%d", &x);

    FILE *arquivo = fopen("Q_09.bin", "wb");

    for(int i = 0; i < x; i++){
        double valores;

        scanf("%lf", &valores);
        fwrite(&valores, sizeof(double), 1, arquivo);
    }

    fclose(arquivo);

    arquivo = fopen("Q_09.bin", "rb");

    //pega o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);

    long quantidade;
    double numero;

    //descobre quantos doubles tem no arquivo
    quantidade = tamanho / sizeof(double);

    //percorre o arquivo de tras para frente e lendo os numeros
    for (long i = quantidade - 1; i >= 0; i--){
        long posicao = i * sizeof(double);
        fseek(arquivo, posicao, SEEK_SET);

        fread(&numero, sizeof(double), 1, arquivo);

        //verifica se o numero e somente parte inteiro
        if (numero == (long)numero){
            printf("%.0f\n", numero); //imprime sem a parte decimal se for inteiro
        } else{
            printf("%g\n", numero);
        }
    }

    fclose(arquivo);

    return 0;
}
