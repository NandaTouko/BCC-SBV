package listarcomajax.dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import listarcomajax.entidades.Fruta;

public class FrutaDAO extends DAO<Fruta> {
    public FrutaDAO() throws SQLException {
        super();
    }

    @Override
    public void salvar(Fruta obj) throws SQLException {
        String sql = "INSERT INTO fruta( nome, cor ) "
                + "VALUES( ?, ? );";

        PreparedStatement stmt = getConnection().prepareStatement(sql);
        stmt.setString(1, obj.getNome());
        stmt.setString(2, obj.getCor());
        stmt.executeUpdate();
        stmt.close();
    }

    @Override
    public void atualizar(Fruta obj) throws SQLException {
        String sql = """
                        UPDATE fruta SET
                            nome = ?,
                            cor = ?
                        WHERE id = ?;
                     """;

        PreparedStatement stmt = getConnection().prepareStatement(sql);
        stmt.setString(1, obj.getNome());
        stmt.setString(2, obj.getCor());
        stmt.setInt(3, obj.getId());

        stmt.executeUpdate();
        stmt.close();
    }

    @Override
    public void excluir(Fruta obj) throws SQLException {
        String sql = "DELETE FROM fruta WHERE id = ?;";
        PreparedStatement stmt = getConnection().prepareStatement(sql);
        stmt.setInt(1, obj.getId());

        stmt.executeUpdate();
        stmt.close();
    }

    @Override
    public List<Fruta> listarTodos() throws SQLException {
        List<Fruta> lista = new ArrayList<>();
        String sql = "SELECT * FROM fruta;";

        PreparedStatement stmt = getConnection().prepareStatement(sql);
        ResultSet rs = stmt.executeQuery();

        while (rs.next()) {

            Fruta fruta = new Fruta();
            fruta.setId(rs.getInt("id"));
            fruta.setNome(rs.getString("nome"));
            fruta.setCor(rs.getString("cor"));

            lista.add(fruta);

        }

        rs.close();
        stmt.close();

        return lista;
    }

    @Override
    public Fruta obterPorId(int id) throws SQLException {
        Fruta fruta = null;
        String sql = "SELECT * FROM fruta WHERE id = ?;";

        PreparedStatement stmt = getConnection().prepareStatement(sql);
        stmt.setInt(1, id);

        ResultSet rs = stmt.executeQuery();

        if (rs.next()) {

            fruta = new Fruta();
            fruta.setId(rs.getInt("id"));
            fruta.setNome(rs.getString("nome"));
            fruta.setCor(rs.getString("cor"));

        }

        rs.close();
        stmt.close();
        
        return fruta;
    }
    
}
