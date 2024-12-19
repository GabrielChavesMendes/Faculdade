import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x = 0;

        do{
            System.out.println("Digite o número binário: ");
            String binary = sc.nextLine();

            int decimal = binaryToDecimal(binary);
            System.out.println("Decimal: " + decimal);

            System.out.println("Base 4: " + decimalToBase(decimal, 4));
            System.out.println("Base 8: " + decimalToBase(decimal, 8));
            System.out.println("Base 16: " + decimalToBase(decimal, 16).toUpperCase());

            System.out.println();

            x++;
        }while(x < 5);

        sc.close();
    }

    public static int binaryToDecimal(String binary) {
        return binaryToDecimal(binary, binary.length() - 1);
    }

    private static int binaryToDecimal(String binary, int index) {
        if (index < 0) {
            return 0;
        }
        int bit = binary.charAt(index) - '0';
        return (int) (bit * Math.pow(2, binary.length() - 1 - index)) + binaryToDecimal(binary, index - 1);
    }

    public static String decimalToBase(int decimal, int base) {
        if (decimal == 0) {
            return "0";
        }
        return decimalToBase(decimal, base, "");
    }

    private static String decimalToBase(int decimal, int base, String result) {
        if (decimal == 0) {
            return result.isEmpty() ? "0" : result;
        }
        int remainder = decimal % base;
        char digit = (remainder < 10) ? (char) ('0' + remainder) : (char) ('A' + remainder - 10);
        return decimalToBase(decimal / base, base, digit + result);
    }
}

/*
Digite o número binário:
10100
Decimal: 20
Base 4: 110
Base 8: 24
Base 16: 14

Digite o número binário:
11010
Decimal: 26
Base 4: 122
Base 8: 32
Base 16: 1A

Digite o número binário:
100111
Decimal: 39
Base 4: 213
Base 8: 47
Base 16: 27

Digite o número binário:
100101
Decimal: 37
Base 4: 211
Base 8: 45
Base 16: 25

Digite o número binário:
101101
Decimal: 45
Base 4: 231
Base 8: 55
Base 16: 2D
 */