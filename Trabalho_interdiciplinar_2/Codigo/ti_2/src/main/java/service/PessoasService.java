package service;

import dao.PessoasDAO;
import model.Pessoas;

public class PessoasService {
    private PessoasDAO pessoasDAO = new PessoasDAO();

    public boolean conectar() {
        return pessoasDAO.conectar();
    }

    public void inserirPessoa(Pessoas pessoa) {
        pessoasDAO.insert(pessoa);
    }

    public Pessoas buscarPessoa(String cpf) {
        return pessoasDAO.get(cpf);
    }

    public void atualizarPessoa(Pessoas pessoa) {
        pessoasDAO.update(pessoa);
    }

    public void removerPessoa(String cpf) {
        pessoasDAO.remove(cpf);
    }

    public Pessoas[] listarPessoas() {
        return pessoasDAO.listar();
    }
}
