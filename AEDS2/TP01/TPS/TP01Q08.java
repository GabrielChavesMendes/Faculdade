import java.io.RandomAccessFile;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class TP01Q08 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        sc.useLocale(Locale.US);

        int x = sc.nextInt();

        try {
            //arquivo aberto em binario para nao ocorrer conversao para texto, arquivo para escreita "rw"
            RandomAccessFile file = new RandomAccessFile("Q_08.bin", "rw");

            for (int i = 0; i < x; i++) {
                double numeros = sc.nextDouble();

                file.writeDouble(numeros);
            }
            file.close(); //fecha arquivo
        } catch (IOException e) {
            System.out.println("Erro ao escrever no arquivo");
        }

        try {
            //abrindo arquivo para somente leitura, "r", em binario
            RandomAccessFile Q_08 = new RandomAccessFile("Q_08.bin", "r");


            long tam = Q_08.length(); //obtem o tamnho do arquivo
            //pega a quantidade total de doubles no arquivo, pegando o tamanho dele e dividindo por 8bytes
            long quantidade = tam / 8;

            for (long i = quantidade - 1; i >= 0; i--) {
                long posicao = i * 8; //pega a posicao da leitura calculando o indice i pelo tamanho do double em bytes

                Q_08.seek(posicao); //move o ponteiro para posicao obtida

                double numero = Q_08.readDouble();

                //verifica se o numero esta apenas com a parte inteira, ao comparar o double recebido com um long
                if (numero == (long) numero){
                    System.out.println(String.format(Locale.US, "%.0f", numero)); //nao imprimi a parte decimal ".0"
                } else {
                    System.out.println(numero);
                }
            }

            Q_08.close();
        } catch (IOException e) {
            System.out.println("Erro ao ler do arquivo");
        }
    }
}
