package model;

public class Pessoas {
    
    private String cpf;
    private String nome;
    private String alergia;
    private int idade;
    private int tipoSanguineo;
    private double peso;
    private double altura;
    private String senha;

    // Construtor padrão
    public Pessoas() {}

    // Construtor completo
    public Pessoas(String cpf, String nome, String alergia, int idade, int tipoSanguineo, double peso, double altura, String senha) {
        this.cpf = cpf;
        this.nome = nome;
        this.alergia = alergia;
        this.idade = idade;
        this.tipoSanguineo = tipoSanguineo;
        this.peso = peso;
        this.altura = altura;
        this.senha = senha;
    }

    // Getters e setters
    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getAlergia() {
        return alergia;
    }

    public void setAlergia(String alergia) {
        this.alergia = alergia;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public int getTipoSanguineo() {
        return tipoSanguineo;
    }

    public void setTipoSanguineo(int tipoSanguineo) {
        this.tipoSanguineo = tipoSanguineo;
    }

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    @Override
    public String toString() {
        return "Pessoa [cpf=" + cpf + ", nome=" + nome + ", alergia=" + alergia + ", idade=" + idade + 
               ", tipoSanguineo=" + tipoSanguineo + ", peso=" + peso + ", altura=" + altura + ", senha=" + senha + "]";
    }
}
