package itens;

/**
 * @author BV3024679
 */
public class Complexo {
    // Atributos
    double imaginario;
    double real;
    
    // Métodos
    Complexo somar(Complexo outro){
        Complexo c = new Complexo();
        
        c.imaginario = imaginario + outro.imaginario;
        c.real = real + outro.real;
        
        return c;
    }
}
