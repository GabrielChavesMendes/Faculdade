import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

//Celula Dupla (lista dupla dinamica)
class CelulaDupla {
	public int elemento;
	public CelulaDupla ant;
	public CelulaDupla prox;

	//Construtor da classe.
	public CelulaDupla() {
		this(0);
	}


	//Construtor da classe.
	public CelulaDupla(int elemento) {
		this.elemento = elemento;
		this.ant = this.prox = null;
	}
}

//Lista dupla dinamica
class ListaDupla {
	private CelulaDupla primeiro;
	private CelulaDupla ultimo;

	//Construtor da classe que cria uma lista dupla sem elementos (somente no cabeca).
	public ListaDupla() {
		primeiro = new CelulaDupla();
		ultimo = primeiro;
	}

	//Insere um elemento na ultima posicao da lista.
	public void inserirFim(int x) {
		ultimo.prox = new CelulaDupla(x);
      ultimo.prox.ant = ultimo;
		ultimo = ultimo.prox;
	}

	// Mostra os elementos da lista separados por espacos.
	public void mostrar() {

        String pokemonFile = "/tmp/pokemon.csv";
        String linha;
        double weight = 0;
        double height = 0;
        int captureRate = 0;
        int isLegendary = 0;
        String lendario = "";

		for (CelulaDupla i = primeiro.prox; i != null; i = i.prox) {
			try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))) {
                leitura.readLine(); // Ignorar cabeçalho
                
                while ((linha = leitura.readLine()) != null) {
                    String[] pokemon = linha.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");      
    
                    if (pokemon.length >= 10) {
                        String id_arq = pokemon[0];
                        int id_poke = Integer.parseInt(id_arq);
    
                        if(i.elemento == id_poke){
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
	}

    public boolean pesquisar(int x) {
		boolean resp = false;
		for (CelulaDupla i = primeiro.prox; i != null; i = i.prox) {
            if(i.elemento == x){
                resp = true;
                i = ultimo;
            }
		}
		return resp;
	}

    public void atualizar(int[] ids) {
        CelulaDupla atual = primeiro.prox;
        for (int id : ids) {
            if (atual != null) {
                atual.elemento = id;
                atual = atual.prox;
            }
        }
    }
}

// Classe para armazenar dados
class Armazena {
    private String[] nomes;
    private int[] geracao;
    private int[] ids;

    public Armazena(int quant) {
        this.nomes = new String[quant];
        this.geracao = new int[quant];
        this.ids = new int[quant];
    }

    public void setNomes(String nome, int i) {
        this.nomes[i] = nome;
    }

    public void setGeracao(int geracao, int i) {
        this.geracao[i] = geracao;
    }

    public void setId(int id, int i) {
        this.ids[i] = id;
    }

    public String getNome(int i) {
        return this.nomes[i];
    }

    public int getGeracao(int i) {
        return this.geracao[i];
    }

    public int getId(int i) {
        return this.ids[i];
    }

    public int[] getIds() {
        return this.ids;
    }

    public int tamanho() {
        return this.ids.length;
    }
}

public class TP03Q10 {

     static void swap(Armazena armazena, int i, int j) {
        String tempNome = armazena.getNome(i);
        armazena.setNomes(armazena.getNome(j), i);
        armazena.setNomes(tempNome, j);

        int tempGeracao = armazena.getGeracao(i);
        armazena.setGeracao(armazena.getGeracao(j), i);
        armazena.setGeracao(tempGeracao, j);

        int tempId = armazena.getId(i);
        armazena.setId(armazena.getId(j), i);
        armazena.setId(tempId, j);
    }

    static void QuickSort(Armazena armazena, int esq, int dir) {
        int i = esq, j = dir;
        int pivoGeracao = armazena.getGeracao((esq + dir) / 2);
        String pivoNome = armazena.getNome((esq + dir) / 2);

        while (i <= j) {
            while (armazena.getGeracao(i) < pivoGeracao || 
                   (armazena.getGeracao(i) == pivoGeracao && armazena.getNome(i).compareTo(pivoNome) < 0)) {
                i++;
            }
            while (armazena.getGeracao(j) > pivoGeracao || 
                   (armazena.getGeracao(j) == pivoGeracao && armazena.getNome(j).compareTo(pivoNome) > 0)) {
                j--;
            }
            if (i <= j) {
                swap(armazena, i, j);
                i++;
                j--;
            }
        }
        if (esq < j) QuickSort(armazena, esq, j);
        if (i < dir) QuickSort(armazena, i, dir);
    }

    static void pegaPokemon(ListaDupla lista, int tam) {
        String pokemonFile = "/tmp/pokemon.csv"; 
        String linha = "";
    
        Armazena armazena = new Armazena(tam);
        int j = 0; // Controla o índice em Armazena
    
        try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))) {
            leitura.readLine(); // Ignora o cabeçalho
    
            while ((linha = leitura.readLine()) != null && j < tam) { 
                String[] pokemon = linha.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");
    
                if (pokemon.length >= 10) {
                    int id_poke = Integer.parseInt(pokemon[0]);
    
                    if (lista.pesquisar(id_poke)) {
                        armazena.setId(id_poke, j);
    
                        String name = pokemon[2].replace("\"", "").trim(); 
                        armazena.setNomes(name, j);
    
                        int geracao = Integer.parseInt(pokemon[1]);
                        armazena.setGeracao(geracao, j);
    
                        j++;
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    
        QuickSort(armazena, 0, j - 1);
        lista.atualizar(armazena.getIds());
    }
    
    public static void main(String[] args) throws Exception {
       
        Scanner sc = new Scanner(System.in);

        ListaDupla lista = new ListaDupla();

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
                lista.inserirFim(valor);
                cont++;
            }
        }

        pegaPokemon(lista, cont);

        lista.mostrar();

        sc.close();
    }
}
