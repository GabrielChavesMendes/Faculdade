package dao;

import java.sql.*;
import model.Medico;

public class MedicosDAO {
    private Connection conexao;

    public MedicosDAO() {
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
        } catch (ClassNotFoundException e) {
            System.err.println("Conexão falhou! Driver não encontrado.");
        } catch (SQLException e) {
            System.err.println("Conexão falhou! Erro de SQL.");
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

    public boolean insert(Medico medico) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            st.executeUpdate("INSERT INTO mydb.medicos (crm, nome, especializacao, senha, id_hospital, email) "
                + "VALUES ('" + medico.getCrm() + "', '" + medico.getNome() + "', '" 
                + medico.getEspecialidade() + "', '" + medico.getSenha() + "', " 
                + medico.getIdHospital() + ", '" + medico.getEmail() + "');");
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public boolean update(Medico medico) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            String sql = "UPDATE mydb.medicos SET nome = '" + medico.getNome() + "', especializacao = '" 
                       + medico.getEspecialidade() + "', senha = '" + medico.getSenha() + "', "
                       + "id_hospital = " + medico.getIdHospital() + ", email = '" + medico.getEmail() + "' "
                       + "WHERE crm = '" + medico.getCrm() + "'";
            st.executeUpdate(sql);
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public boolean remove(String crm) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            st.executeUpdate("DELETE FROM mydb.medicos WHERE crm = '" + crm + "'");
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public Medico get(String crm) {
        Medico medico = null;
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.medicos WHERE crm = '" + crm + "'");      
            if(rs.next()) {
                medico = new Medico(rs.getString("crm"), rs.getString("nome"), rs.getString("especializacao"), 
                                    rs.getString("senha"), rs.getInt("id_hospital"), rs.getString("email"));
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return medico;
    }

    public Medico[] listar() {
        Medico[] medicos = null;
        
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.medicos");      
            if(rs.next()) {
                rs.last();
                medicos = new Medico[rs.getRow()];
                rs.beforeFirst();

                for(int i = 0; rs.next(); i++) {
                    medicos[i] = new Medico(rs.getString("crm"), rs.getString("nome"), rs.getString("especializacao"), 
                                            rs.getString("senha"), rs.getInt("id_hospital"), rs.getString("email"));
                }
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return medicos;
    }
}
