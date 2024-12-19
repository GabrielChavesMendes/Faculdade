import java.util.Scanner;
import java.util.Locale;

public class Main{

    public static void main(String[] args){
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        int x = 0;

        do{
            System.out.println("Escreva o numero decimal: ");
            double decimal = sc.nextDouble();

            String binario = double2bin(decimal);

            System.out.println("O numero em binario e: " + binario);

            x++;
        }while(x < 5);
    }

    public static String double2bin(double decimal){

        int partInteira = (int)decimal;
        StringBuilder parteBinaria_Int = new StringBuilder();

        if(partInteira == 0){
            parteBinaria_Int.append("0");
        }else{
            while(partInteira > 0){
                int resto = partInteira % 2;
                parteBinaria_Int.insert(0, resto);
                partInteira = partInteira / 2;
            }
        }

        double parteFrac = decimal - (int)decimal;
        StringBuilder parteBinaria_Frac = new StringBuilder();

        int cont = 0;
        int interacoes = 10;

        while(parteFrac > 0 && cont < interacoes){
            parteFrac = parteFrac * 2;

            int bit = (int)parteFrac;
            parteBinaria_Frac.append(bit);
            parteFrac = parteFrac - bit;
            cont++;
        }

        return parteBinaria_Frac.length() > 0 ? parteBinaria_Int + "," + parteBinaria_Frac.toString() : parteBinaria_Int.toString();
    }
}

/*
Escreva o numero decimal:
0.37500
O numero em binario e: 0,011
Escreva o numero decimal:
2.125000
O numero em binario e: 10,001
Escreva o numero decimal:
3.625000
O numero em binario e: 11,101
Escreva o numero decimal:
5.03125
O numero em binario e: 101,00001
Escreva o numero decimal:
6.750000
O numero em binario e: 110,11
 */