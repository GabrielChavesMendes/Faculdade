import java.util.Locale;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Locale.setDefault(Locale.US);

        Scanner sc = new Scanner(System.in);

        int num, x = 0;
        double div = 2;

        do{
            System.out.println("Digite um numero: ");
            num = sc.nextInt();

            String binario = dec2bin(num);

            System.out.println("O número " + num + " em binário é " + binario);

            x++;
        }while(x < 5);

        sc.close();
    }

    public static String dec2bin(int num) {

        if (num == 0) {
            return "0";
        }

        StringBuilder binario = new StringBuilder();

        while (num > 0) {
            int resto = num % 2;
            binario.insert(0, resto);
            num = num / 2;
        }
        return binario.toString();
    }
}

        /*
        Resposta:
        Digite um numero:
        26
        O número 26 em binário é 11010
        Digite um numero:
        53
        O número 53 em binário é 110101
        Digite um numero:
        713
        O número 713 em binário é 1011001001
        Digite um numero:
        213
        O número 213 em binário é 11010101
        Digite um numero:
        365
        O número 365 em binário é 101101101
         */