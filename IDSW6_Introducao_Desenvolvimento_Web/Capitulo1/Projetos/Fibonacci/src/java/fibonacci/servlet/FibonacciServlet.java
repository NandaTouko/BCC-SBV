package fibonacci.servlet;

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
@WebServlet(name="FibonacciServlet", urlPatterns={"/ateTrinta"})
public class FibonacciServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        processRequest(req, resp);
    }
    
    private void processRequest(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        for(int i = 1; i <= 30; i++) {
            int resultado = fibonacci(i);
            System.out.println("fibonacci(" + i + "): " + resultado);
        }
    }
    
    private int fibonacci(int num) {
        int antepNum;
        int penNum = 0;
        int numAtual = 1;

        if(num == 1 || num == 2) {
            return 1;
        }
        
        for(int i = 2; i <= num; i++) {
            antepNum = penNum;
            penNum = numAtual;
            numAtual = antepNum + penNum;
        }
        
        return numAtual;
    }
            
}
