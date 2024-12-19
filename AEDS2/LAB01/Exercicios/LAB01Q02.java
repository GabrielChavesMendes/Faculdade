import java.util.Scanner;

public class LAB01Q02{

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        boolean verdade = false;
        int index = 0;

        while(!verdade){
            String frase = sc.nextLine();

            if(frase.charAt(0) == 'F' && frase.charAt(1) == 'I' && frase.charAt(2) == 'M'){
                verdade = true;
            }else{
                int quant = LetrasMaiusculas(frase, index);

                System.out.println(quant);
            }
        }
    }

    public static int LetrasMaiusculas(String frase, int index){

        int cont = 0;

        if(index >= frase.length()){
            return 0;
        }else{
            if(frase.charAt(index) >= 'A' && frase.charAt(index) <= 'Z'){
                cont++;
            }
            return cont + LetrasMaiusculas(frase, index + 1);
        }
    }
}