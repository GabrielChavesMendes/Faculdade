package model;

public class Receita {
    private int id;
    private String text;
    private String formatted_text;
    private String file_url;          
    private String analysis;  


    public Receita() {};

    public Receita(int id, String texte, String formatted_texto, String file_url, String analysis) {
        this.id = id;
        this.text =texte;
        this.formatted_text =formatted_texto;
        this.file_url = file_url;
        this.analysis = analysis;
    }
}
