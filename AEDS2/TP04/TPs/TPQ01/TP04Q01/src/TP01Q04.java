import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

//Arvore binaria de pesquisa
 class ArvoreBinaria {
	private No raiz; // Raiz da arvore.

	//Construtor da classe.
	public ArvoreBinaria() {
		raiz = null;
	}

	//Metodo publico iterativo para pesquisar elemento
	public boolean pesquisar(String x) {
        System.out.print("=>raiz ");
		return pesquisar(x, raiz);
	}

	//Metodo privado recursivo para pesquisar elemento.
	private boolean pesquisar(String x, No i) {
      boolean resp;
		if (i == null) {
         resp = false;

      } else if (x.compareTo(i.elemento) == 0) {
         resp = true;

      } else if (x.compareTo(i.elemento) < 0) {
        System.out.print("esq ");
         resp = pesquisar(x, i.esq);

      } else {
        System.out.print("dir ");
         resp = pesquisar(x, i.dir);
      }
      return resp;
	}

	// Metodo publico iterativo para exibir elementos.
	public void caminharCentral() {
		System.out.print("[ ");
		caminharCentral(raiz);
		System.out.println("]");
	}

	//Metodo privado recursivo para exibir elementos.
	private void caminharCentral(No i) {
		if (i != null) {
			caminharCentral(i.esq); // Elementos da esquerda.
			System.out.print(i.elemento + " "); // Conteudo do no.
			caminharCentral(i.dir); // Elementos da direita.
		}
	}

	//Metodo publico iterativo para exibir elementos.
	public void caminharPre() {
		System.out.print("[ ");
		caminharPre(raiz);
		System.out.println("]");
	}

	//Metodo privado recursivo para exibir elementos.
	private void caminharPre(No i) {
		if (i != null) {
			System.out.print(i.elemento + " "); // Conteudo do no.
			caminharPre(i.esq); // Elementos da esquerda.
			caminharPre(i.dir); // Elementos da direita.
		}
	}

	//Metodo publico iterativo para exibir elementos.
	public void caminharPos() {
		System.out.print("[ ");
		caminharPos(raiz);
		System.out.println("]");
	}

	//Metodo privado recursivo para exibir elementos.
	private void caminharPos(No i) {
		if (i != null) {
			caminharPos(i.esq); // Elementos da esquerda.
			caminharPos(i.dir); // Elementos da direita.
			System.out.print(i.elemento + " "); // Conteudo do no.
		}
	}


	//Metodo publico iterativo para inserir elemento.
	public void inserir(String x) throws Exception {
		raiz = inserir(x, raiz);
	}

	//Metodo privado recursivo para inserir elemento.
	private No inserir(String x, No i) throws Exception {
		if (i == null) {
         i = new No(x);

      } else if (x.compareTo(i.elemento) < 0) {
         i.esq = inserir(x, i.esq);

      } else if (x.compareTo(i.elemento) > 0) {
         i.dir = inserir(x, i.dir);

      } else {
         throw new Exception("Erro ao inserir!");
      }

		return i;
	}

	//Metodo publico para inserir elemento.
	public void inserirPai(String x) throws Exception {
      if(raiz == null){
         raiz = new No(x);
      } else if(x.compareTo(raiz.elemento) < 0){
		   inserirPai(x, raiz.esq, raiz);
      } else if(x.compareTo(raiz.elemento) > 0){
		   inserirPai(x, raiz.dir, raiz);
      } else {
         throw new Exception("Erro ao inserirPai!");
      }
	}

	//Metodo privado recursivo para inserirPai elemento.
	private void inserirPai(String x, No i, No pai) throws Exception {
		if (i == null) {
         if(x.compareTo(pai.elemento) < 0){
            pai.esq = new No(x);
         } else {
            pai.dir = new No(x);
         }
      } else if (x.compareTo(i.elemento) < 0) {
         inserirPai(x, i.esq, i);
      } else if (x.compareTo(i.elemento) > 0) {
         inserirPai(x, i.dir, i);
      } else {
         throw new Exception("Erro ao inserirPai!");
      }
	}


	//Metodo publico iterativo para remover elemento.
	public void remover(String x) throws Exception {
		raiz = remover(x, raiz);
	}

	//Metodo privado recursivo para remover elemento.
	private No remover(String x, No i) throws Exception {

		if (i == null) {
         throw new Exception("Erro ao remover!");

      } else if (x.compareTo(i.elemento) < 0) {
         i.esq = remover(x, i.esq);

      } else if (x.compareTo(i.elemento) > 0) {
         i.dir = remover(x, i.dir);

      // Sem no a direita.
      } else if (i.dir == null) {
         i = i.esq;

      // Sem no a esquerda.
      } else if (i.esq == null) {
         i = i.dir;

      // No a esquerda e no a direita.
      } else {
         i.esq = maiorEsq(i, i.esq);
		}

		return i;
	}

	//Metodo para trocar o elemento "removido" pelo maior da esquerda.
	private No maiorEsq(No i, No j) {

      // Encontrou o maximo da subarvore esquerda.
		if (j.dir == null) {
			i.elemento = j.elemento; // Substitui i por j.
			j = j.esq; // Substitui j por j.ESQ.

      // Existe no a direita.
		} else {
         // Caminha para direita.
			j.dir = maiorEsq(i, j.dir);
		}
		return j;
	}

   public String getRaiz() throws Exception {
      return raiz.elemento;
   }

   public static boolean igual (ArvoreBinaria a1, ArvoreBinaria a2){
      return igual(a1.raiz, a2.raiz);
   }

   private static boolean igual (No i1, No i2){
      boolean resp;
      if(i1 != null && i2 != null){
         resp = (i1.elemento == i2.elemento) && igual(i1.esq, i2.esq) && igual(i1.dir, i2.dir);
      } else if(i1 == null && i2 == null){
         resp = true;
      } else {
         resp = false; 
      }
      return resp;
   }
}

//No da arvore binaria
 class No {
    public String elemento; // Conteudo do no.
    public No esq, dir;  // Filhos da esq e dir.

    //Construtor da classe.
    public No(String elemento) {
        this(elemento, null, null);
    }

    //Construtor da classe.
    public No(String elemento, No esq, No dir) {
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
    }
    
        public No(String elemento2, Object object, Object object2) {
            //TODO Auto-generated constructor stub
        }
}

public class TP01Q04 {

    public static String nomePokemon(int id){

        String nome = " ";
        String pokemonFile = "/tmp/pokemon.csv";
        String linha;

        try (BufferedReader leitura = new BufferedReader(new FileReader(pokemonFile))) {
            leitura.readLine(); // Ignorar cabeçalho
            
            while ((linha = leitura.readLine()) != null) {
                String[] pokemon = linha.split(",(?=([^\"]*\"[^\"]*\")*[^\"]*$)");      

                if (pokemon.length >= 10) {
                    String id_arq = pokemon[0];
                    int id_poke = Integer.parseInt(id_arq);

                    if(id == id_poke){
                        nome = pokemon[2].replace("\"", "").trim();                        
                    }  
                }
                
            } 
        } catch (IOException e) {
            e.printStackTrace();
        }

        return nome;
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        ArvoreBinaria arvore = new ArvoreBinaria();

        String ids;
        boolean continua = true;

        while(continua){

            ids = sc.nextLine();
            
            if(ids.equals("FIM")){
                continua = false;

            }else{
                int id = Integer.parseInt(ids);

                String nome  = nomePokemon(id);

                arvore.inserir(nome);
            }
        }

        continua = true;
        String newName;

        while(continua){

            newName = sc.nextLine();

            if(newName.equals("FIM")){
                continua = false;

            }else{
                System.out.println(newName);
                boolean achou = arvore.pesquisar(newName);

                if(achou == false){
                    System.out.print("NAO");
                    System.out.println();
                    arvore.inserir(newName);
                    
                }else{
                    System.out.print("SIM");
                    System.out.println();
                }
            }
        }
        
        sc.close();
    }
}
