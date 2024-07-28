package ex9;

public class Funcionario {
	private String nome;
	private double salario;
	private String cargo;

	// Set
	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setSalario(double salario) {
		this.salario = salario;
	}

	public void setCargo(String cargo) {
		this.cargo = cargo;
	}

	// Get
	public String getNome() {
		return nome;
	}

	public double getSalario() {
		return salario;
	}

	public String getCargo() {
		return cargo;
	}

	// Ações
	public double reajustarSalario(double porcentagem) {
		return (salario + (salario * (porcentagem / 100)));
	}
}
