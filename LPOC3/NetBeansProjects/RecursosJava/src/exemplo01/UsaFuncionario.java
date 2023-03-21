package exemplo01;

public class UsaFuncionario {
    public static void exibir(Funcionario f){
        f.setTotalVendas(2500.0);
        System.out.println(f.getNome() + "\n" + f.getSalario());
        System.out.println("Com um total de vendas de R$2500,70 a comissao é de " +  f.calcularComissao() + "%");
        System.out.println("Salario com comissao R$" +  f.getSalario() + "\n========");
    }
    
    public static void main(String[] args){
        Funcionario f1 = new Funcionario();
        Funcionario f2 = new Funcionario("Guilherme", 3000);
        // Funcionario f3 = null;
        Funcionario f3 = new Funcionario(null);
        
        exibir(f3);
        exibir(f1);
        
        //aumenta o salario em 5%
        f2.aumentarSalario(5);        
        
        exibir(f2);
    }
}
