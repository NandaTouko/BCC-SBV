package listarcomajax.controladores;

import jakarta.json.bind.Jsonb;
import jakarta.json.bind.JsonbBuilder;
import jakarta.servlet.RequestDispatcher;
import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.sql.SQLException;
import java.util.List;
import listarcomajax.dao.ProdutoDAO;
import listarcomajax.entidades.Produto;

@WebServlet(name = "ProdutoServlet", urlPatterns = {"/ProdutoServlet"})
public class ProdutoServlet extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        String acao = request.getParameter( "acao" );
        ProdutoDAO dao = null;
        RequestDispatcher disp = null;

        try {

            dao = new ProdutoDAO();

            if ( acao.equals( "inserir" ) ) {

                String descricao = request.getParameter("descricao");
                int qtdEstoque = Integer.parseInt(request.getParameter("qtdEstoque"));

                Produto p = new Produto();
                p.setDescricao(descricao);
                p.setQtdEstoque(qtdEstoque);
                
                dao.salvar(p);

                disp = request.getRequestDispatcher(
                        "/formularios/produtos/listagem.jsp" );

            } else {
                
                List<Produto> carros = dao.listarTodos();
                Jsonb jb = JsonbBuilder.create();
                
                try ( PrintWriter out = response.getWriter() ) {
                    out.print( jb.toJson( carros ) );
                }
                
            }

        } catch (SQLException exc) {
            exc.printStackTrace();
        } finally {
            if (dao != null) {
                try {
                    dao.fecharConexao();
                } catch (SQLException exc) {
                    exc.printStackTrace();
                }
            }
        }

        if (disp != null) {
            disp.forward(request, response);
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
