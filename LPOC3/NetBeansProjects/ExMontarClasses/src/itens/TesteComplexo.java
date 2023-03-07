package itens;

/**
 * @author BV3024679
 */
public class TesteComplexo {
    public static void main(String[] args){
        Complexo a = new Complexo();
        Complexo b = new Complexo();
        
        a.real = 2.0;
        a.imaginario = 3.0;
        
        b.real = 3.0;
        b.imaginario = 5.0;
        
        Complexo s = a.somar(b);
        s.imprime();
    }
}
