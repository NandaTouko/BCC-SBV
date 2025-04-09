package threads;

import java.util.Random;

public class Eco implements Runnable {

    @Override
    public void run() {
        try {
            int tempo = new Random().nextInt(5000);
            String nome = Thread.currentThread().getName();
            System.out.println("Eu, " + nome + ", vou dormir por " + tempo + " milisegundos...");
            Thread.sleep(tempo);
            System.out.println(nome + " terminou.");
        } catch(InterruptedException ex) {
            //mensagem
        }
    }
    
}
