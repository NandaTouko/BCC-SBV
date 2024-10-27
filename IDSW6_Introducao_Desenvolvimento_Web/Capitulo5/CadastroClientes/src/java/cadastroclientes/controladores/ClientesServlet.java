package cadastroclientes.controladores;

import cadastroclientes.dao.ClienteDAO;
import cadastroclientes.entidades.Cidade;
import cadastroclientes.entidades.Cliente;
import java.io.IOException;
import java.sql.Date;
import java.sql.SQLException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet( name = "ClientesServlet", 
             urlPatterns = { "/processaClientes" } )
public class ClientesServlet extends HttpServlet {
    protected boolean temErrosInputs(Cliente c) {
        boolean validaNome = c.getNome().length() > 45 || c.getNome().isEmpty();
        boolean validaSobrenome = c.getSobrenome().length() > 45 || c.getSobrenome().isEmpty();
        boolean validaDataNasc = c.getDataNascimento() == null;
        boolean validaCPF = c.getCpf().isEmpty() || !c.getCpf().matches("\\d{3}\\.\\d{3}\\.\\d{3}-\\d{2}");
        boolean validaEmail = c.getEmail().isEmpty() || c.getEmail().length() > 60
                || !c.getEmail().matches("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        boolean validaLogradouro = c.getLogradouro().length() > 50 || c.getLogradouro().isEmpty();
        boolean validaNumero = c.getNumero().length() > 6 || c.getNumero().isEmpty();
        boolean validaBairro = c.getBairro().length() > 30 || c.getBairro().isEmpty();
        boolean validaCEP = c.getCep().isEmpty() || !c.getCep().matches("\\d{5}-\\d{3}");
        
        return (validaNome || validaSobrenome || validaDataNasc || validaCPF || validaEmail
                || validaLogradouro || validaNumero || validaBairro || validaCEP);
    }

    protected void processRequest( 
            HttpServletRequest request, 
            HttpServletResponse response )
            throws ServletException, IOException {
        
        String acao = request.getParameter( "acao" );
        
        ClienteDAO dao = null;
        RequestDispatcher disp = null;
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        
        try {

            dao = new ClienteDAO();

            if ( acao.equals( "inserir" ) ) {

                String nome = request.getParameter( "nome" );
                String sobrenome = request.getParameter( "sobrenome" );
                String dataNascimento = request.getParameter( "dataNascimento" );
                String cpf = request.getParameter( "cpf" );
                String email = request.getParameter( "email" );
                String logradouro = request.getParameter( "logradouro" );
                String numero = request.getParameter( "numero" );
                String bairro = request.getParameter( "bairro" );
                String cep = request.getParameter( "cep" );
                int idCidade = Integer.parseInt( 
                        request.getParameter( "idCidade" ) );

                Cidade ci = new Cidade();
                ci.setId( idCidade );

                Cliente c = new Cliente();
                c.setNome( nome );
                c.setSobrenome( sobrenome );
                
                if(!dataNascimento.isEmpty()) {
                    c.setDataNascimento( Date.valueOf( 
                        LocalDate.parse( dataNascimento, dtf ) ) );
                }
                
                c.setCpf( cpf );
                c.setEmail( email );
                c.setLogradouro( logradouro );
                c.setNumero( numero );
                c.setBairro( bairro );
                c.setCep( cep );
                c.setCidade( ci );
                
                boolean temErros = temErrosInputs(c);
                
                if(temErros) {
                    request.setAttribute("cliente", c);
                    
                    if(!cpf.matches("\\d{3}\\.\\d{3}\\.\\d{3}-\\d{2}")) {
                        request.setAttribute("cpfInvalido", true);
                    }
                    
                    if(!email.matches("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$")) {
                        request.setAttribute("emailInvalido", true);
                    }
                    
                    if(!cep.matches("\\d{5}-\\d{3}")) {
                        request.setAttribute("cepInvalido", true);
                    }
                    
                    disp = request.getRequestDispatcher(
                            "/formularios/clientes/erro.jsp" );
                } else {
                    dao.salvar( c );

                    disp = request.getRequestDispatcher(
                            "/formularios/clientes/listagem.jsp" );
                }                

            } else if ( acao.equals( "alterar" ) ) {

                int id = Integer.parseInt(request.getParameter( "id" ));
                String nome = request.getParameter( "nome" );
                String sobrenome = request.getParameter( "sobrenome" );
                String dataNascimento = request.getParameter( "dataNascimento" );
                String cpf = request.getParameter( "cpf" );
                String email = request.getParameter( "email" );
                String logradouro = request.getParameter( "logradouro" );
                String numero = request.getParameter( "numero" );
                String bairro = request.getParameter( "bairro" );
                String cep = request.getParameter( "cep" );
                int idCidade = Integer.parseInt( 
                        request.getParameter( "idCidade" ) );

                Cidade ci = new Cidade();
                ci.setId( idCidade );

                Cliente c = new Cliente();
                c.setId( id );
                c.setNome( nome );
                c.setSobrenome( sobrenome );
                
                if(!dataNascimento.isEmpty()) {
                    c.setDataNascimento( Date.valueOf( 
                            LocalDate.parse( dataNascimento, dtf ) ) );
                }
                
                c.setCpf( cpf );
                c.setEmail( email );
                c.setLogradouro( logradouro );
                c.setNumero( numero );
                c.setBairro( bairro );
                c.setCep( cep );
                c.setCidade( ci );
                
                boolean temErros = temErrosInputs(c);
                
                if(temErros) {
                    request.setAttribute("cliente", c);
                    
                    if(!cpf.matches("\\d{3}\\.\\d{3}\\.\\d{3}-\\d{2}")) {
                        request.setAttribute("cpfInvalido", true);
                    }
                    
                    if(!email.matches("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$")) {
                        request.setAttribute("emailInvalido", true);
                    }
                    
                    if(!cep.matches("\\d{5}-\\d{3}")) {
                        request.setAttribute("cepInvalido", true);
                    }
                    
                    disp = request.getRequestDispatcher(
                            "/formularios/clientes/erro.jsp" );
                } else {
                    dao.atualizar( c );

                    disp = request.getRequestDispatcher(
                            "/formularios/clientes/listagem.jsp" );
                }                

            } else if ( acao.equals( "excluir" ) ) {

                int id = Integer.parseInt(request.getParameter( "id" ));

                Cliente c = new Cliente();
                c.setId( id );

                dao.excluir( c );

                disp = request.getRequestDispatcher(
                        "/formularios/clientes/listagem.jsp" );

            } else {
                
                int id = Integer.parseInt(request.getParameter( "id" ));
                Cliente c = dao.obterPorId( id );
                request.setAttribute( "cliente", c );
                
                if ( acao.equals( "prepararAlteracao" ) ) {
                    disp = request.getRequestDispatcher( 
                            "/formularios/clientes/alterar.jsp" );
                } else if ( acao.equals( "prepararExclusao" ) ) {
                    disp = request.getRequestDispatcher( 
                            "/formularios/clientes/excluir.jsp" );
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

    @Override
    protected void doGet( 
            HttpServletRequest request, 
            HttpServletResponse response )
            throws ServletException, IOException {
        processRequest( request, response );
    }

    @Override
    protected void doPost( 
            HttpServletRequest request, 
            HttpServletResponse response )
            throws ServletException, IOException {
        processRequest( request, response );
    }

    @Override
    public String getServletInfo() {
        return "ClientesServlet";
    }

}
