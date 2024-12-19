import java.util.Scanner;
import java.util.Locale;

public class Main {

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        int x = 0;

        do {
            System.out.println("Escreva um número: ");
            String numero = sc.nextLine();

            System.out.println("Qual é a base original do número? ");
            int baseOriginal = sc.nextInt();
            sc.nextLine(); // Limpeza de buff

            System.out.println("Qual é a base para a conversão? ");
            int baseDesejada = sc.nextInt();
            sc.nextLine(); // Limpeza de buff

            String binario = convertToBinary(numero, baseOriginal);
            String resultado = dbin2base(baseDesejada, binario);

            System.out.println("O número na base " + baseDesejada + " é: " + resultado);

            x++;
        } while (x < 5);
    }

    public static String convertToBinary(String numero, int base) {
        String[] partes = numero.split(",");
        String parteInteira = partes[0];
        String parteFracionaria = partes.length > 1 ? partes[1] : "";

        // Converter parte inteira para decimal
        int decimalInteiro = Integer.parseInt(parteInteira, base);

        // Converter parte fracionária para decimal
        double decimalFracionario = 0;
        for (int i = 0; i < parteFracionaria.length(); i++) {
            char digito = parteFracionaria.charAt(i);
            int valor = Character.digit(digito, base);
            decimalFracionario += valor * Math.pow(base, -(i + 1));
        }

        // Converter decimal para binário
        String binarioInteiro = Integer.toBinaryString(decimalInteiro);

        // Converter parte fracionária decimal para binário
        StringBuilder binarioFracionario = new StringBuilder();
        int maxIteracoes = 10;
        while (decimalFracionario > 0 && maxIteracoes-- > 0) {
            decimalFracionario *= 2;
            int digito = (int) decimalFracionario;
            binarioFracionario.append(digito);
            decimalFracionario -= digito;
        }

        if (binarioFracionario.length() > 0) {
            return binarioInteiro + "," + binarioFracionario.toString();
        } else {
            return binarioInteiro;
        }
    }

    public static String dbin2base(int base, String binario) {
        String[] partes = binario.split(",");
        String parteInteira = partes[0];
        String parteFracionaria = partes.length > 1 ? partes[1] : "";

        int parteInt_Decimal = 0;
        for (int i = 0; i < parteInteira.length(); i++) {
            if (parteInteira.charAt(i) == '1') {
                parteInt_Decimal += Math.pow(2, parteInteira.length() - 1 - i);
            }
        }
        String parteInt_Convertida = Integer.toString(parteInt_Decimal, base).toUpperCase();

        double parteFrac_Decimal = 0;
        for (int i = 0; i < parteFracionaria.length(); i++) {
            if (parteFracionaria.charAt(i) == '1') {
                parteFrac_Decimal += Math.pow(2, -(i + 1));
            }
        }

        StringBuilder parteFrac_Convertida = new StringBuilder();
        int maxIteracoes = 10;

        while (parteFrac_Decimal > 0 && maxIteracoes-- > 0) {
            parteFrac_Decimal = parteFrac_Decimal * base;
            int digito = (int) parteFrac_Decimal;

            parteFrac_Convertida.append(Integer.toString(digito, base).toUpperCase());
            parteFrac_Decimal = parteFrac_Decimal - digito;
        }

        if (parteFrac_Convertida.length() > 0) {
            return parteInt_Convertida + "," + parteFrac_Convertida.toString();
        } else {
            return parteInt_Convertida;
        }
    }
}

/*
Escreva um número:
0,321
Qual é a base original do número?
4
Qual é a base para a conversão?
2
O número na base 2 é: 0,111001
Escreva um número:
0,3D2
Qual é a base original do número?
16
Qual é a base para a conversão?
4
O número na base 4 é: 0,0331
Escreva um número:
0,751
Qual é a base original do número?
8
Qual é a base para a conversão?
2
O número na base 2 é: 0,111101001
Escreva um número:
7,345
Qual é a base original do número?
8
Qual é a base para a conversão?
4
O número na base 4 é: 13,13022
Escreva um número:
F,A5E
Qual é a base original do número?
16
Qual é a base para a conversão?
4
O número na base 4 é: 33,22113
 */