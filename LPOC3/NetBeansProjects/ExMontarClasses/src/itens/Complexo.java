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
    
    /* Problema: Só printa no terminal
    void imprime() {
        System.out.println(real + " + " + imaginario + "j");
    }
    */
    
    String converteParaTexto() {
        String texto = real + " + " + imaginario + "j";
        return texto;
    }
}
