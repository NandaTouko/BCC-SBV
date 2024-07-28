package ex2;

public class ContaBancaria {
    private int numConta;
    private double saldo;
    private String nome;

    // Set
    public void setNumConta(int num) {
        numConta = num;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    // Get
    public int getNumConta() {
        return numConta;
    }

    public double getSaldo() {
        return saldo;
    }

    public String getNome() {
        return nome;
    }

    // Ações
    public void deposito(double valor) {
        saldo += valor;
    }

    public void sacar(double valor) {
        saldo -= valor;
    }
}
