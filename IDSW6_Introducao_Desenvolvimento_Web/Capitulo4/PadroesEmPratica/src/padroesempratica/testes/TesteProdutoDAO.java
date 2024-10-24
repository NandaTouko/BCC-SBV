package padroesempratica.testes;

import java.sql.SQLException;
import padroesempratica.dao.ProdutoDAO;
import padroesempratica.entidades.Produto;

public class TesteProdutoDAO {
    public static void main(String[] args) {
        Produto prod = new Produto();
        prod.setDescricao("Caixa de Leite (12 unidades)");
        prod.setQtdEstoque(100);
        ProdutoDAO dao = null;
        
        try {
            dao = new ProdutoDAO();
            dao.salvar(prod);
        } catch (SQLException exc) {
            exc.printStackTrace();
        } finally {
            if (dao != null) {
                try {
                    dao.fecharConexao();
                } catch (SQLException exc) {
                    System.err.println("Erro ao fechar a conexão!");
                    exc.printStackTrace();
                }
            }
        }
    }
}
