package exemplo00;

/*
    Exemplo de métodos sobrecarregados
    Method overloading
*/
public class Matematica {
    public int somar(int a, int b){
        return (a + b);
    }
    
    // Método sobrecarregado
    public int somar(int a, int b, int c){
        return (a + b + c);
    }
    
    // Método sobrecarregado
    public int somar(int[] vetor){
        int resultado = 0;
        
        for(int i = 0; i < vetor.length; i++){
            resultado += vetor[i];
        }
        
        return resultado;
    }
}
