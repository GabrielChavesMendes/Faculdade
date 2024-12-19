import java.util.Scanner;

public class LAB03Q01 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String frase = sc.nextLine();
        int verdade;

        while(!frase.equals("FIM")){
            verdade = parenteses(frase);

            if(verdade == 1){
                System.out.println("correto");
            }else{
                System.out.println("incorreto");
            }
            frase = sc.nextLine();
        }
    }

    public static int parenteses(String frase) {

        int cont = 1;

        for(int i = 0; i < frase.length(); i++){
            if(frase.charAt(i) == '('){
                cont++;
            }else if(frase.charAt(i) == ')'){
                cont--;
            }

            if(cont == 0){
                return i;
            }
        }
        return cont;
    }
}