package dao;

import model.Pessoas;
import model.Prontuario;

public class ProntuarioCompleto {
    private Prontuario prontuario;
    private Pessoas pessoas;

    public ProntuarioCompleto(Prontuario prontuario, Pessoas pessoas) {
        this.prontuario = prontuario;
        this.pessoas = pessoas;
    }

    // Getters e Setters

    public Prontuario getProntuario() {
        return prontuario;
    }

    public void setProntuario(Prontuario prontuario) {
        this.prontuario = prontuario;
    }

    public Pessoas getPessoas() {
        return pessoas;
    }

    public void setPessoas(Pessoas pessoas) {
        this.pessoas = pessoas;
    }
}
