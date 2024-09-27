package meuprimeiroformulario.servlets;

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

/**
 *
 * @author bv3024679
 */
@WebServlet(name = "ProcessaDadosClienteServlet", urlPatterns = {"/processaDadosCliente"})
public class ProcessaDadosClienteServlet extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        
        String nome = request.getParameter("nome");
        String sobrenome = request.getParameter("sobrenome");
        String cpf = request.getParameter("cpf");
        String dataNasc = request.getParameter("dataNasc");
        String sexo = "M".equals(request.getParameter("sexo")) ? "Masculino" : "Feminino";
        String observacoes = request.getParameter("observacoes");
        String email = request.getParameter("email");
        String logradouro = request.getParameter("logradouro");
        String numero = request.getParameter("numero");
        String complemento = request.getParameter("complemento");
        String cidade = request.getParameter("cidade");
        String estado = request.getParameter("estado");
        String cep = request.getParameter("cep");
        String filhos = "S".equals(request.getParameter("filhos")) ? "Sim" : "Não";
        
        System.out.println("Dados do Cliente:");
        System.out.println("Nome: " + nome);
        System.out.println("Sobrenome: " + sobrenome);
        System.out.println("CPF: " + cpf);
        System.out.println("Data de Nascimento: " + dataNasc);
        System.out.println("E-mail: " + email);
        System.out.println("Sexo: " + sexo);
        System.out.println("Logradouro: " + logradouro);
        System.out.println("Número: " + numero);
        System.out.println("Complemento: " + complemento);
        System.out.println("Cidade: " + cidade);
        System.out.println("Estado: " + estado);
        System.out.println("CEP: " + cep);
        System.out.println("Possui filhos? " + filhos);
        System.out.println("Observações: " + observacoes);
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
