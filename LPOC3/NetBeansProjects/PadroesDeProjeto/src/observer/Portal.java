/*
Padrão Observer
Fonte: https://refactoring.guru/pt-br/design-patterns/observer
*/

package observer;

public class Portal implements AcaoObserver{
    private String nome;
    
    public Portal(String nome){
        this.nome = nome;
    }

    @Override
    public void notificaAlteracao(Acao acao) {
        System.out.println("Portal " + nome + " foi notificado.");
        System.out.println(acao);
    }
    
}
