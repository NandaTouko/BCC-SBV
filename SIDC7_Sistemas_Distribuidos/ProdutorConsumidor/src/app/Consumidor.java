package app;

// Retira dados do buffer e os processa
public class Consumidor {

    private final Buffer buffer;

    // Lê o valor armazenado no buffer e o retorna
    public Consumidor(Buffer buffer) {
        this.buffer = buffer;
    }

    public int consumir() {
        int valor = this.buffer.ler();
        System.out.println(" Valor consumidor foi " + valor);
        return valor;
    }
}
