import java.util.Scanner;
import java.util.Locale;

public class Main{

    public static void main(String[] args){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        int x = 0;

        do{
            System.out.println("Escreva um numero binario: ");
            String binario = sc.nextLine();

            System.out.println("Agora escreva qual base: ");
            int base = sc.nextInt();
            sc.nextLine(); //Limpeza de buff

            String numero = dbin2base(base, binario);

            System.out.println("O numero na base" + base  + " e: " + numero);

            x++;
        }while(x < 5);
    }

    public static String dbin2base(int base, String binario){

        String[] partes = binario.split(",");
        String parteInteira = partes[0];
        String parteFracionaria = partes.length > 1 ? partes[1] : "";

        int parteInt_Decimal = 0;
        for (int i = 0; i < parteInteira.length(); i++){
            if (parteInteira.charAt(i) == '1'){
                parteInt_Decimal += Math.pow(2, parteInteira.length() - 1 - i);
            }
        }
        String parteInt_Convertida = Integer.toString(parteInt_Decimal, base).toUpperCase();

        double parteFrac_Decimal = 0;

        for (int i = 0; i < parteFracionaria.length(); i++){
            if (parteFracionaria.charAt(i) == '1'){
                parteFrac_Decimal += Math.pow(2, -(i + 1));
            }
        }

        StringBuilder parteFrac_Convertida = new StringBuilder();
        int maxIteracoes = 10;

        while (parteFrac_Decimal > 0 && maxIteracoes-- > 0){
            parteFrac_Decimal = parteFrac_Decimal * base;
            int digito = (int)parteFrac_Decimal;

            parteFrac_Convertida.append(Integer.toString(digito, base).toUpperCase());
            parteFrac_Decimal = parteFrac_Decimal - digito;
        }

        if (parteFrac_Convertida.length() > 0){
            return parteInt_Convertida + "," + parteFrac_Convertida.toString();
        } else{
            return parteInt_Convertida;
        }
    }
}

/*
Escreva um numero binario:
0,011110
Agora escreva qual base:
4
O numero na base4 e: 0,132
Escreva um numero binario:
0,101001
Agora escreva qual base:
8
O numero na base8 e: 0,51
Escreva um numero binario:
0,100110
Agora escreva qual base:
16
O numero na base16 e: 0,98
Escreva um numero binario:
1,111011
Agora escreva qual base:
8
O numero na base8 e: 1,73
Escreva um numero binario:
1101,1001
Agora escreva qual base:
16
O numero na base16 e: D,9
 */