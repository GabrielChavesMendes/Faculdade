package dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import model.Pessoas;

public class PessoasDAO {
    private Connection conexao;

    public PessoasDAO() {
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

    public boolean insert(Pessoas pessoa) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            st.executeUpdate("INSERT INTO mydb.pessoas (cpf, nome, alergias, idade, tipo_sanguineo, peso, altura, senha) "
                           + "VALUES ('" + pessoa.getCpf() + "', '" + pessoa.getNome() + "', '" + pessoa.getAlergia() + "', " 
                           + pessoa.getIdade() + ", " + pessoa.getTipoSanguineo() + ", " + pessoa.getPeso() 
                           + ", " + pessoa.getAltura() + ", '" + pessoa.getSenha() + "');");
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public boolean update(Pessoas pessoa) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            String sql = "UPDATE mydb.pessoas SET nome = '" + pessoa.getNome() + "', alergias = '" + pessoa.getAlergia() 
                       + "', idade = " + pessoa.getIdade() + ", tipo_sanguineo = '" + pessoa.getTipoSanguineo() 
                       + "', peso = " + pessoa.getPeso() + ", altura = " + pessoa.getAltura() 
                       + ", senha = '" + pessoa.getSenha() + "' WHERE cpf = '" + pessoa.getCpf() + "'";
            st.executeUpdate(sql);
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public boolean remove(String cpf) {
        boolean status = false;
        try {  
            Statement st = conexao.createStatement();
            st.executeUpdate("DELETE FROM mydb.pessoas WHERE cpf = '" + cpf + "'");
            st.close();
            status = true;
        } catch (SQLException u) {  
            throw new RuntimeException(u);
        }
        return status;
    }

    public Pessoas get(String cpf) {
        Pessoas pessoa = null;
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.pessoas WHERE cpf = '" + cpf + "'");      
            if(rs.next()) {
                pessoa = new Pessoas(rs.getString("cpf"), rs.getString("nome"), rs.getString("alergias"), rs.getInt("idade"), 
                                     rs.getInt("tipo_sanguineo"), rs.getDouble("peso"), rs.getDouble("altura"), rs.getString("senha"));
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return pessoa;
    }

    public Pessoas[] listar() {
        Pessoas[] pessoas = null;
        
        try {
            Statement st = conexao.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
            ResultSet rs = st.executeQuery("SELECT * FROM mydb.pessoas");      
            if(rs.next()) {
                rs.last();
                pessoas = new Pessoas[rs.getRow()];
                rs.beforeFirst();

                for(int i = 0; rs.next(); i++) {
                    pessoas[i] = new Pessoas(rs.getString("cpf"), rs.getString("nome"), rs.getString("alergias"), rs.getInt("idade"), 
                                             rs.getInt("tipo_sanguineo"), rs.getDouble("peso"), rs.getDouble("altura"), rs.getString("senha"));
                }
            }
            st.close();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return pessoas;
    }
}
