package locacaodvds.controladores;

import jakarta.servlet.RequestDispatcher;
import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.sql.Date;
import java.sql.SQLException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import locacaodvds.dao.DvdDAO;
import locacaodvds.entidades.Ator;
import locacaodvds.entidades.ClassificacaoEtaria;
import locacaodvds.entidades.Dvd;
import locacaodvds.entidades.Genero;

@WebServlet(name = "DvdServlet", urlPatterns = {"/DvdServlet"})
public class DvdServlet extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String acao = request.getParameter( "acao" );
        DvdDAO dao = null;
        RequestDispatcher disp = null;
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy-MM-dd");

        try {

            dao = new DvdDAO();

            if ( acao.equals( "inserir" ) ) {

                String titulo = request.getParameter("titulo");
                int anoLancamento = Integer.parseInt(request.getParameter("anoLancamento"));
                int atorPrincipalId = Integer.parseInt(request.getParameter("atorPrincipalId"));
                int atorCoadjuvanteId = Integer.parseInt(request.getParameter("atorCoadjuvanteId"));
                String dataLancamento = request.getParameter("dataLancamento");
                int duracaoMinutos = Integer.parseInt(request.getParameter("duracaoMinutos"));
                int classificacaoEtariaId = Integer.parseInt(request.getParameter("classificacaoEtariaId"));
                int generoId = Integer.parseInt(request.getParameter("generoId"));

                Ator ap = new Ator();
                ap.setId(atorPrincipalId);
                
                Ator ac = new Ator();
                ac.setId(atorCoadjuvanteId);
                
                ClassificacaoEtaria ce = new ClassificacaoEtaria();
                ce.setId(classificacaoEtariaId);
                
                Genero g = new Genero();
                g.setId(generoId);
                
                Dvd d = new Dvd();
                d.setTitulo(titulo);
                d.setAnoLancamento(anoLancamento);
                d.setDuracaoMinutos(duracaoMinutos);
                d.setAtorPrincipal(ap);
                d.setAtorCoadjuvante(ac);
                d.setClassificacaoEtaria(ce);
                d.setGenero(g);
                
                if(!dataLancamento.isEmpty()) {
                    d.setDataLancamento(Date.valueOf( 
                        LocalDate.parse(dataLancamento, dtf)));
                }
                
                dao.salvar(d);

                disp = request.getRequestDispatcher(
                        "/formularios/dvds/listagem.jsp" );

            } else if ( acao.equals( "alterar" ) ) {

                int id = Integer.parseInt(request.getParameter("id"));
                String titulo = request.getParameter("titulo");
                int anoLancamento = Integer.parseInt(request.getParameter("anoLancamento"));
                int atorPrincipalId = Integer.parseInt(request.getParameter("atorPrincipalId"));
                int atorCoadjuvanteId = Integer.parseInt(request.getParameter("atorCoadjuvanteId"));
                String dataLancamento = request.getParameter("dataLancamento");
                int duracaoMinutos = Integer.parseInt(request.getParameter("duracaoMinutos"));
                int classificacaoEtariaId = Integer.parseInt(request.getParameter("classificacaoEtariaId"));
                int generoId = Integer.parseInt(request.getParameter("generoId"));

                Ator ap = new Ator();
                ap.setId(atorPrincipalId);
                
                Ator ac = new Ator();
                ac.setId(atorCoadjuvanteId);
                
                ClassificacaoEtaria ce = new ClassificacaoEtaria();
                ce.setId(classificacaoEtariaId);
                
                Genero g = new Genero();
                g.setId(generoId);
                
                Dvd d = new Dvd();
                d.setTitulo(titulo);
                d.setAnoLancamento(anoLancamento);
                d.setDuracaoMinutos(duracaoMinutos);
                d.setAtorPrincipal(ap);
                d.setAtorCoadjuvante(ac);
                d.setClassificacaoEtaria(ce);
                d.setGenero(g);
                d.setId(id);
                
                if(!dataLancamento.isEmpty()) {
                    d.setDataLancamento(Date.valueOf( 
                        LocalDate.parse(dataLancamento, dtf)));
                }

                dao.atualizar(d);

                disp = request.getRequestDispatcher(
                        "/formularios/dvds/listagem.jsp" );              

            } else if ( acao.equals( "excluir" ) ) {

                int id = Integer.parseInt(request.getParameter("id"));

                Dvd d = new Dvd();
                d.setId(id);

                dao.excluir(d);

                disp = request.getRequestDispatcher(
                        "/formularios/dvds/listagem.jsp" );

            } else {
                
                int id = Integer.parseInt(request.getParameter("id"));
                Dvd d = dao.obterPorId(id);
                request.setAttribute("dvd", d);
                
                if ( acao.equals( "prepararAlteracao" ) ) {
                    disp = request.getRequestDispatcher( 
                            "/formularios/dvds/alterar.jsp" );
                } else if ( acao.equals( "prepararExclusao" ) ) {
                    disp = request.getRequestDispatcher( 
                            "/formularios/dvds/excluir.jsp" );
                }
                
            }

        } catch ( SQLException exc ) {
            exc.printStackTrace();
        } finally {
            if ( dao != null ) {
                try {
                    dao.fecharConexao();
                } catch ( SQLException exc ) {
                    exc.printStackTrace();
                }
            }
        }

        if ( disp != null ) {
            disp.forward( request, response );
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
