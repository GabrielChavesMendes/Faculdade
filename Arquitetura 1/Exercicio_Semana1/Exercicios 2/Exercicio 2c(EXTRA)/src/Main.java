import java.util.Locale;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        int x = 0;

        do{
            System.out.println("Digite um número binário: ");
            String binario = sc.nextLine();

            int decimal = bin2dec(binario);

            System.out.println("O número " + binario + " em decimal é " + decimal);
            x++;
        }while(x < 5);

        sc.close();
    }

    public static int bin2dec(String binario) {
        int decimal = 0;
        int comprimento = binario.length();

        for (int i = 0; i < comprimento; i++) {
            char digito = binario.charAt(comprimento - 1 - i);

            if (digito == '1') {
                decimal += Math.pow(2, i);
            }
        }

        return decimal;
    }
}

/*
Resposta:
Digite um número binário:
10101
O número 10101 em decimal é 21
Digite um número binário:
11011
O número 11011 em decimal é 27
Digite um número binário:
10010
O número 10010 em decimal é 18
Digite um número binário:
101011
O número 101011 em decimal é 43
Digite um número binário:
110111
O número 110111 em decimal é 55
 */
