import java.util.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class TP1Q01 {

    static class Lista {
        int[] array;
        int n;
        Lista () { 
            this(100); 
        }
        Lista (int tamanho){
            array = new int[tamanho];
            n = 0;
        }
        
        void inserirInicio(int x) throws Exception {
            if (n >= array.length)
            throw new Exception("Erro!");
            //levar elementos para o fim do array

            for (int i = n; i > 0; i--){
                array[i] = array[i-1];
            }
            array[0] = x;
            n++;
        }
        
        void inserirFim(int x) throws Exception {

            if (n >= array.length)
            throw new Exception("Erro!");
              
            array[n] = x;
            n++;
        }
           
       void inserir(int pos, int x) throws Exception{ 

            if (n >= array.length)
            throw new Exception("Erro!");
            //levar elementos para o fim do array
              
            for (int i = n; i > pos; i--){
                array[i] = array[i-1];
            }
            array[pos] = x;
            n++;
        }
        
        int removerInicio() throws Exception {

            if (n == 0)
            throw new Exception("Erro!");
            int resp = array[0];
            n--;
                         
            for (int i = 0; i < n; i++){
                array[i] = array[i+1];
            }
            return resp;
        }      
        
        int removerFim() throws Exception {
            if (n == 0)
            throw new Exception("Erro!");
                      
            int resp = array[n - 1];  
            n--;  
            return resp;  
        }       
        
        int remover(int pos, int tam) throws Exception {

            if (n == 0 || pos < 0){
            throw new Exception("Erro!");
            }
            int resp = array[pos];
            n--;
            
            for (int i = pos; i < n; i++){
                array[i] = array[i+1];
            }
            return resp;
        }           
    }

    static void Imprimi(Lista lista, int cont) {
        String pokemonFile = "/tmp/pokemon.csv";
        String linha;
        double weight = 0;
        double height = 0;
        int captureRate = 0;
        int isLegendary = 0;
        String lendario = "";
        int k = 0;

        for(int i = 0; i < cont; i++){

                try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))) {
                    leitura.readLine(); // Ignorar cabeçalho
                
                while ((linha = leitura.readLine()) != null) {
                    String[] pokemon = linha.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");      

                    if (pokemon.length >= 10) {
                        String id_arq = pokemon[0];
                        int id_poke = Integer.parseInt(id_arq);

                        if(lista.array[i] == id_poke){
                            String name = pokemon[2].replace("\"", "").trim(); 
                        
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
    
                            System.out.println("[" + k + "]" + " [#" + pokemon[0] + " -> " + name + ": " + description + " - [" + typesString +
                            "] - " + habilidade + " - " + weight + "kg - " + height + "m - " + captureRate + "% - " + lendario + " - " 
                            + geracao + " gen] - " + date);

                            k++;
                        }  
                     }
                    
                } 
            } catch (IOException e) {
                e.printStackTrace();
            }
        }   
    }

    static int Escolhas(Lista lista, String[] comandos, int quant, int cont) throws Exception{
        
        ArrayList<Integer> removido = new ArrayList<>();

        for (int i = 0; i < quant; i++) {
            String[] partes = comandos[i].split(" ");
            String parte1 = partes[0];

            /*for(int j = 0; j < cont; j++){
                System.out.print(lista.array[j] + ", ");
            }
            System.out.println();*/

            if (parte1.equals("RI")) {
                if (cont > 0) {
                    removido.add(lista.removerInicio());
                    cont--;
                } else {
                    System.out.println("Lista vazia, não é possível remover do início.");
                }
            } else if (parte1.equals("RF")) {
                if (cont > 0) {
                    removido.add(lista.removerFim());
                    cont--;
                } else {
                    System.out.println("Lista vazia, não é possível remover do fim.");
                }
            } else if (partes.length > 1) {
                int parte2 = Integer.parseInt(partes[1]);
                int parte3 = 0;

                if (parte1.equals("I*")) {
                    parte3 = Integer.parseInt(partes[2]);
                }

                switch (parte1) {
                    case "II":
                        lista.inserirInicio(parte2);
                        cont++;
                        break;
                    case "I*":
                        if (parte2 >= 0 && parte2 <= cont) { 
                            lista.inserir(parte2, parte3);
                            cont++;
                        } else {
                            System.out.println("Posição de inserção inválida: " + parte3);
                        }
                        break;
                    case "IF":
                        lista.inserirFim(parte2);
                        cont++;
                        break;
                    case "R*":
                        if (parte2 >= 0 && parte2 < cont) { 
                            removido.add(lista.remover(parte2, cont));
                            cont--;
                        } else {
                            System.out.println("Posição de remoção inválida: " + parte2);
                        }
                        break;
                    default:
                        System.out.println("Comando inválido: " + comandos[i]);
                        break;
                }
            } else {
                System.out.println("Comando inválido: " + comandos[i]);
            }
        }

        
        
        String pokemonFile = "/tmp/pokemon.csv";
        String linha;

        /*for(int idremove : removido){
            System.out.print(idremove + ", ");
        }*/

        for(int idRemovido : removido){

            try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))) {
                leitura.readLine(); // Ignorar cabeçalho
            
            while ((linha = leitura.readLine()) != null) {
                String[] pokemon = linha.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");      

                if (pokemon.length >= 10) {
                    String id_arq = pokemon[0];
                    int id_poke = Integer.parseInt(id_arq);

                    if(idRemovido == id_poke){
                        String name = pokemon[2].replace("\"", "").trim(); 
                    
                        System.out.println("(R) " + name);
                    }  
                 }      
                } 
            } catch (IOException e) {
                e.printStackTrace();
            }
        } 

        return cont;
    }
       
    public static void main(String[] args) throws Exception {
        
        Lista lista = new Lista();
        
        Scanner sc = new Scanner(System.in);
        
        String num;
        boolean continua = true;
        int j = 0;

        while(continua){
            num = sc.nextLine();

            if(num.equals("FIM")){
                continua = false;
            }else{
                
                int num_alt = Integer.parseInt(num);
                lista.array[j] = num_alt;

                j++;
            }
        }

        lista.n = j;
        int quant;
        quant = sc.nextInt();
        sc.nextLine();
        
        String x;
        String[] comandos = new String[quant];

        for(int i = 0; i < quant; i++){
            x = sc.nextLine();

            comandos[i] = x;
        }
        
        int cont = Escolhas(lista, comandos, quant, j);

        Imprimi(lista, cont);

        sc.close();
    }
}
