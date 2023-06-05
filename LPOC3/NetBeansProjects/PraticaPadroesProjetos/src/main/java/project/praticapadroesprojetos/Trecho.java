package project.praticapadroesprojetos;

public abstract class Trecho {
    private String origem;
    private String destino;
    private double distancia; // KM
    private int tempo; // segundos
    
    // SETs
    
    public void setOrigem(String origem) {
        this.origem = origem;
    }
    
    public void setDestino(String destino) {
        this.destino = destino;
    }
    
    public void setDistancia(double distancia) {
        this.distancia = distancia;
    }
    
    public void setTempo(int tempo) {
        this.tempo = tempo;
    }
    
    // GETs
    
    public String getOrigem() {
        return origem;
    }
    
    public String getDestino() {
        return destino;
    }
    
     public double getDistancia() {
        return distancia;
    }
     
     public int getTempo() {
        return tempo;
    }
}
