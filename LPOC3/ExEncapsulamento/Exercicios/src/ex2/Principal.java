package ex2;

public class Principal {
    public static void main(String[] args) {
        ContaBancaria c = new ContaBancaria();

        c.setNome("Evaristo Souza");
        c.setNumConta(1452);
        c.setSaldo(750.50);

        System.out.println(c.getNome() + ", com numéro da conta " + c.getNumConta() + ", possui R$" + c.getSaldo());
        c.deposito(200);
        System.out.println("Após deposito ficou com R$" + c.getSaldo());
        c.sacar(500);
        System.out.println("Após saque ficou com R$" + c.getSaldo());
    }
}
