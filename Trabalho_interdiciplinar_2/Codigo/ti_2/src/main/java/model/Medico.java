package model;

public class Medico {
    
    private String crm;
    private String nome;
    private String especialidade;
    private String senha;
    private int idHospital;
    private String email;

    // Construtor padrão
    public Medico() {}

    // Construtor completo
    public Medico(String crm, String nome, String especialidade, String senha, int idHospital, String email) {
        this.crm = crm;
        this.nome = nome;
        this.especialidade = especialidade;
        this.senha = senha;
        this.idHospital = idHospital;
        this.email = email;
    }

    // Getters e Setters
    public String getCrm() {
        return crm;
    }

    public void setCrm(String crm) {
        this.crm = crm;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEspecialidade() {
        return especialidade;
    }

    public void setEspecialidade(String especialidade) {
        this.especialidade = especialidade;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public int getIdHospital() {
        return idHospital;
    }

    public void setIdHospital(int idHospital) {
        this.idHospital = idHospital;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return "Medico [crm=" + crm + ", nome=" + nome + ", especialidade=" + especialidade + 
               ", senha=" + senha + ", idHospital=" + idHospital + ", email=" + email + "]";
    }
}
