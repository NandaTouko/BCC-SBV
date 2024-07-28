package exemplo03;

public class OperadorDeCaixa extends Funcionario {
    private double horasExtras;
    
    public void setHorasExtras(double horas){
        horasExtras = horas;
    }
    
    public double getHorasExtras(){
        return horasExtras;
    }
    
    @Override
    public double getSalarioBase(){
        double base = super.getSalarioBase();
        
        return (base + (horasExtras * 9.5));
    }
}
