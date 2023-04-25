package exemplo03;

public class Funcionario {
    private String nome;
    private String cpf;
    private double salarioBase;
    
    public Funcionario() {
        salarioBase = 2000;
    }
    
    public Funcionario(String nome, String cpf) {
        this();
        this.nome = nome;
        this.cpf = cpf;
    }
    
    public String getNome(){
        return nome;
    }
    
    public String getCpf(){
        return cpf;
    }
    
    public double getSalarioBase(){
        return salarioBase;
    }
}
