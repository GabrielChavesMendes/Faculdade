import java.util.Scanner;

public class TP01Q06{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        boolean verdade = false;

        while(!verdade){
            String frase = sc.nextLine();
            if(frase.length() >= 3 && frase.charAt(0) == 'F' && frase.charAt(1) == 'I' && frase.charAt(2) == 'M'){
                verdade = true;
            }else{
                Vogais(frase);
                Consoante(frase);
                Numeros_Intereiros(frase);
                Numeros_Real(frase);
            }
        }
    }

    public static void Vogais(String frase){
        int cont = 0;

        for(int i = 0; i < frase.length(); i++){
            if(frase.charAt(i) >= 'a' && frase.charAt(i) <= 'z'){
                if(frase.charAt(i) == 'a' || frase.charAt(i) == 'e' || frase.charAt(i) == 'i' || frase.charAt(i) == 'o' || frase.charAt(i) == 'u'){
                    cont++;
                }
            }
        }
        if(cont == frase.length()){
            System.out.print("SIM ");
        }else{
            System.out.print("NAO ");
        }
    }

    public static void Consoante(String frase){
        int cont = 0;

        for(int i = 0; i < frase.length(); i++){
            if(frase.charAt(i) >= 'a' && frase.charAt(i) <= 'z'){
                if(frase.charAt(i) != 'a' && frase.charAt(i) != 'e' && frase.charAt(i) != 'i' && frase.charAt(i) != 'o' && frase.charAt(i) != 'u'){
                    cont++;
                }
            }
        }
        if(cont == frase.length()){
            System.out.print("SIM ");
        }else{
            System.out.print("NAO ");
        }
    }

    public static void Numeros_Intereiros(String frase){
        int cont = 0;

        for(int i = 0; i < frase.length(); i++){
            char c = frase.charAt(i);
            if(c >= '0' && c <= '9'){
              cont++;
            }
        }
        if(cont == frase.length()){
            System.out.print("SIM ");
        }else{
            System.out.print("NAO ");
        }
    }

    public static void Numeros_Real(String frase){
        int cont = 0;
        int cont2 = 0;

        for(int i = 0; i < frase.length(); i++){
            char c = frase.charAt(i);
            if(c >= '0' && c <= '9'){
                cont++;
            }else if(c == '.' || c == ',' && cont2 < 1){
                cont++;
                cont2++;
            }
        }
        if(cont == frase.length()){
            System.out.println("SIM");
        }else{
            System.out.println("NAO");
        }
    }
}
