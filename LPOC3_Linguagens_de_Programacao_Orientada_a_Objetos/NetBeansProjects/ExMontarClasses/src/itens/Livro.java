package itens;

/**
 * @author BV3024679
 */
public class Livro {
    // Atributos
    String titulo;
    String autor;
    String editora;
    int paginaAtual;

    // Métodos
    void folhear() {
        paginaAtual++;
    }
    
    void qualPaginaVoceEsta(){
        System.out.println("Eu, " + titulo + " estou na página " + paginaAtual);
    }
}
