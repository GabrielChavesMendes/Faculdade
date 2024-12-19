import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.sql.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Scanner;

public class TP02Q01 {

    //Atributos privados
    static class Pokemon {
        private int id;
        private int generation;
        private String name;
        private String description;
        private ArrayList<String> types = new ArrayList<>();
        private ArrayList<String> abilities = new ArrayList<>();
        private double weight;
        private double height;
        private int captureRate;
        private boolean isLegendary;
        private Date captureDate;

        //Primeiro construtor
        Pokemon(int id, int generation, String name, String description, ArrayList<String> types, ArrayList<String> abilities, double weight, double height, int captureRate, boolean isLegendary, Date captureDate) {
            this.id = id;
            this.generation = generation;
            this.name = name;
            this.description = description;
            this.types = types;
            this.abilities = abilities;
            this.weight = weight;
            this.height = height;
            this.captureRate = captureRate;
            this.isLegendary = isLegendary;
            this.captureDate = captureDate;
        }

        //Segundo construtor
        Pokemon() {
            this.id = 0;
            this.generation = 0;
            this.name = "";
            this.description = "";
            this.types = new ArrayList<>();
            this.abilities = new ArrayList<>();
            this.weight = 0.0;
            this.height = 0.0;
            this.captureRate = 0;
            this.isLegendary = false;
            this.captureDate = null;
        }

        //Metodos getters e setters
        public int getId() {
            return id;
        }

        public void setId(int id) {
            this.id = id;
        }

        public int getGeneration() {
            return generation;
        }

        public void setGeneration(int generation) {
            this.generation = generation;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getDescription() {
            return description;
        }

        public void setDescription(String description) {
            this.description = description;
        }

        public ArrayList<String> getTypes() {
            return types;
        }

        public void setTypes(ArrayList<String> types) {
            this.types = types;
        }

        public ArrayList<String> getAbilities() {
            return abilities;
        }

        public void setAbilities(ArrayList<String> abilities) {
            this.abilities = abilities;
        }

        public double getWeight() {
            return weight;
        }

        public void setWeight(double weight) {
            this.weight = weight;
        }

        public double getHeight() {
            return height;
        }

        public void setHeight(double height) {
            this.height = height;
        }

        public int getCaptureRate() {
            return captureRate;
        }

        public void setCaptureRate(int captureRate) {
            this.captureRate = captureRate;
        }

        public boolean isLegendary() {
            return isLegendary;
        }

        public void setLegendary(boolean legendary) {
            isLegendary = legendary;
        }

        public Date getCaptureDate() {
            return captureDate;
        }

        public void setCaptureDate(Date captureDate) {
            this.captureDate = captureDate;
        }

        //Metodo Imprimir 
        void Imprimir(){
            SimpleDateFormat dataSaida = new SimpleDateFormat("dd/MM/yyyy");
            String dataFormatada = captureDate != null ? dataSaida.format(captureDate) : "Data não disponível";
            System.out.println("[#" + getId() + " -> " + getName() + ": " + getDescription() + " - " + getTypes() + " - " + getAbilities() + " - " + getWeight() + "kg - " + getHeight() + "m - " + getCaptureRate() + "% - " + isLegendary() + " - " + getGeneration() + " gen] - " + dataFormatada);
        }

        //Metodo para Ler o arquivo CSV
        void Ler(int num) {
            String pokemonFile = "/tmp/pokemon.csv"; //String para receber o caminho do arquivo
            String linha = "";

            try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))){ //Tenta abrir o arquivo para leitura
                
                //Pula primeira linha
                leitura.readLine();

                while((linha = leitura.readLine()) != null){ //Le linha por linha ate o final do arquivo
                            
                    String[] pokemon = linha.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");

                    //Faz a conversao de String para um inteiro
                    int pokemon_Id = Integer.parseInt(pokemon[0]);

                    //Se o ID do pokemon atual for igual ao numero digitado
                    if(pokemon_Id == num){
                        //Atribui por meio das funcoes setters cada elemento a sua variavel respectivamente
                        setId(Integer.parseInt(pokemon[0]));
                        setGeneration(Integer.parseInt(pokemon[1]));
                        setName(pokemon[2]);
                        setDescription(pokemon[3]);

                        //Limpa os ArrayList a cada iteracao
                        getTypes().clear();
                        getAbilities().clear();

                        //Atribui aos ArrayList as determinadas informacoes
                        if (!pokemon[4].isEmpty()){ //Verifica se nao esta vazio
                            getTypes().add("'" + pokemon[4] + "'");
                        }
                        
                        if (!pokemon[5].isEmpty()){ //Verifica se nao esta vazio
                            getTypes().add("'" + pokemon[5] + "'");
                        }

                        //Se estiver na coluna 6 e existir 
                        if(pokemon.length > 6 && !pokemon[6].isEmpty()){
                            //Se ouver habilidades, remove os colchetes, apostrofes e aspas duplas deixando apenas a habilidade e atribuindo a um array de habilidades
                            String habilidades = pokemon[6].replace("[", "").replace("]", "").replace("'", "").replace("\"", "");
                            String[] habilidades_array = habilidades.split(", ");
                            
                            //Enquanto existir habilidades no array vai atribuir ao ArrayList de habilidades
                            for (String hab : habilidades_array) {
                                getAbilities().add("'" + hab + "'");
                            }
                        }

                        //Para cada if seguinte, confere se esta no inidice adequado e se nao esta vazio
                        //Se sim, atribui a variavel correspondente por meio do set, fazendo a conversao para o tipo adequado
                        if(pokemon.length > 7 && !pokemon[7].isEmpty()){
                            setWeight(Double.parseDouble(pokemon[7]));
                        }

                        if(pokemon.length > 8 && !pokemon[8].isEmpty()){
                            setHeight(Double.parseDouble(pokemon[8]));                           
                        }

                        if(pokemon.length > 9 && !pokemon[9].isEmpty()){
                            setCaptureRate(Integer.parseInt(pokemon[9]));                            
                        }

                        if(pokemon.length > 10 && !pokemon[10].isEmpty()){
                            //Compara com 1, caso sim sera true, caso nao sera false
                            setLegendary(Integer.parseInt(pokemon[10]) == 1);                            
                        }

                        if(pokemon.length > 11 && !pokemon[11].isEmpty()){
                            //Altera o formato de leitura para a variavel Date
                            SimpleDateFormat dataSaida = new SimpleDateFormat("dd/MM/yyyy");
                           
                            //Tratamento de erro caso nao consiga ler a data corretamente 
                            try {
                                Date data = new Date(dataSaida.parse(pokemon[11]).getTime());
                                setCaptureDate(data);
                            } catch (ParseException e) {
                                System.out.println("Erro ao converter pokemon: " + e.getMessage());
                            }
                        }

                        Imprimir();
                        return;
                    }                    
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        
        boolean verdade = true;

        while(verdade){
            String entrada = sc.next();

            if (entrada.equals("FIM")) {
                verdade = false;
            }else{
                //Converte a String em um inteiro
                int num = Integer.parseInt(entrada);

                Pokemon pokemon = new Pokemon();
    
                pokemon.Ler(num); 
            }            
        }
        sc.close();
    }
}
