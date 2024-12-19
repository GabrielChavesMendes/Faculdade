package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import model.Remedio;

public class RemedioDAO {
    private Connection conexao;

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


    public Remedio[] listar() {
        Remedio[] remedios = null;
        
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.remedio");      
            if(rs.next()) {
                rs.last();
                remedios = new Remedio[rs.getRow()];
                rs.beforeFirst();

                for(int i = 0; rs.next(); i++) {
                    remedios[i] = new Remedio(rs.getInt("id"), rs.getString("nome"));
                }
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return remedios;
    }

    public Remedio get(int id) {
        Remedio remedio = null;
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.remedio WHERE id = " + id);      
            if(rs.next()) {
                remedio = new Remedio(rs.getInt("id"), rs.getString("nome"));
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return remedio;
    }

}
