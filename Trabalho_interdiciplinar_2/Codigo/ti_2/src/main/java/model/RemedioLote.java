package model;

public class RemedioLote {
    private int id;
    private String nome;
    private String codigo;          
    private String dataFabricacao;  
    private String validade;        
    private int dosagem;            
    private int quantidade;

    public RemedioLote() {}

    public RemedioLote(int id, String nome, String codigo, String dataFabricacao, String validade, int dosagem, int quantidade) {
        this.id = id;
        this.nome = nome;
        this.codigo = codigo;
        this.quantidade = quantidade;
        this.dataFabricacao = dataFabricacao;
        this.validade = validade;
        this.dosagem = dosagem;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public String getDataFabricacao() {
        return dataFabricacao;
    }

    public void setDataFabricacao(String dataFabricacao) {
        this.dataFabricacao = dataFabricacao;
    }

    public String getValidade() {
        return validade;
    }

    public void setValidade(String validade) {
        this.validade = validade;
    }

    public int getDosagem() {
        return dosagem;
    }

    public void setDosagem(int dosagem) {
        this.dosagem = dosagem;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public static void quicksort(RemedioLote[] arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high); // Encontra o índice do pivô
            quicksort(arr, low, pivotIndex - 1);  // Ordena a parte à esquerda do pivô
            quicksort(arr, pivotIndex + 1, high); // Ordena a parte à direita do pivô
        }
    }

    // Função que faz a partição e posiciona o pivô no lugar correto
    private static int partition(RemedioLote[] arr, int low, int high) {
        int pivot = arr[high].getId();  // Escolhe o último elemento como pivô
        int i = low - 1; // Índice para o menor elemento

        for (int j = low; j < high; j++) {
            // Se o elemento atual tem um id menor ou igual ao pivô
            if (arr[j].getId() <= pivot) {
                i++;

                // Troca arr[i] e arr[j]
                RemedioLote temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Troca arr[i+1] com o pivô (arr[high])
        RemedioLote temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1; // Retorna o índice do pivô
    }



    @Override
    public String toString() {
        return "RemedioLote [id=" + id + ", nome="+ nome +", codigo=" + codigo + 
               ", dataFabricacao=" + dataFabricacao + ", validade=" + validade + 
               ", dosagem=" + dosagem + ", quantidade=" + quantidade + "]";
    }
}
