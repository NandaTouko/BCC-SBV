package exemplo01;

import java.util.Objects;

public class Funcionario {
    private String nome;
    private double salario;
    private double totalVendas;
    private int comissao = 0;
    
    //construtor padrão
    public Funcionario() {
        this("Desconhecido", 1000);
    }
    
    //construtor não-padrão
    public Funcionario(String nome){
        // null.toUpperCase()
        /*
        if(nome == null){
            this.nome = "DESCONHECIDO";
        } else {
            this.nome = nome.toUpperCase();
        }
        */
        
        // Objects.requireNonNull(nome, "O nome não pode ser nulo.");
        nome = Objects.requireNonNullElse(nome, "desconhecido"); // faz o mesmo que o if-else
        this.nome = nome.toUpperCase();
    }
    
    //construtor não-padrão
    public Funcionario(String nome, double salario){
        // chama o construtor não-padrão com 1 parâmetro
        this(nome);
        this.salario = salario;
    }
    
    public void setTotalVendas(double total){
        this.totalVendas = total;
    }
    
    public double getTotalVendas(){
        return totalVendas;
    }
    
    public String getNome(){
        return nome;
    }
    
    public double getSalario(){
        return (salario + (salario * (comissao/100)));
    }
    
    // aumentarSalario(Funcionario f, double porcentagem)
    // f => parametro implicito (this!)
    // porcentagem => parametro explicito
    public void aumentarSalario(double porcentagem){
        double taxa = porcentagem/100.0;
        double aumento = salario * taxa;
        salario += aumento;
    }
    
    public int calcularComissao() {
        if(totalVendas > 0 && totalVendas <= 2000){
            comissao = 5;
        } else if(totalVendas > 2000 && totalVendas <= 7000) {
            comissao = 10;
        } else if(totalVendas > 7000) {
            comissao = 15;
        }
        
        return comissao;
    }
}
