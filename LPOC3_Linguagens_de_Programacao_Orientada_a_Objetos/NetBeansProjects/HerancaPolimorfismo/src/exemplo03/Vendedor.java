package exemplo03;

public class Vendedor extends Funcionario {
    // atributo especifico
    private double totalDeVendas;
    
    public Vendedor(String nome, String cpf){
        // chama o construtor da superclasse
        super(nome, cpf);
    }
    
    public void setTotalDeVendas(double total){
        if(total > 0){
            totalDeVendas = total;
        }
    }
    
    public double getTotalDeVendas(){
        return totalDeVendas;
    }
    
    // Regra de negócio
    public double calcularComissao() {
        double comissao = 0.0;
        
        if(totalDeVendas <= 5000.0){
            comissao = totalDeVendas * 0.05;
        } else {
            comissao = totalDeVendas * 0.1;
        }
        
        return comissao;
    }
    
    @Override
    public double getSalarioBase(){
        double base = super.getSalarioBase();
        double comissao = this.calcularComissao();
        
        return (base + comissao);
    }
}
