/*
Padrão Observer
Fonte: https://refactoring.guru/pt-br/design-patterns/observer
*/

package observer;

// Corresponde a um tipo de "Concrete Subscriber"
public class Corretora implements AcaoObserver {
    private String nome;
    
    public Corretora(String nome){
        this.nome = nome;
    }

    @Override
    public void notificaAlteracao(Acao acao) {
        System.out.println("Corretora: " + nome + " foi notificada.");
        System.out.println(acao);
    }
}
