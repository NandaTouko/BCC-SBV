package servlets;

import entidades.Cliente;
import jakarta.servlet.RequestDispatcher;
import java.io.IOException;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet(name = "ProcessaDadosClienteServlet", urlPatterns = {"/processaDadosCliente"})
public class ProcessaDadosClienteServlet extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        
        Cliente c = new Cliente();
        
        c.setNome(request.getParameter("nome"));
        c.setSobrenome(request.getParameter("sobrenome"));
        c.setCpf(request.getParameter("cpf"));
        c.setDataNasc(request.getParameter("dataNasc"));
        c.setSexo(request.getParameter("sexo"));
        c.setObservacoes(request.getParameter("observacoes"));
        c.setEmail(request.getParameter("email"));
        c.setLogradouro(request.getParameter("logradouro"));
        c.setNumero(request.getParameter("numero"));
        c.setComplemento(request.getParameter("complemento"));
        c.setCidade(request.getParameter("cidade"));
        c.setEstado(request.getParameter("estado"));
        c.setCep(request.getParameter("cep"));
        c.setFilhos(request.getParameter("filhos"));
        
        request.setAttribute("cliente", c);
        
        RequestDispatcher disp = request.getRequestDispatcher("exibeDados.jsp");
        disp.forward(request, response);
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
