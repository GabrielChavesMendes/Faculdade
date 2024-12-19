import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

class No {
	public int elemento; 
	public No esq; 
	public No dir; 
    public No2 outro;
	
   // Construtor da classe
	No(int elemento) {
		this.elemento = elemento;
		this.esq = this.dir = null;
        this.outro = null;
	}

	//Construtor da classe.
	No(int elemento, No esq, No dir) {
		this.elemento = elemento;
		this.esq = esq;
		this.dir = dir;
      this.outro = null;
	}
}

class No2 {
	public String elemento; 
	public No2 esq; 
	public No2 dir; 
	
   //Construtor da classe.
	No2(String elemento) {
		this.elemento = elemento;
		this.esq = this.dir = null;
	}

	//Construtor da classe.
	No2(String elemento, No2 esq, No2 dir) {
		this.elemento = elemento;
		this.esq = esq;
		this.dir = dir;
	}
}

public class TP04Q02 {

    //Arvore de arvore
    public class ArvoreArvore {
        private No raiz; // Raiz da arvore.

        // Construtor da classe.
        public ArvoreArvore(){
            raiz = null;  
        }

        public void inserir(int numero) {
            raiz = inserir(numero, raiz); 
        }
        
        private No inserir(int numero, No i) {
            if (i == null) {
                i = new No(numero); 
        
            } else if (numero < i.elemento) {
                i.esq = inserir(numero, i.esq); 
        
            } else if (numero > i.elemento) {
                i.dir = inserir(numero, i.dir); 
            }
            return i;
        }

        public void inserir(String s, int numero) throws Exception {
            inserir(s, numero, raiz);
        }
        
        private void inserir(String s, int numero, No i) throws Exception {
            if (i == null) {
                throw new Exception("Erro ao inserir: número inválido!");
        
            } else if (numero < i.elemento) {
                inserir(s, numero, i.esq);
        
            } else if (numero > i.elemento) {
                inserir(s, numero, i.dir);
        
            } else {
                i.outro = inserir(s, i.outro);
            }
        }

        private No2 inserir(String s, No2 i) {
            if (i == null) {
                i = new No2(s);
            } else if (s.compareTo(i.elemento) < 0) {
                i.esq = inserir(s, i.esq);
            } else if (s.compareTo(i.elemento) > 0) {
                i.dir = inserir(s, i.dir);
            }
            return i;
        }        
        
        public void mostrar(){
            mostrar(raiz);
        }

        public void mostrar(No i){
            if (i != null){
                mostrar(i.esq);
                System.out.println("Elemento: " + i.elemento);
                mostrar(i.outro);
                mostrar(i.dir);
            }
        }

        public void mostrar(No2 i){
            if (i != null){
                mostrar(i.esq);
                System.out.println(i.elemento);
                mostrar(i.dir);
            }else{
            }
        }

        //Metodo publico iterativo para pesquisar elemento
        public boolean pesquisar(int elemento, String name) {
            return pesquisar(raiz, elemento, name);
        }
                
        private boolean pesquisar(No no, int x, String name) {
            boolean resp;

            if (no == null) { 
                resp = false;

            } else if (x < no.elemento) { 
                System.out.print("ESQ ");
                resp = pesquisar(no.esq, x, name); 

            } else if (x > no.elemento) { 
                System.out.print("DIR ");
                resp = pesquisar(no.dir, x, name); 
            
            } else { 
                resp = pesquisarSegundaArvore(no.outro, x, name); 
            }
            return resp;
        }

        private boolean pesquisarSegundaArvore(No2 no, int x, String name) {
            boolean resp;
        
            if (no == null) { 
                resp = false;

            } else if (name.compareTo(no.elemento) < 0) { 
                System.out.print("esq ");
                resp = pesquisarSegundaArvore(no.esq, x, name); 

            } else if (name.compareTo(no.elemento) > 0) { 
                System.out.print("dir ");
                resp = pesquisarSegundaArvore(no.dir, x, name); 

            } else { 
                resp = true; 
            }
            return resp;
        }   
    }

    public static int taxaCaptura(int id){

        String pokemonFile = "/tmp/pokemon.csv";
        String linha;
        int captureRate = 0; 

        try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))) {
            leitura.readLine(); // Ignorar cabeçalho
            
            while ((linha = leitura.readLine()) != null) {
                String[] pokemon = linha.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");      

                if (pokemon.length >= 10) {
                    String id_arq = pokemon[0];
                    int id_poke = Integer.parseInt(id_arq);

                    if(id == id_poke){
                        captureRate = Integer.parseInt(pokemon[9].trim());                         
                    }  
                }
                
            } 
        } catch (IOException e) {
            e.printStackTrace();
        }

        int mod = captureRate / 15;

        return mod;
    }

    public static int taxaCaptura(String nome){

        String pokemonFile = "/tmp/pokemon.csv";
        String linha;
        int captureRate = 0; 

        try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))) {
            leitura.readLine(); // Ignorar cabeçalho
            
            while ((linha = leitura.readLine()) != null) {
                String[] pokemon = linha.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");      

                if (pokemon.length >= 10) {
                   String name = pokemon[2].replace("\"", "").trim();

                    if(nome.equals(name)){
                        captureRate = Integer.parseInt(pokemon[9].trim());                         
                    }  
                }
                
            } 
        } catch (IOException e) {
            e.printStackTrace();
        }

        int mod = captureRate / 15;

        return mod;
    }

    public static String nomePokemon(int id){

        String pokemonFile = "/tmp/pokemon.csv";
        String linha;
        String name = " "; 

        try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))) {
            leitura.readLine(); // Ignorar cabeçalho
            
            while ((linha = leitura.readLine()) != null) {
                String[] pokemon = linha.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");      

                if (pokemon.length >= 10) {
                    String id_arq = pokemon[0];
                    int id_poke = Integer.parseInt(id_arq);

                    if(id == id_poke){
                        name = pokemon[2].replace("\"", "").trim();                       
                    }  
                }
                
            } 
        } catch (IOException e) {
            e.printStackTrace();
        }
        return name;
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        TP04Q02 programa = new TP04Q02();
        ArvoreArvore arvore = programa.new ArvoreArvore();

        // Inicializar a primeira arvore com os numeros fixos
        int[] valoresFixos = {7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14};
        for (int valor : valoresFixos) {
            arvore.inserir(valor);
        }

        String num;
        boolean verdade = true;
        String name;

        while(verdade){
            num = sc.nextLine();

            if(num.equals("FIM")){
                verdade = false;
            }else{
                int valor = Integer.parseInt(num);
                int mod = taxaCaptura(valor);
                name = nomePokemon(valor);
                
                arvore.inserir(mod);
                arvore.inserir(name, mod);
            }
        }

        //arvore.mostrar();

        verdade = true;
        String nomes;
        boolean existe = false;

        while(verdade){
            nomes = sc.nextLine();

            if(nomes.equals("FIM")){
                verdade = false;
            }else{
                int mod2 = taxaCaptura(nomes);

                System.out.println("=>" + nomes);
                System.out.print("raiz ");

                existe = arvore.pesquisar(mod2, nomes);
    
                if(existe == true){
                    System.out.println("SIM");
                }else{
                    System.out.println("NAO");
                }
            }
        }

        

        sc.close();
    }
}
