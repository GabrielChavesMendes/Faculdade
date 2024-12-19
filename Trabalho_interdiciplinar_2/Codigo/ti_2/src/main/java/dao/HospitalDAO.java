package dao;

import java.sql.*;
import model.Hospital;

public class HospitalDAO {
    private Connection conexao;

    public HospitalDAO() {
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

    public Hospital getPorUser(String user) {
        Hospital hospital = null;
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.hospital WHERE usuario = '" + user + "'");      
            if(rs.next()) {
                hospital = new Hospital(rs.getInt("id"), rs.getString("nome"), rs.getString("usuario"), rs.getString("senha"));
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return hospital;
    }

    public Hospital get(int id) {
        Hospital hospital = null;
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.hospital WHERE id = " + id);      
            if(rs.next()) {
                hospital = new Hospital(rs.getInt("id"), rs.getString("nome"), rs.getString("usuario"), rs.getString("senha"));
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return hospital;
    }

    public Hospital[] listar() {
        Hospital[] hospitais = null;
        
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.hospital");      
            if(rs.next()) {
                rs.last();
                hospitais = new Hospital[rs.getRow()];
                rs.beforeFirst();

                for(int i = 0; rs.next(); i++) {
                    hospitais[i] = new Hospital(rs.getInt("id"), rs.getString("nome"), rs.getString("usuario"), rs.getString("senha"));
                }
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return hospitais;
    }
}
