package threads;

public class ThreadsEco {
    public static void main(String [] args) {
        Thread t1 = new Thread(new Eco());
        Thread t2 = new Thread(new Eco());
        
        // Define os nomes
        t1.setName("Eco 1");
        t2.setName("Eco 2");
        
        // Dispara as threads
        // Mesmo que o t2 seja iniciado depois, por falta de sincronismo, as vezes ele roda primeiro.
        t1.start();
        t2.start();
    }
}
