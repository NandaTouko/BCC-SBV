package exemplo06;

public interface Vetor {
    int size(); // retorna o tamanho do vetor
    default boolean estaVazio() {
        return size() == 0;
    }
}
