import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

class Hash {
    int tabela[];
    int m1, m2, m, reserva;
    final int NULO = -1;
 
    public Hash() {
       this(21, 9);
    }
 
    public Hash(int m1, int m2) {
       this.m1 = m1;
       this.m2 = m2;
       this.m = m1 + m2;
       this.tabela = new int[this.m];
       for (int i = 0; i < m1; i++) {
          tabela[i] = NULO;
       }
       reserva = 0;
    }
 
    public int h(int elemento) {
       return elemento % m1;
    }
 
    public boolean inserir(int elemento) {
       boolean resp = false;
       if (elemento != NULO) {
          int pos = h(elemento);
          if (tabela[pos] == NULO) {
             tabela[pos] = elemento;
             resp = true;
          } else if (reserva < m2) {
             tabela[m1 + reserva] = elemento;
             reserva++;
             resp = true;
          }
       }
       return resp;
    }
 
    public int pesquisar(int elemento) {
        int pos = h(elemento); // Calcula a posição inicial
        if (tabela[pos] == elemento) {
            return pos; // Retorna a posição se o elemento estiver na área principal
        } else if (tabela[pos] != NULO) {
            for (int i = 0; i < reserva; i++) {
                if (tabela[m1 + i] == elemento) {
                    return m1 + i; // Retorna a posição se o elemento estiver na área de reserva
                }
            }
        }
        return -1; // Retorna -1 se o elemento não for encontrado
    }
} 

public class TP04Q05 {

    public static String nomePokemon(int id){

        String nome = " ";
        String pokemonFile = "/tmp/pokemon.csv";
        String linha;

        try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))) {
            leitura.readLine(); // Ignorar cabeçalho
            
            while ((linha = leitura.readLine()) != null) {
                String[] pokemon = linha.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");      

                if (pokemon.length >= 10) {
                    String id_arq = pokemon[0];
                    int id_poke = Integer.parseInt(id_arq);

                    if(id == id_poke){
                        nome = pokemon[2].replace("\"", "").trim();                        
                    }  
                }
                
            } 
        } catch (IOException e) {
            e.printStackTrace();
        }

        return nome;
    }

    public static int ASCII_name(String nome){

        int valor = 0;

        for (int i = 0; i < nome.length(); i++) {
            char ch = nome.charAt(i); 
            valor = valor + (int) ch; 
        }

        return valor;
    }

    public static void main(String[] args) throws Exception {
         Scanner sc = new Scanner(System.in);

        Hash tabela_hash = new Hash();

        String ids;
        boolean continua = true;

        while(continua){

            ids = sc.nextLine();
            
            if(ids.equals("FIM")){
                continua = false;

            }else{
                int id = Integer.parseInt(ids);

                String nome  = nomePokemon(id);

                int valor = ASCII_name(nome);

                tabela_hash.inserir(valor);
            }
        }

        continua = true;
        String newName;

        while(continua){

            newName = sc.nextLine();

            if(newName.equals("FIM")){
                continua = false;

            }else{
                System.out.print("=> " + newName + ": ");
                int valor_ascii = ASCII_name(newName);
                int achou = tabela_hash.pesquisar(valor_ascii);

                if(achou == (-1)){
                    System.out.println("NAO");
                    tabela_hash.inserir(valor_ascii);
                    
                }else{
                    System.out.println("(Posicao: " + achou +  ") SIM");
                }
            }
        }
        
        sc.close();
    }
}
