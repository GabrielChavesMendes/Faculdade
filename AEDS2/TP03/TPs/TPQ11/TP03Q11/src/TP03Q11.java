import java.util.*;

class Celula {
    public int elemento;
    public Celula esq;
    public Celula dir;
    public Celula sup;
    public Celula inf;

    Celula() {
        this.elemento = 0;
        this.esq = this.dir = this.sup = this.inf = null;
    }
}

class Matriz {
    private Celula inicio;
    private int NumLinhas;
    private int NumColunas;

    Matriz(int linhas, int colunas) {
        inicio = createLinha(colunas);
        Celula linhaAnterior = inicio;

        for (int i = 1; i < linhas; i++) {
            Celula linhaAtual = createLinha(colunas);

            // Conecta verticalmente a linha anterior com a linha atual
            Celula tempAnterior = linhaAnterior;
            Celula tempAtual = linhaAtual;

            while (tempAnterior != null) {
                tempAnterior.inf = tempAtual;
                tempAtual.sup = tempAnterior;
                tempAnterior = tempAnterior.dir;
                tempAtual = tempAtual.dir;
            }

            linhaAnterior = linhaAtual;
        }

        NumLinhas = linhas;
        NumColunas = colunas;
    }

    Celula createLinha(){
        Celula i = new Celula();
        Celula j = new Celula();

        i.dir = j;
        j.esq = i;

        return i;
    }

    Celula createLinha(int x) {
        Celula i = new Celula();
        Celula tmp = i;
    
        for (int j = 1; j < x; j++) {
            Celula nova = new Celula();
            tmp.dir = nova;
            nova.esq = tmp;
            tmp = nova;
        }
        return i;
    }    

    Celula createColuna(int x){
        Celula i = new Celula();
        Celula tmp = i;

        for (int j = 0; j < x - 1; j++) {
            Celula nova = new Celula();
            tmp.inf = nova;
            nova.sup = tmp;

            tmp = nova;
        }
        return i;
    }

    void addLinha(){
        Celula i;
        for (i = inicio; i.inf != null; i = i.inf)
            ;
        for (Celula j = createLinha(NumColunas); j != null; j = j.dir) {
            i.inf = j;
            j.sup = i;

            i = i.dir;
        }
        NumLinhas++;
    }

    void addColuna(){
        Celula i;
        for (i = inicio; i.dir != null; i = i.dir)
            ;
        for (Celula j = createColuna(NumLinhas); j != null; j = j.inf) {
            i.dir = j;
            j.esq = i;

            i = i.inf;
        }

        NumColunas++;
    }

    void addElemento(int x, int linhaPos, int colunaPos){
        if(linhaPos >= NumLinhas || colunaPos >= NumColunas || linhaPos < 0 || colunaPos < 0){
            try{
                throw new Exception("Posicao invalida");
            }catch(Exception e){
                e.printStackTrace();
            }
        } else {
            Celula tmp = inicio;
        
            // Navega até a célula da linha
            for (int i = 0; i < linhaPos; i++) {
                if (tmp.inf == null) tmp.inf = new Celula();  
                tmp = tmp.inf;
            }
    
            // Navega até a célula da coluna
            for (int i = 0; i < colunaPos; i++) {
                if (tmp.dir == null) tmp.dir = new Celula();  
                tmp = tmp.dir;
            }
            tmp.elemento = x;
        }
    }        

    void getDiagonal() {
        if (NumColunas != NumLinhas) {
            System.out.println("Erro na diagonal principal");
        } else {
            Celula i = inicio;
            while (i != null) {
                System.out.print(i.elemento + " ");
                i = (i.dir != null && i.inf != null) ? i.dir.inf : null;
            }
            System.out.println();
        }
    }
    
    void getDiagonalSecundaria() {
        if (NumColunas != NumLinhas) {
            System.out.println("Erro na diagonal secundaria");
        } else {
            Celula i = inicio;
            while (i.dir != null) { 
                i = i.dir;
            }
            while (i != null) {
                System.out.print(i.elemento + " ");
                i = (i.esq != null && i.inf != null) ? i.esq.inf : null;
            }
            System.out.println();
        }
    }        

    Matriz somaMatrizes(Matriz outra) throws Exception {
        if (this.NumLinhas != outra.NumLinhas || this.NumColunas != outra.NumColunas) {
            throw new Exception("Numero de colunas deve ser igual ao de linhas");
        }
    
        Matriz resultado = new Matriz(this.NumLinhas, this.NumColunas);
    
        Celula i = this.inicio;
        Celula j = outra.inicio;
    
        for (int l = 0; l < this.NumLinhas; l++) {
            Celula col1 = i;
            Celula col2 = j;
            for (int c = 0; c < this.NumColunas; c++) {
                int soma = col1.elemento + col2.elemento;
                resultado.addElemento(soma, l, c);
    
                col1 = col1.dir;
                col2 = col2.dir;
            }
            i = i.inf;
            j = j.inf;
        }
    
        return resultado;
    }    

    void multiplicacao(Matriz m2) {
        if (this.NumColunas != m2.NumLinhas) {
            System.out.println("Numero de colunas deve ser igual ao de linhas");
            return;
        }

        Matriz m3 = new Matriz(this.NumLinhas, m2.NumColunas);

        Celula linhaAtual = this.inicio;  
        for (int i = 0; i < this.NumLinhas; i++) {
            Celula colunaResultado = m3.inicio; 
            Celula colunaMatriz2 = m2.inicio;  

            for (int j = 0; j < m2.NumColunas; j++) {
                int valorCelula = 0;
                Celula celulaLinha1 = linhaAtual;
                Celula celulaColuna2 = colunaMatriz2;

                for (int k = 0; k < this.NumColunas; k++) {
                    if (celulaLinha1 == null) {
                        celulaLinha1 = new Celula();  
                    }
                    if (celulaColuna2 == null) {
                        celulaColuna2 = new Celula(); 
                    }

                    valorCelula += celulaLinha1.elemento * celulaColuna2.elemento;

                    celulaLinha1 = celulaLinha1.dir; 
                    celulaColuna2 = celulaColuna2.inf; 
                }

                m3.addElemento(valorCelula, i, j);

                colunaResultado = colunaResultado.dir;
                colunaMatriz2 = colunaMatriz2.dir;
            }

            linhaAtual = linhaAtual.inf;
        }
        m3.mostra();
    }

    void mostra(){
        for (Celula i = inicio; i != null; i = i.inf) {
            for (Celula j = i; j != null; j = j.dir) {
                System.out.print(j.elemento + " ");
            }
            System.out.println();
        }
    }    
}

public class TP03Q11 {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int casos = sc.nextInt();

        for (int i = 0; i < casos; i++) {
            Matriz matriz1 = null;
            Matriz matriz2 = null;

            for (int j = 0; j < 2; j++) {

                int linhas = sc.nextInt();
                int colunas = sc.nextInt();

                Matriz matriz = new Matriz(linhas, colunas);

                for (int l = 0; l < linhas; l++) {
                    for (int c = 0; c < colunas; c++) {
                        int elemento = sc.nextInt();
                        matriz.addElemento(elemento, l, c);
                    }
                }

                if (j == 0) {
                    matriz1 = matriz; 
                } else {
                    matriz2 = matriz; 
                }
            }

            matriz1.getDiagonal();
            matriz1.getDiagonalSecundaria();

            Matriz matrizSoma = matriz1.somaMatrizes(matriz2);
            matrizSoma.mostra();

            matriz1.multiplicacao(matriz2);
        }
        sc.close();
    }
}

