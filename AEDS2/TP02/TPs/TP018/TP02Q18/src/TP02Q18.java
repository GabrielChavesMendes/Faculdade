import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayList;

public class TP02Q18{

    static class Pokemon {
        private int[] id;
        private String[] name;
        private int[] generation;

        Pokemon(int size) {
            this.id = new int[size];
            this.name = new String[size];
            this.generation = new int[size];
        }

        public void setId(int index, int id) {
            this.id[index] = id;
        }

        public void setName(int index, String name) {
            this.name[index] = name;
        }

        public void setGeneration(int index, int generation) {
            this.generation[index] = generation;
        }

        public int getId(int index) {
            return id[index];
        }

        public String getName(int index) {
            return name[index];
        }

        public int getGeneration(int index) {
            return generation[index];
        }
    }

    private static void swap(int[] taxa, String[] nomes, int i, int j) {
        int tempTaxa = taxa[i];
        taxa[i] = taxa[j];
        taxa[j] = tempTaxa;

        String tempNome = nomes[i];
        nomes[i] = nomes[j];
        nomes[j] = tempNome;
    }

    public static void Ordena(int[] taxa, String[] nomes, int esq, int dir) {
        int i = esq, j = dir;
        int pivo = taxa[(esq + dir) / 2];
        String pivoNome = nomes[(esq + dir) / 2];

        while (i <= j) {
            while (taxa[i] < pivo || (taxa[i] == pivo && nomes[i].compareTo(pivoNome) < 0)) {
                i++;
            }
            while (taxa[j] > pivo || (taxa[j] == pivo && nomes[j].compareTo(pivoNome) > 0)) {
                j--;
            }
            if (i <= j) {
                swap(taxa, nomes, i, j);
                i++;
                j--;
            }
        }
        if (esq < j) {
            Ordena(taxa, nomes, esq, j);
        }
        if (i < dir) {
            Ordena(taxa, nomes, i, dir);
        }
    }

    public static Pokemon QuickSort(int[] ids){
        
        String pokemonFile = "/tmp/pokemon.csv"; 
        String linha = "";
        Pokemon poke = new Pokemon(200);
        int i = 0;

        try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))){ 
            
            leitura.readLine();

            while((linha = leitura.readLine()) != null){ 
                
                String[] pokemon = linha.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");
            
                if (pokemon.length >= 11) {
                    int id = Integer.parseInt(pokemon[0].trim().replace("\"", ""));  
                    int generation = Integer.parseInt(pokemon[1].trim().replace("\"", ""));       
                    String name = pokemon[2].trim().replace("\"", "");     
                    
                    for (int id_arq : ids) {
                        if (id == id_arq){
                            poke.setId(i, id);
                            poke.setName(i, name);
                            poke.setGeneration(i, generation);
                            i++;
                        }
                    }
                }
            }              
        } catch (IOException e) {
            e.printStackTrace();
        }

        Ordena(poke.generation, poke.name, 0, i - 1);
        return poke;
    }

    static void Imprimi(Pokemon ordenado) {
        String pokemonFile = "/tmp/pokemon.csv"; 
        String linha = "";
        double weight = 0;
        double height = 0;
        int captureRate = 0;
        int isLegendary = 0;
        String lendario = "";

        int k = 10; // Limitador da ordenacao parcial
    
        try {
            for (int i = 0; i < k; i++) {
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

        Pokemon ordenado = QuickSort(poke.id);

        Imprimi(ordenado);

        sc.close();
    }
}
