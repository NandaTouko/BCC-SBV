package observer;

/*
Padrão Observer
Fonte: https://refactoring.guru/pt-br/design-patterns/observer
*/

import java.util.ArrayList;
import java.util.List;

// Corresponde a classe Publisher
public class Acao {
    private String ticker;
    private double valor;
    private List<AcaoObserver> interessados;
    
    public Acao(String ticker, double valor) {
        this.ticker = ticker;
        this.valor = valor;
        interessados = new ArrayList<>();
    }
    
    public void registrarInteressado(AcaoObserver interessado) {
        interessados.add(interessado);
    }
    
    public void removerInteressado(AcaoObserver interessado) {
        interessados.remove(interessado);
    }
    
    public double getValor() {
        return valor;
    }
    
    public String getTicker() {
        return ticker;
    }
    
    public void setValor(double valor) {
        this.valor = valor;
        
        // notificar interessados
        for(AcaoObserver interessado : interessados) {
            interessado.notificaAlteracao(this);
        }
    }
    
    @Override
    public String toString() {
        return "[" + ticker + "]: R$ " + valor;
    }
}
