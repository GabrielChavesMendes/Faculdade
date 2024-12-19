import java.util.Scanner;

public class LAB01Q01{

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        boolean verdade = false;

        while(!verdade){
            String frase = sc.nextLine();

            if(frase.charAt(0) == 'F' && frase.charAt(1) == 'I' && frase.charAt(2) == 'M'){
                verdade = true;
            }else{
                int quant = LetrasMaiusculas(frase);

                System.out.println(quant);
            }
        }
    }

    public static int LetrasMaiusculas(String frase){

        int cont = 0;

        for(int i = 0; i < frase.length(); i++){
            if(frase.charAt(i) >= 'A' && frase.charAt(i) <= 'Z'){
                cont++;
            }
        }
        return cont;
    }
}