/*
Padão Adapter
Fonte: https://refactoring.guru/pt-br/design-patterns/adapter
*/
package adapter;

public class TesteAdapter {
   public static void main(String [] args) throws InterruptedException {
       ControleDePonto controle = new ControleDePonto();
       Funcionario f = new Funcionario("Ace");
       
       controle.registraEntrada(f);
       Thread.sleep(2000);
       controle.registraSaida(f);
   }
}
