package lojamultithread;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

public class Almoxarifado {
    private final Object localSeparacao = new Object();
    private final Queue<Integer> filaEncomendas = new LinkedList<>();
    private final Random random = new Random();

    public void separarRoupas(int vendedorId) {
        synchronized (localSeparacao) {
            System.out.println("Vendedor " + vendedorId + " está separando as roupas...");
            int tempoSeparacao = 1 + random.nextInt(10);
            try {
                Thread.sleep(tempoSeparacao * 1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
            System.out.println("Vendedor " + vendedorId + " terminou a separação em " + tempoSeparacao + " segundos.");
        }
    }

    public void fazerEncomenda(int vendedorId) {
        while (true) {
            // Simula o tempo de espera para fazer uma nova encomenda
            int tempoEntreEncomendas = 5 + random.nextInt(16);
            try {
                Thread.sleep(tempoEntreEncomendas * 1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }

            System.out.println("Vendedor " + vendedorId + " fez uma nova encomenda.");
            synchronized (filaEncomendas) {
                filaEncomendas.add(vendedorId);
                filaEncomendas.notify(); // Notifica um vendedor para processar a encomenda
            }
            processarEncomenda();
        }
    }

    public void processarEncomenda() {
        while (true) {
            int vendedorId;
            synchronized (filaEncomendas) {
                while (filaEncomendas.isEmpty()) {
                    try {
                        filaEncomendas.wait(); // Espera até que haja uma encomenda
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                    }
                }
                vendedorId = filaEncomendas.poll(); // Remove a encomenda da fila
            }
            separarRoupas(vendedorId);
        }
    }
}
