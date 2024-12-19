import java.util.Scanner;

public class TP01Q15 {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        boolean verdade = false;
        boolean sim;

        while(!verdade){
            String frase = sc.nextLine();
            if(frase.equals("FIM")){
                verdade = true;
            }else{

                int tam = frase.length();
                if (tam == 0) {
                    System.out.println("NAO NAO NAO NAO");
                    continue;
                }

                sim = Vogais(frase, frase.length() - 1, 0, 0);
                if(sim){
                    System.out.print("SIM ");
                }else{
                    System.out.print("NAO ");
                }

                sim = Consoante(frase, frase.length() - 1, 0, 0);
                if(sim){
                    System.out.print("SIM ");
                }else{
                    System.out.print("NAO ");
                }

                sim = Numeros_Intereiros(frase, frase.length() - 1, 0, 0);
                if(sim){
                    System.out.print("SIM ");
                }else{
                    System.out.print("NAO ");
                }

                sim = Numeros_Real(frase, frase.length() - 1, 0, 0, 0);
                if(sim){
                    System.out.println("SIM");
                }else{
                    System.out.println("NAO");
                }
            }
        }
    }

     /*
        A condicao de parada e a mesma para todas, apos a variavel i percorrer todos os caracteres
        e atigir o tamanho da String, o return ira verificar se o contador e igual ao tamanho da
        String, se sim, retorna verdadeiro, ou seja, a todas os caracteres atendem o requisito da
        recursao, se nao, retorna falso
    */


    public static boolean Vogais(String frase, int tam, int cont, int i){
        if(i == tam) {
            return cont == tam;
        }

        char c = frase.charAt(i);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            cont++;
        }
        return Vogais(frase, tam, cont, i + 1);
    }

    public static boolean Consoante(String frase, int tam, int cont, int i){
        if(i == tam) {
            return cont == tam;
        }

        char c = frase.charAt(i);
        if(c >= 'a' && c <= 'z'){
            if(c != 'a' && c != 'e' &&c != 'i' && c != 'o' && c != 'u'){
                cont++;
            }
        }
        return Consoante(frase, tam, cont, i + 1);
    }

    public static boolean Numeros_Intereiros(String frase, int tam, int cont, int i){
        if(i == tam) {
            return cont == tam;
        }

        char c = frase.charAt(i);
        if(c >= '0' && c <= '9'){
            cont++;
        }
        return Numeros_Intereiros(frase, tam, cont, i + 1);
    }

    public static boolean Numeros_Real(String frase, int tam, int cont, int cont2, int i){
        if(i == tam) {
            return cont == tam;
        }

        char c = frase.charAt(i);
        if(c >= '0' && c <= '9'){
            cont++;
        }else if(c == '.' || c == ',' && cont2 < 1){
            cont++;
            cont2++;
        }
        return Numeros_Real(frase, tam, cont, cont2,i + 1);
    }
}

