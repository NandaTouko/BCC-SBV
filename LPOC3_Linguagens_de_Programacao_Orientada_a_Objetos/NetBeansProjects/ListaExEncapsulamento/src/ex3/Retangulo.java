package ex3;

public class Retangulo {
    private double comprimento;
    private double largura;
    
    // Set
    public void setComprimento(double comp){
        comprimento = comp;
    }
    
    public void setLargura(double larg){
        largura = larg;
    }
    
    // Get
    public double getComprimento(){
        return comprimento;
    }
    
    public double getLargura(){
        return largura;
    }
    
    // Ação
    public double calcularArea(){
        return (comprimento * largura);
    }
}
