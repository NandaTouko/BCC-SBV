package itens;

/**
 * @author BV3024679
 */
public class Principal {
    public static void main(String[] args) {
        Livro livro1 = new Livro();
        Livro livro2 = new Livro();
        
        livro1.titulo = "Meditações";
        livro1.autor = "Marco Aurélio";
        livro1.folhear();
        
        
        livro2.titulo = "Amor de Redenção";
        livro2.autor = "Francine";
        livro2.folhear();
        livro2.folhear();
        
        livro1.qualPaginaVoceEsta();
        livro2.qualPaginaVoceEsta();
    }
}
