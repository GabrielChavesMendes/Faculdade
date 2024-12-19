import java.util.Locale;
import java.util.Scanner;


public class Main{

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        int x = 0;

        do{
            System.out.println("Escreva um numero binario: ");
            String binario = sc.nextLine();

            double decimal = bin2double(binario);

            System.out.println("O numero na base decimal e: " + decimal);

            x++;
        }while(x < 5);
    }

    public static double bin2double(String binario) {
        String[] partes = binario.split(",");

        String parteInteira = partes[0];
        String parteFracionaria = partes.length > 1 ? partes[1] : "";

        double decimal = 0;
        int comprimentoInteira = parteInteira.length();

        for (int i = 0; i < comprimentoInteira; i++){
            char digito = parteInteira.charAt(comprimentoInteira - 1 - i);

            if (digito == '1') {
                decimal += Math.pow(2, i);
            }
        }

        int comprimentoFracionaria = parteFracionaria.length();
        for (int i = 0; i < comprimentoFracionaria; i++) {
            char digito = parteFracionaria.charAt(i);

            if (digito == '1') {
                decimal += Math.pow(2, -(i + 1));
            }
        }
        return decimal;
    }
}

/*
Escreva um numero binario:
0,00011
O numero na base decimal e: 0.09375
Escreva um numero binario:
0,01001
O numero na base decimal e: 0.28125
Escreva um numero binario:
0,10101
O numero na base decimal e: 0.65625
Escreva um numero binario:
1,11101
O numero na base decimal e: 1.90625
Escreva um numero binario:
11,11001
O numero na base decimal e: 3.78125
 */