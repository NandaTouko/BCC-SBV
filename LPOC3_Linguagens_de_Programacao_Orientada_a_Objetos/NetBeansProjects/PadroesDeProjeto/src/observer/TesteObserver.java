/*
Padrão Observer
Fonte: https://refactoring.guru/pt-br/design-patterns/observer
*/
package observer;

public class TesteObserver {
    public static void main(String [] args) {
        Acao petr4 = new Acao("PETR4", 27.61);
        Acao vale3 = new Acao("VALE3", 66.39);
        
        Corretora xp = new Corretora("XP");
        Corretora toro = new Corretora("TORO");
        
        Portal infoMoney = new Portal("InfoMoney");
        petr4.registrarInteressado(toro);
        petr4.registrarInteressado(xp);
        petr4.registrarInteressado(infoMoney);
        vale3.registrarInteressado(xp);
        
        // Ocorre alteração e precisa notificar interessados
        petr4.setValor(27.65);
        vale3.setValor(66.10);
    }
}
