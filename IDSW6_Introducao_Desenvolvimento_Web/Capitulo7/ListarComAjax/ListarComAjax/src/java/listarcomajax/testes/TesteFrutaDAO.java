package listarcomajax.testes;

import java.sql.SQLException;
import listarcomajax.dao.FrutaDAO;
import listarcomajax.entidades.Fruta;

public class TesteFrutaDAO {
    public static void main(String[] args) {
        Fruta fruta = new Fruta();
        fruta.setNome("Morango");
        fruta.setCor("Vermelho");
        FrutaDAO dao = null;
        
        try {
            dao = new FrutaDAO();
            dao.salvar(fruta);
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
