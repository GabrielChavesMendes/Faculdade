package model;


public class Prontuario {

    private String cpfPaciente;
    private String descricao;
    private String dataAtendimento;
    private String status;  
    private int idHospital;
    private String medicoResp;
    
    public Prontuario() {}

    public Prontuario( String cpfPaciente, String descricao, String date, String status, int idHospital, String medicoResp) {
        this.cpfPaciente = cpfPaciente;
        this.descricao = descricao;
        this.dataAtendimento = date;
        this.status = status;
        this.idHospital = idHospital;
        this.medicoResp = medicoResp;
    }

    public String getCpfPaciente() {
        return cpfPaciente;
    }

    public void setCpfPaciente(String cpfPaciente) {
        this.cpfPaciente = cpfPaciente;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public String getDataAtendimento() {
        return dataAtendimento;
    }

    public void setDataAtendimento(String dataAtendimento) {
        this.dataAtendimento = dataAtendimento;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public int getIdHospital() {
        return idHospital;
    }

    public void setIdHospital(int idHospital) {
        this.idHospital = idHospital;
    }

    public String getMedicoResp() {
        return medicoResp;
    }

    public void setMedicoResp(String medicoResp) {
        this.medicoResp = medicoResp;
    }
    @Override
    public String toString() {
        return "Prontuario [cpfPaciente=" + cpfPaciente + ", descricao=" + descricao 
            + ", dataAtendimento=" + dataAtendimento + ", status=" + status + ", idHospital=" + idHospital + ", medicoResp=" + medicoResp +"]";
    }

    
}
