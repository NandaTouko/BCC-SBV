/*
Padão Adapter
Fonte: https://refactoring.guru/pt-br/design-patterns/adapter
*/
package adapter;

public class Funcionario {
    private final String nome;
    
    public Funcionario(String nome) {
        this.nome = nome;
    }
    
    public String getNome() {
        return nome;
    }
}
