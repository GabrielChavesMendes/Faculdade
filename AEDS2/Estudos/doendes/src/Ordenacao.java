import java.util.Scanner;
import java.util.ArrayList;

public class Ordenacao {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        sc.nextLine();

        String frase;
        ArrayList<String> strings = new ArrayList<>();
        
        for(int i = 0; i < N; i++){
            boolean verdade = true;

            while(verdade){
                frase = sc.nextLine();

                strings.add(frase);

                if(frase.isEmpty()){
                    verdade = false;
                }

            }

            int tam = strings.size();

            for(int j = 0; j < tam - 1; j++){
                for(int k = 0; k < tam - 1 - j; k++){
                    if(strings.get(k).length() < strings.get(k+1).length()){
                        String temp = strings.get(k);
                        strings.set(k, strings.get(k+1));
                        strings.set(k+1, temp);
                    }
                }
            }
        }
            
        System.out.println("\nVocê digitou:");
        for (String s : strings) {
            System.out.println(s);
        }

        sc.close();
    }
}
