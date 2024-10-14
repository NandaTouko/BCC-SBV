package lojamultithread;

public class Vendedor extends Thread {
    private final Almoxarifado almoxarifado;
    private final int vendedorId;

    public Vendedor(Almoxarifado almoxarifado, int vendedorId) {
        this.almoxarifado = almoxarifado;
        this.vendedorId = vendedorId;
    }

    @Override
    public void run() {
        almoxarifado.fazerEncomenda(vendedorId);
    }
}
