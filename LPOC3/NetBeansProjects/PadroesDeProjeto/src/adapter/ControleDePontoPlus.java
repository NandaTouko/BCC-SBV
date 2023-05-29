/*
Padão Adapter
Fonte: https://refactoring.guru/pt-br/design-patterns/adapter
*/
package adapter;

import java.text.SimpleDateFormat;
import java.util.Calendar;

public class ControleDePontoPlus {
    public void registraPonto(Funcionario f, boolean entrada) {
        String horario = getHorario();
        
        if(entrada) {
            System.out.println("[CPv02Plus] Entrada: " + f.getNome() + " às " + horario);
        } else {
            System.out.println("[CPv02Plus] Saída: " + f.getNome() + " às " + horario);
        }
    }
    
    // método auxiliar para gerar um horario
    private String getHorario(){
        Calendar calendar = Calendar.getInstance();
        SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy H:m:ss");
        String horario = formato.format(calendar.getTime());
        return horario;
    }
}
