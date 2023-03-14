package app;

public class Principal {
    public static void main(String [] args){
        Mouse m1 = new Mouse(); // nosso objeto, q parece uma variável
        // int a = 10; => isso o compilador sabe o que terá na variável, pois o int é primitivo, já o Mouse nós q criamos, então ele não espera nada
        m1.atribuirCor("Preto");
        m1.mover(10, 20);
        
        System.out.println( m1.qualSuaPosicao() );
    }
}
