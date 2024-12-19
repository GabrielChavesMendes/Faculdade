package service;

import dao.HospitalDAO;
import model.Hospital;

public class HospitalService {
    private HospitalDAO hospitalDAO = new HospitalDAO();

    public boolean conectar() {
        return hospitalDAO.conectar();
    }

    public Hospital buscarHospital(int id) {
        return hospitalDAO.get(id);
    }

    public Hospital[] listarHospitais() {
        return hospitalDAO.listar();
    }
}
