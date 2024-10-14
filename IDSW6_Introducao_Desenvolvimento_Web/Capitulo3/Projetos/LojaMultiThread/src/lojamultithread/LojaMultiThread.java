package lojamultithread;

public class LojaMultiThread {
    public static void main(String[] args) {
        Almoxarifado almoxarifado = new Almoxarifado();
        Vendedor vendedor1 = new Vendedor(almoxarifado, 1);
        Vendedor vendedor2 = new Vendedor(almoxarifado, 2);

        vendedor1.start();
        vendedor2.start();
    }    
}
