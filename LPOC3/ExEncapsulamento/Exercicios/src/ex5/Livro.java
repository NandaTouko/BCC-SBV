package ex5;

public class Livro {
	private String titulo;
	private String autor;
	private int numPagina;

	// Set
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public void setAutor(String autor) {
		this.autor = autor;
	}

	public void setNumPagina(int n) {
		numPagina = n;
	}

	// Get
	public String getTitulo() {
		return titulo;
	}

	public String getAutor() {
		return autor;
	}

	public int getNumPagina() {
		return numPagina;
	}

	// Ação
	public boolean isGrande() {
		if (numPagina < 100) {
			return false;
		} else {
			return true;
		}
	}
}
