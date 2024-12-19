import java.util.Scanner;
import java.util.Locale;

public class Main {

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        int x = 0;

        do {
            System.out.println("Escolha a operação (soma, subtração, multiplicação, divisão, resto): ");
            String operacao = sc.nextLine().toLowerCase();

            System.out.println("Escreva o primeiro número binário: ");
            String binario1 = sc.nextLine();

            System.out.println("Escreva o segundo número binário: ");
            String binario2 = sc.nextLine();

            String resultado = "";

            switch (operacao) {
                case "soma":
                    resultado = somaBinarios(binario1, binario2);
                    break;
                case "subtração":
                    resultado = subtracaoBinarios(binario1, binario2);
                    break;
                case "multiplicação":
                    resultado = multiplicacaoBinarios(binario1, binario2);
                    break;
                case "divisão":
                    resultado = divisaoBinarios(binario1, binario2);
                    break;
                case "resto":
                    resultado = restoBinarios(binario1, binario2);
                    break;
                default:
                    System.out.println("Operação inválida.");
                    break;
            }

            System.out.println("O resultado é: " + resultado);

            x++;
        } while (x < 5);
    }

    public static String somaBinarios(String binario1, String binario2) {
        double decimal1 = binarioParaDecimal(binario1);
        double decimal2 = binarioParaDecimal(binario2);
        double somaDecimal = decimal1 + decimal2;
        return decimalParaBinario(somaDecimal);
    }

    public static String subtracaoBinarios(String binario1, String binario2) {
        double decimal1 = binarioParaDecimal(binario1);
        double decimal2 = binarioParaDecimal(binario2);
        double subtracaoDecimal = decimal1 - decimal2;
        return decimalParaBinario(subtracaoDecimal);
    }

    public static String multiplicacaoBinarios(String binario1, String binario2) {
        double decimal1 = binarioParaDecimal(binario1);
        double decimal2 = binarioParaDecimal(binario2);
        double multiplicacaoDecimal = decimal1 * decimal2;
        return decimalParaBinario(multiplicacaoDecimal);
    }

    public static String divisaoBinarios(String binario1, String binario2) {
        double decimal1 = binarioParaDecimal(binario1);
        double decimal2 = binarioParaDecimal(binario2);
        if (decimal2 == 0) {
            return "Erro: Divisão por zero.";
        }
        double divisaoDecimal = decimal1 / decimal2;
        return decimalParaBinario(divisaoDecimal);
    }

    public static String restoBinarios(String binario1, String binario2) {
        double decimal1 = binarioParaDecimal(binario1);
        double decimal2 = binarioParaDecimal(binario2);
        if (decimal2 == 0) {
            return "Erro: Divisão por zero.";
        }
        double restoDecimal = decimal1 % decimal2;
        return decimalParaBinario(restoDecimal);
    }

    public static double binarioParaDecimal(String binario) {
        String[] partes = binario.split(",");
        String parteInteira = partes[0];
        String parteFracionaria = partes.length > 1 ? partes[1] : "";

        // Converter parte inteira para decimal
        int decimalInteiro = Integer.parseInt(parteInteira, 2);

        // Converter parte fracionária para decimal
        double decimalFracionario = 0;
        for (int i = 0; i < parteFracionaria.length(); i++) {
            char digito = parteFracionaria.charAt(i);
            int valor = Character.digit(digito, 2);
            decimalFracionario += valor * Math.pow(2, -(i + 1));
        }

        // Combinar parte inteira e fracionária em um número decimal
        return decimalInteiro + decimalFracionario;
    }

    public static String decimalParaBinario(double decimal) {
        // Converter parte inteira para binário
        long parteInteira = (long) decimal;
        String binarioInteiro = Long.toBinaryString(parteInteira);

        // Converter parte fracionária para binário
        double parteFracionaria = decimal - parteInteira;
        StringBuilder binarioFracionaria = new StringBuilder();

        int maxIteracoes = 10;
        while (parteFracionaria > 0 && maxIteracoes-- > 0) {
            parteFracionaria *= 2;
            long digito = (long) parteFracionaria;
            binarioFracionaria.append(digito);
            parteFracionaria -= digito;
        }

        if (binarioFracionaria.length() > 0) {
            return binarioInteiro + "," + binarioFracionaria.toString();
        } else {
            return binarioInteiro;
        }
    }
}

/*
Escolha a operação (soma, subtração, multiplicação, divisão, resto):
soma
Escreva o primeiro número binário:
101,001
Escreva o segundo número binário:
010,011
O resultado é: 111,1
Escolha a operação (soma, subtração, multiplicação, divisão, resto):
subtração
Escreva o primeiro número binário:
1000,101
Escreva o segundo número binário:
10,01
O resultado é: 110,011
Escolha a operação (soma, subtração, multiplicação, divisão, resto):
multiplicação
Escreva o primeiro número binário:
101,101
Escreva o segundo número binário:
10,101
O resultado é: 1110,110001
Escolha a operação (soma, subtração, multiplicação, divisão, resto):
divisão
Escreva o primeiro número binário:
10111,01
Escreva o segundo número binário:
11,011
O resultado é: 110,1110001110
Escolha a operação (soma, subtração, multiplicação, divisão, resto):
resto
Escreva o primeiro número binário:
1101011
Escreva o segundo número binário:
1101
O resultado é: 11
 */