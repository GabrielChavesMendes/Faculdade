package service;

import dao.ProntuarioDAO;
import model.Prontuario;

public class ProntuarioService {
    private ProntuarioDAO prontuarioDAO = new ProntuarioDAO();

    public boolean conectar() {
        return prontuarioDAO.conectar();
    }

    public void inserirProntuario(Prontuario prontuario) {
        prontuarioDAO.insert(prontuario);
    }

    public Prontuario buscarProntuario(String ddd) {
        return prontuarioDAO.get(ddd);
    }

    public void atualizarProntuario(Prontuario prontuario) {
        prontuarioDAO.update(prontuario);
    }

    public void removerProntuario(String id) {
        prontuarioDAO.remove(id);
    }

    public Prontuario[] listarProntuarios() {
        return prontuarioDAO.listar();
    }
}
