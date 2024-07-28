package entidades;

public class Motor {
    private String cilindradas;
    private int potencia;
    private int qtdeLitros;
    private boolean eletrico;
    
    // Métodos para alterar valores
    public void setCilindradas(String c){
        cilindradas = c;
    }
    
    public void setPotencia(int p){
        potencia = p;
    }
    
    public void setQtdeLitros(int qtd){
        qtdeLitros = qtd;
    }
    
    public void setEletrico(boolean bin){
        eletrico = bin;
    }
    
    // Métodos para ler valores
    public String getCilindradas(){
        return cilindradas;
    }
    
    public int getPotencia(){
        return potencia;
    }
    
    public int getQtdeLitros(){
        return qtdeLitros;
    }
    
    public boolean getEletrico(){
        return eletrico;
    }
    
    // Ações
    public void realizarIgnicao(){
        System.out.println("Realizou ignição...");
    }
}
