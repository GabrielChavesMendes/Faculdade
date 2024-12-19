import java.util.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class NoAN {
    public boolean cor;
    public String elemento;
    public NoAN esq, dir;
  
    public NoAN() {
      this("");
    }
  
    public NoAN(String elemento) {
      this(elemento, false, null, null);
    }
  
    public NoAN(String elemento, boolean cor) {
      this(elemento, cor, null, null);
    }
  
    public NoAN(String elemento, boolean cor, NoAN esq, NoAN dir) {
      this.cor = cor;
      this.elemento = elemento;
      this.esq = esq;
      this.dir = dir;
    }
}

class Alvinegra {
    private NoAN raiz; // Raiz da arvore.
 
    //Construtor da classe.
    public Alvinegra() {
       raiz = null;
    }
 
    //Metodo publico iterativo para pesquisar elemento.
    public boolean pesquisar(String elemento) {
       return pesquisar(elemento, raiz);
    }
 
    //Metodo privado recursivo para pesquisar elemento.
    private boolean pesquisar(String elemento, NoAN i) {
       boolean resp;
       if (i == null) {
          resp = false;
       } else if (elemento.compareTo(i.elemento) == 0) {
          resp = true;
       } else if (elemento.compareTo(i.elemento) < 0) {
            System.out.print("esq ");
            resp = pesquisar(elemento, i.esq);
       } else {
            System.out.print("dir ");
            resp = pesquisar(elemento, i.dir);
       }
       return resp;
    }
 
    //Metodo publico iterativo para exibir elementos.
    public void caminharCentral() {
       System.out.print("[ ");
       caminharCentral(raiz);
       System.out.println("]");
    }
 
    //Metodo privado recursivo para exibir elementos.
    private void caminharCentral(NoAN i) {
       if (i != null) {
          caminharCentral(i.esq); // Elementos da esquerda.
          caminharCentral(i.dir); // Elementos da direita.
       }
    }
  
    //Metodo publico iterativo para inserir elemento.
    public void inserir(String nome) throws Exception {
           // Se a arvore estiver vazia
           if (raiz == null) {
              raiz = new NoAN(nome);
     
           // Senao, se a arvore tiver um elemento
           } else if (raiz.esq == null && raiz.dir == null) {
              if (nome.compareTo(raiz.elemento) < 0) {
                 raiz.esq = new NoAN(nome);
              } else {
                 raiz.dir = new NoAN(nome);
              }
     
           // Senao, se a arvore tiver dois elementos (raiz e dir)
           } else if (raiz.esq == null) {
              if (nome.compareTo(raiz.elemento) < 0) {
                 raiz.esq = new NoAN(nome);
     
              } else if (nome.compareTo(raiz.dir.elemento) < 0) {
                 raiz.esq = new NoAN(raiz.elemento);
                 raiz.elemento = nome;
     
              } else {
                 raiz.esq = new NoAN(raiz.elemento);
                 raiz.elemento = raiz.dir.elemento;
                 raiz.dir.elemento = nome;
              }
              raiz.esq.cor = raiz.dir.cor = false;
     
           // Senao, se a arvore tiver dois elementos (raiz e esq)
           } else if (raiz.dir == null) {
              if (nome.compareTo(raiz.elemento) > 0) {
                 raiz.dir = new NoAN(nome);
     
              } else if (nome.compareTo(raiz.esq.elemento) > 0) {
                 raiz.dir = new NoAN(raiz.elemento);
                 raiz.elemento = nome;
     
              } else {
                 raiz.dir = new NoAN(raiz.elemento);
                 raiz.elemento = raiz.esq.elemento;
                 raiz.esq.elemento = nome;
              }
              raiz.esq.cor = raiz.dir.cor = false;
     
           // Senao, a arvore tem tres ou mais elementos
           } else {
              inserir(nome, null, null, null, raiz);
       }
       raiz.cor = false;
    }
 
    private void balancear(NoAN bisavo, NoAN avo, NoAN pai, NoAN i) {
       // Se o pai tambem e preto, reequilibrar a arvore, rotacionando o avo
       if (pai.cor == true) {
          // 4 tipos de reequilibrios e acoplamento
          if (pai.elemento.compareTo(avo.elemento) > 0) { // rotacao a esquerda ou direita-esquerda
             if (i.elemento.compareTo(pai.elemento) > 0) {
                avo = rotacaoEsq(avo);
             } else {
                avo = rotacaoDirEsq(avo);
             }
          } else { // rotacao a direita ou esquerda-direita
             if (i.elemento.compareTo(pai.elemento) < 0) {
                avo = rotacaoDir(avo);
             } else {
                avo = rotacaoEsqDir(avo);
             }
          }
          if (bisavo == null) {
             raiz = avo;
          } else if (avo.elemento.compareTo(bisavo.elemento) < 0) {
             bisavo.esq = avo;
          } else {
             bisavo.dir = avo;
          }
          // reestabelecer as cores apos a rotacao
          avo.cor = false;
          avo.esq.cor = avo.dir.cor = true;
       } // if(pai.cor == true)
    }
 
    //Metodo privado recursivo para inserir elemento.
    private void inserir(String elemento, NoAN bisavo, NoAN avo, NoAN pai, NoAN i) throws Exception {
       if (i == null) {
          if (elemento.compareTo(pai.elemento) < 0) {
             i = pai.esq = new NoAN(elemento, true);
          } else {
             i = pai.dir = new NoAN(elemento, true);
          }
          if (pai.cor == true) {
             balancear(bisavo, avo, pai, i);
          }
       } else {
          // Achou um 4-no: eh preciso fragmeta-lo e reequilibrar a arvore
          if (i.esq != null && i.dir != null && i.esq.cor == true && i.dir.cor == true) {
             i.cor = true;
             i.esq.cor = i.dir.cor = false;
             if (i == raiz) {
                i.cor = false;
             } else if (pai.cor == true) {
                balancear(bisavo, avo, pai, i);
             }
          }
          if (elemento.compareTo(i.elemento) < 0) {
             inserir(elemento, avo, pai, i, i.esq);
          } else if (elemento.compareTo(i.elemento) > 0) {
             inserir(elemento, avo, pai, i, i.dir);
          } else {
             throw new Exception("Erro inserir (elemento repetido)!");
          }
       }
    }
 
    private NoAN rotacaoDir(NoAN no) {
       NoAN noEsq = no.esq;
       NoAN noEsqDir = noEsq.dir;
 
       noEsq.dir = no;
       no.esq = noEsqDir;
 
       return noEsq;
    }
 
    private NoAN rotacaoEsq(NoAN no) {
       NoAN noDir = no.dir;
       NoAN noDirEsq = noDir.esq;
 
       noDir.esq = no;
       no.dir = noDirEsq;
       return noDir;
    }
 
    private NoAN rotacaoDirEsq(NoAN no) {
       no.dir = rotacaoDir(no.dir);
       return rotacaoEsq(no);
    }
 
    private NoAN rotacaoEsqDir(NoAN no) {
       no.esq = rotacaoEsq(no.esq);
       return rotacaoDir(no);
    }
}

public class TP04Q04 {

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

        Alvinegra arvore = new Alvinegra();

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
                System.out.print("raiz ");
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
