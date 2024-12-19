import java.util.Scanner;

public class TP01Q12 {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        String frase = sc.nextLine();

        while(!frase.equals("FIM")){

            String frase_nova = cezar(frase, "", frase.length() - 1, 0);

            System.out.println(frase_nova);

            frase = sc.nextLine();
        }
    }

    public static String cezar(String frase, String frase_nova, int tam, int i){
        if(i > tam){
            return frase_nova;
        }else{
            char c = frase.charAt(i); //Extrai o caractere na posicao i

            /* Verifica se o caractere está no intervalo desejado,
             de caracteres especiais na tabela ASCII, e realiza a cifragem
             e concatena com base em cada condicao proposta */

             if (c >= 32 && c <= 126) {
                char s = (char) (((c - 32 + 3) % 95) + 32);
                frase_nova = frase_nova + s;
            } else {
                frase_nova = frase_nova + c;
            }
        }
        /* chama a si mesma, retornando a frase inicial, a frase nova sendo concatenada com os novoscaracteres
        o tamano original e o contador para a condição de parada */
        return cezar(frase, frase_nova, tam, i + 1);
    }
}
