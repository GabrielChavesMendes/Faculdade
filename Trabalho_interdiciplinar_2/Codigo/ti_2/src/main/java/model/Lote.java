package model;

public class Lote {
    
    private int idRemedio;          
    private String codigo;          
    private String dataFabricacao;  
    private String validade;        
    private int dosagem;            
    private int quantidade;  
    private int idHospital;       

    public Lote() {}

    public Lote(int idRemedio, String codigo, int quantidade, String dataFabricacao, String validade, int dosagem, int idHospital) {
        this.idRemedio = idRemedio;
        this.codigo = codigo;
        this.quantidade = quantidade;
        this.dataFabricacao = dataFabricacao;
        this.validade = validade;
        this.dosagem = dosagem;
        this.idHospital = idHospital;
    }

    public int getIdRemedio() {
        return idRemedio;
    }

    public void setIdRemedio(int idRemedio) {
        this.idRemedio = idRemedio;
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

    @Override
    public String toString() {
        return "Lote [idRemedio=" + idRemedio + ", codigo=" + codigo + 
               ", dataFabricacao=" + dataFabricacao + ", validade=" + validade + 
               ", dosagem=" + dosagem + ", quantidade=" + quantidade + "]";
    }

    public int getIdHospital() {
        return idHospital;
    }

    public void setIdHospital(int idHospital) {
        this.idHospital = idHospital;
    }
}

