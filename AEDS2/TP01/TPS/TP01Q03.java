import java.util.Scanner;

public class TP01Q03 {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        String cezar = sc.nextLine();
        for(int i = 0; i < cezar.length(); i++){ //For para ler letra por letra da String
            char c = cezar.charAt(i); //Extrai o caractere na posicao i

            char s = (char) (c + 3); //Extrai o caractere e o coloca 3 posicoes a frente no alfabeto, atribuindo o novo caractere na String s

            System.out.print(s);
        }
        System.out.println();

        while(!(cezar = sc.nextLine()).equalsIgnoreCase("FIM")){ //Refaz  o processo enquanto o conteudo da String cezar for diferente da palavra "FIM"
            for(int i = 0; i < cezar.length(); i++){ //For para refazr o processo acima
                char c = cezar.charAt(i);

                char s = (char) (c + 3);

                System.out.print(s);
            }
            System.out.println();
        }
    }
}