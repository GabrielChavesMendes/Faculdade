package service;

import dao.FarmaceuticoDAO;
import model.Farmaceutico;

public class FarmaceuticoService {
    private FarmaceuticoDAO farmaceuticoDAO;

    public FarmaceuticoService() {
        this.farmaceuticoDAO = new FarmaceuticoDAO();
    }

    public void adicionarFarmaceutico(String crf, String nome, String senha, String email, int idHospital) {
        FarmaceuticoDAO dao = new FarmaceuticoDAO();
        if (dao.conectar()) {
            Farmaceutico farmaceutico = new Farmaceutico(crf, nome, senha, email, idHospital);
            boolean sucesso = dao.insert(farmaceutico);

            if (sucesso) {
                System.out.println("Farmacêutico adicionado com sucesso!");
            } else {
                System.out.println("Erro ao adicionar farmacêutico.");
            }

            dao.close();
        } else {
            System.out.println("Erro ao conectar ao banco de dados.");
        }
    }

    public Farmaceutico obterFarmaceutico(String crm) {
        return farmaceuticoDAO.get(crm);
    }

    public boolean atualizarFarmaceutico(Farmaceutico farmaceutico) {
        return farmaceuticoDAO.update(farmaceutico);
    }

    public boolean removerFarmaceutico(String crm) {
        return farmaceuticoDAO.remove(crm);
    }

    public Farmaceutico[] listarFarmaceuticos() {
        return farmaceuticoDAO.listar();
    }
}
