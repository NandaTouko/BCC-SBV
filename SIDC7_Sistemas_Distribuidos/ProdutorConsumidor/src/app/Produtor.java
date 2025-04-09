package app;

import java.util.Random;

// Gera valores inteiros e insere no Buffer
// Representa um processo que usa recursos compartilhados, 
// com a sincronização com o Consumidor para que os dados sejam consumidos corretamente
public class Produtor {

    private final Buffer buffer;

    public Produtor(Buffer buffer) {
        this.buffer = buffer;
    }

    public void produzir() {
        int valor = new Random().nextInt(100);
        buffer.escrever(valor);
        System.out.println(" Valor produzido : " + valor);
    }
}
