package entidades;

public class Moto {
    private Motor motor;
    private Roda rodaDianteira;
    private Roda rodaTraseira;
    
    public void setMotor(Motor motor){
        this.motor = motor;
    }
    
    public void setRodaDianteira(Roda roda){
        this.rodaDianteira = roda;
    }
    
    public void setRodaTraseira(Roda roda){
        this.rodaTraseira = roda;
    }
    
    public Motor getMotor(){
        return motor;
    }
    
    public Roda getRodaDianteira(){
        return rodaDianteira;
    }
    
    public Roda getRodaTraseira(){
        return rodaTraseira;
    }
    
    //Ações
    public void ligar(){
        System.out.println("Ligando a moto...");
        motor.realizarIgnicao();
        System.out.println("Vrum...Vrum...");
    }
    
    public void acelerar(){
        System.out.println("Vruuuuum");
    }
    
    public void frear(){
        System.out.println("Freio apertado!");
    }
}
