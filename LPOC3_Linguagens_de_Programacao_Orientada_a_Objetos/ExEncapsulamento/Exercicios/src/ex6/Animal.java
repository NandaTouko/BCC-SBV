package ex6;

public class Animal {
	private String especie;
	private int idade;
	private double peso;

	// Set
	public void setEspecie(String especie) {
		this.especie = especie;
	}

	public void setIdade(int idade) {
		this.idade = idade;
	}

	public void setPeso(double p) {
		peso = p;
	}

	// Get
	public String getEspecie() {
		return especie;
	}

	public int getIdade() {
		return idade;
	}

	public double getPeso() {
		return peso;
	}

	// Ação
	public boolean isPesoIdeal() {
		int idadeMeses = idade * 12;

		if (peso < (idadeMeses / 10)) {
			return false;
		} else {
			return true;
		}
	}
}
