package model;

public class Farmaceutico {
    
    // Atributos que correspondem às colunas da tabela Farmaceutico no banco de dados
    private String crf;
    private String nome;
    private String senha;
    private String email;
    private int id_hospital;

    // Construtor padrão
    public Farmaceutico() {}

    // Construtor completo
    public Farmaceutico(String crf, String nome, String senha, String email, int idHospital) {
        this.crf = crf;
        this.nome = nome;
        this.senha = senha;
        this.email = email;
        this.id_hospital = idHospital;
    }

    // Getters e Setters
    public String getCrf() {
        return crf;
    }

    public void setCrf(String crf) {
        this.crf = crf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public int getIdHospital() {
        return id_hospital;
    }

    public void setIdHospital(int idHospital) {
        this.id_hospital = idHospital;
    }

    // Métodos utilitários: toString(), equals(), e hashCode()

    @Override
    public String toString() {
        return "Farmaceutico [crf=" + crf + ", nome=" + nome + ", senha=" + senha + ", email=" + email + ", idHospital=" + id_hospital + "]";
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((crf == null) ? 0 : crf.hashCode());
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Farmaceutico other = (Farmaceutico) obj;
        if (crf == null) {
            if (other.crf != null)
                return false;
        } else if (!crf.equals(other.crf))
            return false;
        return true;
    }
}
