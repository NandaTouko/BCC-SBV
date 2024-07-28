package ex8;

public class Telefone {
	private int codArea;
	private String numero;
	private String tipo;

	// Set
	public void setCodArea(int cod) {
		codArea = cod;
	}

	public void setNumero(String num) {
		numero = num;
	}

	public void setTipo(String tipo) {
		this.tipo = tipo;
	}

	// Get
	public int getCodArea() {
		return codArea;
	}

	public String getNumero() {
		return numero;
	}

	public String getTipo() {
		return tipo;
	}

	// Ações
	public boolean isNumeroValido() {
		if (numero.length() == 8 || numero.length() == 9) {
			return true;
		} else {
			return false;
		}
	}
}
