/*
Padão Adapter
Fonte: https://refactoring.guru/pt-br/design-patterns/adapter
*/
package adapter;

public class ControleDePontoAdapter extends ControleDePonto {
    private ControleDePontoPlus controlePlus;
    
    public ControleDePontoAdapter() {
        controlePlus = new ControleDePontoPlus();
    }
    
    @Override
    public void registraEntrada(Funcionario f) {
        controlePlus.registraPonto(f, true);
    }
    
    @Override
    public void registraSaida(Funcionario f) {
         controlePlus.registraPonto(f, false);
    }
}
