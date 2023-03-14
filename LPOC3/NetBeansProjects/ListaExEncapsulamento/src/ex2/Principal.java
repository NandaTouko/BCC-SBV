package ex2;

public class Principal {
    public static void main(String[] args){
        ContaBancaria c = new ContaBancaria();
        
        c.setNome("Evaristo Souza");
        c.setNumConta(1452);
        c.setSaldo(750.50);
        
        System.out.println("Saque de R$" + c.getSaldo() + " feito por " + c.getNome() + " na conta " + c.getNumConta());
    }
}
