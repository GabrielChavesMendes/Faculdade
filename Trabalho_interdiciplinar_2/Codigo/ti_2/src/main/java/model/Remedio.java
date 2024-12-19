package model;

public class Remedio {
    private int id;
    private String nome;

  
    public Remedio() {}

    public Remedio (int id, String nome) {
        this.id = id;
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }


    @Override
    public String toString() {
        return "Remedio [id=" + getId() + ", nome=" + getNome() + "]";
    }
 
}
