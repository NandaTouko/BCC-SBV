import java.util.ArrayList;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class MyThread extends Thread{
    private int numId;
    private int item;

    public MyThread(int numId, int item)
    {
        this.numId = numId;
        this.item = item;
    }

    public static void main(String[] args) throws InterruptedException { 
        ArrayList<MyThread> lista = new ArrayList<>();
        
        while(true) {
            if(lista.isEmpty() || !lista.get(lista.size()-1).isAlive()) {
                Random rnd = new Random();
                int vendedor = 1 + rnd.nextInt(2);
                int opcao = 1 + rnd.nextInt(4);

                lista.add(new MyThread(vendedor, opcao));
                lista.get(lista.size()-1).start();
            }
        }
    }   
    
    @Override
    public void run() {
        Random rnd = new Random();
        
        int tSol = 5 + rnd.nextInt(15);
        try {
            Thread.sleep(tSol * 1000); // Tempo Solicitação
        } catch (InterruptedException ex) {
            Logger.getLogger(MyThread.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        System.out.println("Vendedor " + numId + " solicitou o item " + item + " para o almoxarifado em " + tSol + "s");
        
        int tSep = 1 + rnd.nextInt(9);
        
        try {
            Thread.sleep(tSep * 1000); // Tempo Separação
        } catch (InterruptedException ex) {
            Logger.getLogger(MyThread.class.getName()).log(Level.SEVERE, null, ex);
        }

        System.out.println("Almoxarifado separou o item " + item + " para o vendedor " + numId + " em " + tSep + "s");
        
        try {
            Thread.sleep(5000); // Tempo Espera
        } catch (InterruptedException ex) {
            Logger.getLogger(MyThread.class.getName()).log(Level.SEVERE, null, ex);
        }

        System.out.println("Vendedor " + numId + " coletou o item " + item + " no almoxarifado depois de " + 5 + "s");
    }
}