/*
Padão Adapter
Fonte: https://refactoring.guru/pt-br/design-patterns/adapter
*/
package adapter;

import java.text.SimpleDateFormat;
import java.util.Calendar;

public class ControleDePonto {
    public void registraEntrada(Funcionario f) {
        String entrada = getHorario();
        System.out.println("[CPv01] Entrada: " + f.getNome() + " às " + entrada);
    }
    
    public void registraSaida(Funcionario f) {
        String saida = getHorario();
        System.out.println("[CPv01] Saída: " + f.getNome() + " às " + saida);
    }
    
    // método auxiliar para gerar um horario
    private String getHorario(){
        Calendar calendar = Calendar.getInstance();
        SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy H:m:ss");
        String horario = formato.format(calendar.getTime());
        return horario;
    }
}
