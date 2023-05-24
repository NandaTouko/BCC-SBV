package exemplo00;

public class Exemplo00b {
    // método de teste
    public static double dividir(double numerador, double denominador) throws Exception{
        if(denominador == 0){
            throw new Exception("Divisão por zero");
        }
        
        return numerador/denominador;
    }
    
    public static void main(String[] args) throws Exception {
        double num = 10.0;
        double den = 0.0;
        double resultado = 0.0;
        
        resultado = dividir(num, den);
        System.out.println(resultado);
    }
}
