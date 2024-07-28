package ex4;

public class Carro {
    private String marca;
    private String modelo;
    private int anoFabricacao;
    
    // Set
    public void setMarca(String marca){
        this.marca = marca;
    }
    
    public void setModelo(String modelo){
        this.modelo = modelo;
    }
    
    public void setAnoFabricacao(int ano){
        anoFabricacao = ano;
    }
    
    // Get
    public String getMarca(){
        return marca;
    }
    
    public String getModelo(){
        return modelo;
    }
    
    public int getAnoFabricacao(){
        return anoFabricacao;
    }
    
    // Ação
    public int idadeCarro(){
        return (2023 - anoFabricacao);
    }
}
