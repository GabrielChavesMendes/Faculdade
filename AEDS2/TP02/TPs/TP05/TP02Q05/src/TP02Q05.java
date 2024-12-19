import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayList;

public class TP02Q05{

    static class Pokemon {
        private int[] id;
        private String[] name;

        Pokemon(int size) {
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


    public static void swap(String[] nomes, int i, int j){
        String temp = nomes[i];
        nomes[i] = nomes[j];
        nomes[j] = temp;
    }

    public static void Ordena(String[] nomes, int num){

        for (int i = 0; i < num; i++){
            int menor = i;
           
            for (int j = (i + 1); j < num; j++){
                if (nomes[menor].compareTo(nomes[j]) > 0){
                    menor = j;
                }
            }
            swap(nomes, menor, i);
        }
           
    }

    public static Pokemon Selecao(int[] ids){
        
        String pokemonFile = "/tmp/pokemon.csv"; 
        String linha = "";
        Pokemon poke = new Pokemon(200);
        int i = 0;

        try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))){ 
            
            leitura.readLine();

            while((linha = leitura.readLine()) != null){ 
                
                String[] pokemon = linha.split(",");
            
                if (pokemon.length >= 11) {
                    int id = Integer.parseInt(pokemon[0].trim().replace("\"", ""));  
                    String generation = pokemon[1].trim();        
                    String name = pokemon[2].trim().replace("\"", "");              
                    
                    for (int id_arq : ids) {
                        if (id == id_arq){
                            poke.setId(i, id);
                            poke.setName(i, name);
                            i++;
                        }
                    }
                }
            }              
        } catch (IOException e) {
            e.printStackTrace();
        }

        Ordena(poke.name, i);
        return poke;
    }

    static void Imprimi(Pokemon ordenado, int tam) {
        String pokemonFile = "/tmp/pokemon.csv"; 
        String linha = "";
        double weight = 0;
        double height = 0;
        int captureRate = 0;
        int isLegendary = 0;
        String lendario = "";
    
        try {
            for (int i = 0; i < tam; i++) {
                String name_arq = ordenado.getName(i).trim(); 
    
                try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))) { 
                    leitura.readLine(); 
    
                    while ((linha = leitura.readLine()) != null) { 
                        String[] pokemon = linha.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");
    
                        if (pokemon.length >= 10) {
                            String name = pokemon[2].replace("\"", "").trim(); 
    
                            if (name.equalsIgnoreCase(name_arq)){
                                String generation = pokemon[1];
                                int geracao = Integer.parseInt(generation);

                                String description = pokemon[3];

                                ArrayList<String> types = new ArrayList<>();
                                if (!pokemon[4].isEmpty()) {
                                    types.add("'" + pokemon[4].trim() + "'");
                                }
                                
                                if (!pokemon[5].isEmpty()) {
                                    types.add("'" + pokemon[5].trim() + "'");
                                }
    
                                String abilities = pokemon[6].trim(); 
                                String habilidade = abilities.substring(1, abilities.length() - 1);
    
                                try {
                                    if(pokemon[7].isEmpty()){
                                        weight = 0.0;
                                    }else{
                                        weight = Double.parseDouble(pokemon[7].trim());
                                    }
                                } catch (NumberFormatException e) {
                                    System.out.println("Erro ao converter o peso para double: " + pokemon[7]);
                                }
                                
                                try {
                                    if(pokemon[8].isEmpty()){
                                        height = 0.0;
                                    }else{
                                        height = Double.parseDouble(pokemon[8].trim());     
                                    }
                                } catch (NumberFormatException e) {
                                    System.out.println("Erro ao converter a altura para double: " + pokemon[8]);
                                }
                                
                                captureRate = Integer.parseInt(pokemon[9].trim());                                 
    
                                isLegendary = Integer.parseInt(pokemon[10].trim()); 
                                if(isLegendary == 1){
                                    lendario = "true";
                                }else if(isLegendary == 0){
                                    lendario = "false";
                                }

                                String date = pokemon[11].trim();
    
                                String typesString = String.join(", ", types);
    
                                System.out.println("[#" + pokemon[0] + " -> " + name + ": " + description + " - [" + typesString +
                                "] - " + habilidade + " - " + weight + "kg - " + height + "m - " + captureRate + "% - " + lendario + " - " 
                                + geracao + " gen] - " + date);
                                
                            }
                        }
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);

        String id;
        int i = 0;
        Pokemon poke = new Pokemon(200);
        boolean verdade = true;

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

        Pokemon ordenado = Selecao(poke.id);

        Imprimi(ordenado, i);

        sc.close();
    }
}
