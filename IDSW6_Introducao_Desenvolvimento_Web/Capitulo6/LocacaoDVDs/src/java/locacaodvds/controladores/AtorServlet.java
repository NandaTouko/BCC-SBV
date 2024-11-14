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
import locacaodvds.dao.AtorDAO;
import locacaodvds.entidades.Ator;

@WebServlet(name = "AtorServlet", urlPatterns = {"/AtorServlet"})
public class AtorServlet extends HttpServlet {
    
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        String acao = request.getParameter( "acao" );
        AtorDAO dao = null;
        RequestDispatcher disp = null;
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy-MM-dd");

        try {

            dao = new AtorDAO();

            if ( acao.equals( "inserir" ) ) {

                String nome = request.getParameter("nome");
                String sobrenome = request.getParameter("sobrenome");
                String dataEstreia = request.getParameter( "dataEstreia" );

                Ator a = new Ator();
                a.setNome(nome);
                a.setSobrenome(sobrenome);
                
                if(!dataEstreia.isEmpty()) {
                    a.setDataEstreia(Date.valueOf( 
                        LocalDate.parse(dataEstreia, dtf)));
                }
                
                dao.salvar(a);

                disp = request.getRequestDispatcher(
                        "/formularios/atores/listagem.jsp" );

            } else if ( acao.equals( "alterar" ) ) {

                int id = Integer.parseInt(request.getParameter("id"));
                String nome = request.getParameter("nome");
                String sobrenome = request.getParameter("sobrenome");
                String dataEstreia = request.getParameter( "dataEstreia" );

                Ator a = new Ator();
                a.setNome(nome);
                a.setSobrenome(sobrenome);
                a.setId(id);
                
                if(!dataEstreia.isEmpty()) {
                    a.setDataEstreia(Date.valueOf( 
                        LocalDate.parse(dataEstreia, dtf)));
                }

                dao.atualizar(a);

                disp = request.getRequestDispatcher(
                        "/formularios/atores/listagem.jsp" );              

            } else if ( acao.equals( "excluir" ) ) {

                int id = Integer.parseInt(request.getParameter("id"));

                Ator a = new Ator();
                a.setId(id);

                dao.excluir(a);

                disp = request.getRequestDispatcher(
                        "/formularios/atores/listagem.jsp" );

            } else {
                
                int id = Integer.parseInt(request.getParameter("id"));
                Ator a = dao.obterPorId(id);
                request.setAttribute("ator", a);
                
                if ( acao.equals( "prepararAlteracao" ) ) {
                    disp = request.getRequestDispatcher( 
                            "/formularios/atores/alterar.jsp" );
                } else if ( acao.equals( "prepararExclusao" ) ) {
                    disp = request.getRequestDispatcher( 
                            "/formularios/atores/excluir.jsp" );
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
