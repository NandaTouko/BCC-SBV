/*
Padrão Observer
Fonte: https://refactoring.guru/pt-br/design-patterns/observer
*/

package observer;

// Corresponde a interface Subscriber
public interface AcaoObserver {
    void notificaAlteracao(Acao acao);
}
