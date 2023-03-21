package ex5;

public class Principal {
	public static void main(String[] args) {
		Livro l = new Livro();

		l.setTitulo("Biblía");
		l.setAutor("Apóstolos");
		l.setNumPagina(500);

		System.out.print("O livro '" + l.getTitulo() + "', escrito por '" + l.getAutor() + "', ");
		System.out.println("é " + (l.isGrande() ? "grande!" : "pequeno!"));
	}
}
