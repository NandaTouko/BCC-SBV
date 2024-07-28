package exemplo03;

import java.util.ArrayList;

public class Gerente extends Funcionario {
    // Lista de vendedores subordinados
    private ArrayList<Vendedor> vendedores;
    
    public Gerente(String nome, String cpf){
        super(nome, cpf);
        vendedores = new ArrayList<>();
    }
    
    public void incluirVendedor(Vendedor v){
        vendedores.add(v);
    }
    
    public void removerVendedor(Vendedor v){
        vendedores.remove(v);
    }
    
    @Override
    public double getSalarioBase(){
        // se o total de vendas dos vendedores
        // subordinados <= 15k recebe 1% de comissao,
        // caso contrario 3% de comissão
        
        // obtendo o valor total de vendas
        double totalVendas = 0.0;
        
        for(Vendedor v: vendedores){
            totalVendas += v.getTotalDeVendas();
        }
        
        double comissao = 0.0;
        
        if(totalVendas <= 15000){
            comissao = totalVendas * 0.01; // 1%
        } else {
            comissao = totalVendas * 0.03; // 3%
        }
        
        double base = super.getSalarioBase();
        
        return (base + comissao);
    }
}
