package padroesempratica.testes;

import java.sql.SQLException;
import padroesempratica.dao.PaisDAO;
import padroesempratica.entidades.Pais;

public class TestePaisDAO {
    public static void main(String[] args) {
        Pais pais = new Pais();
        pais.setNome("Brasil");
        pais.setSigla("BR");
        PaisDAO dao = null;
        
        try {
            dao = new PaisDAO();
            dao.salvar(pais);
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
