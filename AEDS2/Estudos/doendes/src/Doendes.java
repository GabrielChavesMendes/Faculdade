import java.util.Scanner;

public class Doendes {

    public static void main(String[] args) throws Exception {
       
        Scanner sc = new Scanner(System.in);

        int N;
        int idade;
        String nome;

        N = sc.nextInt();
        sc.nextLine();

        while (N <= 3 || N >= 300 || N % 3 != 0) {
            System.out.print("Digite o número de doendes: ");
            N = sc.nextInt();
            sc.nextLine();  // Consumir a nova linha deixada pelo nextInt()
        }
            
    
        String doendesNome[] = new String[N];
        int doendesIdade[] = new int[N];

        for(int i = 0; i < N; i++){

            nome = sc.nextLine();
            idade = sc.nextInt();
             
            sc.nextLine();

            doendesNome[i] = nome;
            doendesIdade[i] = idade;
        }

        String[] doendes = ordena(N, doendesNome, doendesIdade);

        int time = 1;
        int divisao = N / 3;

        for(int i = 0; i < divisao; i++){
            System.out.println("Time " + time);
            for(int j = 0; j < N; j += divisao){
                System.out.println(doendes[j]);
            }
            System.out.println();
            time++;
        }

        // 0 1 2 3 4 5 

        sc.close();
    }

    public static String[] ordena(int N, String[] doendesNome, int[] doendesIdade){
    
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N-i-1; j++){
                if (doendesIdade[j] > doendesIdade[j + 1]) {
                   
                    int tempIdade = doendesIdade[j];
                    doendesIdade[j] = doendesIdade[j + 1];
                    doendesIdade[j + 1] = tempIdade;

                    String tempNome = doendesNome[j];
                    doendesNome[j] = doendesNome[j + 1];
                    doendesNome[j + 1] = tempNome;
                }
            }
        }

        String[] doendesOrdenado = new String[N];

        for(int i = 0; i < N; i++){
            doendesOrdenado[i] = doendesNome[i] + " " + doendesIdade[i];
        }
        return doendesOrdenado;
    }
}
