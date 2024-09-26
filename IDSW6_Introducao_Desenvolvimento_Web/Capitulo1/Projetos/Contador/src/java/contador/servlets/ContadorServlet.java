package contador.servlets;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 *
 * @author bv3024679
 */
@WebServlet(name="ContadorServlet", urlPatterns={"/iniciar"})
public class ContadorServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        processRequest(req, resp);
    }
    
    private void processRequest(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        for(int i = 1; i <= 30; i++){
            System.out.println(i);
        }
    }
}
