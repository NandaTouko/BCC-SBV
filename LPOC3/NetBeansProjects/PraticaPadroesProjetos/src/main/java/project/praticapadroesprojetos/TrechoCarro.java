package project.praticapadroesprojetos;

public class TrechoCarro extends Trecho {
    private double kmL; // KM/L
    private double precoCombustivel;
    private double precoAluguel;
    
    // SETs
    public void setKmL(double kmL) {
        this.kmL = kmL;
    }
    
    public void setPrecoCombustivel(double preco) {
        precoCombustivel = preco;
    }
    
    public void setPrecoAluguel(double preco) {
        precoAluguel = preco;
    }
    
    // GETs
    public double getKmL() {
        return kmL;
    }
    
    public double getPrecoCombustivel() {
        return precoCombustivel;
    }
    
    public double getPrecoAluguel() {
        return precoAluguel;
    }
}
