import java.util.Scanner;

public class TP01Q01{

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        String frase = sc.nextLine();
        int tam = frase.length();
        char[] frase_inv = new char[tam];
        int cont = 0;

        //Inverter a string
        for(int i = 0; i < tam; i++){
            char c = frase.charAt(i);
            frase_inv[tam - i - 1] = c; //Atribui o caractere na posicao inversa a primeira string, mapeando o indice para que sejam colocados apartir da ultima posicao
        }
        //Conta caracteres iguais
        for(int i = 0; i < tam; i++){
            if(frase.charAt(i) == frase_inv[i]){
                cont++;
            }
        }

        if(cont == tam){
            System.out.println("SIM");
        }else{
            System.out.println("NAO");
        }

        boolean verdade = false;

        while(!verdade){
            frase = sc.nextLine();
            tam = frase.length();
            frase_inv = new char[tam];
            cont = 0;

            if(tam >= 3 && frase.charAt(0) == 'F' && frase.charAt(1) == 'I' && frase.charAt(2) == 'M'){
                verdade = true;
            }else{
                // Inverter a string
                for(int i = 0; i < tam; i++){
                    char c = frase.charAt(i);
                    frase_inv[tam - i - 1] = c; //Atribui o caractere na posicao inversa a primeira string, mapeando o indice para que sejam colocados apartir da ultima posicao
                }
                // Contar os caracteres iguais
                for(int i = 0; i < tam; i++){
                    if(frase.charAt(i) == frase_inv[i]){
                        cont++;
                    }
                }
                if(cont == tam){
                    System.out.println("SIM");
                }else{
                    System.out.println("NAO");
                }
            }
        }
    }
}
