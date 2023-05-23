package exemplo00;

public class Exemplo00c {
    // método de teste
    public static double dividir(double numerador, double denominador) throws Exception{
        if(denominador == 0){
            throw new Exception("Divisão por zero");
        }
        
        return numerador/denominador;
    }
    
    public static double metodo1(double a, double b) throws Exception{
        return dividir(a,b);
    }
    
    public static double metodo2(double a, double b){
        double resultado = 0.0;
        
        try {
            resultado = metodo1(a, b);
        } catch (Exception e) {
            System.out.println("Método 2: " + e.getMessage());
        }
        
        return resultado;
    }
    
    public static void main(String[] args) {
        double num = 10.0;
        double den = 2.0;
        double resultado = 0.0;
        
        resultado = metodo2(num, den);
        System.out.println(resultado);
    }
}
