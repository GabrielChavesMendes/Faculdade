package model;


public class PessoaProntuario {
    private String cpf;
    private String nome;
    private String alergia;
    private int idade;
    private int tipoSanguineo;
    private double peso;
    private double altura;
    private String senha;
    private String descricao;
    private String dataAtendimento;
    private String status;  
    private int idHospital;
    private String nomeHospital;
    private String medicoResp;

    public PessoaProntuario() {}

    public PessoaProntuario(String cpf, String nome, String alergia, int idade, int tipoSanguineo, double peso, double altura, String senha, String descricao, String date, String status, int idHospital, String nomeHospital, String medicoResp) {
        this.cpf = cpf;
        this.nome = nome;
        this.alergia = alergia;
        this.idade = idade;
        this.tipoSanguineo = tipoSanguineo;
        this.peso = peso;
        this.altura = altura;
        this.senha = senha;
        this.descricao = descricao;
        this.dataAtendimento = date;
        this.status = status;
        this.idHospital = idHospital;
        this.nomeHospital = nomeHospital;
        this.medicoResp = medicoResp;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
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

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public String getDataAtendimento() {
        return dataAtendimento;
    }

    public void setDataAtendimento(String dataAtendimento) {
        this.dataAtendimento = dataAtendimento;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public int getIdHospital() {
        return idHospital;
    }

    public void setIdHospital(int idHospital) {
        this.idHospital = idHospital;
    }

    public String getMedicoResp() {
        return medicoResp;
    }

    public void setMedicoResp(String medicoResp) {
        this.medicoResp = medicoResp;
    }

    public String getNomeHospital() {
        return nomeHospital;
    }

    public void setNomeHospital(String nomeHospital) {
        this.nomeHospital = nomeHospital;
    }

}
