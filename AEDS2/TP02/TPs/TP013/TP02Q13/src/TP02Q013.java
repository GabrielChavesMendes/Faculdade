import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayList;

public class TP02Q013{

    static class Pokemon {
        private int[] id;
        private String[] name;
        private String[] types;

        Pokemon(int size) {
            this.id = new int[size];
            this.name = new String[size];
            this.types = new String[size];
        }

        public void setId(int index, int id) {
            this.id[index] = id;
        }

        public void setName(int index, String name) {
            this.name[index] = name;
        }

        public void setTypes(int index, String types) {
            this.types[index] = types;
        }

        public int getId(int index) {
            return id[index];
        }

        public String getName(int index) {
            return name[index];
        }

        public String getTypes(int index) {
            return types[index];
        }
    }

    public static void Ordena(String[] tipos, String[] names, int esq, int dir){
        
        if (esq < dir){
            int meio = (esq + dir) / 2;
            Ordena(tipos, names, esq, meio);
            Ordena(tipos, names, meio + 1, dir);
            Intercalar(tipos, names, esq, meio, dir);
            }    
    }

    public static void Intercalar(String[] tipos, String[] names, int esq, int meio, int dir){
        //Defini tamanho dos dois subarrays
        int nEsq = (meio+1)-esq;
        int nDir = dir - meio;
        
        String[] arrayEsq_Tipos = new String[nEsq + 1];
        String[] arrayDir_Tipos = new String[nDir + 1];
        String[] arrayEsq_Nomes = new String[nEsq + 1];
        String[] arrayDir_Nomes = new String[nDir + 1];

        //Sentinela no final dos dois arrays
        arrayEsq_Tipos[nEsq] = arrayDir_Tipos[nDir] = "zzzzzz";  
        arrayEsq_Nomes[nEsq] = arrayDir_Nomes[nDir] = ""; 

        //Inicializar o primeiro subarray
        for (int iEsq = 0; iEsq < nEsq; iEsq++) {
            arrayEsq_Tipos[iEsq] = tipos[esq + iEsq];
            arrayEsq_Nomes[iEsq] = names[esq + iEsq];
        }
        
        //Inicializar o segundo subarray
        for (int iDir = 0; iDir < nDir; iDir++) {
            arrayDir_Tipos[iDir] = tipos[(meio + 1) + iDir];
            arrayDir_Nomes[iDir] = names[(meio + 1) + iDir];
        }
        
        // Intercalando os subarrays
        int iEsq = 0, iDir = 0;
        for (int i = esq; i <= dir; i++) {
            //Compara para ver se os elementos de cada subarray sao iguais
            if(arrayEsq_Tipos[iEsq].compareTo(arrayDir_Tipos[iDir]) == 0) {
                //Compara os nomes para ordenar lexicalmente 
                if(arrayEsq_Nomes[iEsq].compareTo(arrayDir_Nomes[iDir]) > 0){
                    tipos[i] = arrayDir_Tipos[iDir];
                    names[i] = arrayDir_Nomes[iDir];
                    iDir++;
                }else{
                    tipos[i] = arrayEsq_Tipos[iEsq];
                    names[i] = arrayEsq_Nomes[iEsq];
                    iEsq++;
                }
            }else{
                if (arrayEsq_Tipos[iEsq].compareTo(arrayDir_Tipos[iDir]) < 0) {
                    tipos[i] = arrayEsq_Tipos[iEsq];
                    names[i] = arrayEsq_Nomes[iEsq];
                    iEsq++;
                } else {
                    tipos[i] = arrayDir_Tipos[iDir];
                    names[i] = arrayDir_Nomes[iDir];
                    iDir++;
                }
            } 
        }
    }

    public static Pokemon MergeSort(int[] ids){
        
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
                    String name = pokemon[2].trim().replace("\"", "");     
                    String types =  pokemon[4].trim();                                    
                    
                    for (int id_arq : ids) {
                        if (id == id_arq){
                            poke.setId(i, id);
                            poke.setName(i, name);
                            poke.setTypes(i, types);
                            i++;
                        }
                    }
                }
            }              
        } catch (IOException e) {
            e.printStackTrace();
        }

        Ordena(poke.types, poke.name, 0, i - 1);
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

        Pokemon ordenado = MergeSort(poke.id);

        Imprimi(ordenado, i);

        sc.close();
    }
}
