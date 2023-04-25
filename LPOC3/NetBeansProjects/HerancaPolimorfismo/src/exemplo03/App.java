package exemplo03;

import java.util.ArrayList;

public class App {
    public static void main(String [] args){
        //Funcionario [] equipe = new Funcionario[6];
        ArrayList<Funcionario> equipe = new ArrayList<>();
        
        Repositor repositor1 = new Repositor("Ana", "111");
        Repositor repositor2 = new Repositor("Bob", "222");
        
        Vendedor vendedor1 = new Vendedor("Silvio", "333");
        vendedor1.setTotalDeVendas(3000);
        
        Vendedor vendedor2 = new Vendedor("Marcela", "444");
        vendedor2.setTotalDeVendas(7000);
        
        Vendedor vendedor3 = new Vendedor("Jair", "555");
        vendedor3.setTotalDeVendas(5000);
        
        Gerente gerente = new Gerente("Cardoso", "667");
        gerente.incluirVendedor(vendedor1);
        gerente.incluirVendedor(vendedor2);
        gerente.incluirVendedor(vendedor3);
        
        equipe.add(repositor1);
        equipe.add(vendedor1);
        equipe.add(repositor2);
        equipe.add(gerente);
        equipe.add(vendedor2);
        equipe.add(vendedor3);
        
        // processamento polimorfico
        for(Funcionario colaborador : equipe){
            System.out.println("Nome: " + colaborador.getNome() + "; Salário R$ " + colaborador.getSalarioBase());
        }
    }
}
