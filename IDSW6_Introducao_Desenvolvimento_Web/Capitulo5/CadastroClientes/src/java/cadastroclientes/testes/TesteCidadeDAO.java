package cadastroclientes.testes;

import cadastroclientes.dao.CidadeDAO;
import cadastroclientes.dao.EstadoDAO;
import cadastroclientes.entidades.Cidade;
import cadastroclientes.entidades.Estado;
import java.sql.SQLException;

public class TesteCidadeDAO {
    public static void main(String[] args) {
        Cidade cidade = new Cidade();
        Estado estado = new Estado();
        cidade.setNome("Araraquara");
        estado.setNome("São Paulo");
        estado.setSigla("SP");
        cidade.setEstado(estado);
        
        CidadeDAO daoC = null;
        EstadoDAO daoE = null;
        
        // Não funcionou T-T
        try {
            daoE = new EstadoDAO();
            daoE.salvar(estado);
            daoC = new CidadeDAO();
            daoC.salvar(cidade);
        } catch (SQLException exc) {
            exc.printStackTrace();
        } finally {
            if (daoE != null && daoC != null) {
                try {
                    daoE.fecharConexao();
                    daoC.fecharConexao();
                } catch (SQLException exc) {
                    System.err.println("Erro ao fechar a conexão!");
                    exc.printStackTrace();
                }
            }
        }
    }
}
