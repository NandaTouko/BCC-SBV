package app;

// Área compartilhada entre produtor e consumidor
public class Buffer {
    
    private int[] buffer;
    private int posicao;

    public Buffer() {
        buffer = new int[5];
    }

    public void escrever(int valor) {
        int pos = posicao % buffer.length;
        buffer[pos] = valor;
        posicao++;
    }

    public int ler() {
        return buffer[0];
    }
}
