import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayList;

public class TP02Q011{

    static class Pokemon {
        private int[] id;
        private String[] name;
        private int[] captureRate;

        Pokemon(int size) {
            this.id = new int[size];
            this.name = new String[size];
            this.captureRate = new int[size];
        }

        public void setId(int index, int id) {
            this.id[index] = id;
        }

        public void setName(int index, String name) {
            this.name[index] = name;
        }

        public void setCaptureRate(int index, int captureRate) {
            this.captureRate[index] = captureRate;
        }

        public int getId(int index) {
            return id[index];
        }

        public String getName(int index) {
            return name[index];
        }

        public int getCaptureRate(int index) {
            return captureRate[index];
        }
    }

    public static int getMaior(int[] array, int num) {
        int maior = array[0];
        for (int i = 1; i < num; i++) {
            if (array[i] > maior) {
                maior = array[i];
            }
        }
        return maior;
    }

    public static void Ordena(int[] taxa, String[] names, int num) {

        int max = getMaior(taxa, num); 
        int[] count = new int[max + 1]; 
        int[] taxa_captura = new int[num]; 
        String[] nomes_aqr = new String[num];
    
        //Inicializa o array com 0
        for (int i = 0; i <= max; i++) {
            count[i] = 0;
        }
    
        //Preenche o array com a contagem de ocorrencia
        for (int i = 0; i < num; i++) {
            count[taxa[i]]++;
        }
    
        //Soma cumulativa para o array de contagem
        for (int i = 1; i <= max; i++) {
            count[i] += count[i - 1];
        }
    
        //Ordena usando Counting Sort
        for (int i = num - 1; i >= 0; i--) {
            int pos = count[taxa[i]] - 1;  
            taxa_captura[pos] = taxa[i];
            nomes_aqr[pos] = names[i];
            count[taxa[i]]--;  
        }
    
        for (int i = 0; i < num - 1; i++) { //Comeca a varrer o array novamente
            if (taxa_captura[i] == taxa_captura[i + 1]) { //Procurando as taxas iguais
                int start = i; //Guarda onde a taxa for igual primeiramente
                while (i < num - 1 && taxa_captura[i] == taxa_captura[i + 1]) { //Incrementa +1 ate que a taxa passe a ser diferente
                    i++;
                }
                Ordena_nomes(nomes_aqr, taxa_captura, start, i);
            }
        }
    
        for (int i = 0; i < num; i++) {
            taxa[i] = taxa_captura[i];
            names[i] = nomes_aqr[i];
        }
    }
    
    private static void Ordena_nomes(String[] nomes_aqr, int[] taxa_captura, int start, int end) {
        for (int i = start; i <= end; i++) { //Comeca onde foi encontrado a primeira taxa ate a ultima, em que ambas sao iguais
            for (int j = i + 1; j <= end; j++) {
                if (nomes_aqr[i].compareTo(nomes_aqr[j]) > 0) { //Compara os nomes lexicalmente 
                    //Troca os nomes de posicao 
                    String tempNome = nomes_aqr[i];
                    nomes_aqr[i] = nomes_aqr[j];
                    nomes_aqr[j] = tempNome;
                    //Troca as taxas de posicao
                    int tempTaxa = taxa_captura[i];
                    taxa_captura[i] = taxa_captura[j];
                    taxa_captura[j] = tempTaxa;
                }
            }
        }
    }

    public static Pokemon CountingSort(int[] ids){
        
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
                    String generation = pokemon[1].trim();        
                    String name = pokemon[2].trim().replace("\"", "");     
                    int taxa = Integer.parseInt(pokemon[9].trim());         
                    
                    for (int id_arq : ids) {
                        if (id == id_arq){
                            poke.setId(i, id);
                            poke.setName(i, name);
                            poke.setCaptureRate(i, taxa);;
                            i++;
                        }
                    }
                }
            }              
        } catch (IOException e) {
            e.printStackTrace();
        }

        Ordena(poke.captureRate, poke.name, i);
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

        Pokemon ordenado = CountingSort(poke.id);

        Imprimi(ordenado, i);

        sc.close();
    }
}
