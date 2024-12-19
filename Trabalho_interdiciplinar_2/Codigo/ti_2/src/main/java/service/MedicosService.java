package service;

import dao.MedicosDAO;
import model.Medico;

public class MedicosService {
    private MedicosDAO medicosDAO = new MedicosDAO();

    public boolean conectar() {
        return medicosDAO.conectar();
    }

    public void inserirMedico(Medico medico) {
        medicosDAO.insert(medico);
    }

    public Medico buscarMedico(String crm) {
        return medicosDAO.get(crm);
    }

    public void atualizarMedico(Medico medico) {
        medicosDAO.update(medico);
    }

    public void removerMedico(String crm) {
        medicosDAO.remove(crm);
    }

    public Medico[] listarMedicos() {
        return medicosDAO.listar();
    }
}
