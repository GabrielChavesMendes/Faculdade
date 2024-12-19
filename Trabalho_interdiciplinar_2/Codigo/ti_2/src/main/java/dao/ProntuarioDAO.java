package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import model.Prontuario;

public class ProntuarioDAO {
    private Connection conexao;

    public ProntuarioDAO() {
        conexao = null;
    }

    public boolean conectar() {
        String driverName = "org.postgresql.Driver";                    
        String serverName = "medlog.postgres.database.azure.com";
        String mydatabase = "postgres";
        int porta = 5432;
        String url = "jdbc:postgresql://" + serverName + ":" + porta + "/" + mydatabase;
        String username = "medlogadmin";
        String password = "123456789a@";
        boolean status = false;

        try {
            Class.forName(driverName);
            conexao = DriverManager.getConnection(url, username, password);
            status = (conexao != null);
            System.out.println("Conexão efetuada com o postgres!");
        } catch (ClassNotFoundException e) { 
            System.err.println("Conexão NÃO efetuada com o postgres -- Driver não encontrado -- " + e.getMessage());
        } catch (SQLException e) {
            System.err.println("Conexão NÃO efetuada com o postgres -- " + e.getMessage());
        }

        return status;
    }

    public boolean close() {
        boolean status = false;
        try {
            conexao.close();
            status = true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return status;
    }

    public boolean insert(Prontuario prontuario) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            st.executeUpdate("INSERT INTO mydb.prontuario (id_cpf, descricao, data_prontuario, status, id_hospital, medico_responsavel) "
                + "VALUES ('" + prontuario.getCpfPaciente() + "', '" 
                + prontuario.getDescricao() + "', '" + prontuario.getDataAtendimento() + "', '" 
                + prontuario.getStatus() + "', " + prontuario.getIdHospital() + ", '"+ prontuario.getMedicoResp() +"');");
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public boolean update(Prontuario prontuario) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            String sql = "UPDATE mydb.prontuario SET descricao = '" + prontuario.getDescricao() + "', data_prontuario = '" + prontuario.getDataAtendimento() 
                        + "', status = '" + prontuario.getStatus() + "', id_hospital = " + prontuario.getIdHospital() + ", medico_responsavel = '" + prontuario.getMedicoResp() + "'"
                        + " WHERE id_cpf = '" + prontuario.getCpfPaciente() +"'";
            st.executeUpdate(sql);
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        
        return status;
    }

    public boolean remove(String id) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            st.executeUpdate("DELETE FROM mydb.prontuario WHERE id_cpf = '" + id +"'");
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public Prontuario get(String id) {
        Prontuario prontuario = null;
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.prontuario WHERE id_cpf = '" + id + "'");      
            if(rs.next()) {
                prontuario = new Prontuario(
                    rs.getString("id_cpf"), rs.getString("descricao"), rs.getDate("data_prontuario").toString(), 
                    rs.getString("status"), rs.getInt("id_hospital"), rs.getString("medico_responsavel")
                );
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return prontuario;
    }
    
    public Prontuario[] listar() {
        Prontuario[] prontuarios = null;
        
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.prontuario");      
            if(rs.next()) {
                rs.last();
                prontuarios = new Prontuario[rs.getRow()];
                rs.beforeFirst();
    
                for(int i = 0; rs.next(); i++) {
                    prontuarios[i] = new Prontuario(
                        rs.getString("id_cpf"), rs.getString("descricao"), rs.getDate("data_prontuario").toString(), 
                        rs.getString("status"), rs.getInt("id_hospital"), rs.getString("medico_responsavel")
                    );
                }
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return prontuarios;
    }    
}
