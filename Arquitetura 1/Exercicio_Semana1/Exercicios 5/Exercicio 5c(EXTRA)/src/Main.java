import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x = 0;

        do{
            System.out.println("Escolha a operação:");
            System.out.println("1: Texto para Hexadecimal ASCII");
            System.out.println("2: Texto para Binário ASCII");
            System.out.println("3: Octal para ASCII");
            System.out.println("4: Hexadecimal para ASCII");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.println("Digite o texto: ");
                    String textHex = sc.nextLine();
                    String hex = asciiToHex(textHex);
                    System.out.println("Hexadecimal ASCII: " + hex);
                    break;

                case 2:
                    System.out.println("Digite o texto: ");
                    String textBin = sc.nextLine();
                    String bin = asciiToBinary(textBin);
                    System.out.println("Binário ASCII: " + bin);
                    break;

                case 3:
                    System.out.println("Digite os números octais separados por espaço: ");
                    String[] octals = sc.nextLine().split(" ");
                    String asciiFromOctal = octalToAscii(octals);
                    System.out.println("Texto ASCII: " + asciiFromOctal);
                    break;

                case 4:
                    System.out.println("Digite os números hexadecimais separados por espaço: ");
                    String[] hexNumbers = sc.nextLine().split(" ");
                    String asciiFromHex = hexToAscii(hexNumbers);
                    System.out.println("Texto ASCII: " + asciiFromHex);
                    break;

                default:
                    System.out.println("Escolha inválida.");
                    break;
            }

            x++;
            System.out.println();

        }while(x < 5);

        sc.close();
    }

    public static String asciiToHex(String text) {
        StringBuilder hex = new StringBuilder();
        for (char c : text.toCharArray()) {
            hex.append(String.format("%02X", (int) c));
        }
        return hex.toString();
    }

    public static String asciiToBinary(String text) {
        StringBuilder binary = new StringBuilder();
        for (char c : text.toCharArray()) {
            binary.append(String.format("%8s", Integer.toBinaryString(c)).replace(' ', '0')).append(" ");
        }
        return binary.toString().trim();
    }

    public static String octalToAscii(String[] octals) {
        StringBuilder text = new StringBuilder();
        for (String octal : octals) {
            int decimal = Integer.parseInt(octal, 8);
            text.append((char) decimal);
        }
        return text.toString();
    }

    public static String hexToAscii(String[] hexNumbers) {
        StringBuilder text = new StringBuilder();
        for (String hex : hexNumbers) {
            int decimal = Integer.parseInt(hex, 16);
            text.append((char) decimal);
        }
        return text.toString();
    }
}

/*
Escolha a operação:
1: Texto para Hexadecimal ASCII
2: Texto para Binário ASCII
3: Octal para ASCII
4: Hexadecimal para ASCII
1
Digite o texto:
PUC-M.G.
Hexadecimal ASCII: 5055432D4D2E472E

Escolha a operação:
1: Texto para Hexadecimal ASCII
2: Texto para Binário ASCII
3: Octal para ASCII
4: Hexadecimal para ASCII
1
Digite o texto:
2024-02
Hexadecimal ASCII: 323032342D3032

Escolha a operação:
1: Texto para Hexadecimal ASCII
2: Texto para Binário ASCII
3: Octal para ASCII
4: Hexadecimal para ASCII
2
Digite o texto:
Belo Horizonte
Binário ASCII: 01000010 01100101 01101100 01101111 00100000 01001000 01101111 01110010 01101001 01111010 01101111 01101110 01110100 01100101

Escolha a operação:
1: Texto para Hexadecimal ASCII
2: Texto para Binário ASCII
3: Octal para ASCII
4: Hexadecimal para ASCII
3
Digite os números octais separados por espaço:
156 157 151 164 145
Texto ASCII: noite

Escolha a operação:
1: Texto para Hexadecimal ASCII
2: Texto para Binário ASCII
3: Octal para ASCII
4: Hexadecimal para ASCII
4
Digite os números hexadecimais separados por espaço:
4D 61 6E 68 61
Texto ASCII: Manha
 */