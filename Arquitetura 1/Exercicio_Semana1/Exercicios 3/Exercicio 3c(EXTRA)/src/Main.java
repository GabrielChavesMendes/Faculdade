import java.util.Locale;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        int x = 0;

        do{
            System.out.print("Digite um número decimal: ");
            int decimal = sc.nextInt();

            String binario = Integer.toString(decimal, 2);
            String base4 = Integer.toString(decimal, 4);
            String octal = Integer.toString(decimal, 8);
            String hexadecimal = Integer.toString(decimal, 16).toUpperCase();

            System.out.println("O número " + decimal + " em binário é " + binario);
            System.out.println("O número " + decimal + " em base 4 é " + base4);
            System.out.println("O número " + decimal + " em octal é " + octal);
            System.out.println("O número " + decimal + " em hexadecimal é " + hexadecimal);

            System.out.println();
            x++;
        }while(x < 5);

        sc.close();
    }
}

/*
Digite um número decimal: 61
O número 61 em binário é 111101
O número 61 em base 4 é 331
O número 61 em octal é 75
O número 61 em hexadecimal é 3D

Digite um número decimal: 53
O número 53 em binário é 110101
O número 53 em base 4 é 311
O número 53 em octal é 65
O número 53 em hexadecimal é 35

Digite um número decimal: 77
O número 77 em binário é 1001101
O número 77 em base 4 é 1031
O número 77 em octal é 115
O número 77 em hexadecimal é 4D

Digite um número decimal: 153
O número 153 em binário é 10011001
O número 153 em base 4 é 2121
O número 153 em octal é 231
O número 153 em hexadecimal é 99

Digite um número decimal: 753
O número 753 em binário é 1011110001
O número 753 em base 4 é 23301
O número 753 em octal é 1361
O número 753 em hexadecimal é 2F1
 */