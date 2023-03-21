package ex7;

public class Circulo {
	private double raio;

	// Set
	public void setRaio(double r) {
		raio = r;
	}

	// Get
	public double getRaio() {
		return raio;
	}

	// Ações
	public double calcPerimetro() {
		return (2 * 3.14 * raio);
	}
}
