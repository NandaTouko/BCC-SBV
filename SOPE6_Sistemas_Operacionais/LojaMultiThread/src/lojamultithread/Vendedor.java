package lojamultithread;

import java.util.Random;

public class Vendedor extends Thread {

    private final int idVendedor;
    private final Almoxarifado almoxarifado;
    private final Random random = new Random();

    public Vendedor(int idVendedor, Almoxarifado almoxarifado) {
        this.idVendedor = idVendedor;
        this.almoxarifado = almoxarifado;
    }

    @Override
    public void run() {
        while (true) {
            try {
                // Simula o tempo de solicitação de nova encomenda
                int tempoSolicitacao = random.nextInt(16) + 5; // 5 a 20 segundos
                Thread.sleep(tempoSolicitacao * 1000);

                System.out.println("Vendedor " + idVendedor + " solicitou item => " + tempoSolicitacao + " segundos");
                almoxarifado.acessarAlmoxarifado(idVendedor);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.err.println("Vendedor " + idVendedor + " foi interrompido.");
            }
        }
    }
}
