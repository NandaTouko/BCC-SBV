package cadastroclientes.controladores.filtros;

import java.io.IOException;
import jakarta.servlet.Filter;
import jakarta.servlet.FilterChain;
import jakarta.servlet.ServletException;
import jakarta.servlet.ServletRequest;
import jakarta.servlet.ServletResponse;
import jakarta.servlet.annotation.WebFilter;

@WebFilter( filterName = "ConfigurarEncodingFilter", 
            urlPatterns = { "/*" } )
public class ConfigurarEncodingFilter implements Filter {
    
    @Override
    public void doFilter( 
            ServletRequest request,
            ServletResponse response,
            FilterChain chain )
            throws IOException, ServletException {
        
        request.setCharacterEncoding( "UTF-8" );
        chain.doFilter( request, response );
        
    }
    
}
