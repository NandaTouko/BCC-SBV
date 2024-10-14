package lojamultithread;

import java.util.Random;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Almoxarifado {
    private final Lock lock = new ReentrantLock();
    private final Random random = new Random();

    public void separarRoupa(int vendedorId) throws InterruptedException {
        // Simula o tempo de separação
        int tempoSeparacao = random.nextInt(9) + 1; // 1 a 10 segundos
        System.out.println("Almoxarifado separando para vendedor: " + vendedorId + " => " + tempoSeparacao + " segundos");
        Thread.sleep(tempoSeparacao * 1000);
        System.out.println("Almoxarifado separou para vendedor: " + vendedorId);
    }

    public void acessarAlmoxarifado(int vendedorId) throws InterruptedException {
        lock.lock(); // Acesso exclusivo ao almoxarifado
        try {
            // Espera 5 segundos para aguardar o local
            Thread.sleep(5000);
            separarRoupa(vendedorId);
            System.out.println("Vendedor " + vendedorId + " coletou o item.");
        } finally {
            lock.unlock();
        }
    }
}
