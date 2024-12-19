import java.util.Scanner;
import java.util.Random;

public class TP01Q04 {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        boolean verdade = false;

        //Funcao Random
        Random gerador = new Random();
        gerador.setSeed(4);

        while(!verdade){
            String frase = sc.nextLine();

            if(frase.length() >= 3 && frase.charAt(0) == 'F' && frase.charAt(1) == 'I' && frase.charAt(2) == 'M'){
                verdade = true;
            }else{
                //Escolhe duas letras aleatorias
                char letra_1 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
                char letra_2 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));

                System.out.println(Troca_Letra(frase, letra_1, letra_2));
            }
        }
    }

    public static String Troca_Letra(String frase, char letra_1, char letra_2){

        char[] nova_frase = new char[frase.length()];

        //Caso encontre a letra_1, a substitui pela letra_2 na frase
        for(int i = 0; i < frase.length(); i++){
            char a = frase.charAt(i);
            if(a == letra_1){
                nova_frase[i] = letra_2;
            }else {
                nova_frase[i] = a;
            }
        }
        return new String(nova_frase);
    }
}
