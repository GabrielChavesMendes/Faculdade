package dao;

import java.sql.*;
import model.Farmaceutico;

public class FarmaceuticoDAO {
    private Connection conexao;

    public FarmaceuticoDAO() {
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

    public boolean insert(Farmaceutico farmaceutico) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            st.executeUpdate("INSERT INTO mydb.farmaceutico (CRF, nome, senha, email, id_hospital) "
                           + "VALUES ('" + farmaceutico.getCrf() + "', '" + farmaceutico.getNome() + "', '" 
                           + farmaceutico.getSenha() + "', '" + farmaceutico.getEmail() + "', "
                           + farmaceutico.getIdHospital() + ");");
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public boolean update(Farmaceutico farmaceutico) {   //o crf foi alterado para minusculo
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            String sql = "UPDATE mydb.farmaceutico SET nome = '" + farmaceutico.getNome() 
                       + "', senha = '" + farmaceutico.getSenha() 
                       + "', email = '" + farmaceutico.getEmail() 
                       + "', id_hospital = " + farmaceutico.getIdHospital() 
                       + " WHERE crf = '" + farmaceutico.getCrf() + "'";
            st.executeUpdate(sql);
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public boolean remove(String crf) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            st.executeUpdate("DELETE FROM mydb.farmaceutico WHERE crf = '" + crf + "'");
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public Farmaceutico get(String crf) {
        Farmaceutico farmaceutico = null;
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.farmaceutico WHERE crf = '" + crf + "'");      
            if(rs.next()) {
                farmaceutico = new Farmaceutico(rs.getString("CRF"), rs.getString("nome"), rs.getString("senha"), 
                                                rs.getString("email"), rs.getInt("id_hospital"));
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return farmaceutico;
    }

    public Farmaceutico[] listar() {
        Farmaceutico[] farmaceuticos = null;
        
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.farmaceutico");      
            if(rs.next()) {
                rs.last();
                farmaceuticos = new Farmaceutico[rs.getRow()];
                rs.beforeFirst();

                for(int i = 0; rs.next(); i++) {
                    farmaceuticos[i] = new Farmaceutico(rs.getString("crf"), rs.getString("nome"), rs.getString("senha"), 
                                                        rs.getString("email"), rs.getInt("id_hospital"));
                }
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return farmaceuticos;
    }
}
