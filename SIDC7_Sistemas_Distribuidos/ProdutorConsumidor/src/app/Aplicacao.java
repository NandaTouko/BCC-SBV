package app;

/*
    A classe Aplicacao é responsável por executar o código. Ela cria instâncias
    de Produtor, Consumidor e Buffer. O Produtor insere valores no buffer em
    um laço, e o Consumidor lê um valor
*/
public class Aplicacao {

    public static void main(String[] args) {
        Buffer buffer = new Buffer();
        Produtor produtor = new Produtor(buffer);
        Consumidor consumidor = new Consumidor(buffer);

        for (int i = 1; i <= 10; i++) {
            produtor.produzir();
        }

        int valorConsumido = consumidor.consumir();
        System.out.println(valorConsumido);
    }
}
