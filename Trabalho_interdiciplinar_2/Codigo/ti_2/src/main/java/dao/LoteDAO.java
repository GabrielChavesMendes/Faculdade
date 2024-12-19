package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import model.Lote;

public class LoteDAO {
    private Connection conexao;

    public LoteDAO() {
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

    public boolean insert(Lote remedio) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            st.executeUpdate("INSERT INTO mydb.lote (id_remedio, codigo, validade, data_fabricacao, quantidade, dosagem, id_hospital) "
                           + "VALUES (" + remedio.getIdRemedio() + ", '" + remedio.getCodigo() + "', '" 
                           + remedio.getValidade() + "', '" + remedio.getDataFabricacao() + "', " + remedio.getQuantidade() + " , " + remedio.getDosagem() + " , " + remedio.getIdHospital()  +");");
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public boolean update(Lote remedio) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            String sql = "UPDATE mydb.lote SET quantidade = " + remedio.getQuantidade() + " WHERE codigo = '" + remedio.getCodigo() + "'"; 
            st.executeUpdate(sql);
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public boolean remove(String codigo) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            st.executeUpdate("DELETE FROM mydb.lote WHERE codigo = '" + codigo + "'");
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public Lote getId(int id) {
        Lote remedio = null;
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.lote WHERE id_hospital = " + id);      
            if(rs.next()) {
                remedio = new Lote(rs.getInt("id_remedio"), rs.getString("codigo"), rs.getInt("quantidade"), rs.getString("data_fabricacao"),  rs.getString("validade"), rs.getInt("dosagem"), rs.getInt("id_hospital"));
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return remedio;
    }

    public Lote getCodigo(String codigo) {
        Lote remedio = null;
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.lote WHERE codigo = '" + codigo + "'");      
            if(rs.next()) {
                remedio = new Lote(rs.getInt("id_remedio"), rs.getString("codigo"), rs.getInt("quantidade"), rs.getString("data_fabricacao"),  rs.getString("validade"), rs.getInt("dosagem"), rs.getInt("id_hospital"));
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return remedio;
    }

    public Lote[] listar() {
        Lote[] remedios = null;
        
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.lote");      
            if(rs.next()) {
                rs.last();
                remedios = new Lote[rs.getRow()];
                rs.beforeFirst();

                for(int i = 0; rs.next(); i++) {
                    remedios[i] = new Lote(rs.getInt("id_remedio"), rs.getString("codigo"), rs.getInt("quantidade"), rs.getString("data_fabricacao"),  rs.getString("validade"), rs.getInt("dosagem"), rs.getInt("id_hospital"));
                }
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return remedios;
    }
}
