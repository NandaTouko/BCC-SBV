package exemplo00;

public class Exemplo00 {
    // método de teste
    public static double dividir(double numerador, double denominador) throws Exception{
        if(denominador == 0){
            throw new Exception("Divisão por zero");
        }
        
        return numerador/denominador;
    }
    
    public static void main(String[] args) {
        double num = 10.0;
        double den = 0.0;
        double resultado = 2.0;
        
        try {
            //utilizando o método dividir
            resultado = dividir(num, den);
            System.out.println(resultado);
        } catch(Exception e){
            System.out.println(e.getMessage());
        } finally {
            System.out.println("Esse trecho é executado sempre");
        }
    }
}
