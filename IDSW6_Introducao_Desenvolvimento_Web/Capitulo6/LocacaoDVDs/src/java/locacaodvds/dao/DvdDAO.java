package locacaodvds.dao;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import locacaodvds.entidades.Ator;
import locacaodvds.entidades.ClassificacaoEtaria;
import locacaodvds.entidades.Dvd;
import locacaodvds.entidades.Genero;

public class DvdDAO extends DAO<Dvd> {

    public DvdDAO() throws SQLException {
    }
    
    @Override
    public void salvar(Dvd obj) throws SQLException {
        PreparedStatement stmt = getConnection().prepareStatement(
            """
                INSERT INTO
                dvd(titulo, ano_lancamento, ator_principal_id, ator_coadjuvante_id, 
                    data_lancamento, duracao_minutos, classificacao_etaria_id, genero_id)
                VALUES (?, ?, ?, ?, ?, ?, ?, ?);
            """
        );

        stmt.setString(1, obj.getTitulo());
        stmt.setInt(2, obj.getAnoLancamento());
        stmt.setInt(3, obj.getAtorPrincipal().getId());
        stmt.setInt(4, obj.getAtorCoadjuvante().getId());
        stmt.setDate(5, obj.getDataLancamento());
        stmt.setInt(6, obj.getDuracaoMinutos());
        stmt.setInt(7, obj.getClassificacaoEtaria().getId());
        stmt.setInt(8, obj.getGenero().getId());

        stmt.executeUpdate();
        stmt.close();
    }

    @Override
    public void atualizar(Dvd obj) throws SQLException {
        PreparedStatement stmt = getConnection().prepareStatement(
            """
                UPDATE dvd SET
                    titulo = ?,
                    ano_lancamento = ?,
                    ator_principal_id = ?,
                    ator_coadjuvante_id = ?,
                    data_lancamento = ?,
                    duracao_minutos = ?,
                    classificacao_etaria_id = ?,
                    genero_id = ?
                WHERE
                    id = ?;
            """
        );

        stmt.setString(1, obj.getTitulo());
        stmt.setInt(2, obj.getAnoLancamento());
        stmt.setInt(3, obj.getAtorPrincipal().getId());
        stmt.setInt(4, obj.getAtorCoadjuvante().getId());
        stmt.setDate(5, obj.getDataLancamento());
        stmt.setInt(6, obj.getDuracaoMinutos());
        stmt.setInt(7, obj.getClassificacaoEtaria().getId());
        stmt.setInt(8, obj.getGenero().getId());
        stmt.setInt(9, obj.getId());

        stmt.executeUpdate();
        stmt.close();
    }

    @Override
    public void excluir(Dvd obj) throws SQLException {
        PreparedStatement stmt = getConnection().prepareStatement(
            """
                DELETE FROM dvd
                WHERE id = ?;
            """
        );

        stmt.setInt(1, obj.getId());

        stmt.executeUpdate();
        stmt.close();
    }

    @Override
    public List<Dvd> listarTodos() throws SQLException {
        List<Dvd> lista = new ArrayList<>();

        PreparedStatement stmt = getConnection().prepareStatement(
            """
                SELECT
                    d.id idDvd,
                    d.titulo tituloDvd,
                    d.ano_lancamento anoLancamentoDvd,
                    d.data_lancamento dataLancamentoDvd,
                    d.duracao_minutos duracaoMinutosDvd,
                    g.id idGenero,
                    g.descricao descricaoGenero,
                    ce.id idClassificacaoEtaria,
                    ce.descricao descricaoClassificacaoEtaria,
                    a.id idAtorPrincipal,
                    a.nome nomeAtorPrincipal,
                    a1.id idAtorCoadjuvante,
                    a1.nome nomeAtorCoadjuvante
                FROM
                    dvd d,
                    genero g,
                    classificacao_etaria ce,
                    ator a,
                    ator a1
                WHERE
                    d.ator_principal_id = a.id AND
                    d.ator_coadjuvante_id = a1.id AND
                    d.classificacao_etaria_id = ce.id AND
                    d.genero_id = g.id
                ORDER BY d.titulo, d.ano_lancamento;
            """
        );

        ResultSet rs = stmt.executeQuery();

        while (rs.next()) {

            Dvd d = new Dvd();
            Ator aP = new Ator();
            Ator aC = new Ator();
            ClassificacaoEtaria ce = new ClassificacaoEtaria();
            Genero g = new Genero();

            d.setId(rs.getInt("idDvd"));
            d.setTitulo(rs.getString("tituloDvd"));
            d.setAnoLancamento(rs.getInt("anoLancamentoDvd"));
            d.setAtorPrincipal(aP);
            d.setAtorCoadjuvante(aC);
            d.setDataLancamento(rs.getDate("dataLancamentoDvd"));
            d.setDuracaoMinutos(rs.getInt("duracaoMinutosDvd"));
            d.setClassificacaoEtaria(ce);
            d.setGenero(g);

            aP.setId(rs.getInt("idAtorPrincipal"));
            aP.setNome(rs.getString("nomeAtorPrincipal"));
            
            aC.setId(rs.getInt("idAtorCoadjuvante"));
            aC.setNome(rs.getString("nomeAtorCoadjuvante"));
            
            ce.setId(rs.getInt("idClassificacaoEtaria"));
            ce.setDescricao(rs.getString("descricaoClassificacaoEtaria"));
            
            g.setId(rs.getInt("idGenero"));
            g.setDescricao(rs.getString("descricaoGenero"));

            lista.add(d);

        }

        rs.close();
        stmt.close();

        return lista;
    }

    @Override
    public Dvd obterPorId(int id) throws SQLException {
        Dvd d = null;

        PreparedStatement stmt = getConnection().prepareStatement(
            """
                SELECT
                    d.id idDvd,
                    d.titulo tituloDvd,
                    d.ano_lancamento anoLancamentoDvd,
                    d.data_lancamento dataLancamentoDvd,
                    d.duracao_minutos duracaoMinutosDvd,
                    g.id idGenero,
                    g.descricao descricaoGenero,
                    ce.id idClassificacaoEtaria,
                    ce.descricao descricaoClassificacaoEtaria,
                    a.id idAtorPrincipal,
                    a.nome nomeAtorPrincipal,
                    a1.id idAtorCoadjuvante,
                    a1.nome nomeAtorCoadjuvante
                FROM
                    dvd d,
                    genero g,
                    classificacao_etaria ce,
                    ator a,
                    ator a1
                WHERE
                    d.ator_principal_id = a.id AND
                    d.ator_coadjuvante_id = a1.id AND
                    d.classificacao_etaria_id = ce.id AND
                    d.genero_id = g.id AND
                    d.id = ?;
            """
        );

        stmt.setInt(1, id);

        ResultSet rs = stmt.executeQuery();

        if (rs.next()) {

            d = new Dvd();
            Ator aP = new Ator();
            Ator aC = new Ator();
            ClassificacaoEtaria ce = new ClassificacaoEtaria();
            Genero g = new Genero();

            d.setId(rs.getInt("idDvd"));
            d.setTitulo(rs.getString("tituloDvd"));
            d.setAnoLancamento(rs.getInt("anoLancamentoDvd"));
            d.setAtorPrincipal(aP);
            d.setAtorCoadjuvante(aC);
            d.setDataLancamento(rs.getDate("dataLancamentoDvd"));
            d.setDuracaoMinutos(rs.getInt("duracaoMinutosDvd"));
            d.setClassificacaoEtaria(ce);
            d.setGenero(g);

            aP.setId(rs.getInt("idAtorPrincipal"));
            aP.setNome(rs.getString("nomeAtorPrincipal"));
            
            aC.setId(rs.getInt("idAtorCoadjuvante"));
            aC.setNome(rs.getString("nomeAtorCoadjuvante"));
            
            ce.setId(rs.getInt("idClassificacaoEtaria"));
            ce.setDescricao(rs.getString("descricaoClassificacaoEtaria"));
            
            g.setId(rs.getInt("idGenero"));
            g.setDescricao(rs.getString("descricaoGenero"));

        }

        rs.close();
        stmt.close();

        return d;
    }
    
}
