package listarcomajax.testes;

import java.sql.SQLException;
import listarcomajax.dao.CarroDAO;
import listarcomajax.entidades.Carro;

public class TesteCarroDAO {
    public static void main(String[] args) {
        Carro carro = new Carro();
        carro.setNome("Mobi");
        carro.setModelo("Fiat");
        carro.setAno(2020);
        CarroDAO dao = null;
        
        try {
            dao = new CarroDAO();
            dao.salvar(carro);
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
