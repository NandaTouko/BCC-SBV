package padroesempratica.dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import padroesempratica.entidades.Produto;

public class ProdutoDAO extends DAO<Produto> {
    public ProdutoDAO() throws SQLException {
        super();
    }

    @Override
    public void salvar(Produto obj) throws SQLException {
        String sql = "INSERT INTO produto( descricao, qtdEstoque ) "
                + "VALUES( ?, ? );";

        PreparedStatement stmt = getConnection().prepareStatement(sql);
        stmt.setString(1, obj.getDescricao());
        stmt.setInt(2, obj.getQtdEstoque());
        stmt.executeUpdate();
        stmt.close();
    }

    @Override
    public void atualizar(Produto obj) throws SQLException {
        String sql = """
                        UPDATE produto SET
                            descricao = ?,
                            qtdEstoque = ?
                        WHERE id = ?;
                     """;

        PreparedStatement stmt = getConnection().prepareStatement(sql);
        stmt.setString(1, obj.getDescricao());
        stmt.setInt(2, obj.getQtdEstoque());
        stmt.setInt(3, obj.getId());

        stmt.executeUpdate();
        stmt.close();
    }

    @Override
    public void excluir(Produto obj) throws SQLException {
        String sql = "DELETE FROM produto WHERE id = ?;";
        PreparedStatement stmt = getConnection().prepareStatement(sql);
        stmt.setInt(1, obj.getId());

        stmt.executeUpdate();
        stmt.close();
    }

    @Override
    public List<Produto> listarTodos() throws SQLException {
        List<Produto> lista = new ArrayList<>();
        String sql = "SELECT * FROM produto;";

        PreparedStatement stmt = getConnection().prepareStatement(sql);
        ResultSet rs = stmt.executeQuery();

        while (rs.next()) {

            Produto prod = new Produto();
            prod.setId(rs.getInt("id"));
            prod.setDescricao(rs.getString("descricao"));
            prod.setQtdEstoque(rs.getInt("qtdEstoque"));

            lista.add(prod);

        }

        rs.close();
        stmt.close();

        return lista;
    }

    @Override
    public Produto obterPorId(int id) throws SQLException {
        Produto prod = null;
        String sql = "SELECT * FROM produto WHERE id = ?;";

        PreparedStatement stmt = getConnection().prepareStatement(sql);
        stmt.setInt(1, id);

        ResultSet rs = stmt.executeQuery();

        if (rs.next()) {

            prod = new Produto();
            prod.setId(rs.getInt("id"));
            prod.setDescricao(rs.getString("descricao"));
            prod.setQtdEstoque(rs.getInt("qtdEstoque"));

        }

        rs.close();
        stmt.close();
        
        return prod;
    }
}
