package project.praticapadroesprojetos;

public abstract class TrechoPago extends Trecho {
    private double passagem;
    private int assento;
    private int plataforma;
    private String viacao;
    
    // SETs
    public void setPassagem(double valor) {
        passagem = valor;
    }
    
    public void setAssento(int num) {
        assento = num;
    }
    
    public void setPlataforma(int num) {
        plataforma = num;
    }
    
    public void setViacao(String viacao) {
        this.viacao = viacao;
    }
    
    // GETs
    public double getPassagem() {
       return passagem;
    }
    
    public int getAssento() {
        return assento;
    }
    
    public int getPlataforma() {
        return plataforma;
    }
    
    public String getViacao() {
        return viacao;
    }
}
