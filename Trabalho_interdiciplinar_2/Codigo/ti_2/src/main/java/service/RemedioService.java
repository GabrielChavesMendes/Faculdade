package service;

import dao.RemedioDAO;
import model.Remedio;

public class RemedioService {
    private RemedioDAO remedioDAO;

    public RemedioService() {
        this.remedioDAO = new RemedioDAO();
    }

    public Remedio obterRemedio(int id) {
        return remedioDAO.get(id);
    }

    public Remedio[] listarRemedios() {
        return remedioDAO.listar();
    }
}
