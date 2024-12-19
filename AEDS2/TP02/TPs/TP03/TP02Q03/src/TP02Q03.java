import java.util.Scanner;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class TP02Q03 {

    static class Pokemon{
        private int[] id;
        private String[] name;

        Pokemon(int size){
            this.id = new int[size];
            this.name = new String[size];
        }

        public void setId(int index, int id) {
            this.id[index] = id;
        }

        public void setName(int index, String name) {
            this.name[index] = name;
        }

        public int getId(int index) {
            return id[index];
        }

        public String getName(int index) {
            return name[index];
        }
    }

    public static boolean Verifica(String nome, int[] ids){
        
        String pokemonFile = "/tmp/pokemon.csv"; 
        String linha = "";
        boolean achou = false;

        try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))){ 
            
            //Pula primeira linha
            leitura.readLine();

            while((linha = leitura.readLine()) != null){ 
                
                String[] pokemon = linha.split(",", 4);
            
                if (pokemon.length >= 3){
                    
                    int id = Integer.parseInt(pokemon[0].trim().replace("\"", ""));  
                    String generation = pokemon[1].trim();        
                    String name = pokemon[2].trim().replace("\"", "");              
                    
                    if (name.equals(nome)){                    
                        for (int inputId : ids) {
                            if (id == inputId) {
                                return true;  
                            }
                        }
                    }
                }              
            }                             
        } catch (IOException e) {
            e.printStackTrace();
        }
        
        return achou;
    }


    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);

        String id;
        String pokemon;
        int i = 0;

        Pokemon poke = new Pokemon(200);

        boolean verdade = true;
        boolean achou;

        while (verdade) {
            id = sc.nextLine();

            if (id.equals("FIM")) {
                verdade = false;
            } else {
                int num = Integer.parseInt(id);
                poke.setId(i, num); 
                i++;
            }
        }

        verdade = true;
        i = 0;

        while (verdade) {
            pokemon = sc.nextLine();

            if (pokemon.equals("FIM")) {
                verdade = false;
            } else {
                poke.setName(i, pokemon);  
                achou = Verifica(poke.getName(i), poke.id);
                if(achou == true){
                    System.out.println("SIM");
                }else if(achou == false){
                    System.out.println("NAO");
                }
                i++;  
            }
        }
 
        sc.close();
    }
}
