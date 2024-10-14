package lojamultithread;

/*
    Amanda Moreira (BV3024679)
    Giovana Naiara Silva (BV3025063)
    João Vitor Ribeiro Maciel (BV3015505)
*/

public class LojaMultiThread {
    public static void main(String[] args) {
        Almoxarifado almoxarifado = new Almoxarifado();
        Vendedor vendedor1 = new Vendedor(1, almoxarifado);
        Vendedor vendedor2 = new Vendedor(2, almoxarifado);

        vendedor1.start();
        vendedor2.start();
    }    
}
