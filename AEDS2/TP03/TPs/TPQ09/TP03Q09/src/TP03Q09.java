import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

//Celula (pilha, lista e fila dinamica)
class Celula {
	public int elemento; // Elemento inserido na celula.
	public Celula prox; // Aponta a celula prox.


	// Construtor da classe.
	public Celula() {
		this(0);
	}

	// Construtor da classe.
	public Celula(int elemento) {
      this.elemento = elemento;
      this.prox = null;
	}
}

//Pilha dinamica
class Pilha {
	private Celula topo;
    private int k;

	// Construtor da classe que cria uma fila sem elementos.
	public Pilha() {
		topo = null;
        k = 0;
	}

	//Insere elemento na pilha (politica FILO).
	public void inserir(int x) {
		Celula tmp = new Celula(x);
		tmp.prox = topo;
		topo = tmp;
		tmp = null;
	}

	//Remove elemento da pilha (politica FILO).
	public int remover() throws Exception {
		if (topo == null) {
			throw new Exception("Erro ao remover!");
		}
		int resp = topo.elemento;
		Celula tmp = topo;
		topo = topo.prox;
		tmp.prox = null;
		tmp = null;
		return resp;
	}

    private void mostrarRecursivo(Celula celula) {
        if (celula != null) {
            mostrarRecursivo(celula.prox);  
            pegaPokemon(celula.elemento, k);
            k++; 
        }
    }

	//Mostra os elementos separados por espacos, comecando do topo.
	public void mostrar() {	
        k = 0;
        mostrarRecursivo(topo);
	}

    private void pegaPokemon(int id_pilha, int k) {
        
        String pokemonFile = "/tmp/pokemon.csv";
        String linha;
        double weight = 0;
        double height = 0;
        int captureRate = 0;
        int isLegendary = 0;
        String lendario = "";

        try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))) {
            leitura.readLine(); // Ignorar cabeçalho
            
            while ((linha = leitura.readLine()) != null) {
                String[] pokemon = linha.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");      

                if (pokemon.length >= 10) {
                    String id_arq = pokemon[0];
                    int id_poke = Integer.parseInt(id_arq);

                    if(id_pilha == id_poke){
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

public class TP03Q09 {

    static class Armazena{
        private int quant;
        private ArrayList<Integer> removidos;

        public Armazena(){
            this.quant = 0;
            this.removidos = new ArrayList<>();
        }

        void setQuant(int quant){
            this.quant = quant;
        }

        int getQuant(){
            return this.quant;
        }

        void setRemovidos(int valor){
            this.removidos.add(valor);
        }

        public ArrayList<Integer> getRemovidos(){
            return removidos;
        }
    }

    static void Escolhas(String[] comando, int cont, Armazena armazena, Pilha pilha) throws Exception{
        
        ArrayList<Integer> removido = new ArrayList<>();

        for(int i = 0; i < armazena.getQuant(); i++){
            String[] partes = comando[i].split(" ");
            String parte1 = partes[0];

            if (parte1.equals("R")) {
                int remove = pilha.remover();
                armazena.setRemovidos(remove);
                cont--;

            } else if (partes.length > 1) {
                int parte2 = Integer.parseInt(partes[1]);

                if (parte1.equals("I")) {
                    pilha.inserir(parte2);
                    cont++;
                }

            }
        }

        for(int removendo : removido){
            System.out.print(removendo + ", ");
        }
        
        String pokemonFile = "/tmp/pokemon.csv";
        String linha;

        for(int idRemovido : armazena.getRemovidos()){

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
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        Pilha pilha = new Pilha();
        Armazena armazena = new Armazena();

        boolean verdade = true;
        String num;
        int valor;
        int cont = 0;

        while(verdade){
            num = sc.nextLine();

            if(num.equals("FIM")){
                verdade = false;
            }else{
                valor = Integer.parseInt(num);
                pilha.inserir(valor);
                cont++;
            }
        }

        int quant = sc.nextInt();
        sc.nextLine();
        armazena.setQuant(quant);

        String[] comando = new String[quant];

        for(int i = 0; i < armazena.getQuant(); i++){
            comando[i] = sc.nextLine();
        }

        Escolhas(comando, cont, armazena, pilha);

        pilha.mostrar();

        sc.close();
    }
}
