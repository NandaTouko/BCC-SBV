package exemplo01;

public class UsaConta {
    public static void main(String [] args) {
        Conta c1 = new Conta();
        
        try{
            c1.depositar(-100);
        } catch(IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
        
        
        System.out.println(c1.getSaldo());
    }
}
