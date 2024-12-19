import java.util.Scanner;
import java.util.ArrayList;

public class Camiseta {

    static class Camisa {

        private String nome;
        private String tipo;

        public Camisa(String nome, String tipo) {
            this.nome = nome;
            this.tipo = tipo;
        }

        public String getNome() {
            return nome;
        }

        public void setNome(String nome) {
            this.nome = nome;
        }

        public String getTipo() {
            return tipo;
        }

        public void setTipo(String tipo) {
            this.tipo = tipo;
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Camisa camisa = new Camisa(" ", " ");

        String nome;
        String tipo;
        ArrayList<String> cor = new ArrayList<>();
        ArrayList<String> name = new ArrayList<>();
        int N = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < N; i++) {

            nome = sc.nextLine();
            camisa.setNome(nome);

            tipo = sc.nextLine();
            camisa.setTipo(tipo);

            cor.add(camisa.getTipo());
            name.add(camisa.getNome());
        }

        // Ordena as cores e nomes
        ordenaCor(cor, name, N);
        System.out.println();

        sc.close();
    }

    public static void ordenaCor(ArrayList<String> cor, ArrayList<String> name, int N) {

        for (int i = 0; i < N - 1; i++) {

            for (int j = 0; j < N - 1 - i; j++) {
                if (cor.get(j).split(" ")[0].compareTo(cor.get(j + 1).split(" ")[0]) > 0){

                    String tempCor = cor.get(j);
                    cor.set(j, cor.get(j + 1));
                    cor.set(j + 1, tempCor);

                    String tempName = name.get(j);
                    name.set(j, name.get(j + 1));
                    name.set(j + 1, tempName);
                }
            }
        }

        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - 1 - i; j++) {
                String tam1 = cor.get(j).split(" ")[1];
                String tam2 = cor.get(j+1).split(" ")[1];
                int tam_ind1 = Tamanho(tam1);
                int tam_ind2 = Tamanho(tam2);

                if(tam_ind1 > tam_ind2){
                    String tempCor = cor.get(j);
                    cor.set(j, cor.get(j + 1));
                    cor.set(j + 1, tempCor);

                    String tempName = name.get(j);
                    name.set(j, name.get(j + 1));
                    name.set(j + 1, tempName);
                }
            }
        }

        for(int i = 0; i < N - 1; i++){
            for (int j = 0; j < N - 1 - i; j++) {
                String cor1 = cor.get(j).split(" ")[0];
                String cor2 = cor.get(j + 1).split(" ")[0];
                String tam1 = cor.get(j).split(" ")[1];
                String tam2 = cor.get(j + 1).split(" ")[1];

                if (cor1.equals(cor2) && tam1.equals(tam2)) {
                    String nome1 = name.get(j);
                    String nome2 = name.get(j + 1);

                    if (nome1.compareTo(nome2) > 0) {
                        String tempName = name.get(j);
                        name.set(j, name.get(j + 1));
                        name.set(j + 1, tempName);

                        String tempCor = cor.get(j);
                        cor.set(j, cor.get(j + 1));
                        cor.set(j + 1, tempCor);
                    }
                }
            }
        }

        // Exibe o resultado ordenado
        for (int i = 0; i < N; i++) {
            System.out.println(cor.get(i) + " " + name.get(i));
        }
    }

    private static int Tamanho(String tamanho){
        switch(tamanho){
            case "P":
                return 1;
            case "M":
                return 2;
            case "G":
                return 3;
            default:
                return 0;
        }
    }
}
