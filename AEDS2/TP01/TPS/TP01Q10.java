import java.util.Scanner;

public class TP01Q10 {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        String frase = sc.nextLine();

        while(!frase.equals("FIM")){

            /* chamada do metodo recursivo que retorna true ou false,
            passando como parametro a frase, o contador para o inicio e um para o final da frase
            frase.length() - 1, para desconisderar o /n */

            boolean igual = palindromo(frase, 0, frase.length() - 1);

            if(igual){ //se true
                System.out.println("SIM");
            }else{ //se false
                System.out.println("NAO");
            }
            frase = sc.nextLine();
        }
    }

    public static boolean palindromo(String frase, int inicio, int fim){

        // se inicio for maior que fim, significa que comparou todas letras da frase, até o contador inicio ser maior
        if(inicio >= fim){
            return true;
        }
        // mas se em algum momento uma letra for diferente da ulta ira retornar false imediatamente
        if(frase.charAt(inicio) != frase.charAt(fim)){
            return false;
        }

        //chama a si mesma, retornando toda a palavra, mas andando com o contador inicio e fim para comparar as letras
        return palindromo(frase, inicio + 1, fim - 1);
    }
}
